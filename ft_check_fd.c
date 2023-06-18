/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: walidnaiji <walidnaiji@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:56:46 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/18 19:46:55 by walidnaiji       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_fd(int *fd, char *name_fd)
{
	*fd = open(name_fd, O_DIRECTORY);
	if (*fd > 0)
	{
		ft_putstr("Error: It's a directory\n");
		system("leaks so_long");
		exit(EXIT_FAILURE);
	}
	*fd = open(name_fd, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr("Error: open file descriptor\n");
		system("leaks so_long");
		exit(EXIT_FAILURE);
	}
	free(name_fd);
	return (*fd);
}
