/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:42:06 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:28:51 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	color_is_ok(char *arg)
{
	char	**split;
	int	i;

	split = ft_split(arg, ',');
	i = 0;
	while (split[i])
	{
		if (ft_isnbr(split[i]) == 0)
		{
			free_char_tab(split);
			return (false);
		}
		else if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
		{
			free_char_tab(split);
			return (false);
		}
		i++;
	}
	free_char_tab(split);
	if (i != 3)
		return (false);
	return (true);
}

bool	position_is_ok(char *arg)
{
	char	**nb;
	int	i;

	nb = ft_split(arg, ',');
	i = 0;
	while (nb[i])
	{
		if (nbr_is_ok(nb[i]) == false)
		{
			free_char_tab(nb);
			return (false);
		}
		i++;
	}
	free_char_tab(nb);
	if (i != 3)
		return (false);
	return (true);
}

bool	direction_is_ok(char *arg)
{
	char	**split;
	int	info;
	int	i;

	split = ft_split(arg, ',');
	info = 1;
	i = 0;
	while (split[i])
	{
		info *= max_direction_ok(split[i]);
		i++;
	}
	free_char_tab(split);
	if (i != 3)
		return (false);
	if (info == 0)
		return (false);
	return (true);
}

bool	len_is_ok(char *arg)
{
	if (nbr_is_ok(arg) == false)
		return (false);
	return (true);
}

bool	fov_is_ok(char *arg)
{
	char **nb;
	
	if (ft_find(arg, '.'))
	{
		nb = ft_split(arg, '.');
		if (ft_isnbr(nb[0]) && ft_isdigits(nb[1]) && !nb[2])
		{
			free_char_tab(nb);
			if (ft_atoi(arg) > 180 || ft_atoi(arg) < 0)
				return (false);
			return (true);
		}
		return (false);
	}
	if (ft_isnbr(arg) == false)
		return (false);
	if (ft_atoi(arg) > 180 || ft_atoi(arg) < 0)
		return (false);
	return (true);
}
