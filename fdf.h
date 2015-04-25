/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 15:19:13 by mbooth            #+#    #+#             */
/*   Updated: 2014/12/19 14:22:32 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <fcntl.h>
# include "libft/includes/libft.h"
# include <stdio.h>

typedef struct	s_info
{
	int			px;
	int			py;
	double		x;
	double		y;
	int			counter;
	double		r;
	double		check;
	void		*start;
	void		*window;
	void		*image;
	t_list		*list;
	int			width_limit;
}				t_info;

typedef struct	s_hello
{
	double		x;
	double		y;
}				t_points;

double			work_out_x(int width, int length);
double			work_out_y(int width, int length, int height);
double			xslope(int px, int py, int height, int heightone);
double			yslope(int px, int py, int height1, int height2);
void			mlx(t_list *list, int width_limit);
void			pixelprint(t_info *info);
void			ft_x_axis(t_points p1, t_points p2, t_info *info);
void			ft_y_axis(t_points p1, t_points p2, t_info *info);
void			draw_x_points(t_info *info);
void			draw_y_points(t_info *info);
void			pixelprint(t_info *info);
int				key_hook(int keycode, t_info *info);
int				expose_hook(t_info *info);

#endif
