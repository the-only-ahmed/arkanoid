/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 18:48:13 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 22:19:26 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_opengl.h"

void				set_color(int cas)
{
	if (cas == 1)
		glColor3f(1.f, 0.f, 0.f);
	else if (cas == 2)
		glColor3f(0.f, 1.f, 0.f);
	else if (cas == 3)
		glColor3f(0.5f, 0.f, 0.5f);
	else if (cas == 4)
		glColor3f(0.f, 1.f, 1.f);
	else
		glColor3f(0.3f, 0.3f, 0.3f);
}

static void			free_map(t_gl *gl)
{
	int		i;

	i = 0;
	while (i < gl->map->nb_l)
	{
		free(gl->map->map[i]);
		gl->map->map[i] = NULL;
		i++;
	}
	free(gl->map->map);
	gl->map->map = NULL;
	free(gl->map);
	gl->map = NULL;
}

void				destroy_opengl(t_gl *gl)
{
	glfwDestroyWindow(gl->window);
	glfwTerminate();
	free_map(gl);
	free(gl->titre);
	gl->titre = NULL;
	get_glide(1);
}

void				show_score(t_gl *gl)
{
	char	*string;

	string = ft_itoa(gl->score);
	glfwSetWindowTitle(gl->window, string);
	free(string);
	string = NULL;
	gl->player.speed = 0;
}

void				move(int dir)
{
	float	mv;
	float	ret;
	t_gl	*gl;

	gl = get_glide(0);
	if (gl->pause)
		return ;
	gl->player.speed = dir;
	mv = (float)dir / 15.f;
	ret = gl->scale.x / gl->player.size;
	if (!((gl->player.x - ret + mv) <= -1 || (gl->player.x + ret + mv) >= 1))
		gl->player.x += mv;
}
