/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/10 20:06:49 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/10 20:06:50 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	part_qweqweqwe(t_ind *ptr, t_draw *all)
{
	double	temporary;

	ptr->x0 = ((double)ptr->x * all->multiplication);
	ptr->y0 = ((double)ptr->y * all->multiplication);
	ptr->z0 = (double)ptr->z * all->mul_z;
	temporary = ptr->y0;
	ptr->y0 = (temporary * cos(ACU[0]) + ptr->z0 * sin(all->corner[0]));
	ptr->z0 = (-temporary * sin(ACU[0]) + ptr->z0 * cos(all->corner[0]));
	temporary = ptr->x0;
	ptr->x0 = (temporary * cos(ACU[1]) + ptr->z0 * sin(all->corner[1]));
	ptr->z0 = (-temporary * sin(ACU[1]) + ptr->z0 * cos(all->corner[1]));
	temporary = ptr->x0;
	ptr->x0 = (temporary * cos(ACU[2]) - ptr->y0 * sin(all->corner[2]));
	ptr->y0 = (temporary * sin(ACU[2]) + ptr->y0 * cos(all->corner[2]));
	ptr->x0 += all->shift_x + X_WIN / 2;
	ptr->y0 += all->shift_y + Y_WIN / 2;
}

void	qweqweqwe(t_draw *all)
{
	int		i;
	t_ind	*ptr;

	i = -1;
	ptr = NULL;
	while (++i < all->y_max)
	{
		ptr = all->mass[i];
		while (ptr)
		{
			part_qweqweqwe(ptr, all);
			ptr = ptr->next;
		}
	}
	ft_bzero(all->str, X_WIN * 4 * Y_WIN);
	brezenhame(all);
	str_calculation(all);
	all->a = mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

int		next_key_function(int key, t_draw *all)
{
	if (key == 78)
	{
		all->multiplication -= 0.3;
		if (all->multiplication < 1)
			all->multiplication = 1;
	}
	if (key == 15)
	{
		all->mul_z -= 0.1;
		if (all->mul_z < 1)
			all->mul_z = 1;
	}
	if (key == 17)
	{
		all->mul_z += 0.1;
	}
	qweqweqwe(all);
	return (0);
}

int		key_function(int key, void *st)
{
	t_draw *all;

	all = (t_draw*)st;
	if (key == 53)
	{
		mlx_destroy_window(all->mlx, all->win);
		exit(0);
	}
	key == 35 ? new_image(all) : 0;
	key == 123 ? all->shift_x -= 3 : 0;
	key == 124 ? all->shift_x += 3 : 0;
	key == 125 ? all->shift_y += 3 : 0;
	key == 126 ? all->shift_y -= 3 : 0;
	key == 12 ? all->corner[0] += 0.16 : 0;
	key == 13 ? all->corner[0] -= 0.16 : 0;
	key == 0 ? all->corner[1] += 0.16 : 0;
	key == 1 ? all->corner[1] -= 0.16 : 0;
	key == 6 ? all->corner[2] += 0.16 : 0;
	key == 7 ? all->corner[2] -= 0.16 : 0;
	if (key == 69)
		all->multiplication += 0.3;
	return (next_key_function(key, all));
}

void	drawing(t_ind **mass_ind)
{
	t_draw	all;
	t_ind	*ptr;

	all.mlx = mlx_init();
	all.win = mlx_new_window(all.mlx, 1000, 1000, "FDF");
	all.mass = mass_ind;
	ptr = all.mass[0];
	all.x_max = ptr->x_max;
	all.y_max = ptr->y_max;
	all.multiplication = ptr->multiplication;
	all.shift_x = 0;
	all.shift_y = 0;
	all.img = mlx_new_image(all.mlx, X_WIN, Y_WIN);
	all.str = mlx_get_data_addr(all.img, &(all).bpp, &(all).sl, &(all).endian);
	all.corner[0] = 0;
	all.corner[1] = 0;
	all.corner[2] = 0;
	all.mul_z = 1;
	new_image(&all);
	mlx_hook(all.win, 2, 5, key_function, &all);
	mlx_hook(all.win, 17, 1L << 17, end, NULL);
	mlx_expose_hook(all.win, expose_hook, &all);
	mlx_loop(all.mlx);
}
