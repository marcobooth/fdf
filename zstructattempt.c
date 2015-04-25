/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zstructattempt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 15:57:24 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/07 11:56:58 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_x_points(t_info *info)
{
	t_points	p1;
	t_points	p2;

	p1.x = info->x;
	p1.y = info->y;
	p2.x = work_out_x(info->px + 20, info->py);
	p2.y = work_out_y(info->px + 20, info->py,
						((int*)info->list->data)[info->counter + 1]);
	ft_x_axis(p1, p2, info);
	ft_y_axis(p1, p2, info);
	mlx_pixel_put(info->start, info->window, p2.x + 300, p2.y + 200, 0xFFFFFF);
}

void	draw_y_points(t_info *info)
{
	t_points	p1;
	t_points	p2;

	p1.x = info->x;
	p1.y = info->y;
	p2.x = work_out_x(info->px, info->py + 20);
	p2.y = work_out_y(info->px, info->py + 20,
						((int*)info->list->next->data)[info->counter]);
	ft_x_axis(p1, p2, info);
	ft_y_axis(p1, p2, info);
	mlx_pixel_put(info->start, info->window, p2.x + 300, p2.y + 200, 0xFFFFFF);
}

void	pixelprint(t_info *info)
{
	t_list	*list;

	list = info->list;
	info->px = 0;
	info->py = 0;
	info->counter = 0;
	while (info->list != NULL)
	{
		while (info->counter < info->width_limit)
		{
			info->x = work_out_x(info->px, info->py);
			info->y = work_out_y(info->px, info->py,
									((int*)info->list->data)[info->counter]);
			mlx_pixel_put(info->start, info->window, info->x + 300,
							info->y + 200, 0xFFFFFF);
			if (info->counter < info->width_limit - 1)
				draw_x_points(info);
			if (info->list->next != NULL)
				draw_y_points(info);
			info->counter++;
			info->px += 20;
		}
		info->counter = 0;
		info->px = 0;
		info->py += 20;
		info->list = info->list->next;
	}
	info->list = list;
}

void	mlx(t_list *list, int width_limit)
{
	void	*start;
	void	*window;
	t_info	info;

	start = mlx_init();
	if (!start)
		return ;
	window = mlx_new_window(start, 1000, 1000, "42");
	info.start = start;
	info.window = window;
	info.width_limit = width_limit;
	info.list = list;
	info.px = 0;
	info.py = 0;
	info.counter = 0;
	mlx_expose_hook(info.window, expose_hook, &info);
	mlx_key_hook(info.window, key_hook, &info);
	mlx_loop(start);
}
