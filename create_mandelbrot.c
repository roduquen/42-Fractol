/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_mandelbrot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 05:43:39 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 11:32:57 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "threads.h"

static void	set_z_and_c(t_data_thread *thread)
{
	if (thread->fract_data->frac_type != 2)
	{
		thread->z.real = 0;
		thread->z.imag = 0;
		thread->c.imag = thread->x / thread->fract_data->move.zoom_x
			+ thread->fract_data->frac_comp.x_min;
		thread->c.real = thread->y / thread->fract_data->move.zoom_y
			+ thread->fract_data->frac_comp.y_min;
	}
	else
	{
		thread->c.real = thread->fract_data->julia_real;
		thread->c.imag = thread->fract_data->julia_imag;
		thread->z.imag = thread->x / thread->fract_data->move.zoom_x
			+ thread->fract_data->frac_comp.x_min;
		thread->z.real = thread->y / thread->fract_data->move.zoom_y
			+ thread->fract_data->frac_comp.y_min;
	}
}

static void	chose_fractal_calc(t_data_thread *thread, double ret_real
	, double ret_imag)
{
	if (thread->fract_data->frac_type == 1)
		calcul_mandelbrot_julia(thread, ret_real, ret_imag);
	if (thread->fract_data->frac_type == 2)
		calcul_mandelbrot_julia(thread, ret_real, ret_imag);
	if (thread->fract_data->frac_type == 3)
		calcul_burningship(thread, ret_real, ret_imag);
	if (thread->fract_data->frac_type == 4)
		calcul_tricorne(thread, ret_real, ret_imag);
	if (thread->fract_data->frac_type == 5)
		calcul_batman_circle(thread);
	if (thread->fract_data->frac_type == 6)
		calcul_hardest(thread);
}

static void	calcul_with_y(t_data_thread *thread, int iter)
{
	double	ret_real;
	double	ret_imag;

	while (thread->y < 911)
	{
		set_z_and_c(thread);
		iter = 0;
		ret_real = thread->z.real * thread->z.real;
		ret_imag = thread->z.imag * thread->z.imag;
		while (ret_real + ret_imag < thread->fract_data->divergence
			&& iter++ < thread->fract_data->prec)
		{
			chose_fractal_calc(thread, ret_real, ret_imag);
			ret_real = thread->z.real * thread->z.real;
			ret_imag = thread->z.imag * thread->z.imag;
		}
		send_to_draw(thread, iter);
		thread->y++;
	}
}

void		*calcul_point_by_thread(void *params)
{
	t_data_thread	*thread;

	thread = (t_data_thread*)params;
	while (thread->x < 810)
	{
		thread->y = 0;
		calcul_with_y(thread, 0);
		thread->x += 8;
	}
	pthread_exit(0);
}

t_func		create_mandelbrot(t_fractol *params)
{
	int				i;
	t_data_thread	threads[8];

	params->move.zoom_y = 911 / (params->frac_comp.y_max
		- params->frac_comp.y_min);
	params->move.zoom_x = 810 / (params->frac_comp.x_max
		- params->frac_comp.x_min);
	i = 0;
	while (i < 8)
	{
		ft_memset(&(threads[i]), 0, sizeof(t_data_thread));
		(threads[i]).fract_data = params;
		(threads[i]).x = i;
		if (pthread_create(&((threads[i]).thread), NULL
				, (*calcul_point_by_thread), &(threads[i])) < 0)
			return (ERROR);
		i++;
	}
	i = 0;
	while (i < 8)
		pthread_join(threads[i++].thread, NULL);
	return (SUCCESS);
}
