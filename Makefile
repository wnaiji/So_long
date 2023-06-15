# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/28 17:46:04 by wnaiji            #+#    #+#              #
#    Updated: 2023/06/15 16:55:44 by wnaiji           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = exit_error.c \
	ft_analysis_map.c \
	ft_check_fd.c \
	ft_check_map.c \
	ft_list.c \
	ft_strtrim.c \
	get_next_line.c \
	get_next_line_utils.c \
	outils_libft.c \
	pars_ber.c \
	ft_flood_fill.c \
	ft_init_mlx.c \
	main.c \

OBJS = $(SRC:.c=.o)

NAME = so_long

CFLAGS = -Werror -Wextra -Wall -Imlx -fsanitize=address -g3

.c.o: $(SRC)
	gcc $(CFLAGS) -I . -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	gcc $(CFLAGS) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
