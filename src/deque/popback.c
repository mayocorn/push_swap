/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:18:57 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_node	*popback(t_deque *deque)
{
	t_node	*res;
	t_node	*prev;

	res = deque->back;
	prev = res->prev;
	deque->back = prev;
	if (prev != NULL)
		prev->next = NULL;
	else
		deque->front = NULL;
	res->prev = NULL;
	deque->size--;
	return (res);
}
