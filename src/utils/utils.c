/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:38:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/21 15:18:50 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/utils.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	*malloc_and_checknull(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		ft_exit(1);
	return (res);
}

void	free_and_setnull(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_exit(int status)
{
	if (status == SUCCESS)
		exit(SUCCESS);
	write(2, "ERROR\n", 6);
	exit(ERROR);
}
