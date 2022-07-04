/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:00:22 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 07:16:41 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_sa(t_deque *stack_a)
{
	t_node	*a_first;
	t_node	*a_second;
	int		tmp;

	a_first = stack_a -> front;
	if (a_first == NULL)
		return ;
	a_second = a_first -> next;
	if (a_second == NULL)
		return ;
	tmp = a_second -> content.number;
	a_second -> content.number = a_first -> content.number;
	a_first -> content.number = tmp;
}
