/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_projection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 22:17:11 by ttwycros          #+#    #+#             */
/*   Updated: 2022/02/19 17:48:24 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	isometric_and_rotate(int z, int z1, t_fdf *data, t_curr	*temp)
{
	int	x_copy;
	int	x1_copy;

	x_copy = temp->x;
	temp->x = x_copy * cos(data->rotation) - temp->y * sin(data->rotation);
	temp->y = x_copy * sin(data->rotation) + temp->y * cos(data->rotation);
	temp->x = (temp->x - temp->y) * cos(data->angle_x);
	temp->y = (temp->x + temp->y) * sin(data->angle_y) - z;
	x1_copy = temp->x1;
	temp->x1 = x1_copy * cos(data->rotation) - temp->y1 * sin(data->rotation);
	temp->y1 = x1_copy * sin(data->rotation) + temp->y1 * cos(data->rotation);
	temp->x1 = (temp->x1 - temp->y1) * cos(data->angle_x);
	temp->y1 = (temp->x1 + temp->y1) * sin(data->angle_y) - z1;
}

/*
after x_copy
	temp->x = x_copy * cos(data->rotation) - temp->y * sin(data->rotation);
	temp->y = x_copy * sin(data->rotation) + temp->y * cos(data->rotation);
after x1_copy
	temp->x1 = x1_copy * cos(data->rotation) - temp->y1 * sin(data->rotation);
	temp->y1 = x1_copy * sin(data->rotation) + temp->y1 * cos(data->rotation);


*/

void	zoom(t_fdf *data, t_curr	*temp)
{
	temp->x *= data->zoom;
	temp->x1 *= data->zoom;
	temp->y *= data->zoom;
	temp->y1 *= data->zoom;
}

void	color(int z, int z1, t_fdf *data)
{
	if (z > 0 || z1 > 0)
		data->color = 0xe80c0c;
	else
		data->color = 0xffffff;
}

void	shift(t_fdf *data, t_curr *temp)
{
	temp->x += data->shift_x;
	temp->x1 += data->shift_x;
	temp->y += data->shift_y;
	temp->y1 += data->shift_y;
}

void	isometric_convert(t_fdf *data, t_curr	*temp)
{
	int	z;
	int	z1;

	z = data->z_matrix[(int)temp->y][(int)temp->x];
	z1 = data->z_matrix[(int)temp->y1][(int)temp->x1];
	zoom(data, temp);
	color(z, z1, data);
	isometric_and_rotate(z, z1, data, temp);
	shift(data, temp);
}
