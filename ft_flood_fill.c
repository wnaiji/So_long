/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:01:25 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/06 18:42:35 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*void	ft_where_is_P(t_list *map, int *x, int *y)
{
	t_list	*tmp;

	tmp = map;
	*y = 0;
	while (tmp)
	{
		*x = 0;
		while (tmp->line[*x])
		{
			if (tmp->line[*x] == 'P')
				break;
			(*x)++;
		}
		if (tmp->line[*x] == 'P')
				break;
		(*y)++;
		tmp = tmp->next;
	}
}*/

/*char	*ft_put_p_in_axe_x(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'P')
		{
			if (str[i - 1] != '1')
				str[i - 1] = 'P';
			if (str[i + 1] != '1')
				str[i + 1] = 'P';
		}
		i++;
	}
	return (str);
}

void	ft_put_w_in_x_and_y(t_list *map, int x, int y)
{
	t_list	*tmp;
	int		i;
	int 	j;

	tmp = map;
	j = 10;
	while (j)
	{
		tmp = tmp;
		while (tmp)
		{
			i = 0;
			tmp->line = ft_put_p_in_axe_x(tmp->line);''
			tmp = tmp->next;
		}
		j--;
	}
}*/
