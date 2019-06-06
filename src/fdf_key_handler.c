/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:11:13 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 11:48:16 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	change_altitude(t_data *data, int key)
{
	if (key == H && data->modif.z < 20)
		data->modif.z += 1;
	if (key == L && data->modif.z > -20)
		data->modif.z -= 1;
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}

static int	change_color(t_data *data)
{
	data->modif.color = (data->modif.color == 0 ? 1 : 0);
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}

static int	move_drawing(t_data *data, int key)
{
	if (key == ARROW_UP)
		data->modif.y -= 20;
	if (key == ARROW_DOWN)
		data->modif.y += 20;
	if (key == ARROW_RIGHT)
		data->modif.x += 20;
	if (key == ARROW_LEFT)
		data->modif.x -= 20;
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}

static int	change_projection(t_data *data)
{
	data->modif.proj = (data->modif.proj == 0 ? 1 : 0);
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}

int			fdf_key_handler(int key, t_data *data)
{
	if (key == ESC)
		fdf_free_and_exit(data);
	if (key == ARROW_UP || key == ARROW_DOWN ||
			key == ARROW_LEFT || key == ARROW_RIGHT)
		move_drawing(data, key);
	if (key == C)
		change_color(data);
	if (key == P)
		change_projection(data);
	if (key == H || key == L)
		change_altitude(data, key);
	return (0);
}
