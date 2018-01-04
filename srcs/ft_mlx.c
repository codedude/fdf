/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:43:44 by vparis            #+#    #+#             */
/*   Updated: 2018/01/04 16:49:50 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "mlx.h"
#include "ft_mlx.h"

int		ft_mlx_exit(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_mlx_init(t_mlx *mlx)
{
	if ((mlx->mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	ft_bzero((void *)mlx->win, sizeof(t_win) * MLX_MAX_WINDOW);
}

int		ft_mlx_win(t_mlx *mlx, int width, int height, char *title)
{
	int	n;

	n = 0;
	while (n < MLX_MAX_WINDOW && mlx->win[n].win != NULL)
		n++;
	if (n == MLX_MAX_WINDOW)
		return (ERROR);
	if ((mlx->win[n].win = mlx_new_window(mlx->mlx, width, height, title))
		!= NULL)
	{
		mlx->win[n].width = width;
		mlx->win[n].height = height;
		mlx->win[n].title = ft_strdup(title);
	}

	return (n);
}

void	ft_mlx_destroy(t_mlx *mlx, int win)
{
	mlx_destroy_window(mlx->mlx, mlx->win[win].win);
	ft_strdel(&(mlx->win[win].title));
	ft_bzero((void *)&(mlx->win[win]), sizeof(t_win));
}
