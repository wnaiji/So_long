/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:01:25 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/08 14:51:27 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_point	ft_where_is_perso(t_list **map, int *x, int *y)
{
	t_point	target;

	*y = 0;
	while (*map)
	{
		*x = 0;
		while ((*map)->line[*x])
		{
			if ((*map)->line[*x] == 'P')
				break ;
			(*x)++;
		}
		if ((*map)->line[*x] == 'P')
			break ;
		(*y)++;
		*map = (*map)->next;
	}
	target.x = *x;
	target.y = *y;
	return (target);
}

void	ft_fill_mapcpy_1(t_list *mapcpy, t_point target, int x, int y)
{
	if (mapcpy->line[x] == 'F')
		return ;
	if (mapcpy->line[x] != '1')
		mapcpy->line[x] = 'F';
	if (mapcpy->prev->line[x] != '1')
		ft_fill_mapcpy_1(mapcpy = mapcpy->prev, target, x, y - 1);
	if (mapcpy->line[x + 1] != '1')
		ft_fill_mapcpy_1(mapcpy, target, x + 1, y);
	if (mapcpy->line[x - 1] != '1')
		ft_fill_mapcpy_1(mapcpy, target, x - 1, y);
	if (mapcpy->next->line[x] != '1')
		ft_fill_mapcpy_1(mapcpy = mapcpy->next, target, x, y + 1);
	if (mapcpy->line[x - 1] != '1')
		ft_fill_mapcpy_1(mapcpy, target, x - 1, y);
	if (mapcpy->line[x + 1] != '1')
		ft_fill_mapcpy_1(mapcpy, target, x + 1, y);
	if (mapcpy->next->line[x] != '1')
		ft_fill_mapcpy_1(mapcpy = mapcpy->next, target, x, y + 1);
	if (mapcpy->line[x + 1] != '1')
		ft_fill_mapcpy_1(mapcpy, target, x + 1, y);
	if (mapcpy->line[x - 1] != '1')
		ft_fill_mapcpy_1(mapcpy, target, x - 1, y);
}

void	ft_check_access(t_list *map)
{
	t_list	*tmp;
	int		i;
	t_point	access;

	tmp = map;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp->next)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'E')
				access.x = 1;
			if (tmp->line[i] == 'C')
				access.y = 1;
			i++;
		}
		tmp = tmp->next;
	}
	if (access.x > 0)
		ft_no_exit_access();
	if (access.y > 0)
		ft_no_access_collec();
}

void	flood_fill(t_list *mapcpy)
{
	t_point	size;
	t_point	target;
	int		x;
	int		y;

	size.y = ft_lstsize(mapcpy);
	size.x = ft_strlen(mapcpy->line);
	target = ft_where_is_perso(&mapcpy, &x, &y);
	ft_fill_mapcpy_1(mapcpy, target, x, y);
}

t_list	*ft_map_cpy(t_list *map)
{
	t_list	*mapcpy;
	t_list	*tmp;

	tmp = map;
	mapcpy = NULL;
	while (tmp->next)
	{
		mapcpy = ft_add_back_list(mapcpy, ft_strdup(tmp->line, 0));
		tmp = tmp->next;
	}
	return (mapcpy);
}
