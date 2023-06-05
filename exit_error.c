/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnaiji <wnaiji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:40:09 by wnaiji            #+#    #+#             */
/*   Updated: 2023/06/05 18:19:43 by wnaiji           ###   ########.fr       */
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
