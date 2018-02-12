/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vert_hor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 11:20:44 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/12 14:09:39 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doth.h"

void	horizontal_d(t_struct *p)
{
	while (p->x1 != p->x2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		p->x1++;
	}
}

void	horizontal_g(t_struct *p)
{
	while (p->x1 != p->x2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		p->x1--;
	}
}

void	vertical_cro(t_struct *p)
{
	while (p->y1 != p->y2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		p->y1++;
	}
}

void	vertical_decro(t_struct *p)
{
	while (p->y1 != p->y2)
	{
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, p->x1, p->y1, 0x00ff00);
		p->y1--;
	}
}
