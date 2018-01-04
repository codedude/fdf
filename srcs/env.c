/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:26:13 by vparis            #+#    #+#             */
/*   Updated: 2018/01/04 16:37:59 by vparis           ###   ########.fr       */
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

	if (z < -10)
		c = C_DEEP;
	else if (z < 0.1)
		c = C_WATER;
	else if (z < 8)
		c = C_GRASS;
	else if (z < 20)
		c = C_MOUNT;
	else
		c = C_SNOW;
	return (c);
}

static int		env_init_img(t_vertex ***img, t_u64 obj_size[2])
{
	t_u64	i;

	if ((*img = (t_vertex **)malloc(sizeof(t_vertex *) * obj_size[0])) == NULL)
		return (ERROR);
	i = 0;
	while (i < obj_size[0])
	{
		if (((*img)[i] = (t_vertex *)malloc(sizeof(t_vertex) * obj_size[1]))
			== NULL)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

void			env_init_obj(t_vertex **obj, t_u64 obj_size[2])
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
	vec3_set(&(env->world), 0, 0, 0);
	vec3_set(&(env->camera), 0, 0, -100);
	vec3_set(&(env->ang), 0, 0, 0);
	env_init_obj(env->obj, env->obj_size);
	if (env_init_img(&(env->img), env->obj_size) == ERROR)
		return (ERROR);
	return (SUCCESS);
}
