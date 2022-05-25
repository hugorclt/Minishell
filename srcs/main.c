/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 00:41:27 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int g_last_status = 0;

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

static int	ft_refacto(t_node *params, t_list **list, t_token *token)
{
	int		flag;
	char	*cmd;
	
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
			return (1);
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
