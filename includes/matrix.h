/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:53:53 by vparis            #+#    #+#             */
/*   Updated: 2018/01/08 13:56:28 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATRIX_H
# define FT_MATRIX_H

# include "libft.h"

# define MATRIX_44		0x44
# define MATRIX_33		0x33
# define MATRIX_22		0x22
# define MATRIX_41		0x41
# define MATRIX_31		0x31
# define MATRIX_21		0x21
# define MATRIX_11		0x11
# define MATRIX_L		0xF0
# define MATRIX_C		0x0F
# define MATRIX_T		t_f64
# define MATRIX_SET		1
# define MATRIX_NOSET	0

typedef t_f64**	t_matrix;

typedef struct	s_screen {
	t_u32		width;
	t_u32		height;
}				t_screen;

typedef struct	s_vec3 {
	t_f64		x;
	t_f64		y;
	t_f64		z;
}				t_vec3;

/*
** matrix.c
*/

t_matrix		matrix_new(int type, int init);
void			matrix_del(int type, t_matrix *mat);
void			matrix_getsize(int type, int *l, int *c);
void			matrix_mul3_vec3(t_matrix mat, t_vec3 *v);
void			matrix_mul3(t_matrix m1, t_matrix m2);

/*
** matrix_rot.c
*/

# define ROT_X	1
# define ROT_Y	2
# define ROT_Z	3

t_matrix		matrix_rot(t_vec3 *ang);

/*
** matrix_scale.c
*/

t_matrix		matrix_id3(t_matrix mat);
t_matrix		matrix_scale3(t_matrix mat, t_vec3 *v);

/*
** angle.c
*/

# ifndef PI
#  define PI	(3.141592653589793)
# endif
# define DEG_TO_RAD (PI / 180.)
# define RAD_TO_DEG (180. / PI)

t_f64			deg_to_rad(t_f64 x);
t_f64			rad_to_deg(t_f64 x);
t_f64			ft_cos(t_f64 x);
t_f64			ft_sin(t_f64 x);

/*
** vec3_1.c
*/

t_vec3			*vec3_new(void);
void			vec3_del(t_vec3 *v1);
void			vec3_add(t_vec3 *v1, t_vec3 *v2);
void			vec3_sub(t_vec3 *v1, t_vec3 *v2);
void			vec3_mul(t_vec3 *v1, t_f64 r);

/*
** vec3_1.c
*/

void			vec3_set(t_vec3 *pt, t_f64 x, t_f64 y, t_f64 z);
void			vec3_norm(t_vec3 *v1);
t_f64			vec3_dot(t_vec3 *v1, t_vec3 *v2);
t_f64			vec3_len(t_vec3 *v1);
t_f64			vec3_len_ns(t_vec3 *v1);
t_vec3			*vec3_cross(t_vec3 *v1, t_vec3 *v2);

#endif
