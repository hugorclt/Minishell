/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 04:55:14 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	g_last_status = 0;

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
	if (ft_main_check_quote(token->token) == -1)
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
		if (ft_refacto_start(params, lst, token) < 0)
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
			ft_refacto_help(params, lst, token, flag);
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
