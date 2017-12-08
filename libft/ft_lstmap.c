/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 17:25:56 by vparis            #+#    #+#             */
/*   Updated: 2017/11/08 20:39:10 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*tmp_s;
	t_list	*r;

	tmp = NULL;
	tmp_s = NULL;
	while (lst != NULL)
	{
		if ((r = (*f)(lst)) == NULL)
			return (NULL);
		if (tmp == NULL)
		{
			tmp = r;
			tmp_s = r;
		}
		else
		{
			tmp->next = r;
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (tmp_s);
}
