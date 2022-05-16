/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 11:03:11 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/16 11:04:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes.h"

int	ft_find_len_env(char *str, t_token *token)
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

char	*ft_strjoin_expand(char *token, char **env, t_token *t_token)
{
	char	*ret;
	char	*var_env;
	int		occ;
	int		len_var;

	len_var = ft_find_len_env(token, t_token);
	var_env = ft_substr(token, 0, len_var);
	if (!var_env)
		return (NULL);
	occ = ft_find_occurence(env, var_env);
	if (occ == -1)
		return (NULL);
	ret = ft_strdup(env[occ] + len_var + 1);
	if (!ret)
		return (NULL);
	return (ret);
}