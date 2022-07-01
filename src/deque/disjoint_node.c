/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disjoint_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:23:36 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 05:24:26 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

void	disjoint_node(t_deque *deque, t_node *ptr)
{
	t_node	*prev;
	t_node	*next;

	prev = ptr -> prev;
	next = ptr -> next;
	if (prev != NULL)
		prev -> next = next;
	else
		deque -> front = next;
	if (next != NULL)
		next -> prev = prev;
	else
		deque -> back = prev;
	deque -> size--;
	ptr -> prev = NULL;
	ptr -> next = NULL;
}