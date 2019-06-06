/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:08:07 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 13:39:17 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		init_settings(t_data data, t_point *a, t_point *b)
{
	int sum;

	if (300 / data.nb_lines > MULTI_MIN)
		sum = 300 / data.nb_lines;
	else
		sum = MULTI_MIN;
	sum = (sum < MULTI_MAX ? sum : MULTI_MAX);
	if (sum + data.modif.zoom > 0)
	{
		a->x -= data.x_pos;
		a->x *= sum + data.modif.zoom;
		a->y *= sum + data.modif.zoom;
		a->x += data.x_pos;
		b->x -= data.x_pos;
		b->x *= sum + data.modif.zoom;
		b->y *= sum + data.modif.zoom;
		b->x += data.x_pos;
	}
	a->z *= data.modif.z;
	b->z *= data.modif.z;
}

static void		projection_iso(t_data data, t_point a, t_point b, t_line *line)
{
	line->x1 = (a.x - a.y) * cos(0.5) + data.modif.x;
	line->y1 = -a.z + (a.x + a.y) * sin(0.5) + data.modif.y;
	line->x2 = (b.x - b.y) * cos(0.5) + data.modif.x;
	line->y2 = -b.z + (b.x + b.y) * sin(0.5) + data.modif.y;
	line->line_x = line->x1;
	line->line_y = line->y1;
	line->dx = line->x2 - line->x1;
	line->dy = line->y2 - line->y1;
}

static void		projection_para(t_data data, t_point a, t_point b, t_line *line)
{
	line->x1 = a.x - a.z * 2 + data.modif.x;
	line->y1 = a.y - a.z * 5 + data.modif.y;
	line->x2 = b.x - b.z * 2 + data.modif.x;
	line->y2 = b.y - b.z * 5 + data.modif.y;
	line->line_x = a.x - a.z * 2 + data.modif.x;
	line->line_y = a.y - a.z * 5 + data.modif.y;
	line->dx = (b.x - b.z * 2) - (a.x - a.z * 2);
	line->dy = (b.y - b.z * 5) - (a.y - a.z * 5);
}

static int		settings(t_data data, t_point a, t_point b, t_line *line)
{
	init_settings(data, &a, &b);
	if (data.modif.proj)
		projection_iso(data, a, b, line);
	if (!data.modif.proj)
		projection_para(data, a, b, line);
	line->x_inc = (line->dx > 0 ? 1 : -1);
	line->y_inc = (line->dy > 0 ? 1 : -1);
	line->dx = ft_absolute(line->dx);
	line->dy = ft_absolute(line->dy);
	line->line_z = (a.z > b.z ? a.z : b.z);
	return (fdf_print_line(data, *line));
}

int				fdf_define_line(t_data data)
{
	int		i;
	int		j;
	t_line	line;

	i = -1;
	j = 0;
	while (++i < data.nbrs)
	{
		if ((i + 1) < data.nbrs && data.point[i + 1].y == data.point[i].y)
			settings(data, data.point[i], data.point[i + 1], &line);
		while ((i + j) < data.nbrs && data.point[i + j].y == data.point[i].y)
			j++;
		if (data.point[i].x == data.point[i + j].x)
			settings(data, data.point[i], data.point[i + j], &line);
	}
	mlx_put_image_to_window(data.mlx_ptr,
			data.win_ptr, data.image->ptr, 0, 0);
	fdf_put_instructions(data);
	return (1);
}
