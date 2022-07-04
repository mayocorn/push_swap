/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushback.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:15:09 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

void	pushback(t_deque *deque, t_node *ptr)
{
	t_node	*prev;

	if (deque -> size == 0)
	{
		deque -> front = ptr;
		deque -> back = ptr;
	}
	else
	{
		prev = deque -> back;
		prev -> next = ptr;
		ptr -> prev = prev;
		deque -> back = ptr;
	}
	deque -> size++;
}
