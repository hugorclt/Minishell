/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2022/04/26 15:55:46 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# include "../libft/libft.h"
# include "struct.h"
# include "includes.h"

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/utils/utils.c                          */
/* -------------------------------------------------------------------------- */
char	**ft_dup_tab(char **tab);
int		print_pwd();
char	*get_pwd();

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/dir/dir_prompt.c                        */
/* -------------------------------------------------------------------------- */
char	*ft_get_last_dir(char *str);

/* -------------------------------------------------------------------------- */
/*                     FILE = srcs/pipes/ft_split_path.c                      */
/* -------------------------------------------------------------------------- */
char	**ft_split_path(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                         FILE = srcs/pipes/error.c                          */
/* -------------------------------------------------------------------------- */
void	ft_command_nt_found(char *cmd);
void	ft_putstr_fd(char *s, int fd);
int	ft_strcmp(char *s1, char *s2);
void	ft_close(void);
void	ft_heredoc_infile(t_node *params);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_exec.c                       */
/* -------------------------------------------------------------------------- */
int	ft_execute(char **av, char **envp);
int	ft_init_pipe(t_node *params);
int	ft_open(t_node *params, char *infile, char *outfile, int flag);
int	ft_heredoc(t_node *params);

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/pipes/ft_free.c                         */
/* -------------------------------------------------------------------------- */
void	ft_free_struct(t_node *params);
int	ft_tab_size(char **tab);
void	ft_free(char **tab);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_path.c                       */
/* -------------------------------------------------------------------------- */
char	*ft_cmd(char *path, char *cmd);
int	ft_cmp_path(char *s1, char *s2);
int	get_path_pos(char **envp);
char	**get_path_lst(char **envp);
char	*check_path(char **path_lst, char *cmd);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_both.c                       */
/* -------------------------------------------------------------------------- */
int	ft_init_pid(t_node *params);
int	ft_norme(t_node *params, char **av, int ac, int j);
int	ft_fill_cmd_name(t_node *params, char **av, int ac);
int	ft_child_exec(t_node *params, char **av, char **envp);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/pipes/join.c                          */
/* -------------------------------------------------------------------------- */
char	*ft_strjoin_pimp(char *s1, char *s2);
int	ft_initialisation(t_node *params, char **av, int ac, int i);
int	ft_args(int ac, char **av);
int	ft_chk_cmd(char *cmd);

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/pipes/ft_split.c                        */
/* -------------------------------------------------------------------------- */
char	**ft_split(char const *s, char c);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_str.c                        */
/* -------------------------------------------------------------------------- */
int	ft_strlen(const char *s);
char	*ft_strdup_pimp(char *s);
int	ft_strchr_pimp(char *s, char c);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_pipe.c                       */
/* -------------------------------------------------------------------------- */
void	ft_close_all(t_node *params);
int	ft_fork(t_node *params, char **envp, char *av);
void	ft_dup2(int in, int out);
int	ft_cmp_heredoc(char **av, char *heredoc, t_node *params, int ac);
void	ft_wrong_args(void);

/* -------------------------------------------------------------------------- */
/*                      FILE = srcs/expand/env_expand.c                       */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/main.c                             */
/* -------------------------------------------------------------------------- */
int	main(int ac, char **av, char **env);

/* -------------------------------------------------------------------------- */
/*                     FILE = srcs/parsing/init_struct.c                      */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                      FILE = srcs/parsing/main_parse.c                      */
/* -------------------------------------------------------------------------- */
char	*ft_strjoin_char(char *cmd, char c);

void	ft_tokenization(t_list **lst, char *cmd);
void	ft_change_dir(char *path);
char	*ft_strjoin_char(char *cmd, char c);
void	ft_print_tab(char **tab);

#endif
