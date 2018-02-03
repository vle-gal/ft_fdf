/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 17:07:44 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:25:24 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strtrim(char const *s)
{
	int		i;
	size_t	n;
	char	*str;

	str = NULL;
	i = 0;
	n = ft_strlen(s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == ',')
	{
		i++;
		if (s[i] == '\0')
			return ("");
	}
	while (s[n - 1] == ' ' || s[n - 1] == '\t' ||
	s[n - 1] == '\n' || s[n - 1] == ',')
	{
		n--;
	}
	if (!(str = ft_strnew(n - i)))
		return (NULL);
	ft_strncpy(str, s + i, n - i);
	return (str);
}
