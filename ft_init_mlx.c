/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:37:32 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 08:53:02 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	ft_init_img(t_data *img, void **mlx)
{
	int		i;

	i = B;
	if (B == 32)
	{
		img->flr = mlx_xpm_file_to_image(*mlx, "xpm32/flr32.xpm", &i, &i);
		img->wall = mlx_xpm_file_to_image(*mlx, "xpm32/wall32.xpm", &i, &i);
		img->perd = mlx_xpm_file_to_image(*mlx, "xpm32/persD32.xpm", &i, &i);
		img->per_a = mlx_xpm_file_to_image(*mlx, "xpm32/persA32.xpm", &i, &i);
		img->per_s = mlx_xpm_file_to_image(*mlx, "xpm32/persS32.xpm", &i, &i);
		img->per_w = mlx_xpm_file_to_image(*mlx, "xpm32/persW32.xpm", &i, &i);
		img->exit = mlx_xpm_file_to_image(*mlx, "xpm32/exit32.xpm", &i, &i);
		img->col = mlx_xpm_file_to_image(*mlx, "xpm32/col32.xpm", &i, &i);
	}
	img->flr = mlx_xpm_file_to_image(*mlx, "xpm64/flr64.xpm", &i, &i);
	img->wall = mlx_xpm_file_to_image(*mlx, "xpm64/wall64.xpm", &i, &i);
	img->perd = mlx_xpm_file_to_image(*mlx, "xpm64/persD64.xpm", &i, &i);
	img->per_a = mlx_xpm_file_to_image(*mlx, "xpm64/persA64.xpm", &i, &i);
	img->per_s = mlx_xpm_file_to_image(*mlx, "xpm64/persS64.xpm", &i, &i);
	img->per_w = mlx_xpm_file_to_image(*mlx, "xpm64/persW64.xpm", &i, &i);
	img->exit = mlx_xpm_file_to_image(*mlx, "xpm64/exit64.xpm", &i, &i);
	img->col = mlx_xpm_file_to_image(*mlx, "xpm64/col64.xpm", &i, &i);
	return (*img);
}

void	ft_put_img(void *mlx, void *win, t_data img, t_list *map)
{
	t_list	*tmp;
	t_point	pt;

	tmp = map;
	pt.y = 0;
	while (tmp->next)
	{
		pt.x = 0;
		while (tmp->line[pt.x])
		{
			if (tmp->line[pt.x] != '1')
				mlx_put_image_to_window(mlx, win, img.flr, pt.x * B, pt.y * B);
			if (tmp->line[pt.x] == '1')
				mlx_put_image_to_window(mlx, win, img.wall, pt.x * B, pt.y * B);
			if (tmp->line[pt.x] == 'C')
				mlx_put_image_to_window(mlx, win, img.col, pt.x * B, pt.y * B);
			if (tmp->line[pt.x] == 'E')
				mlx_put_image_to_window(mlx, win, img.exit, pt.x * B, pt.y * B);
			if (tmp->line[pt.x] == 'P')
				mlx_put_image_to_window(mlx, win, img.perd, pt.x * B, pt.y * B);
			pt.x++;
		}
		pt.y++;
		tmp = tmp->next;
	}
}

int	ft_key(int key_code, t_all *all)
{
	if (key_code == 53)
		exit(EXIT_SUCCESS);
	if (key_code == 13)
		ft_move_w(*(&all));
	if (key_code == 1)
		ft_move_s(*(&all));
	if (key_code == 0)
		ft_move_a(*(&all));
	if (key_code == 2)
		ft_move_d(*(&all));
	return (0);
}

int	ft_close_win(int key_code, void *param)
{
	(void)key_code;
	(void)param;
	exit(0);
	return (0);
}

void	ft_init_window(t_list *map)
{
	t_all	all;
	t_vars	vars;
	t_data	img;
	t_point	pers;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, ft_strlen(map->line) * B - B,
			ft_lstsize(map) * B - B, "|-*Sonic*-|");
	ft_init_img(&img, &vars.mlx);
	ft_put_img(vars.mlx, vars.win, img, map);
	ft_where_is_perso(&map, &pers.x, &pers.y);
	all.vars = vars;
	all.img = img;
	all.pers = pers;
	all.map = map;
	all.step = 0;
	mlx_hook(vars.win, 2, 0, &ft_key, &all);
	mlx_hook(vars.win, 17, 0, &ft_close_win, NULL);
	mlx_loop(vars.mlx);
}
