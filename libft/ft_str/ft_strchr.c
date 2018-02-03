/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 18:42:36 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:30:10 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	if (c == '\0')
	{
		return (ft_strrchr(s, c));
	}
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			return ((char*)s + i);
		}
		i++;
	}
	return (NULL);
}
