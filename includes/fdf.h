/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:21:59 by vparis            #+#    #+#             */
/*   Updated: 2017/12/18 00:52:37 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_mlx.h"
# include "matrix.h"

# define WIDTH		600
# define HEIGHT		400
# define TITLE		"FDF DX400"

typedef struct	s_data {
	t_env		env;
	t_mlx		mlx;
}				t_data;

int		map_get(char *filename, t_env *map);
void	env_init(t_env *env, int width, int height);

#endif
