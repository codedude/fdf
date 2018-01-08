/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binds.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 09:53:02 by vparis            #+#    #+#             */
/*   Updated: 2018/01/08 13:30:33 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"
#include "fdf.h"


static void	key_down_3(int keycode, t_data *data)
{
	if (keycode == K_Q)
		data->env.ang.x += 2.;
	if (keycode == K_A)
		data->env.ang.x -= 2.;
	if (keycode == K_W)
		data->env.ang.y += 2.;
	if (keycode == K_S)
		data->env.ang.y -= 2.;
	if (keycode == K_E)
		data->env.ang.z += 2.;
	if (keycode == K_D)
		data->env.ang.z -= 2.;
}

static void	key_down_2(int keycode, t_data *data)
{
	if (keycode == K_T)
	{
		data->env.altitude += 0.01;
		if (data->env.altitude > 1.)
			data->env.altitude = 1.;
	}
	if (keycode == K_G)
	{
		data->env.altitude -= 0.01;
		if (data->env.altitude < 0.)
			data->env.altitude = 0.;
	}
}

int			manage_key_down(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == K_ESC)
		env_destroy(data);
	if (keycode == K_UP)
		data->env.camera.y += 2.;
	if (keycode == K_DOWN)
		data->env.camera.y -= 2.;
	if (keycode == K_RIGHT)
		data->env.camera.x -= 2.;
	if (keycode == K_LEFT)
		data->env.camera.x += 2.;
	key_down_2(keycode, data);
	key_down_3(keycode, data);
	return (1);
}

int			manage_key_up(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == K_SPACE)
		data->env.demo = !data->env.demo;
	if (keycode == K_C)
		data->env.effect = !data->env.effect;
	if (keycode == K_V)
		data->env.view = !data->env.view;
	return (1);
}

int			manage_mouse(int keycode, int x, int y, void *param)
{
	t_data	*data;

	(void)x;
	(void)y;
	data = (t_data *)param;
	if (keycode == M_DOWN)
	{
		if (data->env.camera.z < -20.)
			data->env.camera.z += 10.;
	}
	else if (keycode == M_UP)
	{
		if (data->env.camera.z > -2000.)
			data->env.camera.z -= 10.;
	}
	return (1);
}