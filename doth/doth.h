/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doth.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:24:07 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/17 10:38:52 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOTH_H
# define DOTH_H
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"

# define BUFFER 1000
# define BUFFER_PRINT 4

typedef struct	s_struct
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			y;
	int			x_max;
	int			y_max;
	int			x;
	int			y_draw;
	int			x_draw;
	int			x1;
	int			x2;
	int			y1;
	int			y2;
	int			iso_x1;
	int			iso_y1;
}				t_struct;

int				fill_tab_bis(char *line, int i, t_struct *p, int a);
void			oct1_4(t_struct *p, int dx, int dy);
void			oct5_8(t_struct *p, int dx, int dy);
void			vert(t_struct *p, int dy);
int				escape(int keycode, t_struct *p);
void			gathering_pixel(t_struct *p);
void			octant1(t_struct *p, int dx, int dy);
void			octant2(t_struct *p, int dx, int dy);
void			octant3(t_struct *p, int dx, int dy);
void			octant4(t_struct *p, int dx, int dy);
void			octant5(t_struct *p, int dx, int dy);
void			octant6(t_struct *p, int dx, int dy);
void			octant7(t_struct *p, int dx, int dy);
void			octant8(t_struct *p, int dx, int dy);
void			horizontal_d(t_struct *p);
void			horizontal_g(t_struct *p);
void			vertical_cro(t_struct *p);
void			vertical_decro(t_struct *p);

#endif
