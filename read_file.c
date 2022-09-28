/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:16 by ttwycros          #+#    #+#             */
/*   Updated: 2022/02/19 17:43:07 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY);
	height = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line)
		{
			height++;
			free(line);
		}
		else
			break ;
	}
	close(fd);
	return (height);
}

/*
//printf("height line %s \n", line);
*/

int	get_width(char *line)
{
	int		width;
	char	**nums;

	nums = ft_split(line, ' ');
	width = 0;
	while (nums[width])
	{
		free(nums[width]);
		width++;
	}
	free(nums);
	return (width);
}

void	fill_matrix(int *z_line, char *line)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	i = 0;
	while (nums[i])
	{
		z_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	z_line[i] = 0;
	free(nums);
}

/*
//printf("nums _%s_\n", nums[i]);
//printf("%3d", z_line[i]);
//printf("\nend\n");
*/

int	global_funk(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	char	**nums;
	int		i;

	fd = open(file_name, O_RDONLY);
	i = -1;
	while (++i < data->height)
	{
		line = get_next_line(fd);
		if (!data->width)
			data->width = get_width(line);
		data->z_matrix[i] = malloc(sizeof(int)
				* (data->width + 1));
		if (!data->z_matrix[i])
			return (free_global(data, &fd, &line));
		fill_matrix(data->z_matrix[i], line);
		free(line);
	}
	data->z_matrix[i] = 0;
	close(fd);
	return (0);
}

/*
//printf("\nline abs_%s-cds\n", line);
//printf("i = %d\n", i);
//printf("width %d\n", data->width);
//printf("\n");
*/

int	read_file(char *file_name, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	//file_name == .fdf
	data->height = get_height(file_name);
	data->z_matrix = malloc((sizeof(int *))
			* (data->height + 1));
	if (!data->z_matrix)
	{
		printf("malloc fail\n");
		return (1);
	}
	if (global_funk(file_name, data))
		return (1);
	return (0);
}

/*
//printf("height = %d\n", data->height);
//printf("malloc for %d spaces\n", data->height + 1);
*/
