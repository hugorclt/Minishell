/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 00:06:07 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_last_status = 0;

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
	g_last_status = WEXITSTATUS(status);
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

	if (ac == 1)
	{
		if (ft_init_env(env, &params) < 0)
			return (-1);
		using_history();
		while (1)
		{
			if (ft_start(&params, &token, &lst) == -1)
				return (1);
			sig_choice();
			cmd = readline("Minishell$>");
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
