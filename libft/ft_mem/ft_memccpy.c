/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 19:29:04 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/17 10:47:06 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *restrict dst,
				const	void	*restrict src, int c, size_t n)
{
	unsigned int					i;
	unsigned char					*s;
	unsigned char					*d;

	i = 0;
	s = (unsigned char*)src;
	d = (unsigned char*)dst;
	while (i < n)
	{
		if (s[i] == (unsigned char)c)
		{
			d[i] = s[i];
			i++;
			return (d + i);
		}
		d[i] = s[i];
		i++;
	}
	return (NULL);
}
