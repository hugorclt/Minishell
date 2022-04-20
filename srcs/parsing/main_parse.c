/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:53:42 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/20 18:13:07 by hrecolet         ###   ########.fr       */
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

int	ft_main_parse(char *input, t_cmd **cmd, t_env *var)
{
	(void)cmd;
	(void)var;
	int		i;
	char	*token;

	i = 0;
	token = NULL;
	while (input[i])
	{
		token = ft_strjoin_char(token, input[i]);
		i++;
	}
	printf("%s\n", token);
	return (0);
}