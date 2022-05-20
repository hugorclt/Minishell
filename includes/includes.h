/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:19:23 by yobougre          #+#    #+#             */
/*   Updated: 2022/05/20 18:11:47 by yuro4ka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "struct.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# define COMMAND_NOT_FOUND ": command not found\n"
# define PROG_NAME "Minishell"
# define PERM_DENIED ": permission denied"
# define SPEC_CHAR "~`!@#$%^&*(){}[]="

#endif
