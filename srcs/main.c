/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 05:25:56 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_last_status = 0;

int	init_shlvl(t_node *params)
{
	int		occ;
	int		shlvl;
	char	*var;
	char	*c_shlvl;
	
	occ = ft_find_occurence(params->env, "SHLVL");
	if (occ == -1)
	{
		params->env = ft_add_var("SHLVL=2", params->env);
		return (0);
	}
	shlvl = ft_atoi(params->env[occ] + 6);
	shlvl++;
	c_shlvl = ft_itoa(shlvl);
	if (!c_shlvl)
		return (-1);
	var = ft_strjoin("SHLVL=", c_shlvl);
	if (!var)
		return (free(c_shlvl), -1);
	if (ft_change_var(params->env, var, occ) == -1)
		return (free(c_shlvl), free(var), -1);
	free(var);
	free(c_shlvl);
	return (0);
}

int	is_sentences(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static int	is_redirect(char *str)
{
	if (ft_strcmp(str, ">") == 0
		|| ft_strcmp(str, ">>") == 0
		|| ft_strcmp(str, "<") == 0
		|| ft_strcmp(str, "<<") == 0)
		return (1);
	return (0);
}

int	ft_count_redirect(char **tab)
{
	int	i;
	int	total;

	i = 0;
	total = 0;
	while (tab[i])
	{
		if (is_redirect(tab[i]) == 1)
			total++;
		i++;
	}
	return (total);
}

int	init_tab_env_redirect(t_node *params, t_token *token)
{
	int	i;
	int	occ;
	int	size;
	int	j;
	
	params->io_env = malloc(sizeof(char *) * (ft_count_redirect(token->token) + 1));
	if (!params->io_env)
		return (-1);
	i = 0;
	j = 0;
	while (token->token[i])
	{
		if (is_redirect(token->token[i]) == 1 && token->token[i + 1])
		{
			occ = ft_find_occ(params->env, token->token[i + 1] + 1);
			if (occ != -1)
			{
				size = ft_find_len_env(params->env[occ]);
				params->io_env[j] = ft_substr(params->env[occ], size + 1, ft_strlen(params->env[i]));
				j++;
			}
		}
		i++;
	}
	params->io_env[j] = NULL;
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
		return (ft_we_dont(), ft_free(token->token), -2);
	token->token = ft_expand(token, params);
	if (!token->token)
		return (ft_free(token->token), -1);
	if (ft_main_check(token->token) == -1)
		return (ft_free(token->token), -2);
	if (ft_check_token(token) == -1)
		return (ft_free(token->token), -2);
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

static int	ft_refacto(t_node *params, t_list **lst, t_token *token, int flag)
{
	char	*cmd;

	while (1)
	{
		if (ft_refacto_start(params, lst, token, &cmd) < 0)
			return (-1);
		if (cmd[0] == '\0')
		{
			ft_refacto_free(params, cmd, lst);
			continue ;
		}
		add_history(cmd);
		flag = ft_exec_parsing(token, cmd, params);
		if (flag == -1)
			return (free(cmd), -1);
		else if (flag == -2 || ft_check_token(token) == -1)
		{
			ft_refacto_help(token, flag);
			ft_refacto_free(params, cmd, lst);
			continue ;
		}
		if (ft_refacto_exec(params, lst, token, cmd) < 0)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_token	token;
	t_list	*lst;
	t_node	params;
	int		flag;

	(void)av;
	flag = 0;
	if (ac == 1)
	{
		if (ft_init_env(env, &params) < 0)
			return (1);
		using_history();
		if (ft_refacto(&params, &lst, &token, flag) < 0)
			return (1);
	}
	return (0);
}
