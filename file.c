/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:18:53 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/27 14:08:12 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_data(t_data *data)
{
	data->nb_cam = 0;
	data->nb_sph = 0;
	data->nb_cyl = 0;
	data->nb_pln = 0;
	data->nb_glu = 0;
	data->nb_alu = 0;
	data->mult_cam = true;
	data->mult_sph = true;
	data->mult_cyl = true;
	data->mult_pln = true;
	data->mult_glu = true;
	data->mult_alu = true;
}

void	check_rules(t_data *data)
{
	if ((data->mult_cam == false) && (data->nb_cam <= 1))
	{
		write(1, ERROR_6, ft_strlen(ERROR_6));
		exit(6);
	}
	else if (data->mult_sph == false && data->nb_sph > 1)
	{
		write(1, ERROR_7, ft_strlen(ERROR_7));
		exit(7);
	}
	else if (data->mult_cyl == false && data->nb_cyl > 1)
	{
		write(1, ERROR_8, ft_strlen(ERROR_8));
		exit(8);
	}
	else if (data->mult_pln == false && data->nb_pln > 1)
	{
		write(1, ERROR_9, ft_strlen(ERROR_9));
		exit(9);
	}
	else if (data->mult_glu == false && data->nb_glu > 1)
	{
		write(1, ERROR_10, ft_strlen(ERROR_10));
		exit(10);
	}
}

void	check_data(t_data *data)
{
	if (data->mult_alu == false && data->nb_alu > 1)
	{
		write(1, ERROR_11, ft_strlen(ERROR_11));
		exit(11);
	}
	if (data->nb_alu < 1)
		write(1, WARNING_2, ft_strlen(WARNING_2));
	else if (data->nb_alu > 1)
		write(1, WARNING_3, ft_strlen(WARNING_3));
	if (data->nb_sph == 0 && data->nb_cyl == 0 && data->nb_pln == 0)
		write(1, WARNING_4, ft_strlen(WARNING_4));
	if (data->nb_glu == 0 && data->nb_alu == 0)
		write(1, WARNING_5, ft_strlen(WARNING_5));
	if (data->nb_cam == 0)
	{
		write(1, ERROR_4, ft_strlen(ERROR_4));
		exit(4);
	}
	if (data->nb_cam > 99)
	{
		write(1, ERROR_5, ft_strlen(ERROR_5));
		exit(5);
	}
}

void	check_objets(char **spt, t_data *data)
{
	(void)data;
	if (!ft_strcmp(spt[0], "C") || !ft_strcmp(spt[0], "c"))
		check_cam(spt, data);
	else if (!ft_strcmp(spt[0], "SP") || !ft_strcmp(spt[0], "sp"))
		check_sph(spt, data);
	else if (!ft_strcmp(spt[0], "CY") || !ft_strcmp(spt[0], "cy"))
		check_cyl(spt, data);
	else if (!ft_strcmp(spt[0], "PL") || !ft_strcmp(spt[0], "pl"))
		check_pln(spt, data);
	else if (!ft_strcmp(spt[0], "L") || !ft_strcmp(spt[0], "l"))
		check_light(spt, data);
	else if (!ft_strcmp(spt[0], "A") || !ft_strcmp(spt[0], "a"))
		check_alight(spt, data);
	else if (spt[0][0] == '\n')
		return ;
	else
	{
		write(1, ERROR_12, ft_strlen(ERROR_12));
		exit(12);
	}
}

void	check_file(t_data *data)
{
	char	*line;
	char	**splited;

	init_data(data);
	while (true)
	{
		line = get_next_line(data->fd);
		splited = ft_split(line, ' ');
		if (line == NULL)
			break;
		if (line[0] == '\0')
		{
			free(line);
			free(splited);
			break;
		}
		else if (splited[0] != NULL)
			check_objets(splited, data);
		free_char_tab(splited);	
		free(line);
	}
	close(data->fd);
	check_rules(data);
	check_data(data);
}
