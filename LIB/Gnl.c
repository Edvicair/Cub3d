/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edvicair <edvicair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:07:38 by edvicair          #+#    #+#             */
/*   Updated: 2023/03/04 02:35:45 by edvicair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static	int	ft_check(const char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static	char	*ft_fill_line(char **str, char *line)
{
	char	*tmp;

	if (*str == NULL || **str == '\0')
	{
		free(*str);
		*str = NULL;
		return (line);
	}
	if (ft_check(*str) == 0 && *str[ft_check(*str)] != '\n')
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
	{
		line = ft_substr(*str, 0, (ft_check(*str)));
		tmp = *str;
		*str = ft_strdup(*str + (ft_check(*str) + 1));
		free(tmp);
	}
	return (line);
}

static	int	ft_read(int *ret, int fd, char **buff)
{
	*ret = read(fd, *buff, 1);
	if (*ret == 0)
		return (0);
	if (*ret == -1)
	{
		free(*buff);
		*buff = NULL;
	}
	return (*ret);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*str;
	char		*line;
	int			ret;

	line = NULL;
	if (fd < 0 || 1 <= 0)
		return (NULL);
	buff = (char *)malloc(sizeof(char) * (1 + 1));
	if (!buff)
		return (NULL);
	while (!(ft_strchr(str, '\n')) && (ft_read(&ret, fd, &buff)))
	{
		if (ret == -1)
			return (NULL);
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	line = ft_fill_line(&str, line);
	return (line);
}
