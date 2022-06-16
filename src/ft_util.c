/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:38:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/16 18:24:06 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_utils.h"

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

void	*ft_malloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		ft_exit(1);
	return (res);
}

void	ft_free(void	**ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_exit(int status)
{
	if (status == 0)
		exit(0);
	write(2, "ERROR", 5);
	exit(1);
}
