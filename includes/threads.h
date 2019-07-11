/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 21:13:57 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/16 13:44:33 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREADS_H
# define THREADS_H

/*
** Includes
*/

# include <pthread.h>

/*
** Typedef & structures
*/

typedef struct s_fractol	t_fractol;

typedef struct				s_compl
{
	double			real;
	double			imag;
}							t_compl;

typedef struct				s_data_thread
{
	t_compl			z;
	t_compl			c;
	pthread_t		thread;
	double			x;
	double			y;
	t_fractol		*fract_data;
}							t_data_thread;

#endif
