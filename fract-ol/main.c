/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:54:39 by lsanglas          #+#    #+#             */
/*   Updated: 2022/07/10 14:54:56 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_pixel	mandelbrot_iterations(t_pixel c)
{
	t_pixel	z;
	double	zx2;
	double	zy2;

	z.iterations = 0;
	z.real = 0.0;
	z.imag = 0.0;
	zx2 = 0.0;
	zy2 = 0.0;
	while (z.iterations < MAX_ITERATIONS && zx2 + zy2 <= 10)
	{
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = zx2 - zy2 + c.real;
		zx2 = z.real * z.real;
		zy2 = z.imag * z.imag;
		z.iterations++;
	}
	return (z);
}

t_pixel	julia_iterations(t_pixel c, t_pixel z)
{
	double	zx2;
	double	zy2;

	z.iterations = 0;
	zx2 = z.real * z.real;
	zy2 = z.imag * z.imag;
	while (z.iterations < MAX_ITERATIONS && zx2 + zy2 <= 10)
	{
		z.imag = z.real * z.imag * 2 + c.imag;
		z.real = zx2 - zy2 + c.real;
		zx2 = z.real * z.real;
		zy2 = z.imag * z.imag;
		z.iterations++;
	}
	return (z);
}

void	init_data(t_data *data)
{
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->img.zoom = 200;
	data->current_area.width = WINDOW_WIDTH;
	data->current_area.height = WINDOW_HEIGHT;
	data->current_area.x = 0;
	data->current_area.y = 0;
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!parse(&data, ac, av))
		return (0);
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr,
			WINDOW_WIDTH, WINDOW_HEIGHT, "fractol");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	init_data(&data);
	data.set = atoi(av[1]);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win_ptr, 4, 1L << 2, handle_scroll, &data);
	mlx_hook(data.win_ptr, 17, 0, handle_cross, &data);
	render(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
