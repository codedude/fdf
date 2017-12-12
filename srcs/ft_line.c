/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 22:38:30 by vparis            #+#    #+#             */
/*   Updated: 2017/12/12 23:08:48 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"

void	ft_mlx_line(t_mlx *mlx, int win, t_pixel *src, t_pixel *dest)
{
	int		dx;
	int		dy;
	t_pixel	pix;

	dx = dest->x - src->x;
	dy = dest->y - src->y;
	pix.x = src->x;
	pix.y = src->y;
	pix.c = src->c;
	while (pix.x <= dest->y)
	{
		pix.y = src->y + dy * (pix.x - src->x) / dx;
		ft_mlx_pixel(mlx, win, &pix);
		pix.x += 1;
	}
}
