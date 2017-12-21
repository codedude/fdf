/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 16:56:56 by vparis            #+#    #+#             */
/*   Updated: 2017/12/21 23:51:09 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "matrix.h"

t_vec3			*vec3_new(void)
{
	t_vec3	*tmp;

	if ((tmp = (t_vec3 *)malloc(sizeof(t_vec3))) == NULL)
		return (NULL);
	return (tmp);
}

void			vec3_del(t_vec3 *v1)
{
	free(v1);
}

void			vec3_add(t_vec3 *v1, t_vec3 *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

void			vec3_sub(t_vec3 *v1, t_vec3 *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}

void			vec3_mul(t_vec3 *v1, t_f64 r)
{
	v1->x *= r;
	v1->y *= r;
	v1->z *= r;
}
