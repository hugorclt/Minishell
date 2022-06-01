/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 04:36:31 by hrecolet          #+#    #+#             */
/*   Updated: 2022/06/01 09:51:18 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	do_expandable(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			return (1);
		i++;
	}
	return (0);
}

void	ft_hd_free(char *line, char *line_after_expand)
{
	if (line)
		free(line);
	if (line_after_expand)
		free(line_after_expand);
}

int	ft_hd_write_fd(char *line, char *line_after_expand, int fd)
{
	ft_putstr_fd(line_after_expand, fd);
	ft_putstr_fd("\n", fd);
	ft_hd_free(line, line_after_expand);
	return (0);
}

char	*ft_hd_create_name(char *str, int *j)
{
	char	*nb;
	char	*ret;

	nb = ft_itoa(*j);
	if (!nb)
		return (NULL);
	ret = ft_strjoin(str, nb);
	free(nb);
	if (!ret)
		return (NULL);
	j++;
	return (ret);
}

int	ft_hd_close(t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	while (tmp)
	{
		i = 0;
		while (i < tmp->nb_infile)
		{
			if (tmp->file_in[i].flag == 1)
			{
				close(tmp->file_in[i].fd);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	ft_hd_open(t_list **lst, int *j)
{
	int		i;
	t_list	*tmp;

	tmp = (*lst);
	while (tmp)
	{
		i = 0;
		while (i < tmp->nb_infile)
		{
			if (tmp->file_in[i].flag == 1)
			{
				tmp->file_in[i].file = ft_hd_create_name(".heredoc_temp", j);
				if (!tmp->file_in[i].file)
					return (-1);
				tmp->file_in[i].fd = open(tmp->file_in[i].file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
			}
			i++;
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_hd_expand(char *limiter, char **line_ex, char *line, t_node *params)
{
	if (do_expandable(limiter) == 0)
		ft_verif_dollars(line_ex, line, params);
	else
		*line_ex = ft_strdup(line);
}

void	ft_hd_quit_fork(t_node *params, t_list **lst_to_free)
{
	ft_putstr_fd("\n", 1);
	ft_hd_close(lst_to_free);
	ft_hd_exit(params, lst_to_free, 130);
}

void	ft_hd_error(char *limiter)
{
	ft_putstr_fd("bash: warning: here-document at line ", 2);
	ft_putstr_fd("1 delimited by end-of-file (wanted `", 2);
	ft_putstr_fd(limiter, 2);
	ft_putstr_fd("')", 2);
	ft_putstr_fd("\n", 2);
}

int	ft_hd_writefile(t_list **lst, t_node *params, t_list **lst_to_free, int *i)
{
	char	*line;
	char	*line_expand;
	
	line = NULL;
	line_expand = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line && g_last_status == 6122002)
		{
			ft_hd_free(line, line_expand);
			ft_hd_quit_fork(params, lst_to_free);
		}
		if (!line)
		{
			ft_hd_error((*lst)->file_in[*i].limiter);
			break ;
		}
		ft_hd_expand((*lst)->file_in[*i].limiter, &line_expand, line, params);
		if (!line_expand)
			ft_putstr_fd("\n", 1);
		if (!ft_strcmp(line_expand, (*lst)->file_in[*i].limiter) || !line_expand)
			break ;
		ft_hd_write_fd(line, line_expand, (*lst)->file_in[*i].fd);
	}
	ft_hd_free(line, line_expand);
	return (0);
}

int	ft_hd_write_node(t_list **lst, t_node *params, t_list **lst_to_free)
{
	int	i;

	i = 0;
	while (i < (*lst)->nb_infile)
	{
		if ((*lst)->file_in[i].flag == 1)
		{
			if (ft_hd_writefile(lst, params, lst_to_free, &i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	ft_hd_write(t_list **lst, t_node *params, t_list **lst_to_free)
{
	t_list	*tmp;
	pid_t	pid;
	
	tmp = (*lst);
	pid = fork();
	if (pid == 0)
	{
		sig_choice(3);
		while (tmp)
		{
			if (ft_hd_write_node(&tmp, params, lst_to_free) == -1)
				return (ft_hd_exit(params, lst_to_free, 0), -1);
			tmp = tmp->next;
		}
		sig_choice(0);
		ft_hd_close(lst_to_free);
		ft_hd_exit(params, lst_to_free, 0);
	}
	else
		waitpid(pid, NULL, 0);
	return (0);
}

int	ft_hd_start(t_list **lst, t_node *params, t_list **lst_to_free)
{
	int	i;

	i = 0;
	if (ft_hd_open(lst, &i) == -1)
		return (-1);
	if (ft_hd_write(lst, params, lst_to_free) == -1)
		return (-1);
	if (ft_hd_close(lst) == -1)
		return (-1);
	return (0);
}
