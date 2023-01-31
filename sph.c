/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sph.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 21:58:19 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:50:06 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_sph(char **splited, t_data *data)
{
	int	ret;

	ret = 1;
	data->nb_cam++;
	write(1, MESSAGE_3, ft_strlen(MESSAGE_3));
	if (ft_isupper(splited[0][0]))
	{
		data->mult_sph = false;
		write(1, MESSAGE_4, ft_strlen(MESSAGE_4));
	}
	if (ft_countlentab(splited) != 4)
	{
		write(1, ERROR_14, ft_strlen(ERROR_14));
		exit(14);
	}
	ret *= position_is_ok(splited[1]);
	ret *= len_is_ok(splited[2]);
	ret *= color_is_ok(splited[3]);
	if (ret == 0)
	{
		write(1, ERROR_14, ft_strlen(ERROR_14));
		exit(14);
	}
}
