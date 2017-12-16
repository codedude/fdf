/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:49 by vparis            #+#    #+#             */
/*   Updated: 2017/12/15 18:55:06 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "ft_stack.h"

static int	map_read(char *filename, t_stack **stack)
{
	int			fd;
	int			n;
	int			r;
	char		*buff;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (ERROR);
	n = 0;
	while ((r = ft_gnl(fd, &buff)) > 0)
	{
		if (r == -1)
			return (ERROR);
		ft_stackpush(stack, buff);
		n++;
	}
	close(fd);
	return (n);
}

static int	map_fill(t_pixel3 **map, char **buff, int l)
{
	int	i;

	i = 0;
	while (buff[i] != NULL)
		i++;
	if ((*map = (t_pixel3 *)malloc(sizeof(t_pixel3) * i)) == NULL)
		return (ERROR);
	i = 0;
	while (buff[i] != NULL)
	{
		(*map)[i].x = (t_f64)i;
		(*map)[i].y = (t_f64)l;
		(*map)[i].z = (t_f64)ft_atoi(buff[i]);
		(*map)[i].c = C_WHITE;
		free(buff[i]);
		i++;
	}
	return (SUCCESS);
}

static int	map_parse(t_stack **stack, t_pixel3 **map, int n)
{
	char	**buff;
	int		i;

	i = 0;
	while (i < n)
	{
		if ((buff = ft_strsplit_whitespaces(ft_stackpop(stack))) == NULL)
			return (ERROR);
		map_fill(&map[n - i - 1], buff, i);
		free(buff);
		i++;
	}
	return (SUCCESS);
}

int			map_get(char *filename, t_pixel3 ***map)
{
	int			n;
	t_stack		*stack;

	if ((n = map_read(filename, &stack)) == ERROR)
	{
		ft_stackclear(&stack);
		return (ERROR);
	}
	if ((*map = (t_pixel3 **)malloc(sizeof(t_pixel3 *) * n)) == NULL)
	{
		ft_stackclear(&stack);
		return (ERROR);
	}
	map_parse(&stack, *map, n);
	return (SUCCESS);
}
