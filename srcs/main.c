/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:32 by vparis            #+#    #+#             */
/*   Updated: 2018/01/08 13:27:41 by vparis           ###   ########.fr       */
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

int		move_auto(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->env.demo == 1)
		data->env.ang.x += 0.4;
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
		return (EXIT_FAILURE);
	ft_mlx_init(&(data.mlx));
	if (ft_mlx_win(&(data.mlx), WIDTH, HEIGHT, TITLE) == ERROR)
		exit(EXIT_FAILURE);
	mlx_hook(data.mlx.win[MAIN_WIN].win, E_KEY_UP, 0,
		&manage_key_up, (void *)&data);
	mlx_hook(data.mlx.win[MAIN_WIN].win, E_KEY_DOWN, 0,
		&manage_key_down, (void *)&data);
	mlx_hook(data.mlx.win[MAIN_WIN].win, E_MOUSE_DOWN, 0,
		&manage_mouse, (void *)&data);
	mlx_loop_hook(data.mlx.mlx, &move_auto, (void *)&data);
	mlx_loop(&(data.mlx));
	return (EXIT_SUCCESS);
}
