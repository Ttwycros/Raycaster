/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 21:23:28 by ttwycros          #+#    #+#             */
/*   Updated: 2022/02/19 18:01:45 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"
#define PI 3.14159

int	just_say_yes_or_no(int key)
{
	if (key == 123 || key == 124
		|| key == 125 || key == 126
		|| key == 13 || key == 1 || key == 0 || key == 2)
		return (1);
	return (0);
}

int	key_hook(int key, t_fdf *data)
{
	if (key == 126)
		data->shift_y -= 30;
	if (key == 125)
		data->shift_y += 30;
	if (key == 123)
		data->shift_x -= 30;
	if (key == 124)
		data->shift_x += 30;
	if (key == 13)
		printf("w\n");
		data->px+=data->pdx;
		data->py+=data->pdy; 
		//data->angle_y += 0.05;
	if (key == 1)
		data->px-=data->pdx;
		data->py+-data->pdy;
		printf("s\n");
		//data->angle_y -= 0.05;
	if (key == 53)
		close_window(0);
	if (key == 0)
		printf("a\n");
		data->pa-=0.1;
		if(data->pa < 0)
		{
			data->pa+=2*PI;
		} 
		data->pdx=cos(data->pa)*5;
		data->pdy=sin(data->pa)*5;
		//data->rotation += 0.05;
	if (key == 2)
		printf("d\n");
		data->pa+-0.1;
		if (data->pa > 2 * PI)
		{
			data->pa-=2*PI;
		}
		data->pdx=cos(data->pa)*5;
		data->pdy=sin(data->pa)*5;
		//data->rotation -= 0.05;
	if (just_say_yes_or_no(key))
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}

/*
printf("%d\n", key);
	if (key == 0)
		data->rotation += 0.05;
	if (key == 2)
		data->rotation -= 0.05;

	if (key == 24)
		data->zoom += 2;
	if (key == 27)
		if (data->zoom > 3)
			data->zoom -= 2;
*/

int	close_window(int zero)
{
	(void) zero;
	exit(EXIT_FAILURE);
}

/*
printf("windows closed\n");
*/

int	mouse_hook(int key, int x, int y, t_fdf *data)
{
	(void) x;
	(void) y;
	if (key == 4)
		data->zoom += 1;
	if (key == 5)
		if (data->zoom > 3)
			data->zoom -= 1;
	if (key == 4 || key == 5)
	{
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw(data);
	}
	return (0);
}
