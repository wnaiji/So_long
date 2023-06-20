/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 14:56:46 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/20 12:26:42 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_fd(int *fd, char *name_fd)
{
	*fd = open(name_fd, O_DIRECTORY);
	if (*fd > 0)
	{
		ft_putstr("Error: It's a directory\n");
		exit(EXIT_FAILURE);
	}
	*fd = open(name_fd, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr("Error: open file descriptor\n");
		exit(EXIT_FAILURE);
	}
	free(name_fd);
	return (*fd);
}
