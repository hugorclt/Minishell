/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:03:02 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/22 10:42:04 by hrecolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
#define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"
# include "../libft/libft.h"

/*	***********************************************	*/
/*	function in utils_char.c						*/
/*													*/
/*	***********************************************	*/

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_print_char_tab(char **str);
char	*ft_get_pwd();

/*	***********************************************	*/
/*	function in ft_malloc.c							*/
/*													*/
/*	***********************************************	*/




void	ft_echo(char *str);
void	ft_echo_n(char *str);
void	ft_init_pwd(t_token *var);
void	ft_init_env(t_token *var, char **env);
char	*ft_get_last_dir(char *str);
int		ft_tokenization(char *input, t_cmd **cmd, t_token **var);
int		ft_main_transfo(t_token **var, t_cmd **cmd, char **env);
char	*ft_env_expand(char *token, char **env);
char	*ft_strjoin_char(char *cmd, char c);

#endif
