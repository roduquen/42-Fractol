/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 13:09:26 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/16 13:41:52 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		zoom_plus(t_fractol *params, int x, int y)
{
	double		delta;

	delta = params->frac_comp.x_max - params->frac_comp.x_min;
	params->frac_comp.x_min += ((y / 810.0) * delta) / 10;
	params->frac_comp.x_max -= (((810 - y) / 810.0) * delta) / 10;
	delta = params->frac_comp.y_max - params->frac_comp.y_min;
	params->frac_comp.y_min += ((x / 911.0) * delta) / 10;
	params->frac_comp.y_max -= (((911 - x) / 911.0) * delta) / 10;
}

void		zoom_less(t_fractol *params, int x, int y)
{
	double		delta;

	delta = params->frac_comp.x_max - params->frac_comp.x_min;
	params->frac_comp.x_min -= ((y / 810.0) * delta) / 10;
	params->frac_comp.x_max += (((810 - y) / 810.0) * delta) / 10;
	delta = params->frac_comp.y_max - params->frac_comp.y_min;
	params->frac_comp.y_min -= ((x / 911.0) * delta) / 10;
	params->frac_comp.y_max += (((911 - x) / 911.0) * delta) / 10;
}
