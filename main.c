/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:42:11 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/27 14:12:16 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data data;

	int i = INT_MAX;
	long int j= LONG_MAX;
	printf("INT_MAX = %d\n", i);
	printf("LONG_INT_MAX = %ld\n", j);
	check_args(&data, argc, argv);
	check_file(&data);
	free_data(&data);
	return (0);
}
