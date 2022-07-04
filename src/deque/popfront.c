/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popfront.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:16:46 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_node	*popfront(t_deque *deque)
{
	t_node	*res;
	t_node	*next;

	res = deque -> front;
	next = res -> next;
	deque -> front = next;
	if (next != NULL)
		next -> prev = NULL;
	else
		deque -> back = NULL;
	res -> next = NULL;
	deque -> size--;
	return (res);
}
