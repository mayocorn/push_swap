/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 20:45:42 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/05 01:25:06 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pushswap.h"

static void	create_initial_deque(size_t size, int *array, t_deque *elements);
static void	sort_size3(int *array);

t_deque	*pushswap(size_t size, int **array)
{
	t_deque	*commands;
	t_deque	*elements;

	if (size == 3)
		sort_size3(*array);
	commands = create_deque();
	elements = create_deque();
	create_initial_deque(size, *array, elements);
	free_and_setnull((void **)array);
	sort_a_start(elements, commands);
	return (commands);
}

static void	create_initial_deque(size_t size, int *array, t_deque *elements)
{
	while (size--)
	{
		pushback(elements, create_number_node(*array));
		array++;
	}
}

static void	sort_size3(int *array)
{
	int	a;
	int	b;
	int	c;

	a = array[0];
	b = array[1];
	c = array[2];
	if (a == 0 && b == 2 && c == 1)
		write(STDOUT_FILENO, "rra\nsa\n", 7);
	if (a == 1 && b == 0 && c == 2)
		write(STDOUT_FILENO, "sa\n", 3);
	if (a == 1 && b == 2 && c == 0)
		write(STDOUT_FILENO, "rra\n", 4);
	if (a == 2 && b == 0 && c == 1)
		write(STDOUT_FILENO, "ra\n", 3);
	if (a == 2 && b == 1 && c == 0)
		write(STDOUT_FILENO, "ra\nsa\n", 6);
	ft_exit(SUCCESS);
}
