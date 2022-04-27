/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 09:58:56 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/27 15:31:59 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*ft_find_env_var(char *token)
{
	int		i;
	char	*env_var;

	i = 0;
	while (token[i] != ' ')
	{
		env_var = ft_strjoin_char(env_var, token[i]);
		if (!env_var)
			return (NULL);
		i++;
	}
	return (env_var);
}

static char	*ft_replace(char **env, char *token)
{
	char	*env_var;
	int		i;
	int		occ;
	char	*ret;
	int		j;

	i = 0;
	env_var = ft_find_env_var(token);
	if (!env_var)
		return (NULL);
	occ = ft_find_occurence(env, env_var);
	if (occ == -1)
		return (NULL);
	ret = malloc(sizeof(char) * ft_strlen(env[occ]) - ft_strlen(env_var));
	if (!ret)
		return (NULL);
	while (env[occ][i] && env[occ][i] != '=')
		i++;
	i++;
	j = 0;
	while (env[occ][i])
		ret[j++] = env[occ][i++];
	ret[j] = '\0';
	return (ret);
}

static char	*ft_expand_one(char *token, char **env)
{
	int		i;
	char	*ret;
	int		j;
	int		last_j;

	i = 0;
	j = 0;
	ret = malloc(sizeof(char) * ft_strlen(token) + 1);
	while (token[j])
	{
		if (token[j] == '$')
		{
			ret = ft_strjoin(ret, ft_replace(env, token + j + 1));
			if (!ret)
				return (NULL);
			last_j = j;
			j += ft_strlen(ft_find_env_var(token + j + 1));
			if (j == last_j)
				return (NULL);
		}
		ret[i] = token[j];
		i++;
		j++;
	}
	ret[i] = '\0';
	return (ret);
}

static void	ft_count_quotes(t_token *token, char c)
{
	if (c == '\'')
		token->nb_quotes++;
	else if (c == '"')
		token->nb_dquotes++;
	if (token->nb_quotes % 2 == 0 && token->nb_dquotes % 2 != 0)
		token->first_quotes = '"';
	else if (token->nb_quotes % 2 != 0 && token->nb_dquotes % 2 == 0)
		token->first_quotes = '\'';
}

int	ft_expand_var(t_token *token, char **env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < ft_tab_size(token->token))
	{
		j = -1;
		while (++j < ft_strlen(token->token[i]))
		{
			ft_count_quotes(token, token->token[i][j]);
			if (token->token[i][j] == '$')
			{
				if (token->nb_quotes % 2 != 0 && token->nb_dquotes % 2 != 0)
				{
					if (token->first_quotes == '\"')
						token->token[i] = ft_expand_one(token->token[i], env);
				}
				else if (token->nb_dquotes % 2 != 0)
					token->token[i] = ft_expand_one(token->token[i], env);
				if (!token->token[i])
					return (-1);
			}
		}
	}
	return (0);
}