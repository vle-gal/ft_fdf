/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:55:13 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/03 11:43:52 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*str_join_free(char *buff, char *tab)
{
	unsigned int	i;
	unsigned int	j;
	char			*ptr;

	i = 0;
	j = 0;
	if (buff)
		i = ft_strlen(buff);
	if (tab)
		j = ft_strlen(tab);
	ptr = (char *)malloc(sizeof(*ptr) * (i + j + 1));
	ft_memcpy(ptr, buff, i);
	ft_memcpy(ptr + i, tab, j);
	ptr[i + j] = '\0';
	free(buff);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (ptr);
}

static	int		line_over(char *buff)
{
	int		count;

	count = 0;
	while (buff[count] != '\n' && buff[count])
		count++;
	if (buff[count] == '\n')
	{
		buff[count] = '\0';
		return (count);
	}
	else
		return (-1);
}

static	int		verif(char **buff, char **tab, char **line)
{
	char	*ptr;
	int		res;

	*buff = str_join_free(*buff, *tab);
	res = line_over(*buff);
	if (res > -1)
	{
		*line = ft_strdup(*buff);
		ptr = *buff;
		*buff = ft_strdup(*buff + res + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

int				ft_get_next_line(int const fd, char **line)
{
	static char *buff[12288];
	char		*tmp;
	int			result;
	int			readed;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (readed = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((readed = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		result = verif(&buff[fd], &tmp, line);
		free(tmp);
		if (result == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((result = verif(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (result);
}
