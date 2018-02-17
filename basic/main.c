/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vle-gal <vle-gal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 13:45:37 by vle-gal           #+#    #+#             */
/*   Updated: 2018/02/17 09:22:02 by vle-gal          ###   ########.fr       */
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
	// if (p->x_draw != p->x_max)
	if (p->y_draw != p->y_max && (p->x_draw + 1) != p->x_max)
	{
		p->x1 = tab_x[0][p->y_draw][p->x_draw];
		p->y1 = tab_y[0][p->y_draw][p->x_draw];
		p->x2 = tab_x[0][p->y_draw][p->x_draw + 1];
		p->y2 = tab_y[0][p->y_draw][p->x_draw + 1];
		printf("first[]%d %d\n", p->y1, p->x1);
		printf("%d %d\n", p->y2, p->x2);
		gathering_pixel(p);
	}
	// printf("condition : %d %d\n", p->y_draw, p->y_max);
	if ((p->y_draw + 1) != p->y_max)
	{
		p->x1 = tab_x[0][p->y_draw][p->x_draw];
		p->y1 = tab_y[0][p->y_draw][p->x_draw];
		p->x2 = tab_x[0][p->y_draw + 1][p->x_draw];
		p->y2 = tab_y[0][p->y_draw + 1][p->x_draw];
		// printf("second{}%d %d\n", p->y1, p->x1);
		// printf("%d %d\n", p->y2, p->x2);
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

static void		before_pixel(t_struct *p, void *tabx, void *taby)
{
	int (*tab_y)[p->y_max][p->x_max];
	int (*tab_x)[p->y_max][p->x_max];

	tab_y = taby;
	tab_x = tabx;
	// printf("TEsT\n");
	// printf("-------------%d\n", tab_y[0][1][1]);
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

	// printf("%d %d\n", p->x_max, p->y_max);
	// printf("%d %d\n", (((p->x_max + p->y_max) - 1) * 100), ((((p->y_max + p->x_max) - 1) * 100) / 2));
	p->win_ptr = mlx_new_window(p->mlx_ptr, (((p->x_max + p->y_max) - 1) * 100)\
	, ((((p->y_max + p->x_max) - 1) * 100) / 2), "DUKE NUKEM");
	printf("TES\n");
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
			tab_y[p->y][p->x] = (p->iso_y1 - (tab[p->y][p->x]));
			tab_x[p->y][p->x] = (p->iso_x1 + (((p->y_max * 100)) + 5));
			more_x += ((p->x_max * 100) / (p->x_max + 2));
			p->x++;
		}
		more_y += ((p->y_max * 100) / (p->y_max + 1));
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
			// printf("remplissage = %d %d\n", p->y, p->x);
			tab[p->y][p->x] = (ft_atoi(line + i) * 5);
			// printf("after == %d\n", tab[p->y][p->x]);
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
	pixel(tab, p);
	return (1);
}



int				main(int ac, char **av)
{
	int			fd;
	t_struct	p = {NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	p.mlx_ptr = mlx_init();
	if (fill_tab(fd, &p) == 0)
		return (0);
	mlx_key_hook(p.win_ptr, escape, &p);
	mlx_loop(p.mlx_ptr);
}
