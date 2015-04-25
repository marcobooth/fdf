/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 17:13:39 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/07 17:13:41 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_hook(int keycode, t_info *info)
{
	(void)info;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		expose_hook(t_info *info)
{
	pixelprint(info);
	return (0);
}
