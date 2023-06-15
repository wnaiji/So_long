/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:35:37 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/15 14:36:25 by wnaiji           ###   ########.fr       */
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

t_list	*ft_check_map(int fd)
{
	t_list	*map;
	t_list	*mapcpy;

	map = NULL;
	map = ft_add_front_list(map, get_next_line(fd));
	if (!(map->line))
		ft_error_file();
	while (ft_last_content(map))
		map = ft_add_back_list(map, get_next_line(fd));
	ft_analysis_map(map);
	mapcpy = ft_map_cpy(map);
	flood_fill(mapcpy);
	ft_check_access(mapcpy);
	ft_free_mapcpy(mapcpy);
	return (map);
}

void	ft_free_mapcpy(t_list *map)
{
	t_list	*tmp;

	tmp = map;
	while (tmp)
	{
		free(tmp->line);
		tmp = tmp->next;
	}
	while (map)
		map = ft_delete_in_head(map);
}
