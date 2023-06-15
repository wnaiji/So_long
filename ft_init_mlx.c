/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 14:37:32 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/15 20:30:36 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = (*data).addr + (y * (*data).line_length + x *
							((*data).bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	(void)keycode;
	(void)vars;
	printf("Hello from key_hook!\n");
	return (0);
}

void	ft_init_window(t_list *map)
{
	t_vars	vars;
	t_data	img;
	(void)map;
	int	i = 0;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "|-*Sonic*-|");
	img.img = mlx_xpm_file_to_image(vars.mlx, "xpm/perso.xpm", &i, &i);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_loop(vars.mlx);
	/*img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
	my_mlx_pixel_put(&img, 50, 500, 0x00FFFF00);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 10, 10);
	//mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);*/
}
