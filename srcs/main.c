/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:32 by vparis            #+#    #+#             */
/*   Updated: 2017/12/18 00:29:36 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "ft_stack.h"
#include "matrix.h"


int		loop(void *param)
{

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
	env_init(&(data.env), WIDTH, HEIGHT);
	ft_mlx_init(&(data.mlx));
	if (ft_mlx_win(&(data.mlx), WIDTH, HEIGHT, TITLE) == ERROR)
		exit(EXIT_FAILURE);
	mlx_key_hook(data.mlx.win[MAIN_WIN].win, &ft_mlx_exit, (void *)&data);
	mlx_loop_hook(data.mlx.mlx, &loop, (void *)&data);
	mlx_loop(&(data.mlx));

	return (EXIT_SUCCESS);
}
