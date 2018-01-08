/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:38:30 by vparis            #+#    #+#             */
/*   Updated: 2018/01/08 13:57:06 by vparis           ###   ########.fr       */
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

static int		is_inscreen(int x, int y, int width, int height)
{
	if (x < 0 || x >= width)
		return (0);
	if (y < 0 || y >= height)
		return (0);
	return (1);
}

static int		is_bound(t_vec3 *p1, t_vec3 *p2, int width, int height)
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

static t_color	interpo(t_color c1, t_color c2, double step)
{
	int	r;
	int	g;
	int	b;

	r = (1. - step) * ((c1 & C_RED) >> 16) + step * ((c2 & C_RED) >> 16);
	g = (1. - step) * ((c1 & C_GREEN) >> 8) + step * ((c2 & C_GREEN) >> 8);
	b = (1. - step) * (c1 & C_BLUE) + step * (c2 & C_BLUE);
	return (0 | (r << 16) | (g << 8) | b);
}

static void		draw_line(MATRIX_T **z, t_mlx *mlx, int win,
						t_vertex *p1, t_vertex *p2)
{
	int		d[2];
	int		dir[2];
	int		e[2];
	t_color	*tmp;
	double	x;
	double	y;
	double	len;

	x = (double)p1->vec3.x;
	y = (double)p1->vec3.y;
	d[0] = (int)fabs(p2->vec3.x - p1->vec3.x);
	d[1] = (int)-fabs(p2->vec3.y - p1->vec3.y);
	dir[0] = (p1->vec3.x < p2->vec3.x) ? 1 : -1;
	dir[1] = (p1->vec3.y < p2->vec3.y) ? 1 : -1;
	e[0] = d[0] + d[1];
	while (1)
	{
		if (is_inscreen((int)p1->vec3.x, (int)p1->vec3.y, WIDTH, HEIGHT))
		{
			len = vec3_len_ns(&(p1->vec3));
			if (len < z[(int)p1->vec3.y][(int)p1->vec3.x])
			{
				z[(int)p1->vec3.y][(int)p1->vec3.x] = len;
				tmp = (t_color *)(mlx->win[win].img + (int)
					(p1->vec3.y * (mlx->win[win].width * 4)
					+ (int)p1->vec3.x * 4));
				if (d[0] != 0 && (d[0] > -d[1]))
					*tmp = interpo(p1->c, p2->c,
						fabs((double)p1->vec3.x - x) / (double)d[0]);
				else if (d[1] != 0)
					*tmp = interpo(p1->c, p2->c,
						fabs((double)p1->vec3.y - y) / (double)-d[1]);
			}
		}
		if (p1->vec3.x == p2->vec3.x && p1->vec3.y == p2->vec3.y)
			break ;
		e[1] = 2 * e[0];
		if (e[1] >= d[1])
		{
			e[0] += d[1];
			p1->vec3.x += dir[0];
		}
		if (e[1] <= d[0])
		{
			e[0] += d[0];
			p1->vec3.y += dir[1];
		}
	}
}

void			ft_mlx_line(MATRIX_T **z, t_mlx *mlx, int win,
							t_vertex *src, t_vertex *dest)
{
	t_vertex	p1;
	t_vertex	p2;

	if (is_bound(&(src->vec3), &(dest->vec3), WIDTH, HEIGHT) == 1)
	{
		p1.vec3.x = floor(src->vec3.x);
		p1.vec3.y = floor(src->vec3.y);
		p1.vec3.z = src->vec3.z;
		p1.c = src->c;
		p2.vec3.x = floor(dest->vec3.x);
		p2.vec3.y = floor(dest->vec3.y);
		p2.vec3.z = dest->vec3.z;
		p2.c = dest->c;
		draw_line(z, mlx, win, &p1, &p2);
	}
}
