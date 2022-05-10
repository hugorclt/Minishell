/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuro4ka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:00:57 by yuro4ka           #+#    #+#             */
/*   Updated: 2022/05/10 18:51:38 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_equal(char *token)
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

char	*ft_unquote(char *var)
{
	char	*output;
	int		i;
	int		j;

	i = 0;
	j = 0;
	output = malloc(sizeof(char) * (ft_strlen(var)));
	if (!output)
		return (NULL);
	while (var[i])
	{
		if (var[i] == '"' )
		{
			if (!var[i + 1])
				break ;
			++i;
		}
		if (var[i] == '\'')
			++i;
		output[j++] = var[i++];
	}
	output[j] = 0;
	return (output);
}

char	**ft_add_var(char *var, char **env)
{
	char	**output;
	int		i;
	int		size;

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
	output[i] = ft_unquote(var);
	if (!output[i])
		return (ft_free(output), NULL);
	output[i + 1] = NULL;
	return (ft_free(env), output);
}

int	ft_find_occ(char **env, char *var)
{
	char	**tmp;

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
			return (ft_find_occurence(env, tmp[0]));
	}
	else
	{
		if (ft_find_occurence(env, var) != -1)
			return (ft_find_occurence(env, var));
	}
	return (ft_free(tmp), -1);
}

int ft_change_var(char **env, char *var, int j)
{
	int	i;

	i = 0;
	if (ft_need_cat(var))
		return (ft_cat_var(env, var, j));
	while (env[i])
	{
		if (i == j)
		{
			free(env[i]);
			env[i] = ft_strdup(var);
			if (!env[i])
				return (ft_free(env), -1);
		}
		i++;
	}
	return (0);
}

int	ft_theres_dquotes(char *token)
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

int	ft_theres_backslash(char *token)
{
	int	i;

	i = 0;
	while (token[i] && token[i] != '=')
		++i;
	++i;
	if (token[i])
	{
		while (token[i])
		{
			if (token[i] == '$')
				return (1);
			++i;
		}
	}
	return (0);
}

char	*ft_backslash(char *token)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	output = malloc(sizeof(char) * (ft_strlen(token) + 2));
	if (!output)
		return (NULL);
	j = 0;
	while (token[i])
	{
		if (token[i + 1] == '$')
		{
			output[j] = '\\';
			++j;
		}
		output[j++] = token[i++];
	}
	output[j] = 0;
	return (free(token), output);
}

char	*ft_quote(char *token)
{
	int		i;
	int		j;
	char	*output;

	i = 0;
	j = 0;
	if (!ft_check_equal(token) || ft_theres_dquotes(token))
		return (token);
	output = malloc(sizeof(char) * (ft_strlen(token) + 3));
	if (!output)
		return (NULL);
	while (token[i] != '=' && token[i])
		output[j++] = token[i++];
	output[j] = token[i];
	ft_increm(&i, &j);
	output[j] = '"';
	++j;
	if (token[i])
	{
		while (token[i])
			output[j++] = token[i++];
	}
	output[j] = '"';
	output[j + 1] = 0;
	return (free(token), output);
}

int	ft_export(t_token **t_token, char *token)
{
	char	**tmp;
	int		i;

	i = 1;
	tmp = ft_split_space(token);
	if (!tmp || !token)
		return (-1);
	if (ft_tab_size(tmp) < 2 && !ft_strcmp("export", tmp[0]))
		return (ft_export_alph((*t_token)->env));
	else
	{
		while (tmp[i])
		{
			if (ft_find_occ((*t_token)->env, tmp[i]) == -1)
				(*t_token)->env = ft_add_var(tmp[i], (*t_token)->env);
			else
				ft_change_var((*t_token)->env, tmp[i], 
						ft_find_occ((*t_token)->env, tmp[i]));
			if (!(*t_token)->env)
				return (ft_free(tmp), -1);
			++i;
		}
	}
	return (ft_free(tmp), 0);
}
