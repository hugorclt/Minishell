/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:51:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 13:30:18 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "includes.h"

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
	struct s_cmd	*next;
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
	struct s_token *next;
}	t_token;

#endif
