/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:25:48 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 20:34:25 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	ratio_is_ok(char *arg)
{
	int	i;
	char	**split;
	bool	ret;

	ret = true;
	if (!ft_strcmp(arg, "0") || !ft_strcmp(arg, "1"))
		return (true);
	i = 0;
	split = ft_split(arg, '.');
	while (split[i])
		i++;
	if (i != 2)
		ret = false;
	if (!ft_isdigits(split[1]) || !ft_isnbr(split[0]))
		ret = false;
	if (ft_atoi(split[0]) > 1 || ft_atoi(split[0]) < 0)
		ret = false;
	if (ft_atoi(split[0]) > 0 && ft_atoi(split[1]) > 0)
		ret = false;
	free_char_tab(split);
	return (ret);
}

bool	nbr_is_ok(char *str)
{
	int	nb;
	char	**nbs;

	if ((ft_isnbr(str) == 1) && ft_find(str, '.') == 0)
	{
		nb = ft_atoi(str);
		if ((nb == INT_MAX) || (nb == INT_MIN))
			return (false);
		return (true);
	}
	nbs = ft_split(str, '.');
	if (nbs[2] != NULL || !ft_isnbr(nbs[0]))
	{
		free_char_tab(nbs);
		return (false);
	}
	nb = ft_atoi(nbs[0]);
	if (!ft_isdigits(nbs[1]) || (nb == INT_MAX) || (nb == INT_MIN))
	{
		free_char_tab(nbs);
		return (false);
	}
	free_char_tab(nbs);	
	return (true);
}

bool	max_direction_ok(char *nb)
{
	char	**split;
	int	ret;
	int	n;
	
	ret = 1;
	if (ft_isnbr(nb))
	{
		n = ft_atoi(nb);
		if (n == 1 || n == 0 || n == -1)
			return (true);
	
	}
	if (ft_find(nb, '.') == false)
		return (0);
	split = ft_split(nb, '.');
	if (split[2])
		ret = 0;
	if (!ft_isdigits(split[1]) || !ft_isnbr(split[0]))
		ret = 0;
	if (ft_atoi(split[0]) > 1 || ft_atoi(split[0]) < -1)
		ret = 0;
	if (ft_atoi(split[0]) > 0 && ft_atoi(split[1]) > 0)
		ret = 0;
	if (ft_atoi(split[0]) < 0 && ft_atoi(split[1]) < 0)
		ret = 0;
	free_char_tab(split);
	if (ret == 0)
		return (false);
	return (true);
}
