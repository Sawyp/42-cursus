/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:10:36 by lsanglas          #+#    #+#             */
/*   Updated: 2022/07/10 15:10:42 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "minilibx-linux/mlx.h"

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		exit(0);
	}
	else if (keysym == XK_g)
	{
		data->img.zoom *= 1.5;
		render(data);
	}
	return (0);
}

int	handle_scroll(int keysym, int x, int y, t_data *data)
{
	double	zoom;
	double	current_zoom_ratio;

	if (keysym == 4)
		zoom = 1.1;
	else if (keysym == 5)
		zoom = -1.1;
	current_zoom_ratio = data->current_area.width * 0.8;
	data->current_area.x += zoom * x
		/ pow(WINDOW_WIDTH, 2) * 0.5 * current_zoom_ratio;
	data->current_area.y += zoom * y
		/ pow(WINDOW_HEIGHT, 2) * 0.5 * current_zoom_ratio;
	data->current_area.width -= zoom * 0.5 * current_zoom_ratio;
	data->current_area.height -= zoom * 0.5 * current_zoom_ratio;
	if (keysym == 4 || keysym == 5)
		render(data);
	return (0);
}

int	handle_cross(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}
