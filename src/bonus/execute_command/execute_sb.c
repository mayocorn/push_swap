/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_sb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 18:05:41 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:37:04 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/bonus.h"

void	execute_sb(t_deque *stack_b)
{
	t_node	*b_first;
	t_node	*b_second;
	int		tmp;

	b_first = stack_b -> front;
	if (b_first == NULL)
		return ;
	b_second = b_first -> next;
	if (b_second == NULL)
		return ;
	tmp = b_second -> content.number;
	b_second -> content.number = b_first;
	b_first -> content.number = tmp;
}
