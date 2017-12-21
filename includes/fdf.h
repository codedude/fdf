/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:21:59 by vparis            #+#    #+#             */
/*   Updated: 2017/12/22 00:11:50 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_mlx.h"
# include "matrix.h"

# define WIDTH		800
# define HEIGHT		600
# define TITLE		"FDF DX400"

# define MARGE		200

typedef struct	s_data {
	t_env		env;
	t_mlx		mlx;
}				t_data;

int		map_get(char *filename, t_env *map);
int		env_init(t_env *env, int width, int height);
int		compute_img(t_env *env);

#endif
