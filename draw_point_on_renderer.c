/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_point_on_renderer.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 07:03:58 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/15 19:30:55 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "threads.h"

void		send_to_draw(t_data_thread *thread, int nb_iterations)
{
	unsigned int		pos;

	pos = thread->x * 911 + thread->y;
	if (nb_iterations != thread->fract_data->prec + 1)
	{
		(thread->fract_data->mlx_comp.renderer)[pos] =
			thread->fract_data->color[nb_iterations];
	}
	else
		(thread->fract_data->mlx_comp.renderer)[pos] = 0;
}
