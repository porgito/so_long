/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 22:57:54 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/30 01:04:35 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_data *data)
{
	if (key == ESC)
		exitprog(data);
	if (data->alive == 0)
	{
		if (key == UP || key == W)
			data->posy -= 64;
		if (key == DOWN || key == S)
			data->posy += 64;
		if (key == LEFT || key == A)
			data->posx -= 64;
		if (key == RIGHT || key == D)
			data->posx += 64;
		checkcheckwall(data, key);
		if (key == UP || key == DOWN || key == LEFT || key == RIGHT
			|| key == W || key == S || key == D || key == A)
		{
			direction(data, key);
			mapscan(data, data->size);
		}
	}
	if (data->alive == 1 || data->alive == 2)
		reset(data, key);
	return (0);
}

void	checkcheckwall(t_data *data, int key)
{
	checkwall(data);
	if (data->iswall == 1)
	{
		if (key == UP || key == W)
			data->posy += 64;
		if (key == DOWN || key == S)
			data->posy -= 64;
		if (key == LEFT || key == A)
			data->posx += 64;
		if (key == RIGHT || key == D)
			data->posx -= 64;
		mlx_put_image_to_window(data->mlx, data->win, data->grass,
			data->posx, data->posy);
		data->movecount--;
	}
	grabc(data);
}

int	chose(t_data *data)
{
	mlx_key_hook(data->win, key_hook, &data->mlx);
	if (data->alive == 1)
		dead(data);
	if (data->alive == 0)
		animcrystal(data);
	if (data->alive == 2)
		youwin(data);
	if (data->alive == 1 || data->alive == 2)
		nextquit(data);
	return (0);
}

void	reset(t_data *data, int key)
{
	if (key == SPACE)
	{
		data->alive = 0;
		data->init = 0;
		data->movecount = 0;
		if (data->level != 0)
		{
			data->level = 0;
			data->iswin = 0;
			mlx_destroy_window(data->mlx, data->win);
		}
		stockmap(data);
	}
	if (key == ENTER && data->alive == 2 && data->level < 2)
	{
		data->alive = 0;
		data->iswin = 0;
		data->init = 0;
		data->movecount = 0;
		data->level++;
		mlx_destroy_window(data->mlx, data->win);
		stockmap(data);
	}
}

void	exitprog(t_data *data)
{
	free(data);
	exit (0);
}
