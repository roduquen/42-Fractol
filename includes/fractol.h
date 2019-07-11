/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 11:28:14 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/21 15:25:19 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/*
** Includes
*/

# include "mlx_component.h"
# include "libft.h"
# include "mandelbrot.h"
# include "threads.h"

/*
** Typedef & structures
*/

typedef enum		e_func
{
	SUCCESS = 0,
	ERROR = -1,
	MLX_INIT_ERROR = -1,
	MLX_WINDOW_ERROR = -2,
	MLX_IMAGE_ERROR = -3,
	MLX_GET_IMAGE_ERROR = -4
}					t_func;

typedef struct		s_fractol
{
	t_move			move;
	t_main_mlx		mlx_comp;
	t_frac_comp		frac_comp;
	unsigned int	color[1001];
	unsigned int	colmod;
	int				frac_type;
	double			julia_real;
	double			julia_imag;
	unsigned char	julia_par;
	int				render_width;
	int				render_length;
	int				prec;
	double			divergence;
}					t_fractol;

/*
** A RANGER
*/

void				full_color_tab(t_fractol *params);
void				init_params(t_fractol *params);
t_func				init_mlx(t_fractol *params);
t_func				leave_mlx(t_fractol *params, t_func type_of_leave);
int					closer(void *param);
int					key_press(int keycode, void *param);
void				send_to_draw(t_data_thread *thread, int nb_iterations);
t_func				create_mandelbrot(t_fractol *params);
t_func				create_julia(t_fractol *params);
t_func				create_burningship(t_fractol *params);

/*
** INITIALISATION
*/

void				send_to_init(t_fractol *params);
void				init_params_mandelbrot(t_fractol *params);
void				init_params_tricorne(t_fractol *params);
void				init_params_julia(t_fractol *params);
void				init_params_burningship(t_fractol *params);
void				init_params_batman(t_fractol *params);
void				init_params_hardest(t_fractol *params);

/*
** CALCULS
*/

void				calcul_burningship(t_data_thread *thread, double ret_real
	, double ret_imag);
void				calcul_mandelbrot_julia(t_data_thread *thread
	, double ret_real, double ret_imag);
void				calcul_tricorne(t_data_thread *thread
	, double ret_real, double ret_imag);
void				calcul_batman_circle(t_data_thread *thread);
void				calcul_hardest(t_data_thread *thread);

/*
** COMMANDS
*/

int					mouse_move(int x, int y, void *param);
int					mouse_event(int button, int x, int y, void *param);
void				zoom_less(t_fractol *params, int x, int y);
void				zoom_plus(t_fractol *params, int x, int y);
void				command_translation(int keycode, t_fractol *params);

/*
** PHOTO
*/

void				create_screen(unsigned int *tab, unsigned int *ref
	, int pad);

#endif
