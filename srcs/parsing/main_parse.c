/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:53:42 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 11:19:24 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin_char(char *cmd, char c)
{
	int		i;
	char	*ret;

	i = 0;
	if (!cmd)
		ret = malloc(sizeof(char) * 2);
	else
	{
		ret = malloc(sizeof(char) * ft_strlen(cmd) + 2);
		while (cmd[i])
		{
			ret[i] = cmd[i];
			i++;
		}
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	return (ret);
}

int	ft_tokenization(char *input, t_cmd **cmd, t_token **var)
{
	(void)cmd;
	int		i;
	char	*token;

	i = 0;
	token = NULL;
	while (input[i])
	{
		if (input[i] == '|')
		{
			ft_lst_addback(var, ft_lstnew(token));
			token = NULL;
		}
		else if (input[i] == '>')
		{
			if (input[i + 1] == '>')
			{
				ft_lst_addback(var, ft_lstnew(token));
				ft_lst_addback(var, ft_lstnew(">>"));
				token = NULL;
			}
			else
			{
				ft_lst_addback(var, ft_lstnew(token));
				ft_lst_addback(var, ft_lstnew(">"));
				token = NULL;
			}
		}
		else if (input[i] == '<')
		{
			if (input[i + 1] == '<')
			{
				ft_lst_addback(var, ft_lstnew(token));
				ft_lst_addback(var, ft_lstnew("<<"));
				token = NULL;
			}
			else
			{
				ft_lst_addback(var, ft_lstnew(token));
				ft_lst_addback(var, ft_lstnew("<"));
				token = NULL;
			}
		}
		token = ft_strjoin_char(token, input[i]);
		i++;
	}
	return (0);
}


