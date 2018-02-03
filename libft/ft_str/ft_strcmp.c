/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 23:26:27 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:29:42 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned int count;

	count = 0;
	while ((unsigned char)s1[count] == (unsigned char)s2[count])
	{
		count++;
		if ((unsigned char)s1[count] == '\0' &&
		(unsigned char)s2[count] == '\0')
			return (0);
	}
	return ((unsigned char)(s1[count]) - (unsigned char)(s2[count]));
}
