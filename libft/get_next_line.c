/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhill <dhill@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 14:05:53 by dhill             #+#    #+#             */
/*   Updated: 2017/10/23 21:21:49 by dhill            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		no_null(int	const fd, int bytes, char **line, char **file)
{
	if (bytes == 0 && file[fd] && file[fd][0])
	{
		*line = file[fd];
		file[fd] = NULL;
		return (1);
	}
	return (0);
}

int		no_nl(int const fd, int *bytes, char **line, char **file)
{
	int		nl;
	char	buff[BUFF_SIZE + 1];
	char	*tmp;

	nl = 0;
	while ((*bytes = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[*bytes] = '\0';
		if (ft_strchr(buff, '\n'))
		{
			while (buff[nl] != '\n')
				nl++;
			tmp = ft_strsub(buff, 0, nl);
			*line = ft_strjoin_null(file[fd], tmp);
			if (file[fd])
				free(file[fd]);
			free(tmp);
			file[fd] = ft_strdup(buff + nl + 1);
			return (1);
		}
		tmp = ft_strjoin_null(file[fd], buff);
		free(file[fd]);
		file[fd] = tmp;
	}
	return (0);
}

int		get_next_line(int const fd, char **line)
{
	int			nl;
	int			bytes;
	char		buff[BUFF_SIZE + 1];
	static char	*file[5000];
	char		*tmp_mv;

	nl = 0;
	bytes = 0;
	if (fd < 0 || fd > 4999 || !line || read(fd, buff, 0) < 0 || BUFF_SIZE < 0)
		return (-1);
	if (ft_strchr(file[fd], '\n'))
	{
		while (file[fd][nl] != '\n')
			nl++;
		*line = ft_strsub(file[fd], 0, nl);
		tmp_mv = ft_strdup(file[fd] + nl + 1);
		free(file[fd]);
		file[fd] = tmp_mv;
		return (1);
	}
	if (no_nl(fd, &bytes, line, file) == 1)
		return (1);
	if (no_null(fd, bytes, line, file))
		return (1);
	return (0);
}
