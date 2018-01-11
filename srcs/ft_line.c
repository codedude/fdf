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

static void		next_step(int d[2], int dir[2], int e[2], t_vertex *p1)
{
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

static t_color	new_value(int d[2], double xyl[3], t_vertex *p1, t_vertex *p2)
{
	if (d[0] != 0 && (d[0] > -d[1]))
	{
		return (interpo(p1->c, p2->c,
			fabs((double)p1->vec3.x - xyl[0]) / (double)d[0]));
	}
	else if (d[1] != 0)
	{
		return (interpo(p1->c, p2->c,
			fabs((double)p1->vec3.y - xyl[1]) / (double)-d[1]));
	}
	return (p1->c);
}

static void		draw_line(MATRIX_T **z, char *img, t_vertex *p1, t_vertex *p2)
{
	int		d[2];
	int		dir[2];
	int		e[2];
	t_color	*tmp;
	double	xyl[3];

	xyl[0] = (double)p1->vec3.x;
	xyl[1] = (double)p1->vec3.y;
	init_param(d, dir, p1, p2);
	e[0] = d[0] + d[1];
	while (1)
	{
		if (is_inscreen((int)p1->vec3.x, (int)p1->vec3.y, WIDTH, HEIGHT))
			if ((xyl[2] = vec3_len_ns(&(p1->vec3)))
				< z[(int)p1->vec3.y][(int)p1->vec3.x])
			{
				z[(int)p1->vec3.y][(int)p1->vec3.x] = xyl[2];
				tmp = (t_color *)(img + (int)(p1->vec3.y * (WIDTH * 4)
					+ (int)p1->vec3.x * 4));
				*tmp = new_value(d, xyl, p1, p2);
			}
		if (p1->vec3.x == p2->vec3.x && p1->vec3.y == p2->vec3.y)
			break ;
		next_step(d, dir, e, p1);
	}
}

void			ft_mlx_line(t_env *env, t_mlx *mlx, t_vertex *src,
							t_vertex *dest)
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
		draw_line(env->img_z, mlx->win[MAIN_WIN].img, &p1, &p2);
	}
}
