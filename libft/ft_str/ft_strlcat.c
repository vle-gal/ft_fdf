/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:41:23 by vle-gal           #+#    #+#             */
/*   Updated: 2017/09/19 11:57:00 by anonymous        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	// char	*base_dst;
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	// base_dst = dst;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	i = 0;
	dst += len_dst;
	if (size == 0)
		return (len_src);
	while (*src != 0 && len_dst + i + 1 < size)
	{
		*dst = *src;
		src++;
		dst++;
		i++;
	}
	*dst = 0;
	if (len_dst + i + 1 > size)
		return (len_src + size);
	return (len_dst + len_src);
}
