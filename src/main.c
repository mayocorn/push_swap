/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:09:40 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/02 16:02:38 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/main.h"

int	main(int argc, char **argv)
{
	int		*array_original;
	int		*array_sorted;
	int		*array_compressed;
	size_t	array_size;
	t_deque	*commands;

	array_size = argc - 1;
	if (array_size == 0)
		ft_exit(SUCCESS);
	array_original = convert_array_str_to_int(array_size, argv + 1);
	array_sorted = duplicate_int_array(array_size, array_original);
	ft_mergesort(array_size, array_sorted);
	check_unique(array_size, array_sorted);
	array_compressed = coordinate_compression \
						(array_size, &array_original, &array_sorted);
	commands = pushswap(array_size, &array_compressed);
	optimize(commands);
	print_commands(commands);
	delete_deque(commands);
	return (0);
}

/*
static void	destructor(void) __attribute__((destructor));

static void	destructor(void)
{
	system("leaks -q push_swap");
}
*/
