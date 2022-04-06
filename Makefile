# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:01:55 by hrecolet          #+#    #+#              #
#    Updated: 2022/04/06 14:34:24 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/main.c \
				srcs/parsing/main_parse.c \
				srcs/utils/utils_char.c \
				srcs/exec/main_exec.c\
				srcs/exec/builtin_1.c

INCL		=	includes/minishell.h

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra 

RM			=	rm -f

NAME		=	minishell

OBJ			=	$(SRCS:.c=.o)

all			:	$(NAME) 


$(NAME)		:	$(OBJ) includes/minishell.h
				@$(CC) $(CFLAGS) $(OBJ) -lreadline $(INCL) -o $(NAME)
				@echo -n "'Minishell', vu par la GoatSquad\n"	
		
clean		:	
				@$(RM) $(OBJ) $(OBJ_BONUS)

fclean		:	clean
				@$(RM) $(NAME) $(BONUS_NAME) $(OBJ_BONUS)

re			:	fclean all

.PHONY		:	clean fclean re all
