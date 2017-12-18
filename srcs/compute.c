/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:47:10 by vparis            #+#    #+#             */
/*   Updated: 2017/12/18 15:49:11 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"
#include "math.h"

# define PIXEL_WIDTH 10
# define PIXEL_HEIGHT 10

static void	perspective_divide(t_vec3 *obj, t_vec3 *img)
{
	img->x = obj->x * 20;
	img->y = obj->y * 20;
}

static void screen_to_raster(t_vec3 *obj, t_canvas *can, t_screen *scr)
{
	obj->x = ((obj->x + can->width / 2.) / can->width) * scr->width;
	obj->y = ((obj->y + can->height / 2.) / can->height) * scr->height;
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

	i = 0;
	while (i < env->obj_size[0])
	{
		j = 0;
		while (j < env->obj_size[1])
		{
			perspective_divide(&(env->obj[i][j].vec3), &(env->img[i][j].vec3));
			screen_to_raster(&(env->img[i][j].vec3), &(env->canvas),
				&(env->screen));
			bound_pixel(&(env->img[i][j].vec3));
			env->img[i][j].c = env->obj[i][j].c;
			j++;
		}
		i++;
	}
	return (SUCCESS);
}