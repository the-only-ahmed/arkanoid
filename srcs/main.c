/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/02 15:48:38 by ael-kadh          #+#    #+#             */
/*   Updated: 2015/05/03 21:56:03 by ael-kadh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene_opengl.h"

static t_player		set_player(void)
{
	t_player			pl;

	pl.x = 0;
	pl.y = 0.95f;
	pl.size = 2;
	pl.speed = 0.f;
	return (pl);
}

static t_ball		set_ball(t_gl *gl)
{
	t_ball				ball;

	ball.radius = 0.02f;
	ball.gravity = -0.01f;
	ball.x = 0;
	ball.y = gl->player.y - (ball.radius * 2);
	ball.dx = 0.01f;
	ball.dy = 0.02f;
	ball.seg = 100;
	return (ball);
}

t_gl				*get_glide(int f)
{
	static t_gl		*gl = NULL;

	if (f)
	{
		free(gl);
		gl = NULL;
	}
	else
	{
		if (!gl)
			gl = (t_gl*)malloc(sizeof(t_gl));
	}
	return (gl);
}

static int			looping(t_gl *gl, int sc, char *level, int lvl)
{
	gl->map = (t_map*)malloc(sizeof(t_map));
	gl->map->map = ft_lecture(level, &(gl->map->nb_l), &(gl->map->nb_c));
	gl->player = set_player();
	gl->ball = set_ball(gl);
	gl->score = sc;
	scene(gl, "ARKANOID", 800, 600);
	lvl = initialiser_fenetre(gl, lvl);
	if (lvl == -1)
		return (-1);
	return (lvl + 1);
}

int					main(int ac, char **av)
{
	t_gl			*gl;
	int				lvl;
	int				sc;

	if (ac < 2)
	{
		ft_putstr("usage : ");
		ft_putstr(av[0]);
		ft_putendl(" FILE.map [...]");
		return (-1);
	}
	lvl = 1;
	sc = 0;
	while (lvl < ac && lvl != -21)
	{
		gl = get_glide(0);
		lvl = looping(gl, sc, av[lvl], lvl);
		if (lvl == -1)
			return (-1);
		sc = gl->score;
		destroy_opengl(gl);
	}
	ft_putstr("GameOver : ");
	ft_putnbr(sc);
	return (0);
}
