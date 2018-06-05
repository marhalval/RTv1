/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:14:54 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/27 18:14:56 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rotation_x(t_vector *v, double a)
{
	t_vector	tmp;
	double		alpha;

	alpha = a * M_PI / 180;
	tmp = *v;
	v->y = tmp.y * cos(alpha) - tmp.z * sin(alpha);
	v->z = tmp.y * sin(alpha) + tmp.z * cos(alpha);
}

static void	rotation_y(t_vector *v, double b)
{
	t_vector	tmp;
	double		alpha;

	alpha = b * M_PI / 180;
	tmp = *v;
	v->x = tmp.x * cos(alpha) + tmp.z * sin(alpha);
	v->z = -tmp.x * sin(alpha) + tmp.z * cos(alpha);
}

static void	rotation_z(t_vector *v, double c)
{
	t_vector	tmp;
	double		alpha;

	alpha = c * M_PI / 180;
	tmp = *v;
	v->x = tmp.x * cos(alpha) - tmp.y * sin(alpha);
	v->y = tmp.x * sin(alpha) + tmp.y * cos(alpha);
}

void		rotate(t_vector *v, double a, double b, double c)
{
	rotation_x(v, a);
	rotation_y(v, b);
	rotation_z(v, c);
}

void		calc_discriminant(double a, double b, double c, t_mlx *new)
{
	double		discriminant;
	double		tt[2];

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
	{
		new->intersection = 0;
		return ;
	}
	else
	{
		tt[0] = (-b + sqrt(discriminant)) / (2 * a);
		tt[1] = (-b - sqrt(discriminant)) / (2 * a);
		new->intersection = 1;
		if (tt[0] > 0.001 && tt[0] < new->t)
			new->t = tt[0];
		if (tt[1] > 0.001 && tt[1] < new->t)
			new->t = tt[1] - 0.1;
		else
			new->intersection = 0;
		if (new->t > new->dist)
			new->intersection = 0;
	}
}
