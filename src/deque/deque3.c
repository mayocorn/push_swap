/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:02:24 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/23 19:18:05 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

t_deques	*create_deques(t_deque *elements, t_deque *commands)
{
	t_deques	*res;

	res = malloc_and_checknull(sizeof(t_deques));
	res -> elements = elements;
	res -> commands = commands;
	res -> af = create_deque();
	res -> ab = create_deque();
	res -> bf = create_deque();
	res -> bb = create_deque();
	return (res);
}

void	popfront_and_pushfront(t_deques *deques, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popfront(deques -> elements);
	pushfront(after, node);
	node = create_command_node(command);
	pushback(deques -> commands, node);
}

void	popfront_and_pushback(t_deques *deques, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popfront(deques -> elements);
	pushback(after, node);
	node = create_command_node(command);
	pushback(deques -> commands, node);
}

void	popback_and_pushfront(t_deques *deques, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popback(deques -> elements);
	pushfront(after, node);
	node = create_command_node(command);
	pushback(deques -> commands, node);
}

void	popback_and_pushback(t_deques *deques, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popback(deques -> elements);
	pushback(after, node);
	node = create_command_node(command);
	pushback(deques -> commands, node);
}
