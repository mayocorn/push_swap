/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 15:52:27 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 09:16:19 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

t_deque	*create_deque(void)
{
	t_deque	*res;

	res = malloc_and_checknull(sizeof(t_deque));
	res->size = 0;
	res->front = NULL;
	res->back = NULL;
	return (res);
}

void	pushback(t_deque *deque, t_node *ptr)
{
	t_node	*prev;

	if (deque->size == 0)
	{
		deque->front = ptr;
		deque->back = ptr;
	}
	else
	{
		prev = deque->back;
		prev->next = ptr;
		ptr->prev = prev;
		deque->back = ptr;
	}
	deque->size++;
}

void	pushfront(t_deque *deque, t_node *ptr)
{
	t_node	*next;

	if (deque->size == 0)
	{
		deque->front = ptr;
		deque->back = ptr;
	}
	else
	{
		next = deque->front;
		next->prev = ptr;
		ptr->next = next;
		deque->front = ptr;
	}
	deque->size++;
}

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
	return ((t_node*)res);
}

t_node	*popfront(t_deque *deque)
{
	t_node	*res;
	t_node	*next;

	res = deque->front;
	next = res->next;
	deque->front = next;
	if (next != NULL)
		next->prev = NULL;
	else
		deque->back = NULL;
	res->next = NULL;
	deque->size--;
	return ((t_node*)res);
}
