/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/11 14:05:48 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "struct.h"
# include "includes.h"

void	ft_increm(int *i, int *j);
int	ft_find_occurence(char **env, char *cmd);
int	ft_export(t_token **t_token, char *token);
int	ft_find_index(char **export, int size);
int	ft_parse_tokens(t_token *token, char *cmd);
int	ft_init_io(t_list **lst, t_node *params);
int	ft_count_in(char **cmd);
int	ft_count_out(char **cmd);
char	**ft_cut_io(t_list **tmp);
int	ft_open_input(t_list **lst, t_node *params, int *i);
int	ft_open_io(t_list **lst, t_node *params);
int	ft_dup_io(t_node *params);
int	ft_isspace(char c);
int	is_operator(char c);
int	ft_total_token(char *cmd);
int  ft_is_quote(char c);
int	ft_strcmp(char *s1, char *s2);
int	ft_wait_all_pid(t_node *params);
void	ft_print_error(char *token);
int	ft_is_operator(char *token);
int	ft_check_token(t_token *token);
void	ft_print_ofpc(void);
int	ft_check_quote(char *token);
int	ft_export_alph(char **env);
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
void	ft_close(void);
void	ft_heredoc_infile(t_node *params);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_exec.c                       */
/* -------------------------------------------------------------------------- */
int	ft_execute(char **av, char **envp);
int	ft_init_pipe(t_node *params);
int	ft_open(t_node *params, char *infile, char *outfile, int flag);
int	ft_heredoc(t_node *params);
int	ft_cut_space(t_list **lst);
void	ft_pass_space_reverse(char *cmd, int *new_j);
int	ft_get_input(t_list **lst, char **tab);

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
int	ft_child_exec(t_node *params, t_list **av, char **envp);

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
int	ft_fork(t_node *params, char **envp, t_list **lst);
void	ft_dup2(int in, int out);
int	ft_cmp_heredoc(char **av, char *heredoc, t_node *params, int ac);
char	**ft_split_space(char *s);
int	ft_close_total(t_node *params, t_list **lst);
void	ft_wrong_args(void);
void	ft_reset_quotes(t_token *token);
t_list	*init_lst(t_token *token);
char	*ft_to_str(char **str);
int		ft_builtin_exec(t_list *lst, char **env);

/* -------------------------------------------------------------------------- */
/*                      FILE = srcs/expand/env_expand.c                       */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             FILE = srcs/main.c                             */
/* -------------------------------------------------------------------------- */
int	main(int ac, char **av, char **env);
char	*ft_unquoting(t_token *token, char *str);
void	ft_quoted(t_token *token, char c);
char	*ft_strcut(char *str, int i_start, int i_end);

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
int	ft_find_occurence(char **env, char *cmd);
void	ft_echo(char **cmd);
int	ft_main_exec(t_list **lst, char **env, t_node *params);
int	ft_expand_var(t_token *token, char **env);
int	ft_export_alph(char **env);

#endif
