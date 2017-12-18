/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:02:38 by vparis            #+#    #+#             */
/*   Updated: 2017/12/17 20:54:53 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "matrix.h"

void			matrix_getsize(int type, int *l, int *c)
{
	*l = (type & MATRIX_L) >> 4;
	*c = type & MATRIX_C;
}

t_matrix		matrix_new(int type, int init)
{
	int			l;
	int			c;
	int			i;
	t_matrix	tmp;

	matrix_getsize(type, &l, &c);
	if ((tmp = (t_matrix)malloc(sizeof(*tmp) * l)) == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		if ((tmp[i] = (MATRIX_TYPE *)malloc(sizeof(tmp[i]) * c)) == NULL)
			return (NULL);
		if (init != 0)
			ft_bzero((void *)tmp[i], sizeof(MATRIX_TYPE) * c);
		i++;
	}
	return (tmp);
}

void			matrix_del(int type, t_matrix *mat)
{
	int			l;
	int			c;

	matrix_getsize(type, &l, &c);
	while (l != 0)
	{
		free((*mat)[l - 1]);
		(*mat)[l - 1] = NULL;
		l--;
	}
	free(*mat);
	*mat = NULL;
}

/*
** DEBUG, to remove
*/

void		matrix_print(int type, t_matrix mat)
{
	int	l;
	int	c;
	int	i;
	int	j;

	matrix_getsize(type, &l, &c);
	i = 0;
	while (i < l)
	{
		j = 0;
		while (j < c)
		{
			printf("%.4F", mat[i][j]);
			if (j < c - 1)
				printf(", ");
			j++;
		}
		printf("\n");
		i++;
	}
}