/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:44:18 by vparis            #+#    #+#             */
/*   Updated: 2017/12/11 18:27:30 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

/*
** color = 4 bytes : 0 | R | G | B
*/

typedef struct		s_mlx {
	void			*mlx;
	void			*win;
	int				width;
	int				height;
}					t_mlx;

typedef struct		s_pixel {
	int				x;
	int				y;
	int				c;
}					t_pixel;

int		ft_mlx_init(t_mlx *mlx, int width, int height, char *title);
void	ft_mlx_destroy(t_mlx *mlx);
void	ft_mlx_clear(t_mlx *mlx);
void	ft_mlx_pixel(t_mlx *mlx, t_pixel *pix);
void	ft_mlx_string(t_mlx *mlx, t_pixel *pix, char *str);

#endif
