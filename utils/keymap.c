/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keymap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:52:32 by vparis            #+#    #+#             */
/*   Updated: 2017/12/12 19:09:09 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "mlx.h"
#include "ft_mlx.h"
#include "fdf.h"


int		mouse(int keycode, int x, int y, void *param)
{
	(void)param;
	(void)x;
	(void)ym;
	printf("%d\n", keycode);
	return (1);
}

int		key(int keycode, void *param)
{
	(void)param;
	printf("%d\n", keycode);
	return (1);
}

int		main(void)
{
	t_mlx	mlx;

	ft_mlx_init(&mlx);
	if (ft_mlx_win(&mlx, WIDTH, HEIGHT, TITLE) == ERROR)
		exit(0);

	mlx_key_hook(mlx.win[MAIN_WIN].win, &key, NULL);
	/*mlx_mouse_hook(mlx.win[MAIN_WIN].win, &mouse, NULL);*/

	mlx_loop(&mlx);
	return (SUCCESS);
}
