/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:16:54 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/18 17:32:56 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, char *needle)
{
	unsigned int		n;
	unsigned int		count;

	n = 0;
	count = 0;
	if (needle[n] == '\0')
		return ((char*)haystack);
	while (haystack[count] != '\0')
	{
		if (haystack[count] == needle[0])
		{
			while (needle[n] != '\0' && haystack[count + n] == needle[n])
			{
				n++;
				if (needle[n] == '\0')
				{
					return ((char*)haystack + count);
				}
			}
		}
		count++;
	}
	return (NULL);
}
