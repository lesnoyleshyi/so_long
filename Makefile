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

SRCS	=	so_long.c	ft_read_map_funcs.c	ft_check_file_extension_funcs.c \
			ft_move_funcs.c	ft_sprite_funcs.c \
			ft_print_on_screen_funcs.c	ft_react_to_keys_funcs.c

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

debug	:
			${CC} ${CFLAGS} -g ${SRCS} -L./libft -lmlx -lft -framework OpenGL \
                                    			-framework AppKit -o ${NAME}_debug

re		:	fclean ${NAME}

run		:	${NAME}
			./${NAME} ./maps/map1.ber

ch_leak	:	${NAME}
			leaks -atExit -- ./${NAME} ./maps/map1.ber