/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_translation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 15:00:43 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/21 15:34:03 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	commands_translation_by_y(int keycode, t_fractol *params)
{
	double	y;

	y = (params->frac_comp.y_max - params->frac_comp.y_min) / 10;
	if (keycode == 123)
	{
		params->frac_comp.y_max -= y;
		params->frac_comp.y_min -= y;
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
				, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (keycode == 124)
	{
		params->frac_comp.y_max += y;
		params->frac_comp.y_min += y;
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
				, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
}

void		command_translation(int keycode, t_fractol *params)
{
	double	x;

	x = (params->frac_comp.x_max - params->frac_comp.x_min) / 10;
	if (keycode == 126)
	{
		params->frac_comp.x_max -= x;
		params->frac_comp.x_min -= x;
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
				, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (keycode == 125)
	{
		params->frac_comp.x_max += x;
		params->frac_comp.x_min += x;
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
				, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	commands_translation_by_y(keycode, params);
}
