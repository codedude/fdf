/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:32 by vparis            #+#    #+#             */
/*   Updated: 2018/01/05 17:44:54 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "ft_stack.h"
#include "matrix.h"


int		loop(void *param)
{
	t_data	*data;
	t_u64	i;
	t_u64	j;

	data = (t_data *)param;
	compute_img(&(data->env));
	ft_bzero((void *)data->mlx.win[MAIN_WIN].img, 4 * WIDTH * HEIGHT);
	i = 0;
	while (i < data->env.obj_size[0])
	{
		j = 0;
		while (j < data->env.obj_size[1])
		{
			if (i + 1 < data->env.obj_size[0])
				ft_mlx_line(&(data->mlx), MAIN_WIN,
					&(data->env.img[i][j]), &(data->env.img[i + 1][j]));
			if (j + 1 < data->env.obj_size[1])
				ft_mlx_line(&(data->mlx), MAIN_WIN,
					&(data->env.img[i][j]), &(data->env.img[i][j + 1]));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win[MAIN_WIN].win,
		data->mlx.win[MAIN_WIN].__img, 0, 0);
	return (1);
}

int		manage_key_down(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == K_ESC)
		ft_mlx_exit();
	if (keycode == K_UP)
		data->env.camera.y += 5.;
	if (keycode == K_DOWN)
		data->env.camera.y -= 5.;
	if (keycode == K_RIGHT)
		data->env.camera.x -= 5.;
	if (keycode == K_LEFT)
		data->env.camera.x += 5.;
	if (keycode == K_T)
	{
		data->env.altitude += 0.02;
		if (data->env.altitude > 1.)
			data->env.altitude = 1.;
	}
	if (keycode == K_G)
	{
		data->env.altitude -= 0.02;
		if (data->env.altitude < 0.)
			data->env.altitude = 0.;
	}
	return (1);
}

int		manage_key_up(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == K_SPACE)
		data->env.demo = !data->env.demo;
	return (1);
}

int		manage_mouse(int keycode, int x, int y, void *param)
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
		if (data->env.camera.z > -5000.)
			data->env.camera.z -= 10.;
	}
	return (1);
}

int		move_auto(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->env.demo == 1)
		data->env.ang.x += 0.5;
	loop(param);
	return (1);
}

int		main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		ft_putstr("fdf : ./fdf MAP\n");
		return (EXIT_SUCCESS);
	}
	if (map_get(argv[1], &(data.env)) == ERROR)
	{
		ft_putstr("map error\n");
		return (EXIT_FAILURE);
	}
	if (env_init(&(data.env), WIDTH, HEIGHT) == ERROR)
	{
		return (EXIT_FAILURE);
	}
	ft_mlx_init(&(data.mlx));
	if (ft_mlx_win(&(data.mlx), WIDTH, HEIGHT, TITLE) == ERROR)
		exit(EXIT_FAILURE);
	data.env.demo = 1;
	mlx_hook(data.mlx.win[MAIN_WIN].win, E_KEY_UP, 0,
		&manage_key_up, (void *)&data);
	mlx_hook(data.mlx.win[MAIN_WIN].win, E_KEY_DOWN, 1,
		&manage_key_down, (void *)&data);
	mlx_hook(data.mlx.win[MAIN_WIN].win, E_MOUSE_DOWN, 0,
		&manage_mouse, (void *)&data);
	mlx_loop_hook(data.mlx.mlx, &move_auto, (void *)&data);
	mlx_loop(&(data.mlx));
	return (EXIT_SUCCESS);
}
