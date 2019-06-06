/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:23:04 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 12:12:31 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	dezoom(t_data *data)
{
	if (data->modif.zoom > -MIN_ZOOM)
		data->modif.zoom -= 2;
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}

static int	zoom(t_data *data)
{
	if (data->modif.zoom < MAX_ZOOM)
		data->modif.zoom += 2;
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}

int			fdf_mouse_handler(int button, int x, int y, t_data *data)
{
	if (button == 4 && (x && y))
		return (zoom(data));
	if (button == 5 && (x && y))
		return (dezoom(data));
	ft_bzero(data->image->image, data->image->width * (data->image->bpp / 8)
			* data->image->height);
	fdf_define_line(*data);
	return (0);
}
