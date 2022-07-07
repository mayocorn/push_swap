/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:21:07 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/08 00:38:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

t_node	*create_node(void)
{
	t_node	*res;

	res = malloc_and_checknull(sizeof(t_node));
	res->next = NULL;
	res->prev = NULL;
	return (res);
}

t_node	*create_command_node(t_command command)
{
	t_node		*res;
	t_content	content;

	res = create_node();
	content.command = command;
	res->content = content;
	return (res);
}

t_node	*create_number_node(int number)
{
	t_node		*res;
	t_content	content;

	res = create_node();
	content.number = number;
	res->content = content;
	return (res);
}
