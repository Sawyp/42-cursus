/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:12:31 by lsanglas          #+#    #+#             */
/*   Updated: 2022/07/10 15:12:33 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define MAX_ITERATIONS 2048
# define WINDOW_WIDTH 300
# define WINDOW_HEIGHT 300

# define MLX_ERROR 1

typedef struct s_current_area
{
	double	x;
	double	y;
	double	width;
	double	height;
}	t_current_area;

typedef struct s_pixel
{
	double	real;
	double	imag;
	double	iterations;
}	t_pixel;

typedef struct s_img
{
	long	zoom;
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	int				set;
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img;
	t_pixel			julia_parameters;
	t_current_area	current_area;
}	t_data;

int		handle_keypress(int keysym, t_data *data);
int		handle_scroll(int keysym, int x, int y, t_data *data);
int		handle_cross(t_data *data);

int		parse(t_data *data, int ac, char **av);

int		color(t_pixel z);

int		render(t_data *data);

void	render_set(t_img *img, t_data *data);
t_pixel	julia_iterations(t_pixel c, t_pixel z);
t_pixel	mandelbrot_iterations(t_pixel c);

#endif
