/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xyslope.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:23:04 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/03 19:31:48 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	work_out_x(int width, int length)
{
	double	c1;
	double	c2;
	double	x;

	c1 = 1;
	c2 = 1;
	x = (c1 * width) - (c2 * length);
	return (x);
}

double	work_out_y(int width, int length, int height)
{
	double	c1;
	double	c2;
	double	y;

	c1 = 1;
	c2 = 1;
	y = -(height) + ((c1 / 2) * width) + ((c2 / 2) * length);
	return (y);
}

void	ft_x_axis(t_points p1, t_points p2, t_info *info)
{
	double	slope;
	double	b;
	double	plus;

	slope = ((p2.y - p1.y) / (p2.x - p1.x));
	b = p1.y - (p1.x * slope);
	plus = ((p1.x < p2.x) ? 1 : -1);
	while (p1.x != p2.x)
	{
		mlx_pixel_put(info->start, info->window, p1.x + 300,
						p1.y + 200, 0xFFFFFF);
		p1.x += plus;
		p1.y = (slope * p1.x) + b;
	}
}

void	ft_y_axis(t_points p1, t_points p2, t_info *info)
{
	double	slope;
	double	b;
	double	plus;

	slope = ((p2.y - p1.y) / (p2.x - p1.x));
	plus = ((p1.y < p2.y) ? 1 : -1);
	b = p1.x - (p1.y / slope);
	while (p1.y != p2.y)
	{
		mlx_pixel_put(info->start, info->window, p1.x + 300,
						p1.y + 200, 0xFFFFFF);
		p1.y += plus;
		p1.x = (p1.y / slope) + b;
	}
}
