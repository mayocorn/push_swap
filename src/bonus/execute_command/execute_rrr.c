/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:54:51 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:57:24 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_rrr(t_deque *stack_a, t_deque *stack_b)
{
	execute_rra(stack_a);
	execute_rrb(stack_b);
}
