/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 15:41:48 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/17 09:27:05 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	char			*s;
	unsigned int	l;

	l = ft_strlen(s1);
	i = 0;
	if (!(s = (char*)malloc((l + 1) * sizeof(char))))
		return (NULL);
	while (i < l)
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
