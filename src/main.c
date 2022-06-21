/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:09:40 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/21 15:26:03 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/convert_array_stoi.h"
# include "../include/libft.h"
# include "../include/mergesort.h"
# include "../include/utils.h"
# include "../include/array.h"
# include "../include/coordinate_compression.h"
# include "../include/command.h"
# include <stdio.h>
# include <stdbool.h>

int main(int argc, char **argv)
{
	int				*array_original;
	int				*array_sorted;
	int				*array_compressed;
	// t_command_node	**command_list;
	size_t			array_size;
	
	array_size = argc - 1;
	if (array_size == 0)	
		ft_exit(SUCCESS);
	array_original = convert_array_str_to_int(array_size, argv + 1);
	array_sorted = duplicate_int_array(array_size, array_original);
	mergesort(array_size, array_sorted);
	check_unique(array_size, array_sorted);
	array_compressed = coordinate_compression(array_size, array_original, array_sorted);
	// command_list = push_swap(array_size, array_compressed);
	// optimize_command(command_list);
	// 結果を出力
	
	while(array_size--)printf("%d\n", *array_compressed++);
	printf("\n");
}