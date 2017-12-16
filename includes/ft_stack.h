/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 18:06:44 by vparis            #+#    #+#             */
/*   Updated: 2017/12/15 18:12:20 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

typedef struct		s_stack {
	struct s_stack	*previous;
	char			*str;
}					t_stack;

char				*ft_stackpop(t_stack **stack);
int					ft_stackpush(t_stack **stack, char *str);
void				ft_stackclear(t_stack **stack);

#endif
