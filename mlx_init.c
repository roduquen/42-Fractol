/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:11:36 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/14 22:39:11 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>

t_func		leave_mlx(t_fractol *params, t_func type_of_leave)
{
	if (params->mlx_comp.image)
		mlx_destroy_image(params->mlx_comp.mlx_ptr, params->mlx_comp.image);
	if (params->mlx_comp.window)
		mlx_destroy_window(params->mlx_comp.mlx_ptr, params->mlx_comp.window);
	return (type_of_leave);
}

t_func		init_mlx(t_fractol *params)
{
	int		bits_per_pixel;
	int		size_line;
	int		endian;

	if (!(params->mlx_comp.mlx_ptr = mlx_init()))
		return (MLX_INIT_ERROR);
	if (!(params->mlx_comp.window = mlx_new_window(params->mlx_comp.mlx_ptr
				, 911, 810, "FRACTOL")))
		return (MLX_WINDOW_ERROR);
	if (!(params->mlx_comp.image = mlx_new_image(params->mlx_comp.mlx_ptr
				, 911, 810)))
		return (MLX_IMAGE_ERROR);
	if (!(params->mlx_comp.renderer = (unsigned int*)mlx_get_data_addr(
				params->mlx_comp.image, &bits_per_pixel, &size_line, &endian)))
		return (MLX_GET_IMAGE_ERROR);
	return (SUCCESS);
}
