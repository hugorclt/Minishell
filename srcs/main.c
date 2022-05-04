/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:29:14 by hrecolet          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/03 15:41:53 by yobougre         ###   ########.fr       */
=======
/*   Updated: 2022/05/04 16:35:26 by yuro4ka          ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
void	ft_print_lst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%s\n", tmp->content->token);
		tmp = tmp->next;
	}
}

void	ft_sign_handle(int signo)
{
	if (signo == SIGINT)
	{
		rl_on_new_line();
		rl_replace_line("\n", 1);
		rl_clear_history();
	}
	else if (signo == SIGQUIT)
		return ;
}*/

void	ft_print_tab(char **tokens)
{
	int	i;

	i = 0;
	if (!*tokens)
		return ;
	while (tokens[i])
		printf("%s\n", tokens[i++]);
}

static int	ft_export_alph(char **env)
{
	int		i;
	int		j;
	int		min;

	i = 0;
	while (env[i])
	{
		j = i;
		while (env[j])
		{
			if (ft_strncmp(env[i], env[j], ft_strlen(env[j]) < 0))
				min = j;
			j++;
		}
		i++;
		printf("export %s\n", env[min]);
	}
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*cmd;
	t_list	*lst;
	t_token token;
	(void)av;
//	(void)env;

	lst = malloc(sizeof(t_list));
	lst = NULL;
	(void)lst;
	token.token = NULL;
	if (ac == 1)
	{
		using_history();
		while (1)
		{
			//signal(SIGINT, ft_sign_handle);
			cmd = readline(ft_get_last_dir(get_pwd()));
			if (!cmd)
				return (0);
<<<<<<< HEAD
			//printf("total token : %d\n", ft_total_token(cmd));
			ft_export_alph(env);
			printf("voila\n");
			if (ft_parse_tokens(&token, cmd) == -1)
				continue ;
			if (ft_check_token(&token) == -1)
			{
				ft_free(token.token);
				continue ;
			}
			token.nb_dquotes = 0;
			token.nb_quotes = 0;
			ft_expand_var(&token, env);
=======
			printf("total token : %d\n", ft_total_token(cmd));
			ft_parse_tokens(&token, cmd);
			//ft_reset_quotes(&token);
			//ft_expand_var(&token, env);
			//ft_reset_quotes(&token);
			//ft_reset_quotes(&token);
			//token.token = ft_split_space(&token, token.token[0], ' ');
			ft_print_tab(token.token);
>>>>>>> master
			add_history(cmd);
		}
	}
	return (0);
}
