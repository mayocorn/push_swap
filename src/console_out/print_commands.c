/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:44:12 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/24 00:53:19 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/console_out.h"

static void	print_command(t_command command);

void	print_commands(t_deque *commands)
{
	t_node		*node;
	t_command	command;

	node = commands -> front;
	while (node != NULL)
	{
		command = node -> content.command;
		print_command(command);
		node = node -> next;
	}
}

static void	print_command(t_command command)
{
	if (command == sa)
		write(1, "sa\n", 3);
	if (command == sb)
		write(1, "sb\n", 3);
	if (command == ss)
		write(1, "ss\n", 3);
	if (command == pa)
		write(1, "pa\n", 3);
	if (command == pb)
		write(1, "pb\n", 3);
	if (command == ra)
		write(1, "ra\n", 3);
	if (command == rb)
		write(1, "rb\n", 3);
	if (command == rr)
		write(1, "rr\n", 3);
	if (command == rra)
		write(1, "rra\n", 4);
	if (command == rrb)
		write(1, "rrb\n", 4);
	if (command == rrr)
		write(1, "rrr\n", 4);
}
