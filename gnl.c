/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:28:25 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/27 14:05:22 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*get_next_line(int fd)
{
	char	buffer;
	char	*line;
	int		rd_byte;
	int		i;

	rd_byte = 1;
	i = 0;
	line = (char *)malloc(sizeof(char) * READLINE_MAX);
	buffer = 0;
	if (fd < 0)
		return (NULL);
	while (rd_byte > 0)
	{
		rd_byte = read(fd, &buffer, 1);
		if (rd_byte <= 0)
			break ;
		line[i++] = buffer;
		if (buffer == '\n')
			break ;
	}
	if ((i == 1 && line[0] == '\n') || (i == 0))
		line[i] = '\0';
	else
		line[i - 1] = '\0';
	return (line);
}
