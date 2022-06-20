/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:08:43 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/20 20:41:28 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_cp;
	const char	*src_cp;

	dest_cp = (char *)dest;
	src_cp = (const char *)src;
	if (dest == src)
		return (dest);
	while (n--)
	{
		if (dest < src)
			*(dest_cp++) = *(src_cp++);
		else
			*(dest_cp + n) = *(src_cp + n);
	}
	return (dest);
}