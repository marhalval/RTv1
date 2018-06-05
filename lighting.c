/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 20:32:57 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/24 20:32:59 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static double	find_lambert(t_light *l_list, t_vector pos, t_vector normal)
{
	double		lambert;
	double		cos;
	t_vector	dir;

	lambert = 0;
	dir = v_norm(v_sub(l_list->pos, pos));
	cos = v_dot(dir, normal);
	if (cos > 0)
		lambert = cos;
	return (lambert);
}

static t_color	find_fong(t_light *list, t_vector pos, t_vector n, t_vector cam)
{
	t_color		fong;
	double		cos;
	t_vector	to_light;
	t_vector	to_cam;
	t_vector	h;

	fong = (t_color){0, 0, 0};
	to_light = v_sub(list->pos, pos);
	to_cam = v_sub(cam, pos);
	h = v_add(to_cam, to_light);
	cos = v_dot(v_norm(h), n);
	if (cos > 0)
	{
		fong.r = pow(cos, list->p) * list->color.r;
		fong.g = pow(cos, list->p) * list->color.g;
		fong.b = pow(cos, list->p) * list->color.b;
	}
	return (fong);
}

static void		lighting(t_object *obj, t_light *l_list, t_mlx *new, t_color *c)
{
	t_color		obj_color;
	double		lambert;
	t_color		fong;
	t_vector	normal;

	normal = obj->normal;
	if (obj->type == 4)
		normal = check_normal(normal, new->light);
	obj_color = get_obj_color(obj);
	lambert = find_lambert(l_list, new->light.start, normal);
	fong = find_fong(l_list, new->light.start, normal, new->ray.start);
	c->r += fong.r + lambert * obj_color.r;
	c->g += fong.g + lambert * obj_color.g;
	c->b += fong.b + lambert * obj_color.b;
}

static void		help_light(t_mlx *new, t_light *light)
{
	new->light.dir = v_sub(light->pos, new->light.start);
	new->dist = v_mod(new->light.dir);//what is it for?
	new->t = new->dist + 1;//and this??
	new->light.dir = v_norm(new->light.dir);
}

void			choose_color_obj(t_object *closest, t_mlx *new, t_color *color)
{
	t_ray		light;
	double		dist;
	int			flag;
	t_light		*lights;
	t_object	*objects;

	lights = new->l_list;
	new->light.start = v_add(new->ray.start, v_mult_c(new->ray.dir, new->t)); //inter_point?
	find_normal(closest, new->light.start, new);
	while (lights)
	{
		help_light(new, lights);
		flag = 1;
		objects = new->o_list;
		while (objects && flag)
		{
			intersection_object(new, objects, new->light);
			flag = (new->intersection == 1) ? 0 : 1;
			objects = objects->next;
		}
		if (flag == 1)
			lighting(closest, lights, new, color);
		lights = lights->next;
	}
}
