/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsanglas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 13:08:29 by lsanglas          #+#    #+#             */
/*   Updated: 2022/07/11 13:08:32 by lsanglas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	encode_rgb(u_int8_t red, u_int8_t green, u_int8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

int	norm_fucker1(t_pixel z)
{
	return ((int)(sqrt(z.iterations - log((log(z.real * z.real
						+ z.imag * z.imag) / 2) / log(2))
			/ log(2)) * 256) % 2048);
}

int	color(t_pixel z)
{
	int		color;

	color = norm_fucker1(z);
	if (z.iterations >= MAX_ITERATIONS)
		return (0);
	if (color < 328)
		return (encode_rgb(0 + color * (double)(32 - 0) / 328,
			7 + color * (double)(107 - 7) / 328,
			100 + color * (double)(203 - 100) / 328));
	else if (color < 860)
		return (encode_rgb(32 + (color - 328) * (double)(237 - 32) / 532,
			107 + (color - 328) * (double)(255 - 107) / 532,
			203 + (color - 328) * (double)(255 - 203) / 532));
	else if (color < 1315)
		return (encode_rgb(237 + (color - 860) * (double)(255 - 237) / 455,
			255 - (color - 860) * (double)(255 - 170) / 455,
			255 - (color - 860) * (double)(255 - 0) / 455));
	else if (color < 1756)
		return (encode_rgb(255 - (color - 1315) * (double)(255 - 0) / 441,
			170 - (color - 1315) * (double)(170 - 2) / 441,
			0 + (color - 1315) * (double)(0 - 0) / 441));
	else
		return (encode_rgb(0 + (color - 1756) * (double)(0 - 0) / 292,
			2 + (color - 1756) * (double)(7 - 2) / 292,
			0 + (color - 1756) * (double)(100 - 0) / 292));
}
