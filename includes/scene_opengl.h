/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_opengl.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:38:02 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 21:57:25 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_OPENGL_H
# define SCENE_OPENGL_H

# include <stdlib.h>
# include <fcntl.h>
# include <time.h>

# include "get_next_line.h"
# include "../libft/includes/libft.h"
# include "list.h"

void	scene(t_gl *gl, char *titre, int width, int height);
void	destroy_opengl(t_gl *gl);
int		initialiser_fenetre(t_gl *gl, int lvl);
void	move(int dir);
int		space_nb(char *str);
int		**remplir(int fd, int nb_l, int **tab, int *nb_c);
char	*delete_spaces(char *str);
int		line_nb(char *file);
int		**ft_lecture(char *file, int *nb_l, int *nb_c);
t_gl	*get_glide(int f);
void	key_callback(GLFWwindow *window, int k, int s, int action, int mods);
void	draw_quad(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4);
void	draw_box(float x, float y, float w, float h);
void	draw_ball(t_ball ball);
void	draw_dot(t_vec3 p);
void	draw_player(t_player pl, float scale);
int		main_loop(float w, float h, t_gl *gl, int ahmed);
int		move_ball(t_gl *gl);
t_vec3	set_vector(float x, float y, float z);
int		check_collision(float x, float y, float w, float h);
void	set_color(int cas);
void	show_score(t_gl *gl);
double	ft_abs(const double v);
double	ft_sqrt(const double fg);
double	ft_sin(const double x);
double	ft_cos(double x);

#endif
