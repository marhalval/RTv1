/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addobject.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:41:51 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/24 17:41:54 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	add_sphere(t_object **obj, t_vector p, double r, t_color col)
{
	t_object	*node;
	t_sphere	*sphere;

	node = (t_object *)malloc(sizeof(t_object));
	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	sphere->center = p;
	sphere->radius = r;
	sphere->color = col;
	node->object = (t_sphere *)sphere;
	node->type = 1;
	node->next = *obj;
	*obj = node;
}

void	add_cylinder(t_object **obj, t_vector p, double r, t_vector d)
{
	t_object	*node;
	t_cylinder	*cylinder;

	node = (t_object *)malloc(sizeof(t_object));
	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	cylinder->center = p;
	cylinder->dir = d;
	cylinder->radius = r;
	cylinder->color = (t_color){0, 0, 1};
	node->object = (t_cylinder *)cylinder;
	node->type = 2;
	node->next = *obj;
	*obj = node;
}

void	add_cone(t_object **obj, t_vector p, double alpha, t_vector d)
{
	t_object	*node;
	t_cone		*cone;

	node = (t_object *)malloc(sizeof(t_object));
	cone = (t_cone *)malloc(sizeof(t_cone));
	cone->center = p;
	cone->dir = d;
	cone->alpha = alpha * M_PI / 180;
	cone->color = (t_color){1, 1, 0};
	node->object = (t_cone *)cone;
	node->type = 3;
	node->next = *obj;
	*obj = node;
}

void	add_plane(t_object **obj, t_vector p, t_vector d, t_color col)
{
	t_object	*node;
	t_plane		*plane;

	node = (t_object *)malloc(sizeof(t_object));
	plane = (t_plane *)malloc(sizeof(t_plane));
	plane->pos = p;
	plane->dir = d;
	plane->color = col;
	node->object = (t_plane *)plane;
	node->type = 4;
	node->next = *obj;
	*obj = node;
}

void	add_light(t_light **light, t_vector p, t_color col, double a)
{
	t_light		*node;

	node = (t_light *)malloc(sizeof(t_light));
	node->pos = p;
	node->color = col;
	node->p = a;
	node->next = *light;
	*light = node;
}
