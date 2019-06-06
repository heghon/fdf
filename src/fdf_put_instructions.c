/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_put_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 13:39:25 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 14:04:03 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	fdf_put_instructions(t_data data)
{
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 0, RED, "INSTRUCTIONS");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 20, WHITE, "   -----");
	mlx_string_put(data.mlx_ptr, data.win_ptr,
			0, 40, WHITE, "Movements : arrows");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 60, WHITE, "   -----");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 80, WHITE, "Color : C");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 100, WHITE, "   -----");
	mlx_string_put(data.mlx_ptr, data.win_ptr,
			0, 120, WHITE, "Projection : P");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 140, WHITE, "   -----");
	mlx_string_put(data.mlx_ptr, data.win_ptr,
			0, 160, WHITE, "Zoom : mouse scroll");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 180, WHITE, "   -----");
	mlx_string_put(data.mlx_ptr, data.win_ptr,
			0, 200, WHITE, "Altitude : H - L");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 220, WHITE, "   -----");
	mlx_string_put(data.mlx_ptr, data.win_ptr, 0, 240, WHITE, "Quit : ESC");
}
