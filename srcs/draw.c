/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 15:59:55 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 21:16:26 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_opengl.h"

void		draw_quad(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4)
{
	glBegin(GL_QUADS);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p3.x, p3.y, p3.z);
	glVertex3f(p4.x, p4.y, p4.z);
	glEnd();
	glFlush();
}

void		draw_ball(t_ball ball)
{
	int		i;
	float	theta;
	float	x;
	float	y;

	glColor3f(1.f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	i = 0;
	while (i < ball.seg)
	{
		theta = 2.0f * 3.1415926f * (float)i / (float)ball.seg;
		x = ball.radius * ft_cos(theta);
		y = ball.radius * ft_sin(theta);
		glVertex2f(x + ball.x, y + ball.y);
		i++;
	}
	glEnd();
}

void		draw_dot(t_vec3 p)
{
	glBegin(GL_POINTS);
	glVertex3f(p.x, p.y, p.z);
	glEnd();
	glFlush();
}

void		draw_player(t_player pl, float scale)
{
	float	ratio;
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	p4;

	ratio = scale / pl.size;
	glColor3f(0.0f, 1.0f, 0.0f);
	p1 = set_vector(pl.x - ratio, pl.y - 0.01f, 0);
	p2 = set_vector(pl.x - ratio, pl.y + 0.01f, 0);
	p3 = set_vector(pl.x + ratio, pl.y + 0.01f, 0);
	p4 = set_vector(pl.x + ratio, pl.y - 0.01f, 0);
	draw_quad(p1, p2, p3, p4);
}

void		draw_box(float x, float y, float w, float h)
{
	t_vec3	p1;
	t_vec3	p2;
	t_vec3	p3;
	t_vec3	p4;

	p1 = set_vector(x - w, y - h, 0);
	p2 = set_vector(x - w, y + h, 0);
	p3 = set_vector(x + w, y + h, 0);
	p4 = set_vector(x + w, y - h, 0);
	draw_quad(p1, p2, p3, p4);
}
