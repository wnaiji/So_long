/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:50 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/07 23:16:30 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_list
{
	char			*line;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;

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
void	ft_putstr(char *str);
int 	ft_lstsize(t_list *lst);
//ft_strtrim.c
char	*ft_strtrim(const char *s, const char *set);

//Verification de la Map:
//ft_check_map.c
void	ft_check_person(t_list *map);
void	ft_check_exit(t_list *map);
void	ft_check_collectible(t_list *map);
void	ft_check_map_is_retangle(t_list *map);
void	ft_check_map_is_closed(t_list *map);
//ft_analysis_map.c
void	ft_check_map(int fd);
int		ft_height_map(int fd);
void	ft_analysis_map(t_list *map);
void	ft_free_mapcpy(t_list *map);
//ft_flood_fill.c
t_point	ft_where_is_P(t_list **map, int *x, int *y);
t_list	*ft_map_cpy(t_list *map);
void	flood_fill(t_list *mapcpy);
void	ft_fill_mapcpy_1(t_list *mapcpy, t_point size, t_point target, int x, int y);
void	ft_check_access(t_list *map);

//Impression de la map:
void	print_map(t_list *map);

#endif
