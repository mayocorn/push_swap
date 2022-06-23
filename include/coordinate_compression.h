/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_compression.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:20:50 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/23 18:30:47 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORDINATE_COMPRESSION_H
# define COORDINATE_COMPRESSION_H
# include <stdlib.h>
# include "utils.h"

int	*coordinate_compression(size_t size, int **original, int **sorted);
#endif