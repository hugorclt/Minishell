/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:00:57 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/07 15:23:46 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	**ft_add_var(char *var, char **env)
{
	char **output;
	int	i;

	size = ft_tab_size(env);
	output = malloc(sizeof(char *) * (size + 2));
	if (!output || !var)
		return (NULL);
	i = 0;
	while (env[i])
	{
		output[i] = ft_strdup(env[i]);
		if (!output[i])
			return (ft_free(output), NULL);
		i++;
	}	
	output[i] = ft_strdup(var);
	if (!output[i])
		return (ft_free(output), NULL);
	output[i + 1] = NULL;
	return (ft_free(env), output);
}

int	ft_find_occ(char **env, char *var)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strnstr(env[i], var, ft_strlen(env[i])))
			return (i);
		++i;
	}
	return (-1);
}

char	**ft_change_var(char **env, char *var, int j)
{
	char **output;
	int	i;
	int	p;

	output = malloc(sizeof(char *) * (ft_tab_size(env) + 1));
	if (!output)
		return (NULL);
	i = 0;
	p = 0;
	while (env[i])
	{
		if (i == j)
		{
			output[i] = ft_strdup(var);
			if (!output[i])
				return (ft_free(output), NULL);
			++i;
		}
		output[i] = ft_strdup(env[p++]);
		if (!output[i])
			return (ft_free(output), NULL);
		i++;
	}
	output[i] = NULL;
	return (ft_free(env), output);
}

static int	ft_check_equal(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '=')
			return (1);
		++i;
	}
	return (0);
}

static int	ft_theres_dquotes(char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (token[i] == '"')
			return (1);
		++i;
	}
	return (0);
}

char	*ft_quote(char *token)
{
	int		i;
	int		j;
	char	*output

	i = 0;
	j = 0;
	if (!ft_check_equal(token) || ft_theres_dquotes(token))
		return (token);
	output = malloc(sizeof(char) * (ft_strlen(token) + 3));
	if (!output)
		return (NULL);
	while (token[i] != '=' && token[i])
		output[j++] = token[i++];
	output[j] = '"';
	++j;
	if (token[i])
	{
		while (token[i])
			output[j++] = token[i++];
	}
	output[j] = '"';
	output[j + 1] = 0;
	return (output);
}

int	ft_export(t_token *t_token, char *token)
{
	char	**tmp;
	int		i;

	i = 1;
	tmp = ft_split_space(token);
	if (!tmp || !token)
		return (-1);
	if (ft_tab_size(tmp) < 2 && !ft_strcmp("export", tmp[0]))
		return (ft_export_alph(t_token->env));
	else
	{
		while (tmp[i])
		{
			if (ft_find_occ(tmp[i], t_token->env) == -1)
				t_token->env = ft_add_var(ft_quote(tmp[i]), t_token->env);
			else
				t_token->env = ft_change_var(t_token->env, tmp[i], 
					ft_find_occ(tmp[i], t_token->env));
			if (!t_token->env)
				return (ft_free_tab(tmp), -1);
			++i;
		}
	}
	return (ft_free_tab(tmp), 0);
}
