/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:32:20 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 12:42:06 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_collect(t_list *map)
{
	t_list	*tmp;
	int		i;
	int		collectible;

	tmp = map;
	i = 0;
	collectible = 0;
	while (tmp->prev)
		tmp = tmp->prev;
	while (tmp->next)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'C')
				collectible++;
			i++;
		}
		tmp = tmp->next;
	}
	return (collectible);
}

void	ft_move_w(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->prev->line[(*all).pers.x] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_w, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->prev->line[(*all).pers.x] == 'E')
		ft_move_to_e_by_w_or_d(*(&all), 'w');
	else if ((*all).map->prev->line[(*all).pers.x] == 'C')
		ft_move_to_c_by_w(*(&all), 'w');
	else if ((*all).map->prev->line[(*all).pers.x] == '0'
		|| (*all).map->prev->line[(*all).pers.x] == 'P')
		ft_move_to_0_by_w(*(&all), 'w');
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
		(*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924,
		nbr = ft_itoa((*all).step));
	free(nbr);
}

void	ft_move_s(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->next->line[(*all).pers.x] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_s, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->next->line[(*all).pers.x] == 'E')
		ft_move_to_e_by_s_or_a(*(&all), 's');
	else if ((*all).map->next->line[(*all).pers.x] == 'C')
		ft_move_to_c_by_s(*(&all), 's');
	else if ((*all).map->next->line[(*all).pers.x] == '0'
		|| (*all).map->prev->line[(*all).pers.x] == 'P')
		ft_move_to_0_by_s(*(&all), 's');
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
		(*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924,
		nbr = ft_itoa((*all).step));
	free(nbr);
}

void	ft_move_a(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->line[(*all).pers.x - 1] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_a, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->line[(*all).pers.x - 1] == 'E')
		ft_move_to_e_by_s_or_a(*(&all), 'a');
	else if ((*all).map->line[(*all).pers.x - 1] == 'C')
		ft_move_to_c_by_a(*(&all), 'a');
	else if ((*all).map->line[(*all).pers.x - 1] == '0'
		|| (*all).map->prev->line[(*all).pers.x - 1] == 'P')
		ft_move_to_0_by_a(*(&all), 'a');
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
		(*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924,
		nbr = ft_itoa((*all).step));
	free(nbr);
}

void	ft_move_d(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->line[(*all).pers.x + 1] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.perd, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->line[(*all).pers.x + 1] == 'E')
		ft_move_to_e_by_w_or_d(*(&all), 'd');
	else if ((*all).map->line[(*all).pers.x + 1] == 'C')
		ft_move_to_c_by_d(*(&all), 'd');
	else if ((*all).map->line[(*all).pers.x + 1] == '0'
		|| (*all).map->prev->line[(*all).pers.x + 1] == 'P')
		ft_move_to_0_by_d(*(&all), 'd');
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
		(*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924,
		nbr = ft_itoa((*all).step));
	free(nbr);
}
