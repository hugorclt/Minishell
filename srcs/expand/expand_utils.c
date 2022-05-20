/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:03:11 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/16 16:35:47 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	ft_find_len_env(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i] && (str[i] != '\'' && str[i] != ' '
			&& str[i] != '"' && str[i] != '$'))
		i++;
	return (i);
}

char	*ft_strjoin_expand(char *token, char **env)
{
	char	*ret;
	char	*var_env;
	int		occ;
	int		len_var;

	len_var = ft_find_len_env(token);
	var_env = ft_substr(token, 0, len_var);
	if (!var_env)
		return (NULL);
	printf("%s\n", var_env);
	occ = ft_find_occurence(env, var_env);
	printf("%d\n", occ);
	if (occ == -1)
		return (free(var_env), "\0");
	ret = ft_strdup(env[occ] + len_var + 1);
	if (!ret)
		return (free(var_env), NULL);
	return (free(var_env), ret);
}

int	ft_expand_utils(char **ret, t_node *par, int *i)
{
	char	*itoa;

	itoa = ft_itoa(par->last_status);
	(*ret) = ft_strjoin_pimp((*ret), itoa);
	if (!(*ret))
		return (free(itoa), -1);
	(*i) += 2;
	return (free(itoa), 0);
}

int	ft_expand_utils_2(char **ret, char *token, int *i, t_node *p)
{
	char	*to_add;

	to_add = ft_strjoin_expand(token + (*i) + 1, p->env);
	(*ret) = ft_strjoin_pimp((*ret), to_add);
	if (!(*ret) && to_add[0] != '\0')
		return (free(to_add), -1);
	(*i) += ft_find_len_env(token + (*i) + 1) + 1;
	if (to_add[0] == '\0')
		return (0);
	else
		return (free(to_add), 0);
}