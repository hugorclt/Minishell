# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrecolet <hrecolet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/01 13:32:09 by yobougre          #+#    #+#              #
#    Updated: 2022/04/18 12:35:01 by hrecolet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS=	srcs/pipex_bonus.c\
			srcs/utils_str.c\
			srcs/utils_both.c\
			srcs/utils_path.c\
			srcs/ft_free.c\
			srcs/ft_split_path.c\
			srcs/ft_split.c\
			srcs/utils_pipe.c\
			srcs/utils_exec.c\
			srcs/error.c\
			srcs/gnl.c\
			srcs/join.c

INCL=	includes/pipex.h\
		includes/includes.h\
		includes/struct.h

NAME=	pipex.a

CFLAGS= -Wall -Werror -Wextra

CC=	gcc

OBJS=	$(SRCS:.c=.o)

RM=	rm -f

all:	$(NAME)

$(NAME): $(OBJS) $(INCL)
			@ar -rcs ${NAME} ${OBJS}

clean:	
		@$(RM) $(OBJS)
fclean: 
		@$(RM) $(OBJS) $(NAME)

re:	fclean all

.PHONY: fclean clean re all bonus
