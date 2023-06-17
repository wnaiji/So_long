/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:16 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/17 16:24:19 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(t_list *map)
{
	t_list	*tmp;

	tmp = map;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}

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
		ft_init_window(map);
		system("leaks so_long");
	}
	else
		ft_putstr("Error: The number of arguments is not good\n");
	return (0);
}
