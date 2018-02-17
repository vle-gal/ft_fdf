/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gathering_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 12:58:02 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/17 09:10:45 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doth.h"

void	gathering_pixel(t_struct *p)
{
	int dx;
	int dy;

	// printf("gatfirst[]%d %d\n",p->y1, p->x1);
	// printf("%d %d\n",p->y2, p->x2);
	if ((dx = (p->x2 - p->x1)) != 0)
	{
		if (dx > 0)
		{
			if ((dy = (p->y2 - p->y1)) != 0)
				oct1_4(p, dx, dy);
			else
				horizontal_d(p);
		}
		else
		{
			if ((dy = (p->y2 - p->y1)) != 0)
				oct5_8(p, dx, dy);
			else
				horizontal_g(p);
		}
	}
	else
	{
		(dy = p->y2 - p->y1) != 0 ? vert(p, dy) : 0;
	}
}

void	oct1_4(t_struct *p, int dx, int dy)
{
	// printf("[]%d %d\n", p->y1, p->x1);
	if (dy > 0)
	{
		if (dx >= dy)
			octant1(p, dx, dy);
		else
			octant2(p, dx, dy);
	}
	else
	{
		if (dx >= -dy)
			octant8(p, dx, dy);
		else
			octant7(p, dx, dy);
	}
}

void	oct5_8(t_struct *p, int dx, int dy)
{
	// printf("{}%d %d\n", p->y1, p->x1);
	if (dy > 0)
	{
		if (-dx >= dy)
			octant4(p, dx, dy);
		else
			octant3(p, dx, dy);
	}
	else
	{
		if (dx <= dy)
			octant5(p, dx, dy);
		else
			octant6(p, dx, dy);
	}
}

void	vert(t_struct *p, int dy)
{
	if (dy > 0)
		vertical_cro(p);
	else
		vertical_decro(p);
}

int		escape(int keycode, t_struct *p)
{
	if (keycode == 53)
	{
		mlx_destroy_window(p->mlx_ptr, p->win_ptr);
		exit(0);
	}
	return (1);
}
