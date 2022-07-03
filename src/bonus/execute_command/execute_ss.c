/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:06:52 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:44:43 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_ss(t_deque *stack_a, t_deque *stack_b)
{
	execute_sa(stack_a);
	execute_sb(stack_b);
}
