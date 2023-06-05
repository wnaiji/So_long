/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:38:50 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/05 18:21:21 by wnaiji           ###   ########.fr       */
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
	struct s_list	*next;
}	t_list;

//Verification du file descriteur:
//ft_strtrim.c
char	*ft_strtrim(const char *s, const char *set);
//pars_ber.c
char	*ft_check_ber(char *str);
//ft_check_fd.c
int	ft_check_fd(int fd, char *name_fd);

//Quelque sortie d'erreur:
//exit_error.c
void	ft_error_closed(void);
void	ft_error_rectangle(void);

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

//Verification de la Map:
//ft_check_map.c
void	ft_check_person(t_list *map);
void	ft_check_exit(t_list *map);
void	ft_check_collectible(t_list *map);
void	ft_check_map_is_retangle(t_list *map);
void	ft_check_map_is_closed(t_list *map);
//ft_analysis_map.c
void	ft_check_map(int fd);
int	ft_height_map(int fd);
void	ft_analysis_map(t_list *map);

#endif
