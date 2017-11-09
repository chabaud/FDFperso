/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <schabaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 11:22:00 by schabaud          #+#    #+#             */
/*   Updated: 2016/08/19 15:54:03 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_read(int const fd, char **over)
{
	int			i;
	char		*tmp;

	tmp = NULL;
	i = 0;
	if (!(tmp = ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if (!(ft_memalloc(BUFF_SIZE + 1)))
		return (-1);
	if ((i = read(fd, tmp, BUFF_SIZE)) == -1)
		return (-1);
	if (!over[fd])
		over[fd] = ft_strdup(tmp);
	else
		over[fd] = ft_strjoin(over[fd], tmp);
	free(tmp);
	return (i);
}

static int		get_line_over(int const fd, char **over, char **line, int k)
{
	int			i;
	char		*tmp;

	i = 0;
	if (!*line)
		*line = ft_strnew(0);
	while (over[fd][i] != '\n' && over[fd][i])
		i++;
	if (i && i == (int)ft_strlen(over[fd]) && k > 0)
		return (-1);
	*line = ft_strsub(over[fd], 0, i);
	tmp = ft_strdup(over[fd]);
	free(over[fd]);
	over[fd] = ft_strsub(tmp, i + 1, ft_strlen(tmp));
	free(tmp);
	return (i);
}

int				get_next_line(int const fd, char **line)
{
	int			i;
	int			k;
	static char	*over[MAX_FD];

	if (!line || fd < MIN_FD || fd > MAX_FD)
		return (-1);
	if ((k = get_read(fd, over)) == -1)
		return (-1);
	while ((i = get_line_over(fd, over, line, k)) == -1)
		k = get_read(fd, over);
	if (!over[fd] && !k && !i)
		return (0);
	return (1);
}
