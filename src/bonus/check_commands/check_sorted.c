/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 06:09:46 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 07:30:32 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	check_sorted(t_deque *stack_a, t_deque *stack_b)
{
	bool	ok;
	t_node	*now;
	t_node	*next;

	ok = true;
	now = stack_a -> front;
	while (now != NULL)
	{
		next = now -> next;
		if (next != NULL && now -> content.number > next -> content.number)
			ok = false;
		now = next;
	}
	if (stack_b -> size)
		ok = false;
	if (ok)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}
