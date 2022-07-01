/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sametime_command.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 00:06:08 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 16:16:10 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/optimize.h"

static void	convert_rr(t_deque *commands, t_node **node);
static void	convert_rrr(t_deque *commands, t_node **node);
static void	convert_ss(t_deque *commands, t_node **node);

void	optimize_sametime_command(t_deque *commands)
{
	t_node	*now;

	now = commands -> front;
	while (now != NULL)
	{
		if (now -> prev == NULL)
			now = now -> next;
		else if (now -> content.command == ra || now -> content.command == rb)
			convert_rr(commands, &now);
		else if (now -> content.command == rra || now -> content.command == rrb)
			convert_rrr(commands, &now);
		else if (now -> content.command == sa || now -> content.command == sb)
			convert_ss(commands, &now);
		else
			now = now -> next;
	}
}

static void	convert_rr(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node)->prev;
	command = (*node)->content.command;
	while (prev != NULL)
	{
		if (command == ra && prev -> content.command == rb || \
			command == rb && prev -> content.command == ra)
		{
			next = prev -> next;
			if (next == *node)
				next = next -> next;
			disjoint_node(commands, prev);
			(*node)->content.command = rr;
			*node = next;
			return ;
		}
		else if (command == ra && prev -> content.command == sa || \
					command == rb && prev -> content.command != sb)
			break ;
		prev = prev -> prev;
	}
	*node = (*node)->next;
}

static void	convert_rrr(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_node		*next;
	t_command	command;

	prev = (*node)->prev;
	command = (*node)->content.command;
	while (prev != NULL)
	{
		if (command == rra && prev -> content.command == rrb || \
			command == rrb && prev -> content.command == rra)
		{
			next = prev -> next;
			if (next == *node)
				next = next -> next;
			disjoint_node(commands, prev);
			(*node)->content.command = rrr;
			*node = next;
			return ;
		}
		else if (command == rra && prev -> content.command != sa || \
					command == rrb && prev -> content.command != sb)
			break ;
		prev = prev -> prev;
	}
	*node = (*node)->next;
}

static void	convert_ss(t_deque *commands, t_node **node)
{
	t_node		*prev;
	t_command	command;

	prev = (*node)->prev;
	command = (*node)->content.command;
	if (command == sa && prev -> content.command == sb || \
		command == sb && prev -> content.command == sa)
	{
		disjoint_node(commands, prev);
		(*node)->content.command = ss;
	}
	*node = (*node)->next;
}
