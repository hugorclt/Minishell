/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:51:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 17:00:27 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "includes.h"

addback(t_list, lstnew((void)ft_initialize_token(str[i])))
ft_parcour_ma_putain_de_liste()
{
	if ((*tmp)->content->flag < 1)
		ft_token;
	else
		ft_cmd(tmp->content);
}
typedef struct s_node
{
	int				infile;
	char			*infile_name;
	char			*outfile_name;
	int				outfile;
	pid_t			*pid;
	int				nb;
	int				*fd;
	char			**cmd;
	char			**cmd_args;
	int				index;
	int				heredoc;
	char			*limiter;
}	t_node;

typedef struct s_garb_col
{
	void				*content;
	struct s_garb_col	*next;
}	t_garb;

typedef struct s_cmd
{
	char			*cmd;
	char			**path;
	char			**option;
	char			**args;
	int				flag;
}	t_cmd;

typedef struct s_token
{
	char	*current_wdir;
	char	*token;
	char	**env;
	int		nb_quotes;
	int		nb_dquotes;
}	t_token;

#endif
