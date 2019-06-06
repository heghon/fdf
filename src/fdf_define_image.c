/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 12:04:19 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 13:37:30 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_image			*fdf_define_image(t_data data)
{
	t_image *image;

	if (!(image = ft_memalloc(sizeof(t_image))))
		fdf_free_and_exit(&data);
	if (!(image->ptr = mlx_new_image(data.mlx_ptr, data.win_x, data.win_y)))
	{
		free(image);
		fdf_free_and_exit(&data);
	}
	if (!(image->image = mlx_get_data_addr(image->ptr,
					&(image->bpp), &(image->size_line), &(image->endian))))
	{
		free(image);
		fdf_free_and_exit(&data);
	}
	image->width = data.win_x;
	image->height = data.win_y;
	return (image);
}
