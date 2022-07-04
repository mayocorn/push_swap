/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_by_commands.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:32:56 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 07:27:47 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	pushswap_by_commands(t_deque *commands, \
								t_deque *stack_a, t_deque *stack_b)
{
	t_command	command;

	while (commands -> size)
	{
		command = commands -> front -> content.command;
		free(popfront(commands));
		execute_command(command, stack_a, stack_b);
	}
}
