/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grab.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:42:37 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/30 01:14:18 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	grabc(t_data *data)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == 'C' && x == data->posx && y == data->posy)
		{
			data->map[i] = '0';
			data->nbc--;
			mlx_put_image_to_window(data->mlx, data->win, data->grass, x, y);
			break ;
		}
		x += 64;
		if (data->map[i] == '\n')
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

void	youwin(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	data->screen = mlx_new_image(data->mlx, data->width * 64,
			data->height * 64);
	data->addr = mlx_get_data_addr(data->screen, &data->bpp,
			&data->line_length, &data->endian);
	mlx_put_image_to_window(data->mlx, data->win, data->screen, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->gg,
		data->width * 64 / 2 - 213, data->height * 64 / 2 - 120);
	movecounterwin(data);
	restart(data);
}

void	countcrystal(t_data *data)
{
	int	i;

	i = 0;
	data->nbc = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == 'C')
			data->nbc++;
		i++;
	}
}
