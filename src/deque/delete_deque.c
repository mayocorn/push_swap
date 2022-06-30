/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_deque.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:22:34 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 05:22:49 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

void	delete_deque(t_deque *deque)
{
	t_node	*prev;
	t_node	*node;

	node = deque -> front;
	while (node != NULL)
	{
		prev = node;
		node = node -> next;
		free(prev);
	}
	free(deque);
}
