/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:21:06 by ttwycros          #+#    #+#             */
/*   Updated: 2022/02/18 22:40:18 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	vertex(float x1, float y1, float x2, float y2, t_fdf *data)
{
	float	max;
	t_curr	*temp;

	temp = malloc(sizeof(t_curr));
	if (!temp)
		return (EXIT_FAILURE);
	temp->x = x2;
	temp->y = y2;
	temp->x1 = x1;
	temp->y1 = y1;
	zoom(data, temp); //working incorectly with high zoom val
	temp->x_step = temp->x1 - temp->x;
	temp->y_step = temp->y1 - temp->y;
	max = maxi(ft_abs(temp->x_step), ft_abs(temp->y_step));
	temp->x_step /= max;
	temp->y_step /= max;
	while ((int)(temp->x - temp->x1) || (int)(temp->y - temp->y1))
	{
		if (temp->x < WIDTH && temp->y < HEIGHT && temp->x >= 0 && temp->y >= 0)
			my_mlx_pixel_put(data, temp->x, temp->y, data->color);
		temp->x += temp->x_step;
		temp->y += temp->y_step;
	}
	free(temp);
	return (0);
}

int	bresenham(float x1, float y1, t_fdf *data)
{
	float	max;
	t_curr	*temp;

	temp = malloc(sizeof(t_curr));
	if (!temp)
		return (EXIT_FAILURE);
	temp->x = data->x_temp;
	temp->y = data->y_temp;
	temp->x1 = x1;
	temp->y1 = y1;
	isometric_convert(data, temp);
	temp->x_step = temp->x1 - temp->x;
	temp->y_step = temp->y1 - temp->y;
	max = maxi(ft_abs(temp->x_step), ft_abs(temp->y_step));
	temp->x_step /= max;
	temp->y_step /= max;
	while ((int)(temp->x - temp->x1) || (int)(temp->y - temp->y1))
	{
		if (temp->x < WIDTH && temp->y < HEIGHT && temp->x >= 0 && temp->y >= 0)
			my_mlx_pixel_put(data, temp->x, temp->y, data->color);
		temp->x += temp->x_step;
		temp->y += temp->y_step;
	}
	free(temp);
	return (0);
}


int draw_obj(t_player *player, t_fdf *data, int color)
{
	int x = player->x_player;
	int y = player->y_player;
	int size_x = player->x_player+player->side;
	int size_y = player->y_player+player->side;

	while (y < size_y)
	{
		x = player->x_player;
		while (x < size_x)
		{
			if (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
			{
				my_mlx_pixel_put(data, x, y, color);
			}
			//printf("x = %d y = %d\n", x, y);
			x++;
		}
		
		y++;
	}
	return (1); //change that

}
/*printf("isometric success\n");*/


#define mapX  8      //map width
#define mapY  8      //map height
#define mapS 64      //map cube size
int map[]=           //the map array. Edit to change level but keep the outer walls
{
 1,1,1,1,1,1,1,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,1,0,0,0,0,1,
 1,0,0,0,0,0,0,1,
 1,0,0,0,0,1,0,1,
 1,0,0,0,0,0,0,1,
 1,1,1,1,1,1,1,1,	
};


void drawMap2D(t_fdf *data)
{
 int x,y,xo,yo;
 int color;
 for(y=0;y<mapY;y++)
 {
  for(x=0;x<mapX;x++)
  {
   if(map[y*mapX+x]==1)
   {color = 0xFB1207;}
   else{color = 0x078AFB;}
   
   xo=x*mapS; yo=y*mapS;
   
   t_player *object;

	object = malloc(sizeof(t_player)); 
   object->x_player = x*mapS;
	object->y_player = y*mapS;
	object->side = mapS;
	draw_obj(object, data, color);
//    glVertex2i( 0   +xo+1, 0   +yo+1); 
//    glVertex2i( 0   +xo+1, mapS+yo-1); 
//    glVertex2i( mapS+xo-1, mapS+yo-1);  
//    glVertex2i( mapS+xo-1, 0   +yo+1); 
//    glEnd();
  } 
 } 
}

float degToRad(int a) { return a*M_PI/180.0;}
int FixAng(int a){ if(a>359){ a-=360;} if(a<0){ a+=360;} return a;}

float px,py,pdx,pdy,pa;



int	draw(t_fdf *data)
{
	int	x;
	int	y;
	t_player *player;

	player = malloc(sizeof(t_player));
	player->x_player = 20 + data->shift_x;
	player->y_player = 20 + data->shift_y;
	player->side = 15;
	do_init_image(data);
	x = 0;
	y = 0;


	// putting each pixel
	
	while (y < HEIGHT && y >= 0)
	{
		x = 0;
		while (x < WIDTH && x >= 0)
		{
			my_mlx_pixel_put(data, x, y, 0xBBBBBB);
			x++;
		}
		y++;
	}
	drawMap2D(data);
	draw_obj(player, data, 0x1FFF00);
	vertex(15, 15, 450, 300, data);
	// while (x < WIDTH && y < HEIGHT && x >= 0 && y >= 0)
	// {
	// 	printf("x = %d y = %d\n", x, y);
	// 	my_mlx_pixel_put(data, x, y, 0xe80c0c);
	// 	x++;
	// 	y++;
	// }
	x = 0;
	y = 0;

	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			data->x_temp = x;
			data->y_temp = y;
			if (x < data->width - 1)
				if (bresenham(x + 1, y, data))
					return (EXIT_FAILURE);
			if (y < data->height - 1)
				if (bresenham(x, y + 1, data))
					return (EXIT_FAILURE);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->image, 0, 0);
	return (0);
}

/*printf("y = %d\n", y);
printf("x = %d\n", x);
*/