/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:47:10 by vparis            #+#    #+#             */
/*   Updated: 2017/12/22 00:42:22 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"
#include "math.h"

static void	view_to_raster(t_vec3 *img, t_screen *scr)
{
	img->x = img->x / (img->z / scr->width) + (scr->width / 2.);
	img->y = img->y / (img->z / (scr->height * scr->width / scr->height))
			+ (scr->height / 2.);
}

static void bound_pixel(t_vec3 *obj)
{
	obj->x = floor(obj->x);
	obj->y = floor(obj->y);
}

int			compute_img(t_env *env)
{
	t_u64	i;
	t_u64	j;
	t_matrix	rot;
	t_vec3		ang;

	vec3_set(&(env->camera), 0, 0, -150);
	vec3_set(&ang, 20., 0., 110.);
	rot = matrix_rot(&ang);
	i = 0;
	while (i < env->obj_size[0])
	{
		j = 0;
		while (j < env->obj_size[1])
		{
			vec3_set(&(env->img[i][j].vec3), env->obj[i][j].vec3.x,
				env->obj[i][j].vec3.y, env->obj[i][j].vec3.z * 0.2);
			matrix_mul3_vec3(rot, &(env->img[i][j].vec3));
			vec3_sub(&(env->img[i][j].vec3), &(env->camera));
			view_to_raster(&(env->img[i][j].vec3), &(env->screen));
			bound_pixel(&(env->img[i][j].vec3));
			env->img[i][j].c = env->obj[i][j].c;
			j++;
		}
		i++;
	}
	matrix_del(MATRIX_33, &rot);
	return (SUCCESS);
}
