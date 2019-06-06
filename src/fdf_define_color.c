/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_define_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 09:56:18 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 14:50:49 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		fdf_define_color(t_data data, t_line line)
{
	int		nbr;

	if (data.modif.color == 1)
		return (WHITE);
	else if (data.modif.color == 0 && data.diff != 0)
	{
		nbr = (line.line_z / data.diff) * 10;
		if (line.line_z == 0)
			return (BROWN);
		if (nbr < 3 && nbr > -3)
			return (DARK_RED);
		if (nbr < 10 && nbr > -10)
			return (RED);
		if (nbr < 20 && nbr > -20)
			return (ORANGE);
		if (nbr < 30 && nbr > -30)
			return (YELLOW);
		if (nbr < 40 && nbr > -40)
			return (LIGHT_YELLOW);
		return (WHITE);
	}
	else
		return (RED);
}
