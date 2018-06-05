/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 19:07:17 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/25 19:07:19 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		intersection_object(t_mlx *new, t_object *o_list, t_ray ray)
{
	if (o_list->type == 1)
		intersection_sphere(o_list, ray, new);
	else if (o_list->type == 2)
		intersection_cyl(o_list, ray, new);
	else if (o_list->type == 3)
		intersection_cone(o_list, ray, new);
	else
		intersection_plane(o_list, ray, new);
}

void		intersection_sphere(t_object *o_list, t_ray ray, t_mlx *new)
{
	double		a;
	double		b;
	double		c;
	t_sphere	*sphere;

	sphere = (t_sphere *)o_list->object;
	a = v_dot(ray.dir, ray.dir);
	b = 2 * v_dot(ray.dir, v_sub(ray.start, sphere->center));
	c = v_dot(v_sub(ray.start, sphere->center),
		v_sub(ray.start, sphere->center)) - pow(sphere->radius, 2);
	calc_discriminant(a, b, c, new);
}

void		intersection_cyl(t_object *o_list, t_ray ray, t_mlx *new)
{
	double		a;
	double		b;
	double		c;
	t_cylinder	*cyl;
	t_vector	x;

	cyl = (t_cylinder *)o_list->object;
	cyl->dir = v_norm(cyl->dir);
	x = v_sub(ray.start, cyl->center);
	a = v_dot(ray.dir, ray.dir)
		- v_dot(ray.dir, cyl->dir) * v_dot(ray.dir, cyl->dir);
	b = 2 * (v_dot(ray.dir, x) - v_dot(ray.dir, cyl->dir) * v_dot(x, cyl->dir));
	c = v_dot(x, x) - v_dot(x, cyl->dir) * v_dot(x, cyl->dir)
		- cyl->radius * cyl->radius;
	calc_discriminant(a, b, c, new);
}

void		intersection_cone(t_object *o_list, t_ray ray, t_mlx *new)
{
	double		a;
	double		b;
	double		c;
	t_cone		*cone;
	double		k;

	cone = (t_cone *)o_list->object;
	cone->dir = v_norm(cone->dir);
	k = tan(cone->alpha);
	a = v_dot(ray.dir, ray.dir) - (1 + k * k) * v_dot(ray.dir, cone->dir)
		* v_dot(ray.dir, cone->dir);
	b = 2 * (v_dot(ray.dir, v_sub(ray.start, cone->center))
		- (1 + k * k) * v_dot(ray.dir, cone->dir)
		* v_dot(v_sub(ray.start, cone->center), cone->dir));
	c = v_dot(v_sub(ray.start, cone->center), v_sub(ray.start, cone->center))
		- (1 + k * k) * v_dot(v_sub(ray.start, cone->center), cone->dir)
		* v_dot(v_sub(ray.start, cone->center), cone->dir);
	calc_discriminant(a, b, c, new);
}

void		intersection_plane(t_object *o_list, t_ray ray, t_mlx *new)
{
	t_vector	x;
	double		tt;
	t_plane		*plane;

	plane = (t_plane *)o_list->object;
	plane->dir = v_norm(plane->dir);
	if (v_dot(ray.dir, plane->dir) == 0)
	{
		new->intersection = 0;
		return ;
	}
	new->intersection = 1;
	x = v_sub(ray.start, plane->pos);
	tt = -v_dot(x, plane->dir) / v_dot(ray.dir, plane->dir);
	if (tt > 0.001 && tt < new->t)
		new->t = tt - 0.1;
	else
		new->intersection = 0;
	if (new->t > new->dist)
		new->intersection = 0;
}
