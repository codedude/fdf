/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:44:18 by vparis            #+#    #+#             */
/*   Updated: 2018/01/08 12:56:09 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "libft.h"
# include "mlx.h"
# include "ft_mlx_key.h"
# include "matrix.h"

# define MLX_MAX_WINDOW	4
# define MAIN_WIN		0

# define C_RED			0x00FF0000
# define C_GREEN		0x0000FF00
# define C_BLUE			0x000000FF
# define C_WHITE		0x00FFFFFF
# define C_BLACK		0x00000000
# define C_GREY			0x00999999
# define C_MOUNT		0x0080461B
# define C_WATER		0x002EA3BF
# define C_GRASS		0x00257F03
# define C_SNOW			0x00DDDDDD
# define C_DEEP			0x00003F69

typedef int		t_color;

typedef struct	s_win {
	void		*win;
	char		*img;
	void		*img__;
	int			width;
	int			height;
	char		*title;
}				t_win;

typedef struct	s_mlx {
	void		*mlx;
	t_win		win[MLX_MAX_WINDOW];
}				t_mlx;

typedef struct	s_pixel {
	int			x;
	int			y;
	t_color		c;
}				t_pixel;

typedef struct	s_pixel3 {
	t_f64		x;
	t_f64		y;
	t_f64		z;
	t_color		c;
}				t_pixel3;

typedef struct	s_vertex {
	t_vec3		vec3;
	t_color		c;
}				t_vertex;

typedef struct	s_env {
	t_screen	screen;
	t_vertex	**obj;
	t_vertex	**img;
	MATRIX_T	**img_z;
	t_u64		obj_size[2];
	t_vec3		camera;
	t_vec3		ang;
	double		altitude;
	int			demo;
	int			effect;
	int			view;
}				t_env;

/*
** MLX and window management
*/

void			ft_mlx_init(t_mlx *mlx);
int				ft_mlx_win(t_mlx *mlx, int width, int height, char *title);
void			ft_mlx_destroy(t_mlx *mlx, int win);
int				ft_mlx_exit(void);

/*
** Drawing management
*/

void			ft_mlx_clear(t_mlx *mlx, int win);
void			ft_mlx_pixel(t_mlx *mlx, int win, t_pixel *pix);
void			ft_mlx_string(t_mlx *mlx, int win, t_pixel *pix, char *str);

/*
** Pixel manipulation
*/

t_color			ft_mlx_getcolor(int r, int g, int b);

/*
** Line drawing
*/

void			ft_mlx_line(MATRIX_T **z, t_mlx *mlx, int win,
							t_vertex *src, t_vertex *dest);

#endif
