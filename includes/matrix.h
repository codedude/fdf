/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:53:53 by vparis            #+#    #+#             */
/*   Updated: 2017/12/18 14:58:08 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include "libft.h"
# include "ft_mlx.h"

# define MATRIX_44		0x44
# define MATRIX_33		0x33
# define MATRIX_22		0x22
# define MATRIX_41		0x41
# define MATRIX_31		0x31
# define MATRIX_21		0x21
# define MATRIX_11		0x11
# define MATRIX_L		0xF0
# define MATRIX_C		0x0F
# define MATRIX_TYPE	t_f64
# define MATRIX_SET		1
# define MATRIX_NOSET	0

typedef t_f64**	t_matrix;

typedef struct	s_canvas {
	t_f64		width;
	t_f64		height;
}				t_canvas;

typedef struct	s_screen {
	t_u32		width;
	t_u32		height;
}				t_screen;

typedef struct	s_vec3 {
	t_f64		x;
	t_f64		y;
	t_f64		z;
}				t_vec3;

typedef struct	s_vertex {
	t_vec3		vec3;
	t_color		c;
}				t_vertex;

typedef struct	s_env {
	t_canvas	canvas;
	t_screen	screen;
	t_vertex	**obj;
	t_vertex	**img;
	t_u64		obj_size[2];
	t_vec3		world;
	t_vec3		camera;
}				t_env;



t_matrix		matrix_new(int type, int init);
void			matrix_del(int type, t_matrix *mat);
void			matrix_getsize(int type, int *l, int *c);

void			vec3_set(t_vec3 *pt, t_f64 x, t_f64 y, t_f64 z);
void			vertex_set(t_vertex *pt, t_f64 x, t_f64 y, t_f64 z, t_color c);

/*
** DEBUG, to remove
*/

void			matrix_print(int type, t_matrix mat);

#endif
