/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:45:37 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/12 14:06:20 by vle-gal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doth.h"

static void		put_the_pixel(t_struct *p)
{
	if (p->y_draw != p->y_max && (p->x_draw + 1) != p->x_max)
	{
		p->x1 = p->tab_x[p->y_draw][p->x_draw];
		p->y1 = p->tab_y[p->y_draw][p->x_draw];
		p->x2 = p->tab_x[p->y_draw][p->x_draw + 1];
		p->y2 = p->tab_y[p->y_draw][p->x_draw + 1];
		gathering_pixel(p);
	}
	if ((p->y_draw + 1) != p->y_max)
	{
		p->x1 = p->tab_x[p->y_draw][p->x_draw];
		p->y1 = p->tab_y[p->y_draw][p->x_draw];
		p->x2 = p->tab_x[p->y_draw + 1][p->x_draw];
		p->y2 = p->tab_y[p->y_draw + 1][p->x_draw];
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x1 - 3), p->y1, (0x00ff00));
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x1 + 3), p->y1, 0x00ff00);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x1), (p->y1 - 3), 0x00ff00);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x1), (p->y1 + 3), 0x00ff00);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x2), (p->y2 - 5), 0xff0000);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x2), (p->y2 + 5), 0xff0000);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x2 + 5), (p->y2), 0xff0000);
		mlx_pixel_put(p->mlx_ptr, p->win_ptr, (p->x2 - 5), (p->y2), 0xff0000);
		gathering_pixel(p);
	}
}

static int		fill_tab(int tab[BUFFER][BUFFER], int fd, t_struct *p)
{
	char	*line;
	int		i;

	i = 0;
	while (ft_get_next_line(fd, &line) == 1)
	{
		while (line[i] != '\0')
		{
			tab[p->y][p->x] = (ft_atoi(line + i) * 50);
			while (line[i] != ' ' && line[i] != '\0')
				i++;
			line[i] == ' ' ? i++ : 0;
			p->x++;
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
	return (1);
}

static void		pixel(int tab[BUFFER][BUFFER], t_struct *p)
{
	int more_x;
	int more_y;

	p->win_ptr = mlx_new_window(p->mlx_ptr, (((p->x_max + p->y_max) - 1) * 100)\
	, ((((p->y_max + p->x_max) - 1) * 100) / 2), "DUKE NUKEM");
	more_y = ((p->y_max * 100) / (p->y_max + 1));
	p->y = 0;
	while (p->y < p->y_max)
	{
		more_x = ((p->x_max * 100) / (p->x_max + 2));
		p->x = 0;
		while (p->x < (p->x_max))
		{
			p->iso_x1 = (p->x + more_x) - (p->y + more_y);
			p->iso_y1 = ((p->x + more_x) + (p->y + more_y)) / 2;
			p->x1 = (p->iso_x1 + (((p->y_max * 100)) + 5));
			p->y1 = (p->iso_y1 - (tab[p->y][p->x]));
			p->tab_y[p->y][p->x] = p->y1;
			p->tab_x[p->y][p->x] = p->x1;
			more_x += ((p->x_max * 100) / (p->x_max + 2));
			p->x++;
		}
		more_y += ((p->y_max * 100) / (p->y_max + 1));
		p->y++;
	}
}

static void		main_bis(t_struct *p)
{
	while (p->y != p->y_max)
	{
		p->x = 0;
		p->x_draw = 0;
		while (p->x != p->x_max)
		{
			put_the_pixel(p);
			p->x++;
			p->x_draw++;
		}
		p->y++;
		p->y_draw++;
	}
}

int				main(int ac, char **av)
{
	int			fd;
	int			tab[BUFFER][BUFFER];
	t_struct	p[2];

	p->y = 0;
	p->x = 0;
	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (fill_tab(tab, fd, p) == 0)
		return (0);
	p->mlx_ptr = mlx_init();
	pixel(tab, p);
	p->y = 0;
	p->y_draw = 0;
	p->x_draw = 0;
	main_bis(p);
	mlx_key_hook(p->win_ptr, escape, p);
	mlx_loop(p->mlx_ptr);
}
