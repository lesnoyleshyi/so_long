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

HEADER	=	so_long.h

MLX_LIB	=	libmlx.dylib

SRCS	=	so_long.c	ft_read_map_funcs.c	ft_check_file_extension_funcs.c \
			ft_move_funcs.c	ft_sprite_funcs.c ft_check_map_content_funcs.c \
			ft_print_on_screen_funcs.c	ft_react_to_keys_funcs.c

B_SRCS	=	${SRCS:.c=_bonus.c}

OBJS	=	${SRCS:.c=.o}

B_OBJS	=	${B_SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

%.o			:	%.c	${HEADER}
				${CC} ${CFLAGS} $< -I./mlx/mlx_mms -c -o $@

.PHONY		:	all re clean fclean debug debug_bonus ch_leak run

${NAME}		:	${OBJS} ${MLX_LIB}
				${CC} ${CFLAGS} -L./libft -lmlx -lft -framework OpenGL \
				-framework AppKit ${OBJS} -o ${NAME}

bonus		:	${B_OBJS} ${MLX_LIB}
				${CC} ${CFLAGS} -L./libft -lmlx -lft -framework OpenGL \
				-framework AppKit ${B_OBJS} -o bonus

${MLX_LIB}	:
				${MAKE} -C ./mlx/mlx_mms/
				cp ./mlx/mlx_mms/libmlx.dylib ./

clean		:
				rm -rf ${OBJS} ${B_OBJS}

fclean		:	clean
				rm -rf ${NAME} ${B_NAME}

debug		:
				${CC} ${CFLAGS} -g ${SRCS} -L./libft -lmlx -lft \
 				-framework OpenGL -framework AppKit -o ${NAME}_debug

debug_bonus	:
				${CC} ${CFLAGS} -g ${B_SRCS} -L./libft -lmlx -lft \
				-framework OpenGL -framework AppKit -o ${B_NAME}_debug

all			:	${NAME} bonus

re			:	fclean ${NAME}

run			:	${NAME}
				./${NAME} ./maps/map1.ber

ch_leak		:	${NAME}
				leaks -atExit -- ./${NAME} ./maps/map1.ber
