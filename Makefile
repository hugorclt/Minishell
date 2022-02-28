# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/28 11:01:55 by hrecolet          #+#    #+#              #
#    Updated: 2022/02/28 11:02:52 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	

INCL		=	includes/minishell.h

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

NAME		=	minishell

OBJ			=	$(SRCS:.c=.o)

all			:	$(NAME) 


$(NAME)		:	$(OBJ) includes/minishell.h 
				$(CC) $(CFLAGS) $(OBJ) $(INCL) -pthread -o $(NAME) 
		
clean		:	
				$(RM) $(OBJ) $(OBJ_BONUS)

fclean		:	clean
				$(RM) $(NAME) $(BONUS_NAME) $(OBJ_BONUS)

re			:	fclean all

.PHONY		:	clean fclean re all
