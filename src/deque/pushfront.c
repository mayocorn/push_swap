/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushfront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:16:08 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 05:16:25 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

void	pushfront(t_deque *deque, t_node *ptr)
{
	t_node	*next;

	if (deque -> size == 0)
	{
		deque -> front = ptr;
		deque -> back = ptr;
	}
	else
	{
		next = deque -> front;
		next -> prev = ptr;
		ptr -> next = next;
		deque -> front = ptr;
	}
	deque -> size++;
}
