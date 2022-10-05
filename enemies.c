/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:41:25 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/30 01:32:19 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	stopnorme(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->perso,
		data->x, data->y);
	data->posx = data->x;
	data->posy = data->y;
	data->init = 1;
}

void	test(t_data *data, int i)
{
	if (data->test == 25)
		enemymove(data, i);
	if (data->test == 81)
		enemymove(data, i);
	if (data->test == 111)
		data->test = 0;
	data->test++;
}

void	initmap(t_data *data, char *map, int i)
{
	if (map[i] == 'M')
	{
		mlx_put_image_to_window(data->mlx, data->win, data->mean,
			data->x, data->y);
		if (data->posx == data->x && data->posy == data->y)
			data->alive = 1;
		test(data, i);
	}
	if (map[i] == '1')
		mlx_put_image_to_window(data->mlx, data->win, data->wall,
			data->x, data->y);
	if (map[i] == 'C')
		mlx_put_image_to_window(data->mlx, data->win, data->crystal,
			data->x, data->y);
	if (map[i] == 'P' && data->init == 1)
		mlx_put_image_to_window(data->mlx, data->win, data->perso,
			data->posx, data->posy);
	if (map[i] == 'P' && data->init != 1)
		stopnorme(data);
	if (map[i] == 'E')
		mlx_put_image_to_window(data->mlx, data->win, data->ufo,
			data->x, data->y);
}

void	enemymove(t_data *data, int i)
{
	int	random;

	data->max = 15;
	srand(time(NULL));
	random = (rand() % (data->max + 1));
	if (random == 0 && data->map[i + 1] == '0')
	{
		data->map[i] = '0';
		data->map[i + 1] = 'M';
	}
	if (random == 5 && data->map[i - 1] == '0')
	{
		data->map[i] = '0';
		data->map[i - 1] = 'M';
	}
	if (random == 10 && data->map[i - data->width] == '0')
	{
		data->map[i] = '0';
		data->map[i - data->width] = 'M';
	}
	if (random == 15 && data->map[i + data->width] == '0')
	{
		data->map[i] = '0';
		data->map[i + data->width] = 'M';
	}
}

int	dead(t_data *data)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	data->screen = mlx_new_image(data->mlx, data->width * 64,
			data->height * 64);
	data->addr = mlx_get_data_addr(data->screen, &data->bpp,
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->screen, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->dead,
		data->width * 64 / 2 - 159, data->height * 64 / 2 - 158);
	restart(data);
	return (0);
}
