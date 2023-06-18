/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_e_c_o.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:49:12 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 11:37:55 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_to_e_by_w_or_d(t_all *all, char c)
{
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr,
		(*all).pers.x * B, (*all).pers.y * B);
	if (c == 'w')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_w, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.y--;
		(*all).map = (*all).map->prev;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	if (c == 'd')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.perd, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.x++;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
}

void	ft_move_to_e_by_s_or_a(t_all *all, char c)
{
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr,
		(*all).pers.x * B, (*all).pers.y * B);
	if (c == 's')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_s, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.y++;
		(*all).map = (*all).map->next;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	if (c == 'a')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_a, ((*all).pers.x - 1) * B, (*all).pers.y * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.x--;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
}

void	ft_move_to_c_by_w(t_all *all, char c)
{
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr,
		((*all).pers.x) * B, (*all).pers.y * B);
	if (c == 'w')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_w, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
				(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
				(*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->prev->line[(*all).pers.x] = '0';
		(*all).pers.y--;
		(*all).map = (*all).map->prev;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
}

void	ft_move_to_c_by_d(t_all *all, char c)
{
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr,
		((*all).pers.x) * B, (*all).pers.y * B);
	if (c == 'd')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.perd, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
				(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
				(*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->line[(*all).pers.x + 1] = '0';
		(*all).pers.x++;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
}

void	ft_move_to_c_by_s(t_all *all, char c)
{
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr,
		((*all).pers.x) * B, (*all).pers.y * B);
	if (c == 's')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.flr, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
			(*all).img.per_s, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
				(*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win,
				(*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->next->line[(*all).pers.x] = '0';
		(*all).pers.y++;
		(*all).map = (*all).map->next;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
}
