/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roduquen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 09:13:11 by roduquen          #+#    #+#             */
/*   Updated: 2019/04/17 11:43:57 by roduquen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <unistd.h>
#include <stdlib.h>

int			closer(void *param)
{
	leave_mlx((t_fractol*)param, 0);
	exit(0);
	return (0);
}

void		send_to_init(t_fractol *params)
{
	params->mlx_comp.win_dim.width = 911;
	params->mlx_comp.win_dim.length = 810;
	if (params->frac_type == 1)
		init_params_mandelbrot(params);
	else if (params->frac_type == 2)
		init_params_julia(params);
	else if (params->frac_type == 3)
		init_params_burningship(params);
	else if (params->frac_type == 4)
		init_params_tricorne(params);
	else if (params->frac_type == 5)
		init_params_batman(params);
	else if (params->frac_type == 6)
		init_params_hardest(params);
}

static int	check_av(char *str, t_fractol *params)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	if (ft_strequ(str, "MANDELBROT"))
		return ((params->frac_type = 1));
	if (ft_strequ(str, "JULIA"))
		return ((params->frac_type = 2));
	if (ft_strequ(str, "BURNINGSHIP"))
		return ((params->frac_type = 3));
	if (ft_strequ(str, "TRICORNE"))
		return ((params->frac_type = 4));
	write(2, "Fractol : usage : ./fractol [name_of_fractal]\n", 46);
	write(2, "    Fractal supported : Julia, Mandelbrot, Burningship", 54);
	write(2, ", Tricorne\n        Others can be load with 'n' in use\n", 55);
	return (0);
}

static int	leave_arg_prob(void)
{
	write(2, "Fractol : usage : ./fractol [name_of_fractal]\n", 46);
	write(2, "    Fractal supported : Julia, Mandelbrot, Burningship", 54);
	write(2, ", Tricorne\n        Others can be load with 'n' in use\n", 55);
	return (1);
}

int			main(int ac, char **av)
{
	t_fractol	params;
	t_func		ret;

	if (ac == 1 || ac > 2)
		return (leave_arg_prob());
	ft_memset(&params, 0, sizeof(t_fractol));
	if (!(check_av(av[1], &params)))
		return (1);
	send_to_init(&params);
	if ((ret = init_mlx(&params)) != SUCCESS)
		return (leave_mlx(&params, ret));
	if ((ret = create_mandelbrot(&params)) != SUCCESS)
		return (leave_mlx(&params, ret));
	mlx_put_image_to_window(params.mlx_comp.mlx_ptr, params.mlx_comp.window
		, params.mlx_comp.image, 0, 0);
	mlx_hook(params.mlx_comp.window, 2, 0, &key_press, &params);
	mlx_hook(params.mlx_comp.window, 4, 0, &mouse_event, &params);
	mlx_hook(params.mlx_comp.window, 6, 0, &mouse_move, &params);
	mlx_hook(params.mlx_comp.window, 17, 0, &closer, &params);
	mlx_loop(params.mlx_comp.mlx_ptr);
	return (0);
}
