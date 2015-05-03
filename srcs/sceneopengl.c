/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceneopengl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:05:04 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 22:27:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_opengl.h"

void		key_callback(GLFWwindow *window, int k, int s, int action, int mods)
{
	(void)mods;
	(void)s;
	if (k == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
		exit(0);
	}
	if (k == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		move(1);
	if (k == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		move(-1);
}

void		paddle_collision(t_gl *gl)
{
	if (gl->ball.y + gl->ball.radius >= gl->player.y - 0.01f)
	{
		if ((gl->player.speed < 0 && gl->ball.dx < 0)
				|| (gl->player.speed > 0 && gl->ball.dx > 0))
		{
			gl->ball.dx *= -1;
			if (gl->ball.x == gl->player.x)
				gl->ball.dx = 0;
		}
		if (gl->player.speed != 0 && gl->ball.dx == 0)
		{
			if (gl->ball.dx > -0.03f && gl->ball.dx < 0.03f)
				gl->ball.dx += (float)(gl->player.speed / 10);
		}
		gl->ball.dy *= -1;
	}
}

int			move_ball(t_gl *gl)
{
	float	rat;

	rat = gl->scale.x / gl->player.size;
	if (gl->ball.y - gl->ball.radius <= -1)
		gl->ball.dy *= -1;
	else if (gl->ball.y + gl->ball.radius >= 1)
		gl->ball.dy *= -1;
	if (gl->ball.x >= gl->player.x - rat && gl->ball.x <= gl->player.x + rat)
		paddle_collision(gl);
	if (gl->ball.x + gl->ball.radius >= 1 || gl->ball.x - gl->ball.radius <= -1)
		gl->ball.dx *= -1;
	gl->ball.x += gl->ball.dx;
	gl->ball.y += gl->ball.dy;
	if (gl->ball.y > gl->player.y)
		return (0);
	return (1);
}

void		ball_direction(float x, float y, float w, float h)
{
	t_gl	*gl;

	gl = get_glide(0);
	if (gl->ball.x + gl->ball.radius >= (x + w)
			|| gl->ball.x - gl->ball.radius <= (x - w))
		gl->ball.dx *= -1;
	if (gl->ball.y + gl->ball.radius >= (y + h)
			|| gl->ball.y - gl->ball.radius <= (y - h))
		gl->ball.dy *= -1;
}

int			check_collision(float x, float y, float w, float h)
{
	t_gl	*gl;

	gl = get_glide(0);
	set_color(gl->this);
	draw_box(x, y, w, h);
	if (gl->ball.x > (x - w) && gl->ball.x < (x + w))
	{
		if (gl->ball.y > (y - h) && gl->ball.y < (y + h))
		{
			if (gl->this < 5)
			{
				gl->score += gl->this;
				gl->this--;
			}
			ball_direction(x, y, w, h);
		}
	}
	return (1);
}
