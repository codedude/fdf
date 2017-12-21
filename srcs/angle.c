/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 17:57:00 by vparis            #+#    #+#             */
/*   Updated: 2017/12/21 18:39:15 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "matrix.h"

t_f64		deg_to_rad(t_f64 x)
{
	return (x * DEG_TO_RAD);
}

t_f64		rad_to_deg(t_f64 x)
{
	return (x * RAD_TO_DEG);
}

t_f64		ft_cos(t_f64 x)
{
	return (cos(deg_to_rad(x)));
}

t_f64		ft_sin(t_f64 x)
{
	return (sin(deg_to_rad(x)));
}
