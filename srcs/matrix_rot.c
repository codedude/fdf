/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:33:10 by vparis            #+#    #+#             */
/*   Updated: 2018/01/11 13:55:38 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <math.h>
#include "libft.h"
#include "matrix.h"

static void		matrix_set_rot_x(t_matrix rot, t_f64 ang)
{
	t_f64	c;
	t_f64	s;

	c = ft_cos(ang);
	s = ft_sin(ang);
	rot[0][0] = 1.;
	rot[0][1] = 0.;
	rot[0][2] = 0.;
	rot[1][0] = 0.;
	rot[1][1] = c;
	rot[1][2] = s;
	rot[2][0] = 0.;
	rot[2][1] = -s;
	rot[2][2] = c;
}

static void		matrix_set_rot_y(t_matrix rot, t_f64 ang)
{
	t_f64	c;
	t_f64	s;

	c = ft_cos(ang);
	s = ft_sin(ang);
	rot[0][0] = c;
	rot[0][1] = 0.;
	rot[0][2] = -s;
	rot[1][0] = 0.;
	rot[1][1] = 1.;
	rot[1][2] = 0.;
	rot[2][0] = s;
	rot[2][1] = 0.;
	rot[2][2] = c;
}

static void		matrix_set_rot_z(t_matrix rot, t_f64 ang)
{
	t_f64	c;
	t_f64	s;

	c = ft_cos(ang);
	s = ft_sin(ang);
	rot[0][0] = c;
	rot[0][1] = s;
	rot[0][2] = 0.;
	rot[1][0] = -s;
	rot[1][1] = c;
	rot[1][2] = 0.;
	rot[2][0] = 0.;
	rot[2][1] = 0.;
	rot[2][2] = 1.;
}

t_matrix		matrix_rot(t_vec3 *ang)
{
	t_matrix	rot;
	t_matrix	tmp;

	if ((rot = matrix_new(MATRIX_33, MATRIX_NOSET)) == NULL)
		return (NULL);
	if ((tmp = matrix_new(MATRIX_33, MATRIX_NOSET)) == NULL)
		return (NULL);
	matrix_set_rot_z(tmp, ang->x);
	matrix_set_rot_y(rot, ang->y);
	matrix_mul3(tmp, rot);
	matrix_set_rot_x(rot, ang->z);
	matrix_mul3(tmp, rot);
	matrix_del(MATRIX_33, &rot);
	return (tmp);
}
