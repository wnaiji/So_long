/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:49:34 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/05 18:34:35 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_is_closed(t_list *map)
{
	t_list	*tmp;
	int		i;

	tmp = map;
	i = 0;
	while (tmp->line[i] != '\n')
	{
		if (tmp->line[i] != '1')
			ft_error_closed();
		i++;
	}
	tmp = tmp->next;
	while (tmp->next)
	{
		if ((tmp->line[0] != '1') || (tmp->line[ft_strlen(tmp->line) - 2] != '1'))
			ft_error_closed();
		tmp = tmp->next;
	}
	while (tmp->line[i] && tmp->line[i] != '\n')
	{
		if (tmp->line[i] != '1')
			ft_error_closed();
		i++;
	}
}


void	ft_check_map_is_retangle(t_list *map)
{
	t_list	*tmp;
	size_t	first_line;

	tmp = map;
	first_line = ft_strlen(tmp->line);
	while (tmp->next)
	{
		if (first_line != ft_strlen(tmp->line))
			ft_error_rectangle();
		tmp = tmp->next;
	}
	if (ft_strchr(tmp->line, '\n') != NULL)
	{
		if (first_line != ft_strlen(tmp->line))
			ft_error_rectangle();
	}
	else if ((first_line - 1) != ft_strlen(tmp->line))
		ft_error_rectangle();
}

void	ft_check_person(t_list *map)
{
	t_list	*tmp;
	int		i;
	int		person;

	tmp = map;
	person = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'P')
				person++;
			i++;
		}
		tmp = tmp->next;
	}
	if (person != 1)
	{
		ft_putstr("Error: The number of player is different from 1\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_exit(t_list *map)
{
	t_list	*tmp;
	int		i;
	int		output;

	tmp = map;
	i = 0;
	output = 0;
	while (tmp)
	{
		i = 0;
		while (tmp->line[i])
		{
			if (tmp->line[i] == 'E')
				output++;
			i++;
		}
		tmp = tmp->next;
	}
	if (output != 1)
	{
		ft_putstr("Error: The output number is different from 1\n");
		exit(EXIT_FAILURE);
	}
}

void	ft_check_collectible(t_list *map)
{
	t_list	*tmp;
	int		i;
	int		collectible;

	tmp = map;
	i = 0;
	collectible = 0;
	while (tmp)
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
	if (collectible < 1)
	{
		ft_putstr("Error: There are no collectibles\n");
		exit(EXIT_FAILURE);
	}
}
