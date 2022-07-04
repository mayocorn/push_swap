/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 00:44:12 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:02 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "console_out.h"

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
		write(STDOUT_FILENO, "sa\n", 3);
	if (command == sb)
		write(STDOUT_FILENO, "sb\n", 3);
	if (command == ss)
		write(STDOUT_FILENO, "ss\n", 3);
	if (command == pa)
		write(STDOUT_FILENO, "pa\n", 3);
	if (command == pb)
		write(STDOUT_FILENO, "pb\n", 3);
	if (command == ra)
		write(STDOUT_FILENO, "ra\n", 3);
	if (command == rb)
		write(STDOUT_FILENO, "rb\n", 3);
	if (command == rr)
		write(STDOUT_FILENO, "rr\n", 3);
	if (command == rra)
		write(STDOUT_FILENO, "rra\n", 4);
	if (command == rrb)
		write(STDOUT_FILENO, "rrb\n", 4);
	if (command == rrr)
		write(STDOUT_FILENO, "rrr\n", 4);
}
