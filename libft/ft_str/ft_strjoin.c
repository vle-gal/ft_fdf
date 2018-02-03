/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 16:53:00 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/18 20:12:15 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	void	*src;
	char	*str;

	if (!(src = ft_memalloc((ft_strlen(s1) + ft_strlen(s2)))))
		return (NULL);
	str = src;
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	return (str);
}
