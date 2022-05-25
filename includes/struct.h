/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:51:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/05/25 18:06:26 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "includes.h"

typedef struct s_help
{
	int	i;
	int	j;
	int	k;
	int	p;
}	t_help;

typedef struct s_token
{
	char	**token;
	char	**env;
	int		nb_quotes;
	int		nb_dquotes;
	char	first_quotes;
	char	old_first_quotes;
}	t_token;

typedef struct s_files
{
	char	*file;
	int		flag;
	int		fd;
}	t_files;

typedef struct s_list
{
	char			**token;
	t_files			*file_in;
	t_files			*file_out;
	char			*limiter;
	int				nb_infile;
	int				nb_outfile;
	int				last_infile;
	int				last_outfile;
	int				heredoc;
	struct s_list	*next;
	int				is_builtin;
}	t_list;

typedef struct s_node
{
	int				last_status;
	int				last_infile;
	int				last_outfile;
	pid_t			*pid;
	int				nb;
	int				*fd;
 	int				index;
	int				heredoc;
	char			*limiter;
	int				fd_stdin;
	int				fd_stdout;
	char			**env;
	int				have_pid;
	char			*root;
	int				save_in;
	int				save_out;
	t_token			*quoter;
	char			**io_env;
	int				shlvl;
}	t_node;

typedef struct s_garb_col
{
	void				*content;
	int					flag;
	struct s_garb_col	*next;
}	t_garb;


#endif
