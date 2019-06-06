/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:00:17 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 14:26:07 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		quit_now(void)
{
	ft_putendl("fdf usage : ./fdf <file.fdf>");
	exit(0);
}

static int		init(t_data *data)
{
	data->modif.x = 0;
	data->modif.y = 0;
	data->modif.z = 1;
	data->modif.zoom = 0;
	data->modif.proj = 1;
	data->modif.color = 1;
	return (1);
}

static void		count_lines(t_data *data)
{
	int		fd;
	char	*line;
	int		nbr;

	if ((fd = open(data->str, O_RDONLY)) == -1)
		exit(0);
	nbr = 0;
	while (get_next_line(fd, &line) == 1 && ++nbr)
		free(line);
	data->win_y = nbr;
	data->win_x = 2 * nbr;
	if (close(fd) == -1)
		exit(0);
}

static void		define_window(t_data *data)
{
	if (data->win_x * 100 < WIN_MAX_L)
		data->win_x *= 100;
	else
		data->win_x = WIN_MAX_L;
	if (data->win_y * 140 < WIN_MAX_H)
		data->win_y *= 140;
	else
		data->win_y = WIN_MAX_H;
	data->win_x = (data->win_x > WIN_MIN_L ? data->win_x : WIN_MIN_L);
	data->win_y = (data->win_y > WIN_MIN_H ? data->win_y : WIN_MIN_H);
}

int				main(int ac, char **av)
{
	t_data	data;
	t_point	*point;

	if (ac != 2)
		quit_now();
	data.str = av[1];
	data.nbrs = fdf_count_numbers(&data, 0, -1);
	init(&data);
	point = fdf_parser(&data);
	count_lines(&data);
	define_window(&data);
	data.mlx_ptr = mlx_init();
	if (!(data.win_ptr = mlx_new_window(data.mlx_ptr,
					data.win_x, data.win_y, "42 - fdf - 42")))
		fdf_free_and_exit(&data);
	fdf_put_instructions(data);
	if (!(data.image = fdf_define_image(data)))
		fdf_free_and_exit(&data);
	fdf_define_line(data);
	mlx_key_hook(data.win_ptr, fdf_key_handler, &data);
	mlx_mouse_hook(data.win_ptr, fdf_mouse_handler, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
