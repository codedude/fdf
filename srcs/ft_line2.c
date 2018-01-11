/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:04:16 by vparis            #+#    #+#             */
/*   Updated: 2018/01/11 12:06:28 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "ft_math.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"

int		is_inscreen(int x, int y, int width, int height)
{
	if (x < 0 || x >= width)
		return (0);
	if (y < 0 || y >= height)
		return (0);
	return (1);
}

int		is_bound(t_vec3 *p1, t_vec3 *p2, int width, int height)
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

void	init_param(int d[2], int dir[2], t_vertex *p1, t_vertex *p2)
{
	d[0] = (int)fabs(p2->vec3.x - p1->vec3.x);
	d[1] = (int)-fabs(p2->vec3.y - p1->vec3.y);
	dir[0] = (p1->vec3.x < p2->vec3.x) ? 1 : -1;
	dir[1] = (p1->vec3.y < p2->vec3.y) ? 1 : -1;
}
