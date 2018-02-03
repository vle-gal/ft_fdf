/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:05:08 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/27 19:29:33 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*next;
	t_list	*liste2;

	liste2 = NULL;
	if (lst)
	{
		if (!(next = (t_list *)malloc(sizeof(t_list))))
			return (NULL);
		next = f(lst);
		liste2 = next;
		while (lst->next)
		{
			if (!(next->next = (t_list *)malloc(sizeof(t_list))))
				return (NULL);
			lst = lst->next;
			next->next = f(lst);
			next = next->next;
		}
	}
	return (liste2);
}
