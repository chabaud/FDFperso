/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 15:15:59 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/18 15:39:08 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_color(char *str, t_object **object, int a, int k)
{
	int			i;
	char		*tmp;
	char		*color;

	i = -1;
	if (str[++i] == ',' && str[++i] == '0' && str[++i] == 'x')
	{
		tmp = ft_strsub(str, 3, ft_strlen(str));
		color = ft_convert_base(tmp, "0123456789ABCDEF", "0123456789");
		i = ft_atoi(color);
		free(color);
		free(str);
		free(tmp);
		return (i);
	}
	free(str);
	return (get_color_hauteur(object, a, k));
}

static int		get_elem_ex(char **tmp)
{
	int			i;
	static int	k = 0;

	i = 0;
	if (k == 0)
	{
		while (tmp[++i])
			;
		k = i;
	}
	else
	{
		while (tmp[++i])
			;
		if (k != i)
		{
			ft_putstr("Map error\n");
			exit(0);
		}
	}
	return (i);
}

static void		get_elem(char *line, t_object **object, int k)
{
	int			i;
	int			j;
	char		**tmp;
	char		*swp;

	swp = ft_strnew(0);
	tmp = ft_strsplit(line, ' ');
	i = get_elem_ex(tmp);
	object[k] = new_line_obj(i + 1);
	i = -1;
	while (tmp[++i])
	{
		j = 0;
		object[k][i].e = 1;
		object[k][i].x = i;
		object[k][i].y = k;
		object[k][i].z = ft_atoi(tmp[i]);
		while (ft_isdigit(tmp[i][j]))
			++j;
		swp = ft_strsub(tmp[i], j, ft_strlen(tmp[i]));
		object[k][i].color = get_color(swp, object, i, k);
	}
	object[k][i].e = 0;
	object[k][i].color = 0x00FF0000;
	free(tmp);
}

static int		get_nbr_line(char *file)
{
	int			i;
	int			fd;
	int			k;
	char		*tmp;

	k = -1;
	tmp = (char*)ft_memalloc(sizeof(tmp) * 1001);
	fd = open(file, O_RDONLY);
	while (read(fd, tmp, 1000))
	{
		i = -1;
		while (tmp[++i])
			if (tmp[i] == '\n')
				++k;
		ft_bzero(tmp, 1000);
	}
	free(tmp);
	close(fd);
	if (k < 0)
	{
		ft_putstr("Map error\n");
		exit(0);
	}
	return (k);
}

t_object		**get_object(char *file)
{
	int			i;
	int			fd;
	char		*line;
	t_object	**object;

	i = get_nbr_line(file) + 1;
	object = (t_object**)malloc(sizeof(t_object) * i);
	object[i] = NULL;
	i = -1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
		get_elem(line, object, ++i);
	free(line);
	return (object);
}
