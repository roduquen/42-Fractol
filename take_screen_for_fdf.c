/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_screen_for_fdf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 12:36:49 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 19:26:33 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fractol.h"

static int	convert_color_to_height(unsigned int value, unsigned int *ref)
{
	int		i;

	i = 0;
	while (value != ref[i])
		i++;
	return (i % 2 == 1 ? i * 10 : -i * 10);
}

void		create_screen(unsigned int *tab, unsigned int *ref, int pad)
{
	int		i;
	int		fd;
	int		j;

	j = 0;
	if ((fd = open("photo", O_CREAT | O_WRONLY | O_TRUNC, 0644)) <= 0)
		return ;
	i = 0;
	while (i < 911 * 810)
	{
		ft_putnbr_fd(convert_color_to_height(tab[i], ref), fd);
		ft_putchar_fd(',', fd);
		ft_putnbr_fd(tab[i], fd);
		i += pad;
		if (i / 911 > j)
		{
			j += pad;
			i = 911 * j;
			ft_putchar_fd('\n', fd);
		}
		else
			ft_putchar_fd(' ', fd);
	}
	close(fd);
}
