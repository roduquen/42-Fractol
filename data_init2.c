/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 11:26:52 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 11:30:25 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		init_params_hardest(t_fractol *params)
{
	params->divergence = 250;
	params->prec = 50;
	params->frac_comp.y_min = -2.08125;
	params->frac_comp.y_max = 2.1375;
	params->frac_comp.x_min = -1.875;
	params->frac_comp.x_max = 1.875;
	params->colmod = 0x3F0F1F;
	full_color_tab(params);
}
