/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 11:51:52 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 11:21:21 by yobougre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
