/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:52:30 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/25 17:52:33 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	find_normal_sphere(t_object *object, t_vector inter_pos)
{
	t_sphere	*sphere;
	t_vector	normal;

	sphere = (t_sphere *)object->object;
	normal = v_norm(v_sub(inter_pos, sphere->center));
	object->normal = normal;
}

static void	find_normal_cyl(t_object *object, t_vector inter_pos, t_mlx *new)
{
	t_cylinder	*cyl;
	t_vector	normal;
	t_vector	v;
	double		m;

	cyl = (t_cylinder *)object->object;
	cyl->dir = v_norm(cyl->dir);
	m = v_dot(cyl->dir, new->ray.dir) * new->t
		+ v_dot(cyl->dir, v_sub(new->ray.start, cyl->center));
	v = v_sub(inter_pos, cyl->center);
	normal = v_norm(v_sub(v, v_mult_c(cyl->dir, m)));
	object->normal = normal;
}

static void	find_normal_cone(t_object *object, t_vector inter_pos, t_mlx *new)
{
	t_cone		*cone;
	t_vector	normal;
	t_vector	v;
	double		m;
	double		k;

	cone = (t_cone *)object->object;
	cone->dir = v_norm(cone->dir);
	k = tan(cone->alpha);
	m = v_dot(cone->dir, new->ray.dir) * new->t
		+ v_dot(cone->dir, v_sub(new->ray.start, cone->center));
	v = v_sub(inter_pos, cone->center);
	normal = v_norm(v_sub(v, v_mult_c(cone->dir, m * (1 + k * k))));
	object->normal = normal;
}

static void	find_normal_plane(t_object *object)
{
	t_plane		*plane;

	plane = (t_plane *)object->object;
	plane->dir = v_norm(plane->dir);
	object->normal = plane->dir;
}

void		find_normal(t_object *obj, t_vector inter_pos, t_mlx *new)
{
	if (obj->type == 1)
		find_normal_sphere(obj, inter_pos);
	else if (obj->type == 2)
		find_normal_cyl(obj, inter_pos, new);
	else if (obj->type == 3)
		find_normal_cone(obj, inter_pos, new);
	else
		find_normal_plane(obj);
}
