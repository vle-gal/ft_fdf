/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 23:26:27 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:27:12 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	count;
	unsigned char	*(s3);
	unsigned char	*(s4);

	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	count = 0;
	while (s3[count] == s4[count] && count < n && s3[count])
	{
		count++;
	}
	if (count < n)
	{
		return (s3[count] - s4[count]);
	}
	else
		return (0);
}
