/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:40:09 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/20 12:26:21 by wnaiji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_closed(void)
{
	ft_putstr("Error: The map is not closed\n");
	exit(EXIT_FAILURE);
}

void	ft_error_rectangle(void)
{
	ft_putstr("Error: The map is not rectangle\n");
	exit(EXIT_FAILURE);
}

void	ft_error_file(void)
{
	ft_putstr("Error: The file is empty\n");
	exit(EXIT_FAILURE);
}

void	ft_no_exit_access(void)
{
	ft_putstr("Error: No exit access\n");
	exit(EXIT_FAILURE);
}

void	ft_no_access_collec(void)
{
	ft_putstr("Error: No access to collectibles\n");
	exit(EXIT_FAILURE);
}
