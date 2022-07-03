/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 05:38:10 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:49:40 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_pb(t_deque *stack_a, t_deque *stack_b)
{
	if (stack_a -> front != NULL)
		pushfront(stack_b, popfront(stack_a));
}
