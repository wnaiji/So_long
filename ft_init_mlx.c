/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:37:32 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/17 18:05:56 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	ft_init_img(t_data *img, void **mlx)
{
	int		i;

	i = BUF;
	img->floor = mlx_xpm_file_to_image(*mlx, "xpm/floor.xpm", &i, &i);
	img->wall = mlx_xpm_file_to_image(*mlx, "xpm/wall.xpm", &i, &i);
	img->perso_d = mlx_xpm_file_to_image(*mlx, "xpm/perso.xpm", &i, &i);
	img->perso_a = mlx_xpm_file_to_image(*mlx, "xpm/perso-gauche.xpm", &i, &i);
	img->perso_s_d = mlx_xpm_file_to_image(*mlx, "xpm/perso bas.xpm", &i, &i);
	img->perso_s_a = mlx_xpm_file_to_image(*mlx, "xpm/perso-gauche bas.xpm", &i, &i);
	img->perso_w_d = mlx_xpm_file_to_image(*mlx, "xpm/perso haut.xpm", &i, &i);
	img->perso_w_a = mlx_xpm_file_to_image(*mlx, "xpm/perso-gauche haut.xpm", &i, &i);
	img->exit = mlx_xpm_file_to_image(*mlx, "xpm/exit.xpm", &i, &i);
	img->collectible = mlx_xpm_file_to_image(*mlx, "xpm/collectible.xpm", &i, &i);
	return (*img);
}

void	ft_put_img(t_vars vars, t_data img, t_list *map)
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
				mlx_put_image_to_window(vars.mlx, vars.win, img.floor, pt.x * BUF, pt.y * BUF);
			if (tmp->line[pt.x] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win, img.wall, pt.x * BUF, pt.y * BUF);
			if (tmp->line[pt.x] == 'C')
				mlx_put_image_to_window(vars.mlx, vars.win, img.collectible, pt.x * BUF, pt.y * BUF);
			if (tmp->line[pt.x] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win, img.exit, pt.x * BUF, pt.y * BUF);
			if (tmp->line[pt.x] == 'P')
				mlx_put_image_to_window(vars.mlx, vars.win, img.perso_d, pt.x * BUF, pt.y * BUF);
			pt.x++;
		}
		pt.y++;
		tmp = tmp->next;
	}
}

int	ft_key(int key_code, t_all *all)
{
	if (key_code == 53)
	{
		print_map((*all).map);
		//mlx_destroy_window((*all).vars.mlx, (*all).vars.win);
		system("leaks so_long");
		exit(EXIT_SUCCESS);
	}
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
	vars.win = mlx_new_window(vars.mlx, ft_strlen(map->line) * BUF -BUF, ft_lstsize(map) * BUF - BUF, "|-*Sonic*-|");
	ft_init_img(&img, &vars.mlx);
	ft_put_img(vars, img, map);
	ft_where_is_perso(&map, &pers.x, &pers.y);
	all.vars = vars;
	all.img = img;
	all.pers = pers;
	all.map = map;
	all.step = 0;
	//mlx_do_key_autorepeatoff(all.vars.mlx);
	mlx_hook(vars.win, 2, 0, &ft_key, &all);
	mlx_hook(vars.win, 17, 0, &ft_close_win, NULL);
	mlx_loop(vars.mlx);
}
