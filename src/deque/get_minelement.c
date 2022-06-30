/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minelement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 05:31:18 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/01 05:31:27 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/deque.h"

int	get_minelement(t_deque *deque)
{
	t_node	*node;
	int		min_element;

	node = deque -> front;
	min_element = INT_MAX;
	while (node != NULL)
	{
		min_element = ft_min(min_element, node -> content.number);
		node = node -> next;
	}
	return (min_element);
}
