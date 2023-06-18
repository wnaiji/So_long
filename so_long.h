/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:50 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 12:51:00 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# include <mlx.h>

# ifndef B
#  define B 32
# endif

typedef struct s_list
{
	char			*line;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_point
{
	int	x;
	int	y;

}	t_point;

typedef struct s_data {
	void	*flr;
	void	*wall;
	void	*perd;
	void	*per_a;
	void	*per_s;
	void	*per_w;
	void	*exit;
	void	*col;
}				t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_all {
	t_vars	vars;
	t_data	img;
	t_point	pers;
	t_list	*map;
	int		step;
}				t_all;

//Verification du file descriteur:
//pars_ber.c
char	*ft_check_ber(char *str);
//ft_check_fd.c
int		ft_check_fd(int *fd, char *name_fd);

//Quelque sortie d'erreur:
//exit_error.c
void	ft_error_closed(void);
void	ft_error_rectangle(void);
void	ft_error_file(void);
void	ft_no_exit_access(void);
void	ft_no_access_collec(void);

//Gestion de la liste chaine:
//ft_list.c
void	*ft_add_front_list(t_list *list, char *line);
void	*ft_add_back_list(t_list *list, char *line);
void	*ft_delete_in_head(t_list *list);
void	*ft_delete_at_back(t_list *list);
char	*ft_last_content(t_list *list);

//Outils de la Libft:
//outils_libft.c
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_lstsize(t_list *lst);
void	ft_putnbr(int n);
//ft_strtrim.c
char	*ft_strtrim(const char *s, const char *set);
//ft_itoa.c
char	*ft_itoa(int n);

//Verification de la Map:
//ft_check_map.c
void	ft_check_person(t_list *map);
void	ft_check_exit(t_list *map);
void	ft_check_collectible(t_list *map);
void	ft_check_map_is_retangle(t_list *map);
void	ft_check_map_is_closed(t_list *map);
//ft_analysis_map.c
t_list	*ft_check_map(int fd);
int		ft_height_map(int fd);
void	ft_analysis_map(t_list *map);
void	ft_free_mapcpy(t_list *map);
//ft_flood_fill.c
t_point	ft_where_is_perso(t_list **map, int *x, int *y);
t_list	*ft_map_cpy(t_list *map);
void	flood_fill(t_list *mapcpy);
void	ft_fill_mapcpy_1(t_list *mapcpy, t_point target, int x, int y);
void	ft_check_access(t_list *map);

//Gestion de la mlx et ouverture de window:
//ft_init_mlx.c
void	ft_init_window(t_list *map);
int		ft_key(int key_code, t_all *all);
void	ft_put_img(void *mlx, void *win, t_data img, t_list *map);
t_data	ft_init_img(t_data *img, void **mlx);
int		ft_close_win(int key_code, void *param);
//ft_move.c
void	ft_move_w(t_all *all);
void	ft_move_s(t_all *all);
void	ft_move_a(t_all *all);
void	ft_move_d(t_all *all);
int		ft_check_collect(t_list *map);
//ft_move_e_and_c.c
void	ft_move_to_e_by_w_or_d(t_all *all, char c);
void	ft_move_to_e_by_s_or_a(t_all *all, char c);
void	ft_move_to_c_by_w(t_all *all, char c);
void	ft_move_to_c_by_d(t_all *all, char c);
void	ft_move_to_c_by_s(t_all *all, char c);
//ft_move_o.c
void	ft_move_to_c_by_a(t_all *all, char c);
void	ft_move_to_0_by_w(t_all *all, char c);
void	ft_move_to_0_by_a(t_all *all, char c);
void	ft_move_to_0_by_d(t_all *all, char c);
void	ft_move_to_0_by_s(t_all *all, char c);

//Impression de la map:
void	print_map(t_list *map);

#endif
