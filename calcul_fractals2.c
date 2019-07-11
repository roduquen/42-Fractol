/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul_fractals2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 10:40:24 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 12:11:37 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

void			calcul_hardest(t_data_thread *thread)
{
	double		tmpcr;
	double		tmpzcr;
	double		tmpzci;

	tmpcr = thread->c.real * thread->c.real + thread->c.imag * thread->c.imag;
	tmpzcr = (thread->z.real * thread->c.real + thread->z.imag
			* thread->c.imag) / tmpcr;
	tmpzci = (thread->z.imag * thread->c.real - thread->z.real
			* thread->c.imag) / tmpcr;
	thread->z.real = cos(tmpzcr) * cosh(tmpzci);
	thread->z.imag = -sin(tmpzcr) * sinh(tmpzci);
}
