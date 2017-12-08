/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:15:51 by vparis            #+#    #+#             */
/*   Updated: 2017/12/04 04:26:59 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "fdf.h"

int		main(void)
{
	void	*mlx;
	void	*win;

	if ((mlx = mlx_init()) == NULL)
		exit(0);
	if ((win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE)) != NULL)
	{
		mlx_loop(mlx);
		mlx_destroy_window(mlx, win);
	}
	return (0);
}
