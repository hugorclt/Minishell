/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:19:51 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/19 14:25:39 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_reset_quotes(t_token *token)
{
	token->nb_dquotes = 0;
	token->nb_quotes = 0;
	token->old_first_quotes = 0;
}

void	ft_pass_space_reverse(char *cmd, int *new_j)
{
	if (cmd[(*new_j) - 1] && cmd[(*new_j) - 1] == ' ')
	{
		(*new_j)--;
		if (cmd[*new_j] && cmd[*new_j] == ' ')
		{
			while (cmd[*new_j] == ' ')
				(*new_j)--;
			(*new_j)++;
		}
	}
}

char	*ft_to_str_without_free(char **str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (ft_tab_size(str) == 1)
		ret = ft_strdup(str[0]);
	else
	{
		while (str[i])
		{
			ret = ft_strjoin_pimp(ret, str[i]);
			if (!ret)
				return (NULL);
			if (i < ft_tab_size(str) - 1)
				ret = ft_strjoin_pimp(ret, " ");
			if (!ret)
				return (NULL);
			i++;
		}
	}
	return (ret);
}

char	*ft_to_str(char **str)
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (ft_tab_size(str) == 1)
		ret = ft_strdup(str[0]);
	else
	{
		while (str[i])
		{
			ret = ft_strjoin_pimp(ret, str[i]);
			if (!ret)
				return (NULL);
			if (i < ft_tab_size(str) - 1)
				ret = ft_strjoin_pimp(ret, " ");
			if (!ret)
				return (NULL);
			i++;
		}
	}
	return (ft_free(str), ret);
}

void	ft_increm(int *i, int *j)
{
	(*i)++;
	(*j)++;
}

int		ft_close_redirect(t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = (*lst);
	while (tmp)
	{
		if (tmp->nb_infile > 0)
		{
			if (close(tmp->file_in[i].fd) == -1)
				return (-1);
			if (tmp->file_in[i].flag == 1)
				unlink(tmp->file_in[i].file);
			i++;
		}
		i = 0;
		if (tmp->nb_outfile > 0)
		{
			if (close(tmp->file_out[i++].fd) == -1)
				return (-1);	
		}
		tmp = tmp->next;
	}
	return (0);
}

void	ft_quoted(t_token *token, char c)
{
	if (c == '\'')
		token->nb_quotes++;
	else if (c == '"')
		token->nb_dquotes++;
	if (token->nb_dquotes % 2 == 0 && token->nb_quotes % 2 != 0)
		token->first_quotes = '\'';
	else if (token->nb_dquotes % 2 != 0 && token->nb_quotes % 2 == 0)
		token->first_quotes = '"';
}
