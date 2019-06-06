/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:08:26 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 11:56:38 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		totaltitude(t_data data)
{
	int max;
	int min;
	int i;

	max = 0;
	min = 0;
	i = -1;
	while (++i < data.nbrs)
	{
		max = (max < data.point[i].z ? data.point[i].z : max);
		min = (min > data.point[i].z ? data.point[i].z : min);
	}
	return (max - min);
}

static int		init(char *line, int nbr, t_data data)
{
	int			i;
	static int	j = -1;
	char		**tab;

	tab = ft_strsplit(line, ' ');
	i = -1;
	while (tab[++i] && ++j >= 0)
	{
		data.point[j].x = i;
		data.point[j].y = nbr;
		data.point[j].z = ft_atoi(tab[i]);
	}
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (1);
}

static void		start_of_the_map(t_data *data, int nb)
{
	int i;
	int x;

	x = (nb * 120 < WIN_MAX_L ? nb * 120 : WIN_MAX_L);
	if (data->nbrs < 5)
		exit(0);
	data->x_pos = x / 3;
	i = -1;
	while (++i < data->nbrs)
		data->point[i].x += x / 3;
}

t_point			*fdf_parser(t_data *data)
{
	int		fd;
	int		num_line;
	char	*line;
	t_point	*point;

	if ((fd = open(data->str, O_RDONLY)) == -1)
		exit(0);
	if (!(point = (t_point *)malloc(sizeof(t_point) * data->nbrs)))
		exit(0);
	data->point = point;
	num_line = -1;
	while (get_next_line(fd, &line) == 1 && ++num_line >= 0)
	{
		init(line, num_line, *data);
		free(line);
	}
	start_of_the_map(data, num_line);
	data->diff = totaltitude(*data);
	if (close(fd) == -1)
		fdf_free_and_exit(data);
	return (data->point);
}
