/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_and_checknull.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 04:50:53 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*malloc_and_checknull(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
		ft_exit(ERROR);
	return (res);
}
