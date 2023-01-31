/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdescour <cdescour@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:49:40 by cdescour          #+#    #+#             */
/*   Updated: 2023/01/30 19:46:41 by cdescour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h> // a supprimer

# include "libft/libft.h"
# include "mlx42/mlx.h"

# define READLINE_MAX 1024
# define WIN_X 1920
# define WIN_Y 1080
# define PATH_MAP "maps/"

# define ERROR_1 "Error: No arguments detected. Use ./miniRT [NAME].rt\n"
# define ERROR_2 "Error: Many arguments detected. Use ./miniRT [NAME].rt\n"
# define ERROR_3 "Error: Can't open the map, check is presence in maps.\n"
# define ERROR_4 "Error: No camera in the file, can't make a render.\n"
# define ERROR_5 "Error: To many cameras in the file, max is 99.\n"
# define ERROR_6 "Error: To many cameras because C is uppercase.\n"
# define ERROR_7 "Error: To many spheres because SP is uppercase.\n"
# define ERROR_8 "Error: To many cylinders because CY is uppercase.\n"
# define ERROR_9 "Error: To many plans because PL is uppercase.\n"
# define ERROR_10 "Error: To many spots because L is uppercase.\n"
# define ERROR_11 "Error: To many ambiante lighr because A is uppercase.\n"
# define ERROR_12 "Error: Argument on the file invalid.\n"
# define ERROR_13 "Error: Settings camera invalid.\n"
# define ERROR_14 "Error: Settings sphere invalid.\n"
# define ERROR_15 "Error: Settings cylinder invalid.\n"
# define ERROR_16 "Error: Settings plan invalid.\n"
# define ERROR_17 "Error: Settings light invalid.\n"
# define ERROR_18 "Error: Settings ambiant light invalid.\n"

# define WARNING_1 "Warning: Extension name is invalid.\n"
# define WARNING_2 "Warning: No ambiant light.\n"
# define WARNING_3 "Warning: Multiple ambiant lights.\n"
# define WARNING_4 "Warning: No object, black screen.\n"
# define WARNING_5 "Warning: No light, black screen.\n"

# define MESSAGE_1 "Info: Camera added.\n"
# define MESSAGE_2 "Info: Multi-camera denied.\n"
# define MESSAGE_3 "Info: Sphere added.\n"
# define MESSAGE_4 "Info: Multi-sphere denied.\n"
# define MESSAGE_5 "Info: Cylinder added.\n"
# define MESSAGE_6 "Info: Multi-cylinder denied.\n"
# define MESSAGE_7 "Info: Plan added.\n"
# define MESSAGE_8 "Info: Multi-plan denied.\n"
# define MESSAGE_9 "Info: Light added.\n"
# define MESSAGE_10 "Info: Multi-light denied.\n"
# define MESSAGE_11 "Info: Ambiant light added.\n"
# define MESSAGE_12 "Info: Multi-ambiant-light denied.\n"

typedef struct s_data{
	int	fd;
	int	nb_cam;
	int	nb_sph;
	int	nb_cyl;
	int	nb_pln;
	int	nb_glu;
	int	nb_alu;
	bool	mult_cam;
	bool	mult_sph;
	bool	mult_cyl;
	bool	mult_pln;
	bool	mult_glu;
	bool	mult_alu;
}	t_data;

//main.c
int	main(int argc, char **argv);

//args.c
bool	check_extension(char *file_name, char *extension);
bool	open_file(t_data *data, char *file_name);
void	check_args(t_data *data, int argc, char **argv);

//file.c
void	init_data(t_data *data);
void	check_rules(t_data *data);
void	check_data(t_data *data);
void	check_file(t_data *data);

//gnl.c
char	*get_next_line(int fd);

//cam.c

void	check_cam(char **splited, t_data *data);

//sph.c

void	check_sph(char **splited, t_data *data);

//cyl.c

void	check_cyl(char **splited, t_data *data);

//pln.c

void	check_pln(char **splited, t_data *data);

//light.c

void	check_light(char **splited, t_data *data);

//a_light.c

void	check_alight(char **splited, t_data *data);

//obj.c
bool	color_is_ok(char *arg);
bool	position_is_ok(char *arg);
bool	direction_is_ok(char *arg);
bool	len_is_ok(char *arg);
bool	fov_is_ok(char *arg);
bool	ratio_is_ok(char *arg);
bool	nbr_is_ok(char *arg);
bool	max_direction_ok(char *nb);

//free.C
void	free_char_tab(char **tab);
void	free_data(t_data *data);

#endif
