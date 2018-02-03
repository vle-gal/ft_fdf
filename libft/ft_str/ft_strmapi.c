/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/17 02:45:29 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/19 21:27:30 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*src;
	int		i;

	i = 0;
	if (!(src = ft_strdup(s)))
		return (NULL);
	while (src[i])
	{
		src[i] = f(i, src[i]);
		i++;
	}
	return (src);
}
