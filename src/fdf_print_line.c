/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:14:16 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 13:34:29 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		print_pixel(t_data data, t_line line, int color)
{
	if (!(line.line_y >= data.image->height || line.line_y < 0 ||
			line.line_x < 0 || line.line_x >= data.image->width))
		*(int *)(data.image->image + ((line.line_x + line.line_y
						* data.image->width) * data.image->bpp / 8)) = color;
}

static void		the_rest(t_data data, t_line line, int i)
{
	int		sum;

	sum = line.dy / 2;
	print_pixel(data, line, fdf_define_color(data, line));
	while (++i <= line.dy)
	{
		line.line_y += line.y_inc;
		sum += line.dx;
		if (sum >= line.dy)
		{
			sum -= line.dy;
			line.line_x += line.x_inc;
		}
		print_pixel(data, line, fdf_define_color(data, line));
	}
}

int				fdf_print_line(t_data data, t_line line)
{
	int		i;
	int		sum;

	i = 0;
	if (line.dx > line.dy)
	{
		sum = line.dx / 2;
		print_pixel(data, line, fdf_define_color(data, line));
		while (++i <= line.dx)
		{
			line.line_x += line.x_inc;
			sum += line.dy;
			if (sum >= line.dx)
			{
				sum -= line.dx;
				line.line_y += line.y_inc;
			}
			print_pixel(data, line, fdf_define_color(data, line));
		}
	}
	else
		the_rest(data, line, i);
	return (1);
}
