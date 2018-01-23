/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 17:34:49 by vparis            #+#    #+#             */
/*   Updated: 2018/01/15 11:40:45 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft.h"
#include "ft_input.h"
#include "ft_mlx.h"
#include "fdf.h"
#include "matrix.h"
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

static int	map_fill(t_vertex **map, char **buff, int l, int s)
{
	int		i;
	char	*tmp;

	if ((*map = (t_vertex *)malloc(sizeof(t_vertex) * s)) == NULL)
		return (ERROR);
	i = 0;
	while (buff[i] != NULL)
	{
		(*map)[i].vec3.x = (t_f64)i;
		(*map)[i].vec3.y = (t_f64)l;
		(*map)[i].vec3.z = (t_f64)ft_atoi(buff[i]);
		if ((tmp = ft_strchr(buff[i], ',')) != NULL)
		{
			(*map)[i].c = (t_color)ft_atoi_base(tmp + 3, CHARSET_BASE_16L);
			if ((*map)[i].c == -1)
				(*map)[i].c = (t_color)ft_atoi_base(tmp + 3, CHARSET_BASE_16U);
		}
		else
			(*map)[i].c = (t_color)-1;
		free(buff[i]);
		i++;
	}
	free(buff);
	return (SUCCESS);
}

static int	map_parse(t_stack **stack, t_env *map, int n)
{
	char	**buff;
	char	*input;
	int		i;
	int		s[2];

	i = 0;
	while (i < n)
	{
		input = ft_stackpop(stack);
		if ((buff = ft_strsplit_whitespaces(input)) == NULL)
		{
			free(input);
			return (ERROR);
		}
		free(input);
		s[0] = 0;
		while (buff[s[0]] != NULL)
			s[0]++;
		if ((s[0] != (s[1] = map->obj_size[1]) && s[1] != 0) || s[0] == 0)
			return (ERROR);
		map->obj_size[1] = (t_u64)s[0];
		map_fill(&(map->obj[n - i - 1]), buff, i, s[0]);
		i++;
	}
	return (SUCCESS);
}

int			map_get(char *filename, t_env *map)
{
	int			n;
	t_stack		*stack;

	if ((n = map_read(filename, &stack)) == ERROR)
	{
		ft_stackclear(&stack);
		return (ERROR);
	}
	if ((map->obj = (t_vertex **)malloc(sizeof(t_vertex *) * n)) == NULL)
	{
		ft_stackclear(&stack);
		return (ERROR);
	}
	map->obj_size[0] = n;
	map->obj_size[1] = 0;
	return (map_parse(&stack, map, n));
}
