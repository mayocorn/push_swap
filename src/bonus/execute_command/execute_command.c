/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 17:54:58 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:14 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	execute_command(t_command command, t_deque *stack_a, t_deque *stack_b)
{
	if (command == sa)
		execute_sa(stack_a);
	else if (command == sb)
		execute_sb(stack_b);
	else if (command == ss)
		execute_ss(stack_a, stack_b);
	else if (command == pa)
		execute_pa(stack_a, stack_b);
	else if (command == pb)
		execute_pb(stack_a, stack_b);
	else if (command == ra)
		execute_ra(stack_a);
	else if (command == rb)
		execute_rb(stack_b);
	else if (command == rr)
		execute_rr(stack_a, stack_b);
	else if (command == rra)
		execute_rra(stack_a);
	else if (command == rrb)
		execute_rrb(stack_b);
	else if (command == rrr)
		execute_rrr(stack_a, stack_b);
}
