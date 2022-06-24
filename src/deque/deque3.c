/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 15:02:24 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 09:39:43 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

void	popfront_and_pushfront(t_div_info *div_info, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popfront(div_info -> elements);
	pushfront(after, node);
	node = create_command_node(command);
	pushback(div_info -> commands, node);
}

void	popfront_and_pushback(t_div_info *div_info, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popfront(div_info -> elements);
	pushback(after, node);
	node = create_command_node(command);
	pushback(div_info -> commands, node);
}

void	popback_and_pushfront(t_div_info *div_info, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popback(div_info -> elements);
	pushfront(after, node);
	node = create_command_node(command);
	pushback(div_info -> commands, node);
}

void	popback_and_pushback(t_div_info *div_info, \
								t_deque *after, t_command command)
{
	t_node	*node;

	node = popback(div_info -> elements);
	pushback(after, node);
	node = create_command_node(command);
	pushback(div_info -> commands, node);
}

int	get_minelement(t_deque *deque)
{
	t_node	*node;
	int		min_element;

	node = deque -> front;
	min_element = INT_MAX;
	while (node != NULL)
	{
		min_element = ft_min(min_element, node -> content.number);
		node = node -> next;
	}
	return (min_element);
}
