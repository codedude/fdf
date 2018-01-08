/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:26:13 by vparis            #+#    #+#             */
/*   Updated: 2018/01/08 11:39:47 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"

static t_color	env_getcolor_alt(t_f64 z)
{
	t_color	c;

	if (z < -30.)
		c = C_DEEP;
	else if (z < 3.)
		c = C_WATER;
	else if (z < 90.)
		c = C_GRASS;
	else if (z < 250.)
		c = C_MOUNT;
	else
		c = C_SNOW;
	return (c);
}

static int		env_init_img(MATRIX_T ***z, t_vertex ***img, t_u64 obj_size[2])
{
	t_u64	i;

	if ((*img = (t_vertex **)malloc(sizeof(t_vertex *) * obj_size[0])) == NULL)
		return (ERROR);
	if ((*z = (MATRIX_T **)malloc(sizeof(MATRIX_T *) * HEIGHT)) == NULL)
		return (ERROR);
	i = 0;
	while (i < obj_size[0])
	{
		if (((*img)[i] = (t_vertex *)malloc(sizeof(t_vertex) * obj_size[1]))
			== NULL)
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		if (((*z)[i] = (MATRIX_T *)malloc(sizeof(MATRIX_T) * WIDTH))
			== NULL)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

static void		env_init_obj(t_vertex **obj, t_u64 obj_size[2])
{
	t_u64	i;
	t_u64	j;
	t_f64	w;
	t_f64	h;

	w = obj_size[1] / 2.;
	h = obj_size[0] / 2.;
	i = 0;
	while (i < obj_size[0])
	{
		j = 0;
		while (j < obj_size[1])
		{
			obj[i][j].vec3.x -= w;
			obj[i][j].vec3.y -= h;
			if (obj[i][j].c == -1)
				obj[i][j].c = env_getcolor_alt(obj[i][j].vec3.z);
			j++;
		}
		i++;
	}
}

int				env_init(t_env *env, int width, int height)
{
	env->screen.width = (t_u32)width;
	env->screen.height = (t_u32)height;
	vec3_set(&(env->camera), 0, 0, -100);
	vec3_set(&(env->ang), 0, 0, 120);
	env->demo = 1;
	env->effect = 0;
	env->altitude = 0.05;
	env_init_obj(env->obj, env->obj_size);
	if (env_init_img(&(env->img_z), &(env->img), env->obj_size) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

void			env_destroy(t_data *data)
{
	t_u64	i;

	i = 0;
	while (i < data->env.obj_size[0])
	{
		free(data->env.img[i]);
		free(data->env.obj[i]);
		i++;
	}
	free(data->env.img_z);
	free(data->env.img);
	free(data->env.obj);
	ft_mlx_destroy(&(data->mlx), MAIN_WIN);
	ft_mlx_exit();
}
