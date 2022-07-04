/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_and_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:28:28 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deque.h"

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
