/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbooth <mbooth@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 19:32:53 by mbooth            #+#    #+#             */
/*   Updated: 2015/01/06 16:04:43 by mbooth           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	find_split_length(char **thingy)
{
	int	i;

	i = 0;
	while (thingy[i] != 0)
		i++;
	return (i);
}

static void	dbl_free(void *ptr1, void *ptr2)
{
	free(ptr1);
	free(ptr2);
}

static void	fdf_error(char *str)
{
	perror(str);
	exit(1);
}

static int	set_next_line(t_list **list, int fd, int *width)
{
	int		checker;
	char	**split;
	int		*inter;
	int		counter;
	char	*line;

	if (((checker = get_next_line(fd, &line)) >= 0))
	{
		split = ft_strsplit(line, ' ');
		if ((!find_split_length(split)) && checker == 1)
			fdf_error("File Contains Empty Line");
		if (!find_split_length(split))
		{
			dbl_free(split, line);
			return (checker);
		}
		*width = find_split_length(split);
		inter = (int*)malloc(sizeof(int) * *(width));
		counter = *(width);
		while (counter-- > 0)
			inter[counter] = ft_atoi(split[counter]);
		ft_list_push_back(&*(list), inter);
		dbl_free(split, line);
	}
	return (checker);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*ints;
	int		width;
	int		this_width;
	int		check;

	ints = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			fdf_error(argv[1]);
		check = set_next_line(&ints, fd, &width);
		while (((check = set_next_line(&ints, fd, &this_width)) > 0))
		{
			if (width != this_width)
			{
				ft_putendl_fd("Invalid File Format", 2);
				return (1);
			}
		}
		mlx(ints, width);
	}
	return (0);
}
