# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:46:04 by wnaiji            #+#    #+#              #
#    Updated: 2023/06/18 19:53:21 by walidnaiji       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = exit_error.c \
	ft_analysis_map.c \
	ft_check_fd.c \
	ft_check_map.c \
	ft_list.c \
	ft_strtrim.c \
	outils_libft.c \
	pars_ber.c \
	ft_flood_fill.c \
	ft_init_mlx.c \
	ft_move.c \
	get_next_line.c \
	get_next_line_utils.c \
	ft_itoa.c \
	ft_move_0.c \
	ft_move_e_and_c.c \
	main.c \

OBJS = $(SRC:.c=.o)

NAME = so_long

CFLAGS = -Werror -Wextra -Wall -Imlx #-fsanitize=address -g3

.c.o: $(SRC)
	gcc $(CFLAGS) -I . -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
