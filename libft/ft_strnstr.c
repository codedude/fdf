/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:51:45 by vparis            #+#    #+#             */
/*   Updated: 2017/12/04 04:54:00 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t size)
{
	char const	*sb;
	char const	*sl;
	char const	*limit_sb;

	if (size < 1)
		return ((char *)haystack);
	if (*needle == 0)
		return ((char *)haystack);
	limit_sb = haystack + size;
	while (*haystack != 0 && haystack < limit_sb)
	{
		sb = haystack;
		sl = needle;
		while (*sb == *sl && *sb != 0 && sb < limit_sb)
		{
			sb++;
			sl++;
		}
		if (*sl == 0)
			return ((char *)haystack);
		if (*sb == 0)
			return (NULL);
		haystack++;
	}
	return (NULL);
}
