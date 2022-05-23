/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/23 16:35:49 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_node(t_node *params)
{
	params->pid = NULL;
	params->fd = NULL;
	params->limiter = NULL;
	params->root = NULL;
}

void	ft_print_lst(t_list *lst)
 {
 	t_list	*tmp;
 	int		i;

 	tmp = lst;
 	while (tmp)
 	{
 		i = 0;
 		while (tmp->token[i])
 		{
 			printf("%s", tmp->token[i]);
 			i++;
 		}
 		printf("\n");
 		tmp = tmp->next;
 	}
 }

void	ft_sign_handle(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("\n", 0);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
		return ;
}

void	ft_print_tab(char **tokens)
{
	int	i;

	i = 0;
	if (!*tokens)
		return ;
	while (tokens[i])
		dprintf(2, "|%s|\n", tokens[i++]);
}

int	ft_test_export(t_token *token)
{
	if (token->token[0])
	{
		if (ft_strcmp(token->token[0], "export") == 0)
		{
			if (ft_export_alph(token->env) < 0)
				return (-1);
		}
	}
	return (0);
}

int	ft_find_occ_free(char **env, char *var)
{
	char	**tmp;
	int		ret;

	tmp = NULL;
	if (ft_check_equal(var) > 0)
	{
		if (ft_need_cat(var))
			tmp = ft_split(var, '+');
		else
			tmp = ft_split(var, '=');
		if (!tmp)
			return (-1);
		if (ft_find_occurence(env, tmp[0]) != -1)
		{
			ret = ft_find_occurence(env, tmp[0]);
			return (ft_free(tmp), ret);
		}
	}
	else
	{
		if (ft_find_occurence(env, var) != -1)
		{
			ret = ft_find_occurence(env, var);
			return (ft_free(tmp), ret);
		}
	}
	return (ft_free(tmp), -1);
}

static int	ft_init_env(char **env, t_node *params)
{
	int		index;

	ft_init_node(params);
	if (!params->env)
		params->env = ft_dup_tab(env);
	if (!params->env)
		return (-1);
	index = ft_find_occ_free(env, "HOME=");
	if (index > -1)
	{
		params->root = ft_strdup(env[index] + ft_strlen("HOME="));
		if (!params->root)
			return (-1);
	}
	return (0);
}

int	is_dpipe(t_token *token)
{
	int	i;

	i = 0;
	while (token->token[i])
	{
		if (ft_strcmp(token->token[i], "||") == 0)
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_exec_parsing(t_token *token, char *cmd, t_node *params)
{
	int	flag;

	flag = ft_parse_tokens(token, cmd, 0);
	if (flag == -1)
		return (ft_free(token->token), -1);
	else if (flag == -2)
		return (-2);
	else if (flag == 0)
		return (0);
	if (is_dpipe(token) == -1)
		return (ft_putstr_fd("omg no a '||' too difficult for me\n", 2), ft_free(token->token), -2);
	token->token = ft_expand(token, params);
	if (!token->token)
		return (ft_free(token->token), -1);
	if (ft_main_check_quote(token->token) == -1)
		return (ft_free(token->token), -2);
	return (0);
}
/*
int check_export(t_token *token)
{
	if (ft_export(token, token->token[0]) < 0)
		return (-1);
	return (0);
}*/

void	ft_print_env(t_node *params, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_check_equal(env[i]))
			printf("%s\n", env[i]);
		++i;
	}
	params->last_status = 0;
}

int	ft_wait_all_pid(t_node *params)
{
	int	i;
	int	status;

	i = 0;
	while (i < params->nb)
	{
		if (waitpid(params->pid[i], &status, 0) == -1)
			return (-1);
		i++;
	}
	params->last_status = WEXITSTATUS(status);
	return (0);
}

int	ft_start(t_node *params, t_token *token, t_list **lst)
{
	*lst = NULL;
	params->have_pid = 0;
	token->token = NULL;
	params->save_in = dup(0);
	params->save_out = dup(1);
	params->prompt = ft_get_last_dir(get_pwd());
	if (!params->prompt)
		return (free(params->prompt), -1);
	return (0);
}

int	ft_launch_exec(t_node *params, t_list **lst, t_token *token, char *cmd)
{
	*lst = init_lst(token);
	if (!lst)
		return (free(cmd), -1);
	if (ft_main_exec(params, lst) == -1)
		return (-2);
	ft_close_all(params);
	if (params->have_pid > 0)
	{
		if (ft_wait_all_pid(params) == -1)
			return (-1);
	}
	ft_free_after_cmd(params, lst, 1);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_token token;
	t_list	*lst;
	t_node	params;
	(void)av;
	int		flag;

	params.env = NULL;
	params.last_status = 0;
	params.prompt = NULL;
	if (ac == 1)
	{
		if (ft_init_env(env, &params) < 0)
			return (free(params.prompt), -1);
		using_history();
		while (1)
		{
			if (ft_start(&params, &token, &lst) == -1)
				return (1);
			signal(SIGINT, ft_sign_handle);
			cmd = readline(params.prompt);
			if (!cmd)
				return (ft_free_after_cmd(&params, &lst, 0), free(cmd), 1);
			if (cmd[0] == '\0')
			{
				ft_free_after_cmd(&params, &lst, 1);
				free(cmd);
				continue ;
			}
			add_history(cmd);
			flag = ft_exec_parsing(&token, cmd, &params);
			if (flag == -1)
				return (free(cmd), 1);
			else if (flag == -2 || ft_check_token(&token) == -1)
			{
				if (flag != -2)
					ft_free(token.token);
				ft_free_after_cmd(&params, &lst, 1);
				free(cmd);
				continue ;
			}
			flag = ft_launch_exec(&params, &lst, &token, cmd);
			if (flag == -1)
				return (1);
			else if (flag == -2)
				ft_free_after_cmd(&params, &lst, 1);
			rl_redisplay();
			free(cmd);
		}
	}
	return (0);
}
