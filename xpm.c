/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 15:35:22 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/29 23:20:16 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_xpm(t_data *data)
{
	int	w;
	int	h;

	data->wall = mlx_xpm_file_to_image(data->mlx, "./box.xpm", &w, &h);
	data->grass = mlx_xpm_file_to_image(data->mlx, "./grass.xpm", &w, &h);
	data->crystal = mlx_xpm_file_to_image(data->mlx, "./cry0.xpm", &w, &h);
	data->perso = mlx_xpm_file_to_image(data->mlx, "./pdown.xpm", &w, &h);
	data->ufo = mlx_xpm_file_to_image(data->mlx, "./ufo.xpm", &w, &h);
	data->mean = mlx_xpm_file_to_image(data->mlx, "./ufo.xpm", &w, &h);
	data->dead = mlx_xpm_file_to_image(data->mlx, "./deathscreen.xpm", &w, &h);
	data->gg = mlx_xpm_file_to_image(data->mlx, "./youwin.xpm", &w, &h);
}

void	direction(t_data *data, int key)
{
	int	w;
	int	h;

	mlx_destroy_image(data->mlx, data->perso);
	if (key == UP || key == W)
		data->perso = mlx_xpm_file_to_image(data->mlx, "./pup.xpm", &w, &h);
	if (key == DOWN || key == S)
		data->perso = mlx_xpm_file_to_image(data->mlx, "./pdown.xpm", &w, &h);
	if (key == LEFT || key == A)
		data->perso = mlx_xpm_file_to_image(data->mlx, "./pleft.xpm", &w, &h);
	if (key == RIGHT || key == D)
		data->perso = mlx_xpm_file_to_image(data->mlx, "./pright.xpm", &w, &h);
	data->movecount++;
}

int	animcrystal(t_data *data)
{
	int	w;
	int	h;

	mlx_destroy_image(data->mlx, data->crystal);
	if (data->ani < 15)
		data->crystal = mlx_xpm_file_to_image(data->mlx, "./cry0.xpm", &w, &h);
	if (data->ani >= 15 && data->ani < 30)
		data->crystal = mlx_xpm_file_to_image(data->mlx, "./cry1.xpm", &w, &h);
	if (data->ani >= 30 && data->ani < 45)
		data->crystal = mlx_xpm_file_to_image(data->mlx, "./cry2.xpm", &w, &h);
	if (data->ani >= 45 && data->ani < 60)
		data->crystal = mlx_xpm_file_to_image(data->mlx, "./cry3.xpm", &w, &h);
	if (data->nbc == 0)
		data->ufo = mlx_xpm_file_to_image(data->mlx, "./ufo.xpm", &w, &h);
	data->ani++;
	if (data->ani == 60)
		data->ani = 0;
	mapscan(data, data->size);
	return (0);
}
