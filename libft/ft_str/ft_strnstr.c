/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 09:16:54 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/18 17:53:01 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, char *needle, size_t len)
{
	unsigned int		n;
	unsigned int		count;

	n = 0;
	count = 0;
	if (needle[n] == '\0')
		return ((char*)haystack);
	while (haystack[count] != '\0' && count < len)
	{
		if (haystack[count] == needle[0])
		{
			while (needle[n] != '\0' && haystack[count + n] == needle[n] &&
			count + n < len)
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
