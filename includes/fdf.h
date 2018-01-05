/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:21:59 by vparis            #+#    #+#             */
/*   Updated: 2018/01/05 17:12:13 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_mlx.h"
# include "matrix.h"

# define WIDTH		1920
# define HEIGHT		1080
# define TITLE		"FDF DX4000"

# define MARGE		400

typedef struct	s_data {
	t_env		env;
	t_mlx		mlx;
}				t_data;

int				map_get(char *filename, t_env *map);
int				env_init(t_env *env, int width, int height);
int				compute_img(t_env *env);

#endif
