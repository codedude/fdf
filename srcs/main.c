/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:32 by vparis            #+#    #+#             */
/*   Updated: 2017/12/12 22:44:01 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"

int		loop(void *param)
{
	t_mlx	*mlx;
	t_pixel	pix1;
	t_pixel	pix2;
	static int	off = 0;

	mlx = (t_mlx *)param;
	ft_mlx_clear(mlx, MAIN_WIN);
	pix1.c = C_RED;
	pix1.x = 15;
	pix1.y = 15;
	pix2.c = C_BLUE;
	pix2.x = 234;
	pix2.y = 125;
	ft_mlx_line(mlx, MAIN_WIN, &pix1, &pix2);
	off++;
	usleep(100);
	return (1);
}

int		main(void)
{
	t_mlx	mlx;

	ft_mlx_init(&mlx);
	if (ft_mlx_win(&mlx, WIDTH, HEIGHT, TITLE) == ERROR)
		exit(EXIT_FAILURE);
	mlx_key_hook(mlx.win[MAIN_WIN].win, &ft_mlx_exit, (void *)&mlx);
	mlx_loop_hook(mlx.mlx, &loop, (void *)&mlx);

	mlx_loop(&mlx);
	return (EXIT_SUCCESS);
}
