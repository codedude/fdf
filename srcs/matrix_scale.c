/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_scale.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:29:45 by vparis            #+#    #+#             */
/*   Updated: 2018/01/11 13:55:33 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "matrix.h"

void			matrix_getsize(int type, int *l, int *c)
{
	*l = (type & MATRIX_L) >> 4;
	*c = type & MATRIX_C;
}

t_matrix		matrix_id3(t_matrix mat)
{
	t_matrix	tmp;

	if ((tmp = matrix_new(MATRIX_33, MATRIX_SET)) == NULL)
		return (NULL);
	tmp[0][0] = mat[0][0];
	tmp[1][1] = mat[1][1];
	tmp[2][2] = mat[2][2];
	return (tmp);
}

t_matrix		matrix_scale3(t_matrix mat, t_vec3 *v)
{
	t_matrix	tmp;

	if ((tmp = matrix_new(MATRIX_33, MATRIX_SET)) == NULL)
		return (NULL);
	tmp[0][0] = mat[0][0] * v->x;
	tmp[1][1] = mat[1][1] * v->y;
	tmp[2][2] = mat[2][2] * v->z;
	return (tmp);
}
