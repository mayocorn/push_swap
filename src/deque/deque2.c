/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:35:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/22 09:12:50 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

t_node	*create_node(void)
{
	t_node	*res;

	res = malloc_and_checknull(sizeof(t_node));
	res -> next = NULL;
	res -> prev = NULL;
	return (res);
}

t_node	*create_command_node(t_command command)
{
	t_node		*res;
	t_content	content;

	res = create_node();
	content.command = command;
	res -> content = content;
	return (res);
}

t_node	*create_number_node(size_t number)
{
	t_node		*res;
	t_content	content;

	res = create_node();
	content.number = number;
	res -> content = content;
	return (res);
}

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
