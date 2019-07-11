/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 22:18:59 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/16 13:32:19 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		full_color_tab(t_fractol *params)
{
	int		i;

	i = 1;
	while (i < 1001)
	{
		params->color[i] = (params->color[i - 1] + params->colmod) % 0x1000000;
		i++;
	}
}
