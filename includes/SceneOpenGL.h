/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SceneOpenGL.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:48:32 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/02 20:38:14 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_OPENGL_H
# define SCENE_OPENGL_H

#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <math.h>

#include "get_next_line.h"
#include "../libft/includes/libft.h"
#include "list.h"

t_gl  *gl;

void  scene(t_gl *gl, char *titre, int width, int height);
void  destroy_opengl(t_gl *gl);
int   initialiser_fenetre(t_gl *gl);
void  move(int dir);
int		space_nb(char *str);
int		**remplir(int fd, int nb_l, int **tab, int *nb_c);
char	*delete_spaces(char *str);
int		line_nb(char *file);
int		**ft_lecture(char *file, int *nb_l, int *nb_c);

#endif
