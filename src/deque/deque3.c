/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:02:24 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 16:11:29 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

t_deques	*create_deques(void)
{
	t_deques	*res;

	res = malloc_and_checknull(sizeof(t_deques));
	res -> large_q = create_deque();
	res -> med_q = create_deque();
	res -> small_q = create_deque();
	return (res);
}