/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 08:03:22 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/21 15:05:39 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				mouse_move(int x, int y, void *param)
{
	t_fractol	*params;

	params = (t_fractol*)param;
	if (params->frac_type == 2)
	{
		if (params->julia_par % 2 == 0)
		{
			params->julia_real = (x / 911.0 - 0.5) * 3;
			params->julia_imag = (y / 810.0 - 0.5) * 3;
			create_mandelbrot(params);
			mlx_put_image_to_window(params->mlx_comp.mlx_ptr
				, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
		}
	}
	return (0);
}

int				mouse_event(int button, int x, int y, void *param)
{
	t_fractol *params;

	params = (t_fractol*)param;
	if (button == 4)
	{
		zoom_plus(params, x, y);
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (button == 5)
	{
		zoom_less(params, x, y);
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	return (0);
}

static void		key_press3(int keycode, t_fractol *params)
{
	if (keycode == 45)
	{
		params->frac_type++;
		if (params->frac_type > 6)
			params->frac_type = 1;
		send_to_init(params);
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (keycode == 49)
		params->julia_par++;
	if (keycode == 84)
		create_screen(params->mlx_comp.renderer, params->color, 2);
	if (keycode == 85)
		create_screen(params->mlx_comp.renderer, params->color, 3);
	command_translation(keycode, params);
}

static void		key_press2(int keycode, t_fractol *params)
{
	if (keycode == 8)
	{
		params->colmod += 0xF546215;
		full_color_tab(params);
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (keycode == 15)
	{
		send_to_init(params);
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (keycode == 53)
		closer(params);
	key_press3(keycode, params);
}

int				key_press(int keycode, void *param)
{
	t_fractol *params;

	params = (t_fractol*)param;
	if (keycode == 83)
		create_screen(params->mlx_comp.renderer, params->color, 1);
	if (keycode == 24)
	{
		if (params->prec < 996)
			params->prec += 5;
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	if (keycode == 27)
	{
		if (params->prec > 5)
			params->prec -= 5;
		create_mandelbrot(params);
		mlx_put_image_to_window(params->mlx_comp.mlx_ptr
			, params->mlx_comp.window, params->mlx_comp.image, 0, 0);
	}
	else
		key_press2(keycode, params);
	return (0);
}
