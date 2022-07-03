/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 14:54:55 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 05:10:20 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus.h"

static void	check_array(size_t size, int *array);

int	main(int argc, char **argv)
{
	int		*array;
	size_t	size;

	size = argc - 1;
	if (size == 0)
		ft_exit(SUCCESS);
	array = convert_array_str_to_int(size, argv + 1);
	check_array(size, array);
	check_commands(size, array);
	return (0);
}

static void	check_array(size_t size, int *array)
{
	int	*sorted;

	sorted = duplicate_int_array(size, array);
	ft_mergesort(size, sorted);
	check_unique(size, sorted);
	free(sorted);
}

/*
static void	destructor(void) __attribute__((destructor));

static void	destructor(void)
{
	system("leaks -q checker");
}
*/
