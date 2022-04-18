/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/18 12:37:26 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "struct.h"
# include "includes.h"

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/ft_split_path.c                         */
/* -------------------------------------------------------------------------- */
char	**ft_split_path(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_split.c                           */
/* -------------------------------------------------------------------------- */
char	**ft_split(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_exec.c                          */
/* -------------------------------------------------------------------------- */
int		ft_execute(char **av, char **envp);
int		ft_init_pipe(t_node *params);
int		ft_open(t_node *params, char *infile, char *outfile, int flag);
int		ft_heredoc(t_node *params);
/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_str.c                           */
/* -------------------------------------------------------------------------- */
int		ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin_pimp(char *s1, char *s2);
int		ft_strchr_pimp(char *s, char c);
char	*ft_strdup_pimp(char *s);
char	*ft_strjoin(char *s1, char *s2);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_path.c                          */
/* -------------------------------------------------------------------------- */
char	*ft_cmd(char *path, char *cmd);
int		ft_cmp_path(char *s1, char *s2);
int		get_path_pos(char **envp);
char	**get_path_lst(char **envp);
char	*check_path(char **path_lst, char *cmd);

/* -------------------------------------------------------------------------- */
/*                            FILE = srcs/pipex.c                             */
/* -------------------------------------------------------------------------- */
void	ft_error(int in, int out);
int		ft_init_pid(t_node *params);
int		ft_fill_cmd_name(t_node *params, char **av, int ac);
int		ft_child_exec(t_node *params, char **av, char **envp);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/utils_pipe.c                          */
/* -------------------------------------------------------------------------- */
void	ft_close_all(t_node *params);
int		ft_fork(t_node *params, char **envp, char *av);
void	ft_dup2(int in, int out);
int		ft_cmp_heredoc(char **av, char *heredoc, t_node *params, int ac);
void	ft_wrong_args(void);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/ft_free.c                            */
/* -------------------------------------------------------------------------- */
int		ft_tab_size(char **tab);
void	ft_free(char **tab);
void	ft_free_struct(t_node *params);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/error.c                              */
/* -------------------------------------------------------------------------- */
void	ft_putstr_fd(char *s, int fd);
void	ft_command_nt_found(char *cmd);
int		ft_strcmp(char *s1, char *s2);
void	ft_close(void);
void	ft_heredoc_infile(t_node *params);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/gnl.c                                */
/* -------------------------------------------------------------------------- */
char	*ft_next_line(char *line);
char	*get_next_line(int fd);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/join.c                               */
/* -------------------------------------------------------------------------- */
int		ft_initialisation(t_node *params, char **av, int ac, int i);
int		ft_args(int ac, char **av);
int		ft_chk_cmd(char *cmd);

/* -------------------------------------------------------------------------- */
/*                           FILE = srcs/utils_both.c                         */
/* -------------------------------------------------------------------------- */
int		ft_init_pid(t_node *params);
int		ft_norme(t_node *params, char **av, int ac, int j);
int		ft_fill_cmd_name(t_node *params, char **av, int ac);
int		ft_child_exec(t_node *params, char **av, char **envp);

#endif
