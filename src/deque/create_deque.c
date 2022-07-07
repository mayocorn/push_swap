/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:14:22 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_deque	*create_deque(void)
{
	t_deque	*res;

	res = malloc_and_checknull(sizeof(t_deque));
	res->size = 0;
	res->front = NULL;
	res->back = NULL;
	return (res);
}
