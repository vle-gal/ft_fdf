/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 10:26:53 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/17 10:54:17 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doth.h"

int		fill_tab_bis(char *line, int i, t_struct *p, int a)
{
	if (a == 1)
	{
		while (line[i] == ' ')
			i++;
	}
	if (a == 2)
	{
		while (line[i] != ' ' && line[i] != '\0')
			i++;
		while (line[i] == ' ')
			i++;
		p->x++;
	}
	return (i);
}
