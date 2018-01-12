/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 04:21:59 by vparis            #+#    #+#             */
/*   Updated: 2018/01/12 14:17:09 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "ft_mlx.h"

# define WIDTH		1920
# define HEIGHT		1080
# define TITLE		"FDF DX4000"

# define MARGE		400
# define VIEW_PAR	0
# define VIEW_ISO	1

typedef struct	s_data {
	t_env		env;
	t_mlx		mlx;
}				t_data;

int				map_get(char *filename, t_env *map);
int				env_init(t_env *env, int width, int height);
void			env_destroy(t_data *data);
int				manage_key_down(int keycode, void *param);
int				manage_key_up(int keycode, void *param);
int				manage_mouse(int keycode, int x, int y, void *param);
void			key_down(t_data *data);
int				compute_img(t_env *env);
void			clean_maps(t_data *data);
void			draw_img(t_data *data);

#endif
