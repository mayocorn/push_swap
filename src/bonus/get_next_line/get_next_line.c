/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayocorn <twitter@mayocornsuki>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 15:19:15 by mayocorn          #+#    #+#             */
/*   Updated: 2022/07/04 17:14:39 by mayocorn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/get_next_line.h"

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	s1_size;
	size_t	s2_size;
	size_t	res_size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	res_size = s1_size + s2_size;
	res = (char *)malloc((res_size + 1) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, res_size + 1);
	ft_strlcpy(res + s1_size, s2, s2_size + 1);
	return (res);
}

static int	ft_gnl_exit(char **s, char *buf)
{
	free(*s);
	*s = NULL;
	free(buf);
	return (ERROR);
}

static int	ft_gnl_read(int fd, char **s)
{
	char	*buf;
	char	*new;
	char	*end;
	ssize_t	read_size;

	end = ft_strchr(s[fd], LF);
	read_size = BUFFER_SIZE;
	while (end == NULL && read_size == BUFFER_SIZE)
	{
		buf = (char *)malloc(((size_t)BUFFER_SIZE + 1) * sizeof(*buf));
		if (buf == NULL)
			return (ft_gnl_exit(&s[fd], buf));
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
			return (ft_gnl_exit(&s[fd], buf));
		buf[read_size] = '\0';
		new = ft_strjoin(s[fd], buf);
		if (new == NULL)
			return (ft_gnl_exit(&s[fd], buf));
		free (s[fd]);
		s[fd] = new;
		end = ft_strchr(buf, LF);
		free(buf);
	}
	return (SUCCESS);
}

static char	*ft_gnl_trim(int fd, char **s)
{
	char	*res;
	char	*new;
	char	*end;

	res = NULL;
	new = NULL;
	end = ft_strchr(s[fd], LF);
	if (end == NULL && *s[fd])
		res = ft_strdup(s[fd]);
	else if (end != NULL)
	{
		res = ft_substr(s[fd], 0, end - s[fd] + 1);
		if (res != NULL && *(end + 1))
			new = ft_strdup(end + 1);
	}
	free (s[fd]);
	s[fd] = new;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*s[FOPEN_MAX];

	if (fd < 0 || FOPEN_MAX <= fd || \
		BUFFER_SIZE <= 0 || SSIZE_MAX < BUFFER_SIZE)
		return (NULL);
	if (s[fd] == NULL)
	{
		s[fd] = malloc(sizeof(**s));
		if (s[fd] == NULL)
			return (NULL);
		*s[fd] = '\0';
	}
	if (ft_gnl_read(fd, s) == ERROR)
		return (NULL);
	return (ft_gnl_trim(fd, s));
}
