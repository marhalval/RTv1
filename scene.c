/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 22:45:52 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/20 22:45:54 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		scene_1(t_mlx *new)
{
	t_object	*o_list;
	t_light		*l_list;

	o_list = NULL;
	l_list = NULL;
	add_sphere(&o_list, (t_vector){0, 0, 0}, 300, (t_color){1, 0, 0});
	add_cone(&o_list, (t_vector){200, 0, 0}, 30, (t_vector){0, 1, 0});
	add_plane(&o_list, (t_vector){0, 900, 0}, (t_vector){0, -1, 0},
											(t_color){0.6, 0.6, 0.7});
	add_light(&l_list, (t_vector){800, 600, 800}, (t_color){0.8, 0.8, 0.8}, 20);
	new->o_list = o_list;
	new->l_list = l_list;
}

static void		scene_2(t_mlx *new)
{
	t_object	*o_list;
	t_light		*l_list;

	o_list = NULL;
	l_list = NULL;
	add_cylinder(&o_list, (t_vector){0, 0, 0}, 200, (t_vector){0, 1, 0});
	add_light(&l_list, (t_vector){1200, 1200, 1200},
						(t_color){0.7, 0.7, 0.7}, 10);
	add_light(&l_list, (t_vector){-1500, -800, 400},
						(t_color){0.8, 0.8, 0.8}, 30);
	new->o_list = o_list;
	new->l_list = l_list;
}

static void		scene_3(t_mlx *new)
{
	t_object	*o_list;
	t_light		*l_list;

	o_list = NULL;
	l_list = NULL;
	add_cone(&o_list, (t_vector){0, 0, 0}, 15, (t_vector){1, 1, 0});
	add_light(&l_list, (t_vector){1200, 1200, 1200},
						(t_color){0.7, 0.7, 0.7}, 10);
	add_light(&l_list, (t_vector){-100, 800, 400},
						(t_color){0.8, 0.8, 0.8}, 30);
	new->o_list = o_list;
	new->l_list = l_list;
}

static void		scene_4(t_mlx *new)
{
	t_object	*o_list;
	t_light		*l_list;

	o_list = NULL;
	l_list = NULL;
	add_cylinder(&o_list, (t_vector){300, 0, 300}, 100, (t_vector){0, 1, 0});
	add_cylinder(&o_list, (t_vector){-300, 0, 300}, 100, (t_vector){0, 1, 0});
	add_plane(&o_list, (t_vector){0, -400, 0}, (t_vector){0, -1, 0},
											(t_color){0.6, 0.6, 0.7});
	add_light(&l_list, (t_vector){800, 800, 900}, (t_color){0.7, 0.7, 0.7}, 50);
	add_light(&l_list, (t_vector){-800, 800, 900}, (t_color){1, 1, 1}, 50);
	new->o_list = o_list;
	new->l_list = l_list;
}

void			init_scene(t_mlx *new)
{
	new->ray.start = (t_vector){0, 0, 2000};
	new->amb = (t_color){0.2, 0.2, 0.2};
	new->black = (t_color){0, 0, 0};
	new->t = 20000;
	if (new->scene == 1)
		scene_1(new);
	if (new->scene == 2)
		scene_2(new);
	if (new->scene == 3)
		scene_3(new);
	if (new->scene == 4)
		scene_4(new);
}
