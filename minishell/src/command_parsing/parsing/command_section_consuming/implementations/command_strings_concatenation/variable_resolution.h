/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_resolution.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:06:50 by aronez            #+#    #+#             */
/*   Updated: 2022/12/21 10:06:50 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLE_RESOLUTION_H
# define VARIABLE_RESOLUTION_H

# include "../../consumers.h"

char	*resolve_section(
			const char *section,
			t_resolution_data resolution_data,
			int display_last_dollar
			);

#endif //VARIABLE_RESOLUTION_H
