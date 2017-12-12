/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:44:18 by vparis            #+#    #+#             */
/*   Updated: 2017/12/12 22:41:06 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "mlx.h"
# include "ft_mlx_key.h"

# define MLX_MAX_WINDOW	4
# define MAIN_WIN		0

# define C_RED			0x00FF0000
# define C_GREEN		0x0000FF00
# define C_BLUE			0x000000FF
# define C_WHITE		0x00FFFFFF
# define C_BLACK		0x00000000
# define C_GREY			0x00999999

typedef struct	s_win {
	void		*win;
	int			width;
	int			height;
	char		*title;
}				t_win;

typedef struct	s_mlx {
	void		*mlx;
	t_win		win[MLX_MAX_WINDOW];
}				t_mlx;

typedef int		t_color;

typedef struct	s_pixel {
	int			x;
	int			y;
	t_color		c;
}				t_pixel;

/*
** MLX and window management
*/

void			ft_mlx_init(t_mlx *mlx);
int				ft_mlx_win(t_mlx *mlx, int width, int height, char *title);
void			ft_mlx_destroy(t_mlx *mlx, int win);
int				ft_mlx_exit(int keycode, void *param);

/*
** Drawing management
*/

void			ft_mlx_clear(t_mlx *mlx, int win);
void			ft_mlx_pixel(t_mlx *mlx, int win, t_pixel *pix);
void			ft_mlx_string(t_mlx *mlx, int win, t_pixel *pix, char *str);

/*
** Pixel manipulation
*/

void			ft_mlx_pixel_init(t_pixel *pix);
t_color			ft_mlx_getcolor(int r, int g, int b);

/*
** Line drawing
*/

void			ft_mlx_line(t_mlx *mlx, int win, t_pixel *src, t_pixel *dest);

#endif
