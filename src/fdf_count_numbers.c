/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_count_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 11:55:34 by bmenant           #+#    #+#             */
/*   Updated: 2019/06/04 14:04:43 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	handle_error(int i)
{
	static int error = 0;

	if (i == 0)
		return (1);
	if (error == 0)
		error = i;
	if (error == i)
		return (0);
	exit(0);
	return (1);
}

static int	isint(char *s)
{
	size_t i;

	i = -1;
	while (s[++i])
	{
		if (s[0] == '-')
			i++;
		if (!ft_isdigit(s[i]))
			break ;
	}
	return (i == ft_strlen(s));
}

static int	isvalid(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[0] == '-')
			i++;
		if (!(isint(&str[i])))
			break ;
	}
	return (i);
}

int			fdf_count_numbers(t_data *data, int nbr, int i)
{
	char	**tab;
	char	*line;
	int		fd;

	if ((fd = open(data->str, O_RDONLY)) == -1)
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		tab = ft_strsplit(line, ' ');
		i = -1;
		while (tab[++i])
		{
			if (!(isvalid(tab[i])))
				exit(0);
			free(tab[i]);
		}
		free(line);
		free(tab);
		handle_error(i);
		nbr += i;
	}
	if (close(fd) == -1)
		exit(0);
	return (nbr);
}
