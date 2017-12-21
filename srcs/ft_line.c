/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:38:30 by vparis            #+#    #+#             */
/*   Updated: 2017/12/21 23:46:46 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"


static void	draw_line(void *mlx, void *win, t_pixel *p1, t_pixel *p2)
{
	int		d[2];
	int		dir[2];
	int		e[2];

	d[0] = abs(p2->x - p1->x);
	d[1] = -abs(p2->y - p1->y);
	dir[0] = (p1->x < p2->x) ? 1 : -1;
	dir[1] = (p1->y < p2->y) ? 1 : -1;
	e[0] = d[0] + d[1];
	while (1)
	{
		mlx_pixel_put(mlx, win, p1->x, p1->y, p1->c);
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
	draw_line(mlx->mlx, mlx->win[win].win, &p1, &p2);
}
