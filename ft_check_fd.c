/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:56:46 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/05 16:51:03 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_fd(int fd, char *name_fd)
{
	fd = open(name_fd, O_DIRECTORY);
	if (fd > 0)
	{
		ft_putstr("Error: It's a directory\n");
		free(name_fd);
		exit(EXIT_FAILURE);
	}
	fd = open(name_fd, O_RDONLY);
	if (!fd)
	{
		ft_putstr("Error: open file descriptor\n");
		free(name_fd);
		exit(EXIT_FAILURE);
	}
	free(name_fd);
	return (fd);
}
