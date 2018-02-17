/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:45:37 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/17 10:56:32 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doth.h"

static void		put_the_pixel(t_struct *p, void *tabx, \
								void *taby)
{
	int (*tab_x)[p->y_max][p->x_max];
	int (*tab_y)[p->y_max][p->x_max];

	tab_x = tabx;
	tab_y = taby;
	if (p->y_draw != p->y_max && (p->x_draw + 1) != p->x_max)
	{
		p->x1 = tab_x[0][p->y_draw][p->x_draw];
		p->y1 = tab_y[0][p->y_draw][p->x_draw];
		p->x2 = tab_x[0][p->y_draw][p->x_draw + 1];
		p->y2 = tab_y[0][p->y_draw][p->x_draw + 1];
		gathering_pixel(p);
	}
	if ((p->y_draw + 1) != p->y_max)
	{
		p->x1 = tab_x[0][p->y_draw][p->x_draw];
		p->y1 = tab_y[0][p->y_draw][p->x_draw];
		p->x2 = tab_x[0][p->y_draw + 1][p->x_draw];
		p->y2 = tab_y[0][p->y_draw + 1][p->x_draw];
		gathering_pixel(p);
	}
}

static void		before_pixel(t_struct *p, void *tabx, void *taby)
{
	int (*tab_y)[p->y_max][p->x_max];
	int (*tab_x)[p->y_max][p->x_max];

	tab_y = taby;
	tab_x = tabx;
	p->y = 0;
	while (p->y != p->y_max)
	{
		p->x = 0;
		p->x_draw = 0;
		while (p->x != p->x_max)
		{
			put_the_pixel(p, tab_x, tab_y);
			p->x++;
			p->x_draw++;
		}
		p->y++;
		p->y_draw++;
	}
}

static void		pixel(int tab[BUFFER][BUFFER], t_struct *p)
{
	int more_x;
	int more_y;
	int tab_y[p->y_max][p->x_max];
	int tab_x[p->y_max][p->x_max];

	p->win_ptr = mlx_new_window(p->mlx_ptr, 2100, 1100, "DUKE NUKEM");
	more_y = (BUFFER / (p->y_max + 1));
	p->y = 0;
	while (p->y < p->y_max)
	{
		more_x = (BUFFER / (p->x_max + 1));
		p->x = 0;
		while (p->x < (p->x_max))
		{
			p->iso_x1 = (p->x + more_x) - (p->y + more_y);
			p->iso_y1 = ((p->x + more_x) + (p->y + more_y)) / 2;
			tab_y[p->y][p->x] = (p->iso_y1 - ((tab[p->y][p->x]) - 50));
			tab_x[p->y][p->x] = (p->iso_x1 + ((2000 / 2) + 50));
			more_x += (BUFFER / (p->x_max + 1));
			p->x++;
		}
		more_y += (BUFFER / (p->y_max + 1));
		p->y++;
	}
	before_pixel(p, &tab_x, &tab_y);
}

static int		fill_tab(int fd, t_struct *p)
{
	char	*line;
	int		i;
	int		tab[BUFFER][BUFFER];

	i = 0;
	while (ft_get_next_line(fd, &line) == 1)
	{
		while (line[i] != '\0')
		{
			i = fill_tab_bis(line, i, p, 1);
			tab[p->y][p->x] = (ft_atoi(line + i) * BUFFER_PRINT);
			i = fill_tab_bis(line, i, p, 2);
		}
		if ((p->x_max < (p->x) || p->x_max > (p->x)) && p->x_max != 0)
			return (0);
		p->x_max == 0 ? p->x_max = (p->x) : 0;
		p->x = 0;
		i = 0;
		p->y++;
	}
	if ((p->y_max < (p->y) || p->y_max > (p->y)) && p->y_max != 0)
		return (0);
	p->y_max == 0 ? p->y_max = (p->y) : 0;
	pixel(tab, p);
	return (1);
}

int				main(int ac, char **av)
{
	int			fd;
	t_struct	p;

	ft_bzero(&p, sizeof(p));
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	p.mlx_ptr = mlx_init();
	if (fill_tab(fd, &p) == 0)
		return (0);
	mlx_key_hook(p.win_ptr, escape, &p);
	mlx_loop(p.mlx_ptr);
}
