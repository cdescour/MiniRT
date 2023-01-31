/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pln.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 22:10:26 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:51:35 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void check_pln(char **splited, t_data *data)
{
	int	ret;

	ret = 1;
	data->nb_pln++;
	write(1, MESSAGE_7, ft_strlen(MESSAGE_7));
	if (ft_isupper(splited[0][0]))
	{
		data->mult_pln = false;
		write(1, MESSAGE_8, ft_strlen(MESSAGE_8));
	}
	if (ft_countlentab(splited) != 4)
	{
		write(1, ERROR_16, ft_strlen(ERROR_16));
		exit(16);
	}
	ret *= position_is_ok(splited[1]);
	ret *= direction_is_ok(splited[2]);
	ret *= color_is_ok(splited[3]);

	if (ret == 0)
	{
		write(1, ERROR_16, ft_strlen(ERROR_16));
		exit(16);
	}
}
