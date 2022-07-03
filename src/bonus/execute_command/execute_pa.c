/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:26:45 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:48:40 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_pa(t_deque *stack_a, t_deque *stack_b)
{
	if (stack_b -> front != NULL)
		pushfront(stack_a, popfront(stack_b));
}
