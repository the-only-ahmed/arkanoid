/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_glide.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:47:03 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 22:28:33 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_opengl.h"

void			scene(t_gl *gl, char *titre, int width, int height)
{
	gl->titre = ft_strdup(titre);
	gl->width = width;
	gl->height = height;
	gl->scale.x = 2 / (float)gl->map->nb_c;
	gl->scale.y = 2 / ((float)gl->map->nb_l + 2);
	gl->scale.z = 1;
}

static void		init_glide(t_gl *gl, float *w, float *h)
{
	glfwMakeContextCurrent(gl->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(gl->window, key_callback);
	glEnable (GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, 0, 3);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.5, 0.5, -2.);
	glRotatef(180, 1, 0, 0);
	glScalef(0.5f, 0.5f, 1.f);
	*w = (gl->scale.x / 2.f) - 0.005f;
	*h = (gl->scale.y / 2.f) - 0.005f;
}

int				initialiser_fenetre(t_gl *gl, int lvl)
{
	float	w;
	float	h;

	if (!glfwInit())
		return (-1);
	gl->window = glfwCreateWindow(gl->width, gl->height, gl->titre, NULL, NULL);
	if (!gl->window)
	{
		glfwTerminate();
		return (-1);
	}
	init_glide(gl, &w, &h);
	while (!glfwWindowShouldClose(gl->window))
	{
		show_score(gl);
		if (!main_loop(w, h, gl, 0))
			return (lvl);
		if (!move_ball(gl))
			return (-22);
		draw_ball(gl->ball);
		draw_player(gl->player, gl->scale.x);
		glfwSwapBuffers(gl->window);
		glfwPollEvents();
	}
	return (lvl);
}

int				main_loop(float w, float h, t_gl *gl, int ahmed)
{
	float	x;
	float	y;
	int		l;
	int		c;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable (GL_BLEND);
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	y = -1 + h;
	l = -1;
	while (++l < gl->map->nb_l)
	{
		x = -1 + w;
		c = -1;
		while (++c < gl->map->nb_c)
		{
			gl->this = gl->map->map[l][c];
			if (gl->this != 0)
				ahmed += check_collision(x, y, w, h);
			gl->map->map[l][c] = gl->this;
			x += gl->scale.x;
		}
		y += gl->scale.y;
	}
	return (ahmed);
}

t_vec3			set_vector(float x, float y, float z)
{
	t_vec3	vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return (vect);
}
