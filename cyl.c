/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cyl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:08:39 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:24:44 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_cyl(char **splited, t_data *data)
{
	int error;
	
	data->nb_cyl++;
	write(1, MESSAGE_5, ft_strlen(MESSAGE_5));
	if (ft_isupper(splited[0][0]))
	{
		data->mult_cyl = false;
		write(1, MESSAGE_6, ft_strlen(MESSAGE_6));
	}
	if (ft_countlentab(splited) != 6)
	{
		write(1, ERROR_15, ft_strlen(ERROR_15));
		exit(15);
	}
	error = 1;
	error *= position_is_ok(splited[1]);
	error *= direction_is_ok(splited[2]);
	error *= len_is_ok(splited[3]);
	error *= len_is_ok(splited[4]);
	error *= color_is_ok(splited[5]);
	if (error == 0)
	{
		write(1, ERROR_15, ft_strlen(ERROR_15));
		exit(15);
	}
}
