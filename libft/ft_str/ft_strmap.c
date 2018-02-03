/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/15 23:33:06 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:27:54 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*src;
	int		i;

	i = 0;
	if (!(src = ft_strdup((char*)s)))
		return (NULL);
	while (src[i])
	{
		src[i] = f(src[i]);
		i++;
	}
	return (src);
}
