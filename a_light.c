/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_light.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:22:42 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/27 13:25:49 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_alight(char **splited, t_data *data)
{
	int	error;

	error = 1;
	data->nb_alu++;
	write(1, MESSAGE_11, ft_strlen(MESSAGE_11));
	if (ft_isupper(splited[0][0]))
	{
		data->mult_alu = false;
		write(1, MESSAGE_12, ft_strlen(MESSAGE_12));
	}
	if (ft_countlentab(splited) != 3)
	{
		write(1, ERROR_18, ft_strlen(ERROR_18));
		exit(18);
	}
	error *= ratio_is_ok(splited[1]);
	error *= color_is_ok(splited[2]);
	if (error == 0)
	{
		write(1, ERROR_18, ft_strlen(ERROR_18));
		exit(18);
	}
}
