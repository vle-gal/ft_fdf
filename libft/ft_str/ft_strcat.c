/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:41:23 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/15 18:00:45 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *restrict s1, const char *restrict s2)
{
	int i;
	int n;

	i = 0;
	n = ft_strlen(s1);
	while (s2[i])
	{
		s1[n] = s2[i];
		n++;
		i++;
	}
	s1[n] = '\0';
	return (s1);
}
