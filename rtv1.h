/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 19:10:46 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/15 19:10:48 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <math.h>
# define WIDTH 800
# define HEIGHT 600
# define FOV 90
# define MIN(a, b) (a < b) ? a : b;

typedef	struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef	struct	s_ray
{
	t_vector	start;
	t_vector	dir;
}				t_ray;

typedef	struct	s_color
{
	double		r;
	double		g;
	double		b;
}				t_color;

typedef	struct	s_plane
{
	t_vector	pos;
	t_vector	dir;
	t_color		color;
}				t_plane;

typedef	struct	s_sphere
{
	t_vector	center;
	double		radius;
	t_color		color;
}				t_sphere;

typedef	struct	s_cylinder
{
	t_vector	center;
	t_vector	dir;
	double		radius;
	t_color		color;
}				t_cylinder;

typedef	struct	s_cone
{
	t_vector	center;
	t_vector	dir;
	double		alpha;
	t_color		color;
}				t_cone;

typedef	struct	s_light
{
	t_vector		pos;
	t_color			color;
	double			p;
	struct s_light	*next;
}				t_light;

typedef	struct	s_object
{
	void			*object;
	int				type;
	t_vector		normal;
	struct s_object	*next;
}				t_object;

typedef	struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			size;
	int			scene;
	t_ray		ray;
	t_ray		light;
	int			intersection;
	double		t;
	double		dist;
	t_color		black;
	t_color		amb;
	t_object	*o_list;
	t_light		*l_list;
}				t_mlx;

double			v_mod(t_vector v);
double			v_dot(t_vector v1, t_vector v2);
t_vector		v_cross(t_vector v1, t_vector v2);
t_vector		v_sub(t_vector v1, t_vector v2);
t_vector		v_add(t_vector v1, t_vector v2);
t_vector		v_mult_c(t_vector v, double c);
t_vector		v_norm(t_vector v);
t_vector		check_normal(t_vector normal, t_ray light);
void			add_sphere(t_object **obj, t_vector p, double r, t_color col);
void			add_cylinder(t_object **obj, t_vector p, double r, t_vector d);
void			add_cone(t_object **obj, t_vector p, double alpha, t_vector d);
void			add_plane(t_object **obj, t_vector p, t_vector d, t_color col);
void			add_light(t_light **light, t_vector p, t_color col, double a);
void			init_scene(t_mlx *new);
void			ray_tracing(t_mlx *new);
void			intersection_object(t_mlx *new, t_object *o_list, t_ray ray);
void			intersection_sphere(t_object *o_list, t_ray ray, t_mlx *new);
void			intersection_cyl(t_object *o_list, t_ray ray, t_mlx *new);
void			intersection_cone(t_object *o_list, t_ray ray, t_mlx *new);
void			intersection_plane(t_object *o_list, t_ray ray, t_mlx *new);
void			calc_discriminant(double a, double b, double c, t_mlx *new);
t_color			get_obj_color(t_object *o_list);
void			choose_color_obj(t_object *closest, t_mlx *new, t_color *color);
void			find_normal(t_object *obj, t_vector inter_pos, t_mlx *new);
t_vector		get_obj_normal(t_object *obj);
void			draw_pixel(t_mlx *new, int x, int y, t_color color);
void			rotate(t_vector *v, double a, double b, double c);

#endif
