/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:48:38 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/02 20:38:28 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SceneOpenGL.h"

t_player	setPlayer()
{
	t_player	pl;

	pl.x = 0;
	pl.y = 0.95f;
	pl.size = 2;
	pl.speed = 15.f;

	return pl;
}

t_ball setBall()
{
	t_ball ball;

	ball.radius = 0.02f;
	ball.gravity = -0.01f;
	ball.x = 0;
	ball.y = 0;//gl->player.y - ball.radius;
	ball.dx = 0.01f;
	ball.dy = 0.01f;
	ball.seg = 100;

	return ball;
}

int		main(int ac, char **av)
{
	srand(time(NULL));
	if (ac != 2)
	{
		ft_putstr("usage : ");
		ft_putstr(av[0]);
		ft_putendl(" FILE.map");
		return (-1);
	}

	gl = (t_gl*)malloc(sizeof(t_gl));
	gl->map = (t_map*)malloc(sizeof(t_map));
	gl->map->map = ft_lecture(av[1], &(gl->map->nb_l), &(gl->map->nb_c));
	gl->player = setPlayer();
	gl->ball = setBall();

	scene(gl, "ARKANOID", 800, 600);
	if (initialiser_fenetre(gl) == -1)
		return (-1);
	destroy_opengl(gl);
	return (0);
}
