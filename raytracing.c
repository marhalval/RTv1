/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:39:49 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/18 18:39:50 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		draw_pixel(t_mlx *new, int x, int y, t_color c)
{
	new->data[y * new->size + x * 4] = MIN(c.b * 255, (unsigned char)255);
	new->data[y * new->size + x * 4 + 1] = MIN(c.g * 255, (unsigned char)255);
	new->data[y * new->size + x * 4 + 2] = MIN(c.r * 255, (unsigned char)255);
}

t_color		get_obj_color(t_object *o_list)
{
	t_sphere	*sphere;
	t_cylinder	*cyl;
	t_cone		*cone;
	t_plane		*plane;

	if (o_list->type == 1)
	{
		sphere = (t_sphere *)o_list->object;
		return (sphere->color);
	}
	else if (o_list->type == 2)
	{
		cyl = (t_cylinder *)o_list->object;
		return (cyl->color);
	}
	else if (o_list->type == 3)
	{
		cone = (t_cone *)o_list->object;
		return (cone->color);
	}
	else
	{
		plane = (t_plane *)o_list->object;
		return (plane->color);
	}
}

static void	add_ambient(t_color *color, t_mlx *new)
{
	color->r *= new->amb.r;
	color->g *= new->amb.g;
	color->b *= new->amb.b;
}

static void	choose_scene(t_mlx *new, int x, int y, t_object *o_list)
{
	t_object	*closest;
	t_object	*objects;
	t_color		color;
	double		tt;

	objects = o_list;
	closest = NULL;
	while (objects)
	{
		intersection_object(new, objects, new->ray);
		if (new->intersection == 1)
			closest = objects;
		objects = objects->next;
	}
	if (closest)
	{
		color = get_obj_color(closest);
		add_ambient(&color, new);
		choose_color_obj(closest, new, &color);
		draw_pixel(new, x, y, color);
	}
	else
		draw_pixel(new, x, y, new->black);
}

void		ray_tracing(t_mlx *new)
{
	int		x;
	int		y;							
	double	sc;
	double	ar;

	sc = tan((FOV / 2) * (M_PI / 180));
	ar = (double)WIDTH / (double)HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			new->ray.dir.x = (2 * ((x + 0.5) / (double)WIDTH) - 1) * sc * ar;
			new->ray.dir.y = (1 - 2 * (y + 0.5) / (double)HEIGHT) * sc;
			new->ray.dir.z = -1;
			rotate(&new->ray.dir, 0, 0, 0);
			new->ray.dir = v_norm(new->ray.dir);
			choose_scene(new, x, y, new->o_list);
			new->t = 5000000;
			new->dist = 4999999;
			x++;
		}
		y++;
	}
}
