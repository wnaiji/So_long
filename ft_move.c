/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:32:20 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/17 19:29:45 by wnaiji           ###   ########.fr       */
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
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_w, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->prev->line[(*all).pers.x] == 'E')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_w, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.y--;
		(*all).map = (*all).map->prev;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->prev->line[(*all).pers.x] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, ((*all).pers.x) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_w, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->prev->line[(*all).pers.x] = '0';
		(*all).pers.y--;
		(*all).map = (*all).map->prev;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->prev->line[(*all).pers.x] == '0' || (*all).map->prev->line[(*all).pers.x] == 'P')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_w, (*all).pers.x * B, ((*all).pers.y - 1) * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).pers.y--;
		(*all).map = (*all).map->prev;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924, nbr = ft_itoa((*all).step));
	free(nbr);
}

void	ft_move_s(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->next->line[(*all).pers.x] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_s, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->next->line[(*all).pers.x] == 'E')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_s, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.y++;
		(*all).map = (*all).map->next;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->next->line[(*all).pers.x] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, ((*all).pers.x) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_s, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->next->line[(*all).pers.x] = '0';
		(*all).pers.y++;
		(*all).map = (*all).map->next;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->next->line[(*all).pers.x] == '0' || (*all).map->prev->line[(*all).pers.x] == 'P')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_s, (*all).pers.x * B, ((*all).pers.y + 1) * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).pers.y++;
		(*all).map = (*all).map->next;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924, nbr = ft_itoa((*all).step));
	free(nbr);
}

void	ft_move_a(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->line[(*all).pers.x - 1] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_a, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->line[(*all).pers.x - 1] == 'E')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_a, ((*all).pers.x - 1) * B, (*all).pers.y * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.x--;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->line[(*all).pers.x - 1] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, ((*all).pers.x) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, ((*all).pers.x - 1) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_a, ((*all).pers.x - 1) * B, (*all).pers.y * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->line[(*all).pers.x - 1] = '0';
		(*all).pers.x--;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->line[(*all).pers.x - 1] == '0' || (*all).map->prev->line[(*all).pers.x - 1] == 'P')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.per_a, ((*all).pers.x - 1) * B, (*all).pers.y * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).pers.x--;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924, nbr = ft_itoa((*all).step));
	free(nbr);
}

void	ft_move_d(t_all *all)
{
	char	*nbr;

	if ((*all).map->line[(*all).pers.x] == 'P')
		(*all).map->line[(*all).pers.x] = '0';
	if ((*all).map->line[(*all).pers.x + 1] == '1')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perd, (*all).pers.x * B, (*all).pers.y * B);
	}
	else if ((*all).map->line[(*all).pers.x + 1] == 'E')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perd, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		if (!ft_check_collect((*all).map))
			exit(EXIT_SUCCESS);
		(*all).pers.x++;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->line[(*all).pers.x + 1] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, ((*all).pers.x) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perd, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).map->line[(*all).pers.x + 1] = '0';
		(*all).pers.x++;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	else if ((*all).map->line[(*all).pers.x + 1] == '0' || (*all).map->prev->line[(*all).pers.x + 1] == 'P')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perd, ((*all).pers.x + 1) * B, (*all).pers.y * B);
		if ((*all).map->line[(*all).pers.x] == 'E')
		{
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.flr, (*all).pers.x * B, (*all).pers.y * B);
			mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.exit, (*all).pers.x * B, (*all).pers.y * B);
		}
		(*all).pers.x++;
		(*all).step++;
		ft_putnbr((*all).step);
		ft_putchar('\n');
	}
	mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.wall, 0, 0);
	mlx_string_put((*all).vars.mlx, (*all).vars.win, 0, 0, 0x0034C924, nbr = ft_itoa((*all).step));
	free(nbr);
}
