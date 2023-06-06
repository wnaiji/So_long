/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:35:37 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/06 21:21:18 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_height_map(int fd)
{
	int	i;

	i = 0;
	while (get_next_line(fd))
		i++;
	return (i);
}

void	ft_analysis_map(t_list *map)
{
	ft_check_person(map);
	printf("je suis ici\n");
	ft_check_exit(map);
	ft_check_collectible(map);
	ft_check_map_is_retangle(map);
	ft_check_map_is_closed(map);
}

void	print_map(t_list *map)
{
	t_list	*tmp;

	tmp = map;
	while (tmp->next)
	{
		printf("%s", tmp->line);
		tmp = tmp->next;
	}
}

void	ft_check_map(int fd)
{
	int		i;
	t_list	*map;

	//int		x;
	//int		y;

	map = NULL;
	i = 5;
	map = ft_add_front_list(map, get_next_line(fd));
	if (!(map->line))
		ft_error_file();
	while (ft_last_content(map))
		map = ft_add_back_list(map, get_next_line(fd));
	print_map(map);
	ft_analysis_map(map);
	//ft_where_is_P(map, &x, &y);
	//ft_put_w_in_y(map, x, y);
	//printf("%d--%d\n", x, y);
}
