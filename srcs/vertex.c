/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:22:24 by vparis            #+#    #+#             */
/*   Updated: 2017/12/18 00:17:57 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "matrix.h"

void			vec3_set(t_vec3 *pt, t_f64 x, t_f64 y, t_f64 z)
{
	pt->x = x;
	pt->y = y;
	pt->z = z;
}

void			vertex_set(t_vertex *pt, t_f64 x, t_f64 y, t_f64 z, t_color c)
{
	pt->vec3.x = x;
	pt->vec3.y = y;
	pt->vec3.z = z;
	pt->c = c;
}
