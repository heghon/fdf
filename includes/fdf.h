/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:51:41 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 14:27:00 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>

# define A 0
# define B 11
# define C 8
# define D 2
# define E 14
# define F 3
# define G 5
# define H 4
# define I 34
# define J 38
# define K 40
# define L 37
# define M 46
# define N 45
# define O 31
# define P 35
# define Q 12
# define R 15
# define S 1
# define T 17
# define U 32
# define V 9
# define W 13
# define X 7
# define Y 16
# define Z 6
# define ESC 53
# define TAB 48
# define RETURN 36
# define L_SHIFT 257
# define R_SHIFT 258
# define SPACE 49
# define ARROW_UP 126
# define ARROW_LEFT 123
# define ARROW_RIGHT 124
# define ARROW_DOWN 125
# define PAGE_UP 116
# define PAGE_DOWN 121

# define WIN_MAX_L 2560
# define WIN_MAX_H 1440
# define WIN_MIN_L 1000
# define WIN_MIN_H 600
# define MULTI_MAX 50
# define MULTI_MIN 5
# define MAX_ZOOM 100
# define MIN_ZOOM 100

# define BROWN 0x825C26
# define DARK_RED 0xC8621C
# define RED 0xFF3700
# define ORANGE 0xFF8C00
# define YELLOW 0xFFD52A
# define LIGHT_YELLOW 0xFFFF00
# define WHITE 0xFFFFFF

typedef struct		s_line
{
int					x1;
int					y1;
int					x2;
int					y2;
int					dx;
int					dy;
int					x_inc;
int					y_inc;
int					line_x;
int					line_y;
int					line_z;
}					t_line;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

typedef struct		s_modif
{
	int				x;
	int				y;
	int				z;
	int				proj;
	int				zoom;
	int				color;
}					t_modif;

typedef struct		s_image
{
	void			*ptr;
	char			*image;
	int				width;
	int				height;
	int				bpp;
	int				size_line;
	int				endian;
}					t_image;

typedef struct		s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_x;
	int				win_y;
	int				x_pos;
	int				nb_lines;
	int				nbrs;
	int				diff;
	char			*str;
	t_image			*image;
	t_modif			modif;
	t_point			*point;
}					t_data;

int					fdf_count_numbers(t_data *data, int nbr, int i);
int					fdf_define_color(t_data data, t_line line);
t_image				*fdf_define_image(t_data data);
int					fdf_define_line(t_data data);
void				fdf_free_and_exit(t_data *data);
int					fdf_key_handler(int key, t_data *data);
int					fdf_mouse_handler(int button, int x, int y, t_data *data);
t_point				*fdf_parser(t_data *data);
int					fdf_print_line(t_data data, t_line line);
void				fdf_put_instructions(t_data data);

#endif
