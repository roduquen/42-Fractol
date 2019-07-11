/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 13:13:01 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 11:55:17 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_params_mandelbrot(t_fractol *params)
{
	params->divergence = 4;
	params->prec = 50;
	params->frac_comp.y_min = -2.1;
	params->frac_comp.y_max = 0.6;
	params->frac_comp.x_min = -1.2;
	params->frac_comp.x_max = 1.2;
	params->colmod = 0X81750785;
	full_color_tab(params);
}

void		init_params_burningship(t_fractol *params)
{
	params->divergence = 4;
	params->prec = 50;
	params->frac_comp.y_min = -2.2165;
	params->frac_comp.y_max = 1.199;
	params->frac_comp.x_min = -1.738;
	params->frac_comp.x_max = 1.298;
	params->colmod = 0X1F0000;
	full_color_tab(params);
}

void		init_params_batman(t_fractol *params)
{
	params->divergence = 70;
	params->prec = 50;
	params->frac_comp.y_min = -2.08125;
	params->frac_comp.y_max = 2.1375;
	params->frac_comp.x_min = -1.875;
	params->frac_comp.x_max = 1.875;
	params->colmod = 0X1F0F00;
	full_color_tab(params);
}

void		init_params_tricorne(t_fractol *params)
{
	params->divergence = 4;
	params->prec = 50;
	params->frac_comp.y_min = -2.08125;
	params->frac_comp.y_max = 2.1375;
	params->frac_comp.x_min = -1.875;
	params->frac_comp.x_max = 1.875;
	params->colmod = 0XF00F0;
	full_color_tab(params);
}

void		init_params_julia(t_fractol *params)
{
	params->divergence = 4;
	params->julia_real = -0.038088;
	params->julia_imag = 0.9754633;
	params->prec = 150;
	params->frac_comp.y_min = -2.16;
	params->frac_comp.y_max = 2.16;
	params->frac_comp.x_min = -1.92;
	params->frac_comp.x_max = 1.92;
	params->colmod = 0XF0F0F;
	full_color_tab(params);
}
