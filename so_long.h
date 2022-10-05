/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlaurent <jlaurent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:51:14 by jlaurent          #+#    #+#             */
/*   Updated: 2022/01/30 01:27:04 by jlaurent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# define ESC	53
# define UP		126
# define DOWN	125
# define LEFT	123
# define RIGHT	124
# define W		13
# define A		0
# define S		1
# define D		2
# define SPACE	49
# define ENTER	36

typedef struct s_data{
	void	*mlx;
	void	*win;
	void	*img;
	void	*sprite;
	int		width;
	int		height;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	void	*wall;
	void	*grass;
	void	*crystal;
	void	*perso;
	void	*ufo;
	void	*mean;
	void	*dead;
	void	*gg;
	void	*screen;
	char	*map;
	int		x;
	int		y;
	int		posx;
	int		posy;
	int		init;
	int		enemy;
	int		imean;
	int		iswall;
	int		nbc;
	int		size;
	int		ani;
	int		test;
	int		alive;
	int		iswin;
	int		level;
	int		movecount;
	int		max;
}				t_data;

void	initwin(t_data *data, char *map);
int		stockmap(t_data *data);
void	init_xpm(t_data *data);
void	mapscan(t_data *data, int size);
void	checkwall(t_data *data);
void	checkcheckwall(t_data *data, int key);
void	grabc(t_data *data);
void	countcrystal(t_data *data);
void	direction(t_data *data, int key);
int		animcrystal(t_data *data);
void	initmap(t_data *data, char *map, int i);
void	textinfo(t_data *data);
void	movecounterwin(t_data *data);
//void	enemydraw(t_data *data);
//void	enemypos(t_data *data, int x, int y);
void	enemymove(t_data *data, int i);
void	enemywall(t_data *data, int random);
//void	checkenemywall(t_data *data);
int		dead(t_data *data);
int		chose(t_data *data);
void	reset(t_data *data, int key);
void	restart(t_data *data);
void	youwin(t_data *data);
void	nextquit(t_data *data);
void	exitprog(t_data *data);
int		key_hook(int key, t_data *data);
char	*levelmap(t_data *data);
int		ft_strcmp(const char str1, const char str2);
void	pixelput(t_data *data, int x, int y, int color);
char	*ft_strjoin(char *str1, char *str2);
char	*ft_itoa(int n);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

#endif
