# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stycho <stycho@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 14:40:48 by stycho            #+#    #+#              #
#    Updated: 2021/11/23 14:40:49 by stycho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	so_long

SRCS	=	so_long.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

%.o		:	%.c
			${CC} ${CFLAGS} $< -I./mlx/mlx_mms -c -o $@

.PHONY	:	all re clean fclean

${NAME}	:	${OBJS}
			cp ./mlx/mlx_mms/libmlx.dylib ./
			${CC} ${CFLAGS} -L./libft -lmlx -lft -framework OpenGL \
			-framework AppKit ${OBJS} -o ${NAME}

clean	:
			rm -rf ${OBJS}

fclean	:	clean
			rm -rf ${NAME}