/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hvashchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/15 21:31:55 by hvashchu          #+#    #+#             */
/*   Updated: 2017/10/15 21:31:58 by hvashchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	exit_mouse(void)
{
	exit(0);
}

static int	key_hook(int keycode, t_mlx *new)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int			main(int argc, char **argv)
{
	t_mlx	*new;
	int		tmp;

	if (argc != 2 || (ft_atoi(argv[1]) < 1 || ft_atoi(argv[1]) > 4))
	{
		ft_putendl("Usage: ./RTv1 [number of scene]");
		ft_putendl("choose scene: 1, 2, 3, 4");
		exit(0);
	}
	new = ft_memalloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, WIDTH, HEIGHT, "RTv1");
	new->img = mlx_new_image(new->mlx, WIDTH, HEIGHT);
	new->data = mlx_get_data_addr(new->img, &tmp, &new->size, &tmp);
	new->scene = ft_atoi(argv[1]);
	init_scene(new);
	ray_tracing(new);
	mlx_put_image_to_window(new->mlx, new->win, new->img, 0, 0);
	mlx_hook(new->win, 17, 1L << 17, exit_mouse, new);
	mlx_hook(new->win, 2, 5, key_hook, new);
	mlx_loop(new->mlx);
	return (0);
}
