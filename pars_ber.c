/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:42:33 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 19:47:47 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fd_is_ber(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] == 'b' && str[i + 2] == 'e'
			&& str[i + 3] == 'r' && str[i + 4] == '\0')
			return ;
		i++;
	}
	ft_putstr("Error file descriptor\n");
	system("leaks so_long");
	exit(EXIT_FAILURE);
}

char	*ft_check_ber(char *str)
{
	int		i;
	char	*strtrim;

	i = 0;
	strtrim = ft_strtrim(str, "  ");
	while (strtrim[i])
	{
		if (strtrim[i] == ' ')
		{
			ft_putstr("Error: file descriptor\n");
			system("leaks so_long");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ft_fd_is_ber(strtrim);
	return (strtrim);
}
