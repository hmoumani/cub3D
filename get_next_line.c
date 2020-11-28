/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoumani <hmoumani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 16:38:49 by hmoumani          #+#    #+#             */
/*   Updated: 2019/11/18 17:09:45 by hmoumani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

static	int		ft_double_free(char **p1, char **p2, int ret)
{
	free(*p1);
	free(*p2);
	return (ret);
}

static	int		ft_lastline(int ret, char **temp)
{
	if (!ret && *temp[0] == '\n')
	{
		free(*temp);
		*temp = NULL;
		return (1);
	}
	free(*temp);
	*temp = NULL;
	return (0);
}

static	int		ft_printline(int fd, char **rest, char **line, char *temp)
{
	char	*p;
	char	*pfree;
	int		ret;

	while ((ret = read(fd, temp, BUFFER_SIZE)))
	{
		temp[ret] = '\0';
		if ((p = ft_strchr(temp, '\n')) != NULL)
		{
			*p = '\0';
			pfree = *line;
			if (!(*line = ft_strjoin(*line, temp)))
				return (ft_double_free(&temp, NULL, -1));
			free(pfree);
			pfree = rest[fd];
			if (!(rest[fd] = ft_strdup(p + 1)))
				return (ft_double_free(&temp, NULL, -1));
			return (ft_double_free(&pfree, &temp, 1));
		}
		pfree = *line;
		if (!(*line = ft_strjoin(*line, temp)))
			return (ft_double_free(&temp, NULL, -1));
		free(pfree);
	}
	return (ft_lastline(ret, &temp));
}

static	int		ft_handlerest(char **rest, char **line, char *temp, int fd)
{
	char	*pfree;
	char	*p;

	if (!rest[fd])
		return (0);
	if ((p = ft_strchr(rest[fd], '\n')) != NULL)
	{
		*p = '\0';
		pfree = *line;
		if (!(*line = ft_strjoin(*line, rest[fd])))
			return (ft_double_free(&temp, NULL, -1));
		free(pfree);
		pfree = rest[fd];
		if (!(rest[fd] = ft_strdup(p + 1)))
			return (ft_double_free(&temp, NULL, -1));
		return (ft_double_free(&pfree, &temp, 1));
	}
	pfree = *line;
	*line = ft_strjoin(*line, rest[fd]);
	free(pfree);
	pfree = NULL;
	free(rest[fd]);
	rest[fd] = NULL;
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char *rest[OPEN_MAX];
	char		*temp;
	int			ret;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!(temp = malloc((BUFFER_SIZE + 1) * sizeof(char))))
		ft_error("malloc failed");
	temp[0] = 0;
	if (!(*line = ft_strdup("")))
		return (ft_double_free(&temp, NULL, -1));
	if ((ret = ft_handlerest(rest, line, temp, fd)))
		return (ret);
	return (ft_printline(fd, rest, line, temp));
}
