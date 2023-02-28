/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:21:31 by lsanglas          #+#    #+#             */
/*   Updated: 2022/07/10 15:21:33 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

void	norm_fucker2(t_img *img, t_data *data, t_pixel c)
{
	img_pix_put(img, c.real, c.imag,
		color(mandelbrot_iterations((t_pixel){((double)c.real
					* data->current_area.width / pow(WINDOW_WIDTH, 2)
					+ data->current_area.x) * 3.0 - 1.5,
				((double)c.imag * data->current_area.height
					/ pow(WINDOW_HEIGHT, 2) + data->current_area.y) * 3.0 - 1.5,
				0})));
}

void	render_set(t_img *img, t_data *data)
{
	t_pixel	c;

	c.imag = 0;
	while (c.imag < WINDOW_HEIGHT && ++c.imag)
	{
		c.real = 0;
		while (c.real < WINDOW_WIDTH && ++c.real)
		{
			if (data->set == 1)
				img_pix_put(img, c.real, c.imag,
					color(julia_iterations(data->julia_parameters,
							(t_pixel){((double)c.real * data->current_area.width
								/ pow(WINDOW_WIDTH, 2) + data->current_area.x)
							* 3.0 - 1.5,
							((double)c.imag * data->current_area.height
								/ pow(WINDOW_HEIGHT, 2) + data->current_area.y)
							* 3.0 - 1.5,
							0})));
			else
				norm_fucker2(img, data, c);
		}
	}
}

int	render(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	render_set(&data->img, data);
	mlx_put_image_to_window(data->mlx_ptr,
		data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}
