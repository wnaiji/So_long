/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:16 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 19:46:10 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	char	*name_fd;
	int		fd;
	t_list	*map;

	name_fd = NULL;
	if (argc == 2)
	{
		name_fd = ft_check_ber(argv[1]);
		ft_check_fd(&fd, name_fd);
		map = ft_check_map(fd);
		if (B != 32 && B != 64)
		{
			ft_putstr("Error: BUFFER is not correct\n");
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		ft_init_window(map);
		system("leaks so_long");
	}
	else
		ft_putstr("Error: The number of arguments is not good\n");
	return (0);
}
