/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:26:03 by ttwycros          #+#    #+#             */
/*   Updated: 2022/02/19 17:43:50 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->pixel_bits / 8));
	*(unsigned int *)dst = color;
}

void	do_init_image(t_fdf *data)
{
	if (data->image)
		mlx_destroy_image(data->mlx_ptr, data->image);
	data->image = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->image, &data->pixel_bits,
			&data->size_line, &data->endian);
}

float	maxi(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float	ft_abs(float a)
{
	if (a >= 0)
		return (a);
	else
		return (-a);
}
