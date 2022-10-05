/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:53:18 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/30 00:57:08 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->mlx = mlx_init();
	init_xpm(data);
	data->ani = 0;
	data->alive = 0;
	data->level = 0;
	data->movecount = 0;
	stockmap(data);
	mlx_loop_hook(data->mlx, chose, data);
	mlx_loop(data->mlx);
	return (0);
}

void	restart(t_data *data)
{
	char	*space;

	space = "Press SPACE to restart";
	mlx_string_put(data->mlx, data->win, data->width * 64 - 190,
		data->height * 64 - 10, 0xFFFFFF, space);
}

void	textinfo(t_data *data)
{
	char	*str1;
	char	*str2;

	str1 = "Move counter : ";
	mlx_string_put(data->mlx, data->win, 10, data->height * 64 - 10, 0xFFFFFF,
		ft_strjoin(str1, ft_itoa(data->movecount)));
	str2 = "Level ";
	mlx_string_put(data->mlx, data->win, data->width * 64 / 2 - 24, 25,
		0xFFC300, ft_strjoin(str2, ft_itoa(data->level + 1)));
}

void	movecounterwin(t_data *data)
{
	char	*str;

	str = "Level finished in ";
	mlx_string_put(data->mlx, data->win, 10, data->height * 64 - 10, 0xFFFFFF,
		ft_strjoin(ft_strjoin(str, ft_itoa(data->movecount)), " moves, GG !"));
}

void	nextquit(t_data *data)
{
	char	*str1;
	char	*str2;

	str1 = "Press ESC to quit";
	str2 = "Press ENTER for next level";
	mlx_string_put(data->mlx, data->win, 10, 20, 0xC70039, str1);
	if (data->level < 2 && data->alive == 2)
		mlx_string_put(data->mlx, data->win, data->width * 64 - 190,
			data->height * 64 - 30, 0xFFC300, str2);
}
