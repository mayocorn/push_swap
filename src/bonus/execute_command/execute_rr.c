/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:42:56 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:29:14 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

void	execute_rr(t_deque *stack_a, t_deque *stack_b)
{
	execute_ra(stack_a);
	execute_rb(stack_b);
}
