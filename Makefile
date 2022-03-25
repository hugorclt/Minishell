# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:01:55 by hrecolet          #+#    #+#              #
#    Updated: 2022/03/25 16:19:34 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	srcs/main.c \
				srcs/utils_char.c

INCL		=	includes/minishell.h

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra 

RM			=	rm -f

NAME		=	minishell

OBJ			=	$(SRCS:.c=.o)

all			:	$(NAME) 


$(NAME)		:	$(OBJ) includes/minishell.h
				$(CC) $(CFLAGS) $(OBJ) -lreadline $(INCL) -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean		:	clean
				$(RM) $(NAME) $(BONUS_NAME) $(OBJ_BONUS)

re			:	fclean all

.PHONY		:	clean fclean re all
