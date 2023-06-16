/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:32:20 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/16 17:40:18 by wnaiji           ###   ########.fr       */
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
	t_list	*tmp;

	tmp = (*all).map;
	if (tmp->prev->line[(*all).pers.x] == '1')
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_w_a, (*all).pers.x * 64, (*all).pers.y * 64);
	else if (tmp->prev->line[(*all).pers.x] == 'E' && ft_check_collect((*all).map))
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_w_a, (*all).pers.x * 64, ((*all).pers.y - 1) * 64);
		(*all).pers.y--;
	}
	else if (tmp->prev->line[(*all).pers.x] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, (*all).pers.x * 64, ((*all).pers.y - 1) * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_w_a, (*all).pers.x * 64, ((*all).pers.y - 1) * 64);
		tmp->prev->line[(*all).pers.x] = '0';
		(*all).pers.y--;
	}
	else if (tmp->prev->line[(*all).pers.x] == '0')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, (*all).pers.x * 64, (*all).pers.y * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_w_a, (*all).pers.x * 64, ((*all).pers.y - 1) * 64);
		(*all).pers.y--;
	}
}

void	ft_move_s(t_all *all)
{
	t_list	*tmp;

	tmp = (*all).map;
	if (tmp->next->line[(*all).pers.x] == '1')
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, (*all).pers.x * 64, (*all).pers.y * 64);
	else if (tmp->next->line[(*all).pers.x] == 'E' && ft_check_collect((*all).map))
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, (*all).pers.x * 64, ((*all).pers.y + 1) * 64);
		(*all).pers.y++;
	}
	else if (tmp->next->line[(*all).pers.x] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, (*all).pers.x * 64, ((*all).pers.y + 1) * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, (*all).pers.x * 64, ((*all).pers.y + 1) * 64);
		tmp->next->line[(*all).pers.x] = '0';
		(*all).pers.y++;
	}
	else if (tmp->next->line[(*all).pers.x] == '0')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, (*all).pers.x * 64, (*all).pers.y * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, (*all).pers.x * 64, ((*all).pers.y + 1) * 64);
		(*all).pers.y++;
	}
}

void	ft_move_a(t_all *all)
{
	t_list	*tmp;

	tmp = (*all).map;
	if (tmp->line[(*all).pers.x - 1] == '1')
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_a, (*all).pers.x * 64, (*all).pers.y * 64);
	else if (tmp->line[(*all).pers.x - 1] == 'E' && ft_check_collect((*all).map))
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_a, ((*all).pers.x - 1) * 64, (*all).pers.y * 64);
		(*all).pers.x--;
	}
	else if (tmp->line[(*all).pers.x - 1] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, ((*all).pers.x - 1) * 64, (*all).pers.y * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, ((*all).pers.x - 1) * 64, (*all).pers.y * 64);
		tmp->line[(*all).pers.x] = '0';
		(*all).pers.x--;
	}
	else if (tmp->line[(*all).pers.x - 1] == '0')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, (*all).pers.x * 64, (*all).pers.y * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, ((*all).pers.x - 1) * 64, (*all).pers.y * 64);
		(*all).pers.x--;
	}
}

void	ft_move_d(t_all *all)
{
	t_list	*tmp;

	tmp = (*all).map;
	if (tmp->line[(*all).pers.x + 1] == '1')
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_d, (*all).pers.x * 64, (*all).pers.y * 64);
	else if (tmp->line[(*all).pers.x + 1] == 'E' && ft_check_collect((*all).map))
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_d, ((*all).pers.x + 1) * 64, (*all).pers.y * 64);
		(*all).pers.x++;
	}
	else if (tmp->line[(*all).pers.x + 1] == 'C')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, ((*all).pers.x + 1) * 64, (*all).pers.y * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, ((*all).pers.x + 1) * 64, (*all).pers.y * 64);
		tmp->line[(*all).pers.x] = '0';
		(*all).pers.x++;
	}
	else if (tmp->line[(*all).pers.x + 1] == '0')
	{
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.floor, (*all).pers.x * 64, (*all).pers.y * 64);
		mlx_put_image_to_window((*all).vars.mlx, (*all).vars.win, (*all).img.perso_s_a, ((*all).pers.x + 1) * 64, (*all).pers.y * 64);
		(*all).pers.x++;
	}
}
