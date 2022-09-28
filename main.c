/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:18:13 by ttwycros          #+#    #+#             */
/*   Updated: 2022/02/19 17:25:21 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	data_init(t_fdf *data)
{
	data->zoom = 20;
	data->angle_x = 0.7;
	data->angle_y = 0.7;
	data->rotation = 0.7;
	data->width = 0;
	data->shift_x = 450;
	data->shift_y = 250;
}

/*
void	debug_print(t_fdf	*data)
{
	for (int i = 0; i < data->height; i++)
	{
		for (int j = 0; j < data->width; j++)
		{
			printf("%3d", data->z_matrix[i][j]);
		}
		printf("\n");
	}
}
*/

int	main(int argc, char **agrv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		printf("Пошел нахуй");
		return (1);
	}
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (EXIT_FAILURE);
	data_init(data);
	if (read_file(agrv[1], data))
	{
		free(data);
		(EXIT_FAILURE);
	}
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIDTH, HEIGHT, "FDF");
	if (draw(data))
		return (free_data_protected(data));
	mlx_key_hook(data->win_ptr, key_hook, data);
	mlx_mouse_hook(data->win_ptr, mouse_hook, data);
	mlx_hook(data->win_ptr, 17, 0, &close_window, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

//printf("Reading %s \n", agrv[1]);

//read_file_debug(data);
//debug_print(data);
//printf("Reading was successful %s \n", agrv[1]);
//printf("Init was successful \n");
//printf("Draw was successful \n");

/*

	debug_print(data);
	free_data_protected(data);
	printf("Init was successful \n");

void	read_file_debug(t_fdf	*data)
{
	int i = 0;
	int j = 0;

	data->height = 50;
	data->width = 20;
	data->z_matrix = malloc((sizeof(int *)) * (data->height + 1));
	while (i < data->height)
	{
		j = 0;
		data->z_matrix[i] = malloc(sizeof(int) * (data->width + 1));
		while (j < data->width)
		{
			data->z_matrix[i][j] = i + j;
			j++;
		}
		data->z_matrix[i][j] = 0;
		i++;
	}
	data->z_matrix[i] = 0;
}
*/