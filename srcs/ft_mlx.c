/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:43:44 by vparis            #+#    #+#             */
/*   Updated: 2017/12/11 18:30:44 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "ft_mlx.h"

int		ft_mlx_init(t_mlx *mlx, int width, int height, char *title)
{
	if ((mlx->mlx = mlx_init()) == NULL)
		exit(0);
	if ((mlx->win = mlx_new_window(mlx->mlx, width, height, title)) != NULL)
	{
		mlx_loop(mlx->mlx);
		ft_mlx_destroy(mlx);
		return (SUCCESS);
	}
	return (ERROR);
}

void	ft_mlx_destroy(t_mlx *mlx)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
}

void	ft_mlx_clear(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
}

void	ft_mlx_pixel(t_mlx *mlx, t_pixel *pix)
{
	mlx_pixel_put(mlx->mlx, mlx->win, pix->x, pix->y, pix->c);
}

void	ft_mlx_string(t_mlx *mlx, t_pixel *pix, char *str)
{
	mlx_string_put(mlx->mlx, mlx->win, pix->x, pix->y, pix->c, str);
}
