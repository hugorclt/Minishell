/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 22:26:10 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/11 15:42:56 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_execute(char **av, char **envp)
{
	char	*path;

	path = check_path(get_path_lst(envp), av[0]);
	if (!path)
		return (ft_free(av), -1);
	if (execve(path, av, envp) == -1)
		return (ft_free(av), free(path), -1);
	return (1);
}

int	ft_init_pipe(t_node *params)
{
	int	i;

	i = 0;
	params->fd = malloc(sizeof(int) * (params->nb - 1) * 2);
	if (!params->fd)
		return (-1);
	while (i < params->nb - 1)
	{
		if (pipe(params->fd + i * 2) < 0)
			return (-1);
		++i;
	}
	return (1);
}

int	ft_open(t_node *params, char *infile, char *outfile, int flag)
{
	(void)params;
	(void)infile;
	(void)outfile;
	(void)flag;
	if (flag < 1)
	{
		//params->infile = open(infile, O_RDONLY, 0644);
		//params->infile_name = ft_strdup(infile);
	}
	else
		return (420);
	//params->outfile = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (params->outfile < 0)
		return (-1);
	//params->outfile_name = ft_strdup(outfile);
	//if (!params->infile_name || !params->outfile_name)
		//return (-1);
	return (1);
}
