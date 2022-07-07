/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:38:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:48:54 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit(int status)
{
	if (status == EXIT_FAILURE)
		write(STDERR_FILENO, "Error\n", 6);
	exit(status);
}
