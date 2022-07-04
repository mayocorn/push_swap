/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:38:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 03:10:56 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_exit(int status)
{
	if (status == SUCCESS)
		exit(SUCCESS);
	write(STDERR_FILENO, "Error\n", 6);
	exit(ERROR);
}
