/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 16:14:54 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/25 18:07:07 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_extension(char *file_name, char *extension)
{
	int	i;
	int	j;

	i = 0;
	while (file_name[i])
		i++;
	j = 0;
	while (extension[j])
		j++;
	while (j--)
	{
		if (--i < 0)
			return (false);
		else if (file_name[i] != extension[j])
			return (false);
	}
	return (true);

}

bool	open_file(t_data *data, char *file_name)
{
	char *path_file;
	
	if (check_extension(file_name, ".rt") == false)
		write(1, WARNING_1, ft_strlen(WARNING_1));
	path_file = ft_strjoin(PATH_MAP, file_name);
	data->fd = open(path_file, O_RDONLY);
	free (path_file);
	if (data->fd < 0)
		return (false);
	return (true);
}

void	check_args(t_data *data, int argc, char **argv)
{
	if (argc < 2)
	{
		write(1, ERROR_1, ft_strlen(ERROR_1));
		exit(1);
	}
	else if (argc > 2)
	{
		write(1, ERROR_2, ft_strlen(ERROR_2));
		exit(2);
	}
	else if (open_file(data, argv[1]) == false)
	{
		write(1, ERROR_3, ft_strlen(ERROR_3));
		exit(3);
	}
}
