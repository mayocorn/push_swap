/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:46:04 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:14 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	execute_rra(t_deque *stack_a)
{
	if (stack_a -> back != NULL)
		pushfront(stack_a, popback(stack_a));
}
