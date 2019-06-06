/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_free_and_exit.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:58:42 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 10:15:54 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_free_and_exit(t_data *data)
{
	free(data->point);
	if (data->image->image)
		free(data->image->image);
	if (data->image)
		free(data->image);
	exit(0);
}
