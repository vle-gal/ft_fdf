/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 19:06:54 by vle-gal           #+#    #+#             */
/*   Updated: 2017/04/20 18:13:36 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_len(char const *s, char c, int i)
{
	size_t	len;

	len = 1;
	i++;
	while (s[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static int			ft_before(char const *s, char c)
{
	int i;
	int	res;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] != c && s[i] && s[i - 1] == c)
		{
			res++;
		}
		i++;
	}
	return (res);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		split;

	i = 0;
	split = 0;
	if (!(str = malloc((ft_before(s, c) + 1) * sizeof(char*))))
		return (NULL);
	str[ft_before(s, c)] = NULL;
	while (s[i])
	{
		if (s[i] != c && (!i || s[i - 1] == c))
		{
			if (!(str[split] = malloc((ft_len(s, c, i) + 1) * sizeof(char))))
				return (NULL);
			ft_strncpy(str[split], s + i, ft_len(s, c, i));
			str[split][ft_len(s, c, i)] = 0;
			split++;
		}
		i++;
	}
	str[split] = NULL;
	return (str);
}
