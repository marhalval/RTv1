/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 18:26:05 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/18 18:26:08 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		v_mod(t_vector v)
{
	double	mod;

	mod = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	return (mod);
}

double		v_dot(t_vector v1, t_vector v2)
{
	double	dot;

	dot = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	return (dot);
}

t_vector	v_cross(t_vector v1, t_vector v2)
{
	t_vector	cross;

	cross.x = v1.y * v2.z - v1.z * v2.y;
	cross.y = v1.z * v2.x - v1.x * v2.z;
	cross.z = v1.x * v2.y - v1.y * v2.x;
	return (cross);
}

t_vector	v_add(t_vector v1, t_vector v2)
{
	t_vector	add;

	add.x = v2.x + v1.x;
	add.y = v2.y + v1.y;
	add.z = v2.z + v1.z;
	return (add);
}

t_vector	v_sub(t_vector v2, t_vector v1)
{
	t_vector	sub;

	sub.x = v2.x - v1.x;
	sub.y = v2.y - v1.y;
	sub.z = v2.z - v1.z;
	return (sub);
}
