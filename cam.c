/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:54:40 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:43:57 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_cam(char **splited, t_data *data)
{
	int	error;

	error = 1;
	data->nb_cam++;
	write(1, MESSAGE_1, ft_strlen(MESSAGE_1));
	if (ft_isupper(splited[0][0]))
	{
		data->mult_cam = false;
		write(1, MESSAGE_2, ft_strlen(MESSAGE_2));
	}
	if (ft_countlentab(splited) != 4)
	{
		write(1, ERROR_13, ft_strlen(ERROR_13));
		exit(13);
	}
	error *= position_is_ok(splited[1]);
	error *= direction_is_ok(splited[2]);
	error *= fov_is_ok(splited[3]);
	if (error == 0)
	{
		write(1, ERROR_13, ft_strlen("ERROR_13"));
		exit(13);
	}
}
