/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sceneopengl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 16:05:04 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/02 20:53:48 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SceneOpenGL.h"

void 	move(int dir) {

	float mv = (float)dir / gl->player.speed;
	float	ratio = gl->scale.x / gl->player.size;
	if (!((gl->player.x-ratio+mv) <= -1 || (gl->player.x+ratio+mv) >= 1))
		gl->player.x += mv;
}

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void)mods;
	(void)scancode;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		move(1);
	if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT))
		move(-1);
}
#include <stdio.h>
void	scene(t_gl *gl, char *titre, int width, int height)
{
	gl->titre = ft_strdup(titre);
	gl->width = width;
	gl->height = height;
	gl->scale.x = 1 / (float)gl->map->nb_c;
	gl->scale.y = 1 / ((float)gl->map->nb_l + 5);
	gl->scale.z = 1;

	printf("x= %f, y= %f\n\n\n", gl->scale.x, gl->scale.y);
}

void	destroy_opengl(t_gl *gl)
{
	glfwDestroyWindow(gl->window);
	glfwTerminate();
}

void drawQuad(t_vec3 p1, t_vec3 p2, t_vec3 p3, t_vec3 p4) {
	glBegin(GL_QUADS);
	glVertex3f(p1.x, p1.y, p1.z);
	glVertex3f(p2.x, p2.y, p2.z);
	glVertex3f(p3.x, p3.y, p3.z);
	glVertex3f(p4.x, p4.y, p4.z);
	glEnd();
	glFlush();
}

void drawBall(t_ball ball)
{
	glColor3f(1.f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	for(int i = 0; i < ball.seg; i++)
	{
		float theta = 2.0f * 3.1415926f * (float)i / (float)ball.seg;//get the current angle

		float x = ball.radius * cosf(theta);//calculate the x component
		float y = ball.radius * sinf(theta);//calculate the y component

		glVertex2f(x + ball.x, y + ball.y);//output vertex

	}
	glEnd();
}

t_vec3		setVector(float x, float y, float z)
{
	t_vec3 vect;

	vect.x = x;
	vect.y = y;
	vect.z = z;
	return vect;
}

void drawDot(t_vec3 p) {

	glBegin(GL_POINTS);
	glVertex3f(p.x, p.y, p.z);
	glEnd();
	glFlush();
}

void drawPlayer(t_player pl)
{
	glColor3f(0.0f, 1.0f, 0.0f);
	float	ratio = gl->scale.x / pl.size;
	t_vec3 p1 = setVector(pl.x-ratio, pl.y-0.01f, 0);
	t_vec3 p2 = setVector(pl.x-ratio, pl.y+0.01f, 0);
	t_vec3 p3 = setVector(pl.x+ratio, pl.y+0.01f, 0);
	t_vec3 p4 = setVector(pl.x+ratio, pl.y-0.01f, 0);
	drawQuad(p1, p2, p3, p4);
}

void move_ball() {

	if (gl->ball.y - gl->ball.radius <= -1)
		gl->ball.dy *= -1;
	else if (gl->ball.y + gl->ball.radius >= 1)
			gl->ball.dy *= -1;
	/*else
		gl->ball.dy -= gl->ball.gravity; //Apply gravity*/

	//Update ball coordinates
	gl->ball.x += gl->ball.dx;
	gl->ball.y += gl->ball.dy;



	float	ratio = gl->scale.x / gl->player.size;


	if (gl->ball.x >= gl->player.x - ratio && gl->ball.x <= gl->player.x + ratio)
	{
		if (gl->ball.y+gl->ball.radius >= gl->player.y-0.01f)
		{
			gl->ball.dx *= -1;
			gl->ball.dy *= -1; // a is a fudge factor between 0 and 1
			printf("ahmed\n");
		}
	}
	if (gl->ball.x + gl->ball.radius >= 1 || gl->ball.x - gl->ball.radius <= -1)
		gl->ball.dx *= -1;
/*	if (gl->ball.y + gl->ball.radius >= 1 || gl->ball.y - gl->ball.radius <= -1)
		gl->ball.dy *= -1;*/
}

int		initialiser_fenetre(t_gl *gl)
{
	if (!glfwInit())
		return (-1);
	gl->window = glfwCreateWindow(gl->width, gl->height, gl->titre, NULL, NULL);
	if (!gl->window)
	{
		glfwTerminate();
		return (-1);
	}
	glfwMakeContextCurrent(gl->window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(gl->window, key_callback);

	// Boucle principale
	glEnable (GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1, 0, 1, 0, 3);
	glMatrixMode(GL_MODELVIEW);
	glTranslatef(0.5, 0.5, -2.); // (0.8, 0.3, -2.)
	glRotatef(180, 1, 0, 0);
	// glRotatef(60, 1, 0, 0);
	glScalef(0.5f, 0.5f, 1.f);

	float w = (gl->scale.x / 2.f) - 0.005f;
	float h = (gl->scale.y / 2.f) - 0.005f;

	while (!glfwWindowShouldClose(gl->window))
	{

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable (GL_BLEND);
		glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glColor3f(1.f, 0.0f, 0.0f);

		// drawDot(setVector(-0.9f, -0.9f, 0));

		float y = -1 + h;

		for(int l=0; l < gl->map->nb_l; l++)
		{
			float x = -1 + w;
			for(int c=0; c < gl->map->nb_c; c++)
			{
				if (gl->map->map[l][c] != 0)
				{
					t_vec3 p1 = setVector(x-w, y-h, 0);
					t_vec3 p2 = setVector(x-w, y+h, 0);
					t_vec3 p3 = setVector(x+w, y+h, 0);
					t_vec3 p4 = setVector(x+w, y-h, 0);
					drawQuad(p1, p2, p3, p4);
				}
				x += gl->scale.x;
			}
			y += gl->scale.y;
		}
		move_ball();
		drawBall(gl->ball);
		drawPlayer(gl->player);
		glfwSwapBuffers(gl->window);
		glfwPollEvents();
	}
	return (0);
}
