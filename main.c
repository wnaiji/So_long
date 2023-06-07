/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:16 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/07 23:27:10 by walidnaiji       ###   ########.fr       */
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

	name_fd = NULL;
	if (argc == 2)
	{
		name_fd = ft_check_ber(argv[1]);
		ft_check_fd(&fd, name_fd);
		ft_check_map(fd);
		//system("leaks so_long");
	}
	else
		ft_putstr("Error: The number of arguments is not good\n");
	return (0);
}
