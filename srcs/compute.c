/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:47:10 by vparis            #+#    #+#             */
/*   Updated: 2018/01/11 14:10:08 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"
#include "ft_math.h"

static void		view_to_raster(t_vec3 *img, t_screen *scr)
{
	if (img->z > ZERO_FLOAT)
	{
		img->x = img->x / (img->z / scr->width) + (scr->width / 2.);
		img->y = img->y / (img->z
		/ (scr->height * scr->width / scr->height)) + (scr->height / 2.);
	}
}

int				compute_img(t_env *env)
{
	t_u64		i;
	t_u64		j;
	t_matrix	rot;

	rot = matrix_rot(&(env->ang), env->view);
	i = 0;
	while (i < env->obj_size[0])
	{
		j = 0;
		while (j < env->obj_size[1])
		{
			vec3_set(&(env->img[i][j].vec3), env->obj[i][j].vec3.x,
				env->obj[i][j].vec3.y, env->obj[i][j].vec3.z * env->altitude);
			matrix_mul3_vec3(rot, &(env->img[i][j].vec3));
			vec3_sub(&(env->img[i][j].vec3), &(env->camera));
			view_to_raster(&(env->img[i][j].vec3), &(env->screen));
			env->img[i][j].c = env->obj[i][j].c;
			j++;
		}
		i++;
	}
	matrix_del(MATRIX_33, &rot);
	return (SUCCESS);
}

static void		apply_effect(char *img)
{
	size_t	i;
	int		r;
	int		g;
	int		b;
	t_color	*pix;

	i = 0;
	pix = (t_color *)img;
	while (i < WIDTH * HEIGHT)
	{
		if (pix[i] > 0)
		{
			r = ((pix[i] & C_RED) >> 17);
			g = ((pix[i] & C_GREEN) >> 9);
			b = (pix[i] & C_BLUE) >> 1;
			pix[i] = 0 | (r << 16) | (g << 8) | b;
		}
		i++;
	}
}

void			clean_maps(t_data *data)
{
	size_t	i;

	if (data->env.effect)
		apply_effect(data->mlx.win[MAIN_WIN].img);
	else
		ft_bzero((void *)data->mlx.win[MAIN_WIN].img, 4 * WIDTH * HEIGHT);
	i = 0;
	while (i < HEIGHT)
	{
		ft_memset((void *)data->env.img_z[i], 127, sizeof(MATRIX_T) * WIDTH);
		i++;
	}
}

void			draw_img(t_data *data)
{
	t_u32	i;
	t_u32	j;

	i = 0;
	while (i < data->env.obj_size[0])
	{
		j = 0;
		while (j < data->env.obj_size[1])
		{
			if (i + 1 < data->env.obj_size[0])
				ft_mlx_line(&(data->env), &(data->mlx),
					&(data->env.img[i][j]), &(data->env.img[i + 1][j]));
			if (j + 1 < data->env.obj_size[1])
				ft_mlx_line(&(data->env), &(data->mlx),
					&(data->env.img[i][j]), &(data->env.img[i][j + 1]));
			j++;
		}
		i++;
	}
}
