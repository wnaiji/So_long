/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:01:25 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/07 21:49:06 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_where_is_P(t_list **map, int *x, int *y)
{
	t_point	target;

	*y = 0;
	while (*map)
	{
		*x = 0;
		while ((*map)->line[*x])
		{
			if ((*map)->line[*x] == 'P')
				break;
			(*x)++;
		}
		if ((*map)->line[*x] == 'P')
				break;
		(*y)++;
		*map = (*map)->next;
	}
	target.x = *x;
	target.y = *y;
	return (target);
}

void	ft_fill_mapcpy_1(t_list *mapcpy, t_point size, t_point target, int x, int y)
{
	if (mapcpy->line[x] == 'F')
		return ;
	if (mapcpy->line[x] != '1')
		mapcpy->line[x] = 'F';
	if (mapcpy->prev->line[x] != '1')
		ft_fill_mapcpy_1(mapcpy = mapcpy->prev, size, target, x, y - 1);
	if (mapcpy->line[x + 1] != '1')
		ft_fill_mapcpy_1(mapcpy, size, target, x + 1, y);
	if (mapcpy->line[x - 1] != '1')
		ft_fill_mapcpy_1(mapcpy, size, target, x - 1, y);
	if (mapcpy->next->line[x] != '1')
		ft_fill_mapcpy_1(mapcpy = mapcpy->next, size, target, x, y + 1);
	if (mapcpy->line[x - 1] != '1')
		ft_fill_mapcpy_1(mapcpy, size, target, x - 1, y);
	if (mapcpy->line[x + 1] != '1')
		ft_fill_mapcpy_1(mapcpy, size, target, x + 1, y);
	if (mapcpy->next->line[x] != '1')
		ft_fill_mapcpy_2(mapcpy = mapcpy->next, size, target, x, y + 1);
	if (mapcpy->line[x + 1] != '1')
		ft_fill_mapcpy_2(mapcpy, size, target, x + 1, y);
	if (mapcpy->line[x - 1] != '1')
		ft_fill_mapcpy_2(mapcpy, size, target, x - 1, y);

}

void	flood_fill(t_list *mapcpy)
{
	t_point	size;
	t_point	target;
	int		x;
	int		y;

	size.y = ft_lstsize(mapcpy);
	size.x = ft_strlen(mapcpy->line);
	target = ft_where_is_P(&mapcpy, &x, &y);
	ft_fill_mapcpy_1(mapcpy, size, target, x, y);
	print_map(mapcpy);
}

t_list	*ft_map_cpy(t_list *map)
{
	t_list	*mapcpy;
	t_list	*tmp;

	tmp = map;
	mapcpy = NULL;
	while (tmp->next)
	{
		mapcpy = ft_add_back_list(mapcpy, tmp->line);
		tmp = tmp->next;
	}
	return (mapcpy);
}
