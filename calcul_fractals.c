/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_fractals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 09:38:14 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 18:53:32 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

static double	ft_abs(double nbr)
{
	return (nbr < 0 ? -nbr : nbr);
}

void			calcul_mandelbrot_julia(t_data_thread *thread, double ret_real
	, double ret_imag)
{
	double	tmp;

	tmp = thread->z.real;
	thread->z.real = ret_real - ret_imag + thread->c.real;
	thread->z.imag = 2 * thread->z.imag * tmp + thread->c.imag;
}

void			calcul_burningship(t_data_thread *thread, double ret_real
	, double ret_imag)
{
	double	tmp;

	tmp = thread->z.real;
	thread->z.real = ret_real - ret_imag + thread->c.real;
	thread->z.imag = ft_abs(2 * thread->z.imag * tmp) + thread->c.imag;
}

void			calcul_tricorne(t_data_thread *thread, double ret_real
	, double ret_imag)
{
	double	tmp;

	tmp = thread->z.real;
	thread->z.real = ret_imag - ret_real + thread->c.real;
	thread->z.imag = 2 * thread->z.imag * tmp + thread->c.imag;
}

void			calcul_batman_circle(t_data_thread *thread)
{
	double		tmp;
	double		tmpcr;
	double		tmpci;

	tmp = thread->z.real;
	tmpcr = thread->c.real * thread->c.real;
	tmpci = thread->c.imag * thread->c.imag;
	thread->z.real = cos(thread->z.real) * cosh(thread->z.imag)
		+ thread->c.real / (tmpcr + tmpci);
	thread->z.imag = -sin(tmp) * sinh(thread->z.imag)
		+ thread->c.imag / (tmpcr + tmpci);
}
