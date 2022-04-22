/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:58:56 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 10:51:23 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_find_line_env(char *token, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], token, ft_strlen(token)))
		{
			return (*env[i] + ft_strlen(token) + 1);
		}
		i++;
	}
	return (NULL);
}

int	ft_find_dolls(char *token)
{
	int	i;
	int	nb_dolls;

	nb_dolls = 0;
	i = 0;
	while (token[i])
	{
		if (token[i] == "$")
			nb_dolls++;
		i++;
	}
	return (nb_dolls);
}

int	ft_len_var(char *token)
{
	int	i;

	i = 0;
	while (token[i] != " " || token[i] != "\0")
		i++;
	return (i);
}

char	*ft_env_expand(char *token, char **env)
{
	char	*env_line;
	char	*ret;
	int		i;
	int		nb_dolls;

	i = 0;
	nb_dolls = ft_find_dolls(token);
	while (token[i])
	{
		if (nb_dolls && token[i] == "$")
		{
			env_line = ft_find_line_env(token + i, env);
			ret = ft_strjoin(ret, env_line);
			nb_dolls--;
			i += ft_len_var(token + i);
		}
		ret = ft_strjoin_char(ret, token[i]);
		i++;
	}
	return (ret);
}

int	ft_main_transfo(t_token **var, t_cmd **cmd, char **env)
{
	t_token **temp;

	temp = var;
	while ((*temp)->next != NULL)
	{
		(*temp)->token = ft_env_expand((*temp)->token, env);
		temp = (*temp)->next;
	}
}
