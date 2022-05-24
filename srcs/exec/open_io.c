/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_io.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 17:58:22 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 00:26:05 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_file_of_var(char *file, t_node *params)
{
	int	i;

	i = 0;
	while (params->io_env[i])
	{
		printf("%s, %s\n", file, params->io_env[i]);
		printf("%d %d\n", ft_strcmp(file, params->io_env[i]), is_sentences(params->io_env[i]));
		if (ft_strcmp(file, params->io_env[i]) == 0
			&& is_sentences(params->io_env[i]))
			return (1);
		i++;
	}
	return (0);
}

void	error_ambiguous(char *file)
{
	g_last_status = 1;
	ft_putstr_fd("bash: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ambiguous redirect\n", 2);
}

static int	ft_open_output(t_list **lst)
{
	int	i;

	i = 0;
	while (i < (*lst)->nb_outfile)
	{
		if ((*lst)->file_out[i].file)
		{
			if ((*lst)->file_out[i].flag == 0)
				(*lst)->file_out[i].fd = open((*lst)->file_out[i].file,
						O_CREAT | O_TRUNC | O_WRONLY, 0644);
			else if ((*lst)->file_out[i].flag == 1)
				(*lst)->file_out[i].fd = open((*lst)->file_out[i].file,
						O_CREAT | O_WRONLY | O_APPEND, 0644);
			if ((*lst)->file_out[i].fd == -1)
				ft_print_io_error_choice((*lst)->file_in[i].file);
		}
		i++;
	}
	if (i == 0)
		(*lst)->last_outfile = 1;
	else
		(*lst)->last_outfile = (*lst)->file_out[i - 1].fd;
	return (0);
}

static int	ft_open_input(t_list **lst, t_node *params)
{
	int	i;

	i = 0;
	while (i < (*lst)->nb_infile)
	{
		if ((*lst)->file_in[i].file)
		{
			if ((*lst)->file_in[i].flag == 0)
				(*lst)->file_in[i].fd = open((*lst)->file_in[i].file,
						O_RDONLY, 0644);
			else if ((*lst)->file_in[i].flag == 1)
			{
				(*lst)->limiter = ft_strdup((*lst)->file_in[i].file);
				if (!(*lst)->limiter)
					return (-1);
				ft_heredoc(lst, &i, params);
			}
			if ((*lst)->file_in[i].fd == -1)
				ft_print_io_error_choice((*lst)->file_in[i].file);
		}
		i++;
	}
	if (i == 0)
		(*lst)->last_infile = 0;
	else
		(*lst)->last_infile = (*lst)->file_in[i - 1].fd;
	return (0);
}

int	ft_open_io(t_list **lst, t_node *params)
{
	if (ft_open_input(lst, params) == -1)
		return (-1);
	if (ft_open_output(lst) == -1)
		return (-1);
	return (0);
}
