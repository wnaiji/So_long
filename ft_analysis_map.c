/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:35:37 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/06 20:25:23 by wnaiji           ###   ########.fr       */
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

int	ft_number_1_for_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '1')
			j++;
		i++;
	}
	if (i - 1 == j)
		return (1);
	return (0);
}

void	ft_check_map(int fd)
{
	int		i;
	t_list	*map;
	//int		x;
	//int		y;

	map = NULL;
	if (!fd)
		return ;
	i = 5;
	map = ft_add_front_list(map, get_next_line(fd));
	if (!(map->line))
		ft_error_file();
	while (i)
	{
		map = ft_add_back_list(map, get_next_line(fd));
		if (ft_number_1_for_line(ft_last_content(map)))
			break ;
	}
	ft_analysis_map(map);
	//ft_where_is_P(map, &x, &y);
	//ft_put_w_in_y(map, x, y);
	//printf("%d--%d\n", x, y);
}
