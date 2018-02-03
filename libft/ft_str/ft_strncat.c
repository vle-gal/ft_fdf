/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:41:23 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/15 18:51:35 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	unsigned int	i;
	int				c;

	i = 0;
	c = ft_strlen(s1);
	while (s2[i] && i < n)
	{
		s1[c] = s2[i];
		c++;
		i++;
	}
	s1[c] = '\0';
	return (s1);
}
