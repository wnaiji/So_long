/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:35:37 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/05 17:53:40 by wnaiji           ###   ########.fr       */
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
	ft_check_exit(map);
	ft_check_collectible(map);
	ft_check_map_is_retangle(map);
	ft_check_map_is_closed(map);
}

void	ft_check_map(int fd)
{
	int		i;
	t_list	*map;

	map = NULL;
	if (!fd)
		return ;
	//i = ft_height_map(fd) - 1;
	i = 5;
	map = ft_add_front_list(map, get_next_line(fd));
	while (i)
	{
		map = ft_add_back_list(map, get_next_line(fd));
		i--;
	}
	ft_analysis_map(map);
}
