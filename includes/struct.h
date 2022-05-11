/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:51:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/11 14:08:21 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "includes.h"

/*addback(t_list, lstnew((void)ft_initialize_token(str[i])))
ft_parcour_ma_putain_de_liste()
{
	if ((*tmp)->content->flag < 1)
		ft_token;
	else
		ft_cmd(tmp->content);
}
*/

typedef struct s_token
{
	char	**token;
	char	**env;
	char	**tmp_var;
	int		nb_quotes;
	int		nb_dquotes;
	char	first_quotes;
	char	old_first_quotes;
}	t_token;

typedef struct s_files
{
	char	*file;
	int		flag;
}	t_files;

typedef struct s_list
{
	char			**token;
	char			*cmd;
	t_files			*file_in;
	t_files			*file_out;
	int				nb_infile;
	int				nb_outfile;
	int				heredoc;
	struct s_list	*next;
	int				is_builtin;
}	t_list;

typedef struct s_node
{
	int				last_infile;
	int				last_outfile;
	char			*infile_name;
	char			*outfile_name;
	int				*infile;
	int				*outfile;
	pid_t			*pid;
	int				nb;
	int				*fd;
	char			**cmd;
	char			**cmd_args;
	int				index;
	int				heredoc;
	char			*limiter;
	int				fd_stdin;
	int				fd_stdout;
	char			**env
}	t_node;

typedef struct s_garb_col
{
	void				*content;
	struct s_garb_col	*next;
}	t_garb;


#endif
