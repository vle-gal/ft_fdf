/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:35:56 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/20 17:20:14 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *actual;
	t_list *next;

	if (*alst)
	{
		actual = *alst;
		while (actual)
		{
			next = actual->next;
			(*del)(actual->content, actual->content_size);
			free(actual);
			actual = next;
		}
		*alst = NULL;
	}
}
