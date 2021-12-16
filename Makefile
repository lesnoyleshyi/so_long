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

MLX_LIB	=	./mlx/mlx_mms/libmlx.dylib

LIBFT	=	./libft/libft.a

SRCS	=	so_long.c	ft_read_map_funcs.c	ft_check_file_extension_funcs.c \
			ft_move_funcs.c	ft_sprite_funcs.c ft_check_map_content_funcs.c \
			ft_print_on_screen_funcs.c	ft_react_to_keys_funcs.c

B_SRCS	=	${SRCS:.c=_bonus.c} ft_move_enemies_funcs_bonus.c \
								ft_create_enemy_funcs_bonus.c

OBJS	=	${SRCS:.c=.o}

B_OBJS	=	${B_SRCS:.c=.o}

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

%.o			:	%.c	${HEADER}
				${CC} ${CFLAGS} $< -I./mlx/mlx_mms -c -o $@

%_bonus.o	:	%_bonus.c	${HEADER}
				${CC} ${CFLAGS} $< -I./mlx/mlx_mms -c -o $@

.PHONY		:	all re clean fclean debug debug_bonus ch_leak run libft

${NAME}		:	${OBJS} ${MLX_LIB} ${LIBFT}
				${CC} ${CFLAGS} ${OBJS} -L./libft -lmlx -lft \
 				-framework OpenGL -framework AppKit -o ${NAME}

bonus		:	${B_OBJS} ${MLX_LIB} ${LIBFT}
				${CC} ${CFLAGS} ${B_OBJS} -L./libft -lmlx -lft \
				-framework OpenGL -framework AppKit -o bonus

${MLX_LIB}	:	libmlx ;

libmlx		:
				${MAKE} -C ./mlx/mlx_mms/ libmlx.dylib

${LIBFT}	:	libft ;

libft		:
				${MAKE} -C ./libft

clean		:
				rm -rf ${OBJS} ${B_OBJS}
				${MAKE} -C ./libft clean
				${MAKE} -C ./mlx/mlx_mms/ clean

fclean		:
				rm -rf ${OBJS} ${B_OBJS} ${NAME} bonus ${MLX_LIB}
				${MAKE} -C ./libft fclean
				${MAKE} -C ./mlx/mlx_mms/ clean
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

ch_leak		:	${NAME} bonus
				leaks -atExit -- ./bonus ./maps/map1.ber
