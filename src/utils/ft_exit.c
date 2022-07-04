/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:38:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 06:44:52 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

void	ft_exit(int status)
{
	if (status == SUCCESS)
		exit(SUCCESS);
	write(STDERR_FILENO, "ERROR\n", 6);
	exit(ERROR);
}
