/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectormath2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 21:58:38 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/29 21:58:40 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	v_mult_c(t_vector v, double c)
{
	t_vector	new;

	new.x = v.x * c;
	new.y = v.y * c;
	new.z = v.z * c;
	return (new);
}

t_vector	v_norm(t_vector v)
{
	t_vector	norm;

	norm.x = v.x / v_mod(v);
	norm.y = v.y / v_mod(v);
	norm.z = v.z / v_mod(v);
	return (norm);
}

t_vector	check_normal(t_vector normal, t_ray light)
{
	double		cos;

	cos = v_dot(normal, light.dir);
	if (cos < 0)
		normal = v_mult_c(normal, -1);
	return (normal);
}
