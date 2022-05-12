/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:10:41 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/07 15:08:18by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	ft_find_len_env(char *str, t_token *token)
{
	int	i;

	i = 0;
	(void)token;
	if (!str[i])
		return (0);
	while (str[i] && (str[i] != '\'' && str[i] != ' '
			&& str[i] != '"' && str[i] != '$'))
		i++;
	return (i);
}

static char	*ft_strjoin_expand(char *token, char **env, t_token *t_token)
{
	char	*ret;
	char	*var_env;
	int		occ;
	int		len_var;

	len_var = ft_find_len_env(token, t_token);
	var_env = ft_substr(token, 0, len_var);
	if (!var_env)
		return (NULL);
	printf("%s\n", var_env);
	occ = ft_find_occurence(env, var_env);
	if (occ == -1)
		return (NULL);
	ret = ft_strdup(env[occ] + len_var + 1);
	if (!ret)
		return (NULL);
	return (ret);
}

static char	*ft_expand_1(char *token, char **env, t_token *t_token)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	while (token[i])
	{
		if (token[i] == '$')
		{
			ret = ft_strjoin_pimp(ret,
					ft_strjoin_expand(token + i + 1, env, t_token));
			i += ft_find_len_env(token + i + 1, t_token) + 1;
		}
		else
		{
			ret = ft_strjoin_char(ret, token[i]);
			i++;
		}
	}
	return (free(token), ret);
}

static void	ft_quoted_expand(t_token *token, char c)
{
	if (c == '\'')
		token->nb_quotes++;
	else if (c == '"')
		token->nb_dquotes++;
	if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 != 0)
		token->first_quotes = '\'';
	else if (token->nb_dquotes % 2 != 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = '"';
	else if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = ' ';
}

int	ft_expand_var(t_token *token, char **env)
{
	int	i;
	int	j;

	i = 0;
	while (token->token[i])
	{
		j = 0;
		while (token->token[i][j])
		{
			ft_quoted_expand(token, token->token[i][j]);
			if (token->token[i][j] == '$')
			{
				if (token->nb_dquotes == 0 && token->nb_quotes == 0)
					token->token[i] = ft_expand_1(token->token[i], env, token);
				if (token->nb_dquotes % 2 != 0 && token->first_quotes == '"')
					token->token[i] = ft_expand_1(token->token[i], env, token);
				if (!token->token[i][j])
					break ;
			}
			j++;
		}
		i++;
	}
	ft_reset_quotes(token);
	return (0);
}
