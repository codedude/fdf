/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:32 by vparis            #+#    #+#             */
/*   Updated: 2017/12/21 20:01:11 by vparis           ###   ########.fr       */
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
	ft_mlx_clear(&(data->mlx), MAIN_WIN);
	i = 0;
	while (i < data->env.obj_size[0])
	{
		j = 0;
		while (j < data->env.obj_size[1])
		{
			if (i + 1 < data->env.obj_size[0])
				ft_mlx_line(data->mlx.mlx, MAIN_WIN,
					&(data->env.img[i][j]), &(data->env.img[i + 1][j]));
			if (j + 1 < data->env.obj_size[1])
				ft_mlx_line(data->mlx.mlx, MAIN_WIN,
					&(data->env.img[i][j]), &(data->env.img[i][j + 1]));
			j++;
		}
		i++;
	}
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
	mlx_key_hook(data.mlx.win[MAIN_WIN].win, &ft_mlx_exit, (void *)&data);
	mlx_loop_hook(data.mlx.mlx, &loop, (void *)&data);
	mlx_loop(&(data.mlx));
	return (EXIT_SUCCESS);
}
