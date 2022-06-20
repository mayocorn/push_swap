/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_array_stoi.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 20:57:08 by mayocorn          #+#    #+#             */
/*   Updated: 2022/06/20 19:43:23 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../include/convert_array_stoi.h"

static int	stoi_or_exit(char *str);
static int	getsign_or_exit(char c);
static int	stoi_pos(char *str);
static int	stoi_neg(char *str);

int	*convert_array_str_to_int(size_t array_size, char **src)
{
	int	*dst;
	int	*dst_head;

	dst = malloc_and_checknull(array_size * sizeof(int));
	dst_head = dst;
	while (array_size--)
	{
		*dst = stoi_or_exit(*src);
		dst++;
		src++;
	}
	return (dst_head);
}

static int	stoi_or_exit(char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = getsign_or_exit(*str);
	str++;
	if (sign == POSITIVE)
		res = stoi_pos(str);
	else
		res = stoi_neg(str);
	return (res);
}

static int	getsign_or_exit(char c)
{
	if (ft_isdigit(c))
		return (POSITIVE);
	if (c == '-')
		return (NEGATIVE);
	ft_exit(ERROR);
}

static int	stoi_pos(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit(ERROR);
		if (res != 0 && INT_MAX / res < 10)
			ft_exit(ERROR);
		res *= 10;
		if (INT_MAX - res < *str - '0')
			ft_exit(ERROR);
		res += *str - '0';
		str++;
	}
	return (res);
}

static int	stoi_neg(char *str)
{
	int	res;

	res = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_exit(ERROR);
		if (res != 0 && INT_MIN / res < 10)
			ft_exit(ERROR);
		res *= 10;
		if (INT_MIN - res > -(*str - '0'))
			ft_exit(ERROR);
		res -= *str - '0';
		str++;
	}
	return (res);
}
