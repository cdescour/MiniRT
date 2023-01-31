/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:17:06 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:54:34 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_light(char **splited, t_data *data)
{
	int	ret;

	ret = 1;
	data->nb_glu++;
	write(1, MESSAGE_9, ft_strlen(MESSAGE_9));
	if (ft_isupper(splited[0][0]))
	{
		data->mult_glu = false;
		write(1, MESSAGE_10, ft_strlen(MESSAGE_10));
	}
	if (ft_countlentab(splited) != 4 && ft_countlentab(splited) != 3)
	{
		write(1, ERROR_17, ft_strlen(ERROR_17));
		exit(17);
	}
	ret *= position_is_ok(splited[1]);
	ret *= ratio_is_ok(splited[2]);
	if (ft_countlentab(splited) == 4)
		ret *=color_is_ok(splited[3]);
	if (ret == 0)
	{
		write(1, ERROR_17, ft_strlen(ERROR_17));
		exit(17);
	}
}
