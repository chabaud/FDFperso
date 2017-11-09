/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schabaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 15:45:49 by schabaud          #+#    #+#             */
/*   Updated: 2016/09/14 13:41:44 by schabaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

t_object	*new_line_obj(int k)
{
	int			i;
	t_object	*object;

	i = -1;
	object = (t_object*)malloc(sizeof(t_object) * k);
	while (++i < k)
	{
		object[i].e = 0;
		object[i].x = 0;
		object[i].y = 0;
		object[i].z = 0;
		object[i].color = 0x00FFFFFF;
	}
	return (object);
}

static void	line_dx(t_all all, t_p p, int color)
{
	int		i;
	int		tmp;

	i = 0;
	mlx_pixel_put(all.mlx, all.win, p.x, p.y, color);
	tmp = p.dx / 2;
	while (++i <= p.dx)
	{
		p.x += p.xinc;
		tmp += p.dy;
		if (tmp >= p.dx)
		{
			tmp -= p.dx;
			p.y += p.yinc;
		}
		mlx_pixel_put(all.mlx, all.win, p.x, p.y, color);
	}
}

static void	line_dy(t_all all, t_p p, int color)
{
	int		i;
	int		tmp;

	i = 0;
	mlx_pixel_put(all.mlx, all.win, p.x, p.y, color);
	tmp = p.dy / 2;
	while (++i <= p.dy)
	{
		p.y += p.yinc;
		tmp += p.dx;
		if (tmp >= p.dy)
		{
			tmp -= p.dy;
			p.x += p.xinc;
		}
		mlx_pixel_put(all.mlx, all.win, p.x, p.y, color);
	}
}

void		line_tracer(t_all all, t_object pointa, t_object pointb)
{
	t_p		p;
	t_rot	ra;
	t_rot	rb;

	ra.x = (pointa.x - all.pos.refx) * all.pos.zoom;
	ra.y = (pointa.y - all.pos.refy) * all.pos.zoom;
	ra.z = (pointa.z - all.pos.refz) * all.pos.zoom_z;
	rb.x = (pointb.x - all.pos.refx) * all.pos.zoom;
	rb.y = (pointb.y - all.pos.refy) * all.pos.zoom;
	rb.z = (pointb.z - all.pos.refz) * all.pos.zoom_z;
	ra = rotate(ra, all.pos.a, all.pos.b, all.pos.c);
	rb = rotate(rb, all.pos.a, all.pos.b, all.pos.c);
	p.x = ra.x;
	p.y = ra.y;
	p.dx = rb.x - p.x;
	p.dy = rb.y - p.y;
	p.x += all.pos.x;
	p.y += all.pos.y;
	p.xinc = (p.dx > 0) ? 1 : -1;
	p.yinc = (p.dy > 0) ? 1 : -1;
	p.dx = abs(p.dx);
	p.dy = abs(p.dy);
	if (p.dx > p.dy)
		return (line_dx(all, p, pointa.color));
	return (line_dy(all, p, pointa.color));
}
