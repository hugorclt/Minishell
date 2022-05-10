/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 16:14:06 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/10 17:47:43 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_init_io(t_list **lst, t_node *params)
{
	t_list *tmp;

	tmp = (*lst);
	tmp->nb_infile = ft_count_in(tmp->token);
	tmp->nb_outfile = ft_count_out(tmp->token);
	tmp->file_in = malloc(sizeof(t_files) * tmp->nb_infile + 1);
	tmp->file_out = malloc(sizeof(t_files) * tmp->nb_outfile + 1);
	params->outfile = malloc(sizeof(int) * tmp->nb_outfile);
	params->infile = malloc(sizeof(int) * tmp->nb_infile);
	params->last_infile = 0;
	params->last_outfile = 1;
	if (!tmp->file_in || !tmp->file_out || !tmp->file_in || !tmp->file_out
		|| !params->outfile || !params->infile)
		return (-1);
	return (0);
}

char	**ft_cut_io(t_list **tmp)
{
	t_list	*lst;
	char	**ret;
	int		i;
	int		k;

	i = 0;
	k = 0;
	lst = (*tmp);
	ret = malloc(sizeof(char *) * (ft_tab_size(lst->token) - ((lst->nb_infile + lst->nb_outfile) * 2) + 1));
	if (!ret)
		return (NULL);
	while (lst->token[i])
	{
		if (ft_strcmp(lst->token[i], ">") == 0 || ft_strcmp(lst->token[i], ">>") == 0
			|| ft_strcmp(lst->token[i], "<") == 0 || ft_strcmp(lst->token[i], "<<") == 0)
			i += 2;
		else
		{
			ret[k] = ft_strdup(lst->token[i]);
			if (!ret[k])
				return (NULL);
			i++;
			k++;
		}
	}
	ret[k] = 0;
	return (ret);
}

int	ft_open_input(t_list **lst, t_node *params, int *i)
{
	t_list *tmp;

	tmp = (*lst);
	if (tmp->file_in[*i].flag == 0)
		params->infile[*i] = open(tmp->file_in[*i].file, O_RDONLY, 0644);
	else
		params->infile[*i] = open(tmp->file_in[*i].file, O_RDONLY, 0644);
	if (params->infile[*i] == -1)
		return (-1);
	(*i)++;
	return (0);
}

int	ft_open_io(t_list **lst, t_node *params)
{
	t_list *tmp;
	int	i;

	i = 0;
	tmp = (*lst);
	while (i < tmp->nb_infile)
		ft_open_input(&tmp, params, &i);
	if (tmp->nb_infile >= 1)
		params->last_infile = params->infile[i - 1];
	i = 0;
	while (i < tmp->nb_outfile)
	{
		if (tmp->file_out[i].flag == 0)
		{
			params->outfile[i] = open(tmp->file_out[i].file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else
			params->outfile[i] = open(tmp->file_out[i].file,  O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (params->outfile[i] == -1)
			return (-1);
		i++;
	}
	if (tmp->nb_outfile >= 1)
		params->last_outfile = params->outfile[i - 1];
	return (0);
}

int	ft_dup_io(t_node *params)
{
	if (params->last_infile != 0)
	{
		if (dup2(params->last_infile, 0) == -1)
			return (-1);
	}
	if (params->last_outfile != 1)
	{
		if (dup2(params->last_outfile, 1) == -1)
			return (-1);
	}
	return (0);
}