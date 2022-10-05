/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapscan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 20:43:17 by jlaurent          #+#    #+#             */
/*   Updated: 2022/02/09 15:12:52 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initwin(t_data *data, char *map)
{
	int	i;

	i = 0;
	data->width = 0;
	data->height = 0;
	while (map[data->width] != '\n')
		data->width++;
	while (map[i] != '\0')
	{
		if (map[i] == '\n')
			data->height++;
		i++;
	}
	data->win = mlx_new_window(data->mlx, data->width * 64,
			data->height * 64, "so_long");
	data->iswin = 1;
	countcrystal(data);
}

int	stockmap(t_data *data)
{
	int		fd;
	char	buf[1024];
	int		i;
	char	*map;

	i = 0;
	fd = open(levelmap(data), O_RDONLY);
	if (fd == -1)
		return (1);
	data->size = read(fd, buf, 1023);
	buf[data->size] = '\0';
	map = malloc(sizeof(char *) * data->size);
	while (buf[i] != '\0')
	{
		map[i] = buf[i];
		i++;
	}
	map[i] = '\0';
	data->map = malloc(sizeof(char *) * data->size);
	ft_strcpy(data->map, map);
	if (data->iswin != 1)
		initwin(data, map);
	mapscan(data, data->size);
	close(fd);
	return (0);
}

void	mapscan(t_data *data, int size)
{
	int	i;

	i = 0;
	data->x = 0;
	data->y = 0;
	mlx_put_image_to_window(data->mlx, data->win, data->grass,
		data->x, data->y);
	while (size-- > 0)
	{
		if (data->posx != data->x || data->posy != data->y)
			mlx_put_image_to_window(data->mlx, data->win, data->grass,
				data->x, data->y);
		initmap(data, data->map, i);
		if (data->map[i] == 'E' && data->nbc == 0 && data->posx == data->x
			&& data->posy == data->y)
			data->alive = 2;
		data->x += 64;
		if (data->map[i] == '\n')
		{
			data->y += 64;
			data->x = 0;
		}
		i++;
	}
	textinfo(data);
}

void	checkwall(t_data *data)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	data->iswall = 0;
	while (data->map[i] != '\0')
	{
		if (data->map[i] == '1' && x == data->posx && y == data->posy)
			data->iswall = 1;
		x += 64;
		if (data->map[i] == '\n')
		{
			y += 64;
			x = 0;
		}
		i++;
	}
}

char	*levelmap(t_data *data)
{
	char	*test;
	char	*level1;
	char	*level2;

	level2 = "test.ber";
	test = "leveltest.ber";
	level1 = "level1.ber";
	if (data->level == 1)
		return (level1);
	if (data->level == 2)
		return (level2);
	return (test);
}
