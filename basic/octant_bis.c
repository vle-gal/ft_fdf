/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octant_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:11:18 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/12 14:22:48 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doth.h"

void	octant5(t_struct *p, int dx, int dy)
{
	int e;

	e = dx;
	dx *= 2;
	dy = (dy * 2);
	while (p->x1 != p->x2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		if ((p->x1 -= 1) == p->x2)
			break ;
		if ((e = e - dy) >= 0)
		{
			p->y1--;
			e += dx;
		}
	}
}

void	octant6(t_struct *p, int dx, int dy)
{
	int e;

	e = dy;
	dy *= 2;
	dx = (dx * 2);
	while (p->y1 != p->y2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		if ((p->y1 -= 1) == p->y2)
			break ;
		if ((e = e - dx) >= 0)
		{
			p->x1--;
			e += dy;
		}
	}
}

void	octant7(t_struct *p, int dx, int dy)
{
	int e;

	e = dy;
	dy *= 2;
	dx = (dx * 2);
	while (p->y1 != p->y2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		if ((p->y1 -= 1) == p->y2)
			break ;
		if ((e = e + dx) > 0)
		{
			p->x1++;
			e += dy;
		}
	}
}

void	octant8(t_struct *p, int dx, int dy)
{
	int e;

	e = dx;
	dx *= 2;
	dy = (dy * 2);
	while (p->x1 != p->x2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		if ((p->x1 += 1) == p->x2)
			break ;
		if ((e = e + dy) < 0)
		{
			p->y1--;
			e += dx;
		}
	}
}
