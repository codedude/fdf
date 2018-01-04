/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:38:30 by vparis            #+#    #+#             */
/*   Updated: 2018/01/04 17:44:25 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"
#include "ft_math.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"

int			is_inscreen(int x, int y, int width, int height)
{
	if (x < 0 || x >= width)
		return (0);
	if (y < 0 || y >= height)
		return (0);
	return (1);
}

t_color		interpo(t_color c1, t_color c2, double step)
{
	int	r;
	int	g;
	int	b;

	r = (1. - step) * ((c1 & C_RED) >> 16) + step * ((c2 & C_RED) >> 16);
	g = (1. - step) * ((c1 & C_GREEN) >> 8) + step * ((c2 & C_GREEN) >> 8);
	b = (1. - step) * (c1 & C_BLUE) + step * (c2 & C_BLUE);
	return (ft_mlx_getcolor(r, g, b));
}

static void	draw_line(t_mlx *mlx, int win, t_pixel *p1, t_pixel *p2)
{
	int		d[2];
	int		dir[2];
	int		e[2];
	t_color	*tmp;
	char	*addr;
	int endian;
	int size_line;
	int depth;
	double	x;
	double	y;

	x = (double)p1->x;
	y = (double)p1->y;
	depth = sizeof(t_color) * 8;
	size_line = sizeof(t_color) * WIDTH;
	endian = 0;
	addr = mlx_get_data_addr(mlx->win[win].img, &depth, &size_line, &endian);;
	d[0] = abs(p2->x - p1->x);
	d[1] = -abs(p2->y - p1->y);
	dir[0] = (p1->x < p2->x) ? 1 : -1;
	dir[1] = (p1->y < p2->y) ? 1 : -1;
	e[0] = d[0] + d[1];
	while (1)
	{
		if (is_inscreen(p1->x, p1->y, WIDTH, HEIGHT))
		{
			tmp = (t_color *)(addr + (p1->y * size_line + p1->x * 4));
			if (d[0] > -d[1])
				*tmp = interpo(p1->c, p2->c,
					fabs((double)p1->x - x) / (double)d[0]);
			else
				*tmp = interpo(p1->c, p2->c,
					fabs((double)p1->y - y) / (double)-d[1]);
		}
		if (p1->x == p2->x && p1->y == p2->y)
			break ;
		e[1] = 2 * e[0];
		if (e[1] >= d[1])
		{
			e[0] += d[1];
			p1->x += dir[0];
		}
		if (e[1] <= d[0])
		{
			e[0] += d[0];
			p1->y += dir[1];
		}
	}
}

int			is_bound(t_vec3 *p1, t_vec3 *p2, int width, int height)
{
	if (p1->x < -MARGE || p1->x > width + MARGE)
		return (0);
	if (p1->y < -MARGE || p1->y > height + MARGE)
		return (0);
	if (p2->x < -MARGE || p2->x > width + MARGE)
		return (0);
	if (p2->y < -MARGE || p2->y > height + MARGE)
		return (0);
	if (p1->z < ZERO_FLOAT || p2->z < ZERO_FLOAT)
		return (0);
	return (1);
}

void		ft_mlx_line(t_mlx *mlx, int win, t_vertex *src, t_vertex *dest)
{
	t_pixel	p1;
	t_pixel	p2;

	p1.x = (int)src->vec3.x;
	p1.y = (int)src->vec3.y;
	p1.c = src->c;
	p2.x = (int)dest->vec3.x;
	p2.y = (int)dest->vec3.y;
	p2.c = dest->c;
	if (is_bound(&(src->vec3), &(dest->vec3), WIDTH, HEIGHT) == 1)
		draw_line(mlx, win, &p1, &p2);
}
