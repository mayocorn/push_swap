/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rrb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:54:25 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:55:00 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_rrb(t_deque *stack_b)
{
	if (stack_b -> back != NULL)
		pushfront(stack_b, popback(stack_b));
}
