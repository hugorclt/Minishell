/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:52:24 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/20 16:41:44 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include "struct.h"
# include "includes.h"

int	ft_strlen_exp(char *s);
int	ft_strcmp_exp(char *s1, char *s2);
void	ft_exit(t_node *params, t_list **start, int value);
char	*ft_to_str_without_free(char **str);
int ft_change_var(char **env, char *var, int j);
int	ft_find_occ(char **env, char *var);
int	ft_is_in(char **var_lst, char *var);
char	*ft_unquote(char *var);
int	ft_total_unquote(t_list **lst);
void	ft_print_env(t_node *params, char **env);
char	*ft_backslash(char *token);
int	ft_theres_backslash(char *token);
int	ft_check_equal(char *token);
char	**ft_unset(t_node *params, char **env, char **var);
int	ft_need_cat(char *var);
int	ft_size_s2(char *var);
char	*ft_dup_addon(char *var);
int ft_cat_var(char **env, char *var, int j);
int	ft_theres_dquotes(char *token);
void	ft_quoted_expand(t_token *token, char c);
char	*ft_quote(char *token);
void	ft_increm(int *i, int *j);
int	ft_find_occurence(char **env, char *cmd);
int	ft_export(t_node *params, char *token);
int	ft_find_index(char **export, int size);
void	ft_exit_choice(t_node *params, t_list **lst, char *cmd);
int	ft_parse_tokens(t_token *token, char *cmd, int flag);
int	ft_init_io(t_list **lst, t_node *params);
void	ft_count_in(char **token, t_list **lst);
void	ft_count_out(char **token, t_list **lst);
char	**ft_cut_io(t_list **tmp);
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
int		print_pwd(t_node *params);
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
int		ft_heredoc_infile(t_list **lst, int *i);

/* -------------------------------------------------------------------------- */
/*                       FILE = srcs/pipes/utils_exec.c                       */
/* -------------------------------------------------------------------------- */
int	ft_execute(t_node *params, char **av, char **envp, t_list **lst);
char		*get_next_line(int fd);
int	ft_prepare_cmd(t_list **lst);
int	ft_execute_one_fork_builtin(t_node *params, t_list **lst);
int	ft_execute_one_builtin(t_node *params, t_list **lst);
int	ft_execute_one_binaries(t_node *params, t_list **lst);
int	ft_exec_one(t_node *params, t_list **lst);
int	ft_init_pipe(t_node *params);
int	ft_heredoc(t_list **lst, int *i);
int	ft_exec_builtin(t_node *params, char **cmd, t_list **lst);
int	ft_is_builtin(char *cmd);
int	ft_cut_space(t_list **lst);
void	ft_pass_space_reverse(char *cmd, int *new_j);
int	ft_get_input(t_list **lst, char **tab);

/* -------------------------------------------------------------------------- */
/*                        FILE = srcs/pipes/ft_free.c                         */
/* -------------------------------------------------------------------------- */
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
int	ft_child_exec(t_node *params, t_list **av);

/* -------------------------------------------------------------------------- */
/*                          FILE = srcs/pipes/join.c                          */
/* -------------------------------------------------------------------------- */
char	*ft_strjoin_pimp(char *s1, char *s2);
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
int	ft_fork(t_node *params, char **envp, t_list **lst, t_list **lst_to_free);
int		ft_close_redirect(t_list **lst);
void	ft_dup2(int in, int out);
int	ft_cmp_heredoc(char **av, char *heredoc, t_node *params, int ac);
char	**ft_split_space(char *s);
void	ft_free_after_cmd(t_node *params, t_list **start, int flag);
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
int	ft_save_file(t_list **lst);
char	*ft_unquoting(char *str);
void	ft_quoted(t_token *token, char c);
char	*ft_strcut(char *str, int i_start, int i_end);
char	**ft_clean_redirection(t_list **lst);

/* -------------------------------------------------------------------------- */
/*                     FILE = srcs/parsing/init_struct.c                      */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                      FILE = srcs/parsing/main_parse.c                      */
/* -------------------------------------------------------------------------- */
char	*ft_strjoin_char(char *cmd, char c);

void	ft_tokenization(t_list **lst, char *cmd);
int		ft_change_dir(t_node *params, char *path);
char	*ft_strjoin_char(char *cmd, char c);
void	ft_print_tab(char **tab);
void	ft_echo(t_node *params, char **cmd);
int	ft_main_exec(t_node *params, t_list **lst);
char	**ft_expand(t_token *token, t_node *params);
int	ft_find_len_env(char *str);
char	*ft_strjoin_expand(char *token, char **env);
int	ft_expand_utils(char **ret, t_node *par, int *i);
int	ft_expand_utils_2(char **ret, char *token, int *i, t_node *p);
int	ft_export_alph(char **env);

#endif
