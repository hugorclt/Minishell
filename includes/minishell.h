/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 11:03:02 by hrecolet          #+#    #+#             */
/*   Updated: 2022/04/18 14:04:09 by hrecolet         ###   ########.fr       */
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

/*	***********************************************	*/
/*	function in utils_char.c						*/
/*													*/
/*	***********************************************	*/

int		ft_strlen(char *str);
void	ft_putstr(char *str);
void	ft_print_char_tab(char **str);
char	*get_pwd();

/*	***********************************************	*/
/*	function in ft_malloc.c							*/
/*													*/
/*	***********************************************	*/




void	ft_echo(char *str);
void	ft_echo_n(char *str);
void	init_pwd(t_env *var);
void	init_env(t_env *var, char **env);
char	*get_last_dir(char *str);

#endif
