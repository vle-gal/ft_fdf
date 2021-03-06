/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:42:36 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/15 18:06:23 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s) + 1;
	while (i != 0)
	{
		i--;
		if (s[i] == c)
		{
			return ((char*)s + i);
		}
	}
	return (NULL);
}
