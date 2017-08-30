/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:32:06 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/18 20:35:13 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

int		expose_hook(void *st)
{
	t_draw	*all;

	all = (t_draw*)st;
	mlx_clear_window(all->mlx, all->win);
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	return (0);
}

int		end(void)
{
	exit(0);
	return (0);
}

void	calculation(t_draw *all)
{
	t_ind	*ptr;
	int		i;

	ptr = NULL;
	i = -1;
	while (++i < all->y_max)
	{
		ptr = all->mass[i];
		while (ptr)
		{
			ptr->x0 = (double)ptr->x * all->multiplication + X_WIN / 2;
			ptr->y0 = (double)ptr->y * all->multiplication + Y_WIN / 2;
			ptr->z0 = (double)ptr->z;
			ptr = ptr->next;
		}
	}
}

void	str_calculation(t_draw *all)
{
	t_ind	*ptr;
	int		i;

	ptr = NULL;
	i = -1;
	while (++i < all->y_max)
	{
		ptr = all->mass[i];
		while (ptr)
		{
			if (PX >= 0 && PX < X_WIN && ptr->y0 >= 0 && ptr->y0 < Y_WIN)
			{
				all->str[(int)ptr->y0 * X_WIN * 4 + (int)PX * 4 + 2] = PC[0];
				all->str[(int)ptr->y0 * X_WIN * 4 + (int)PX * 4 + 1] = PC[1];
				all->str[(int)ptr->y0 * X_WIN * 4 + (int)PX * 4 + 0] = PC[2];
			}
			ptr = ptr->next;
		}
	}
}

void	new_image(t_draw *all)
{
	all->shift_x = 0;
	all->shift_y = 0;
	all->corner[0] = 0;
	all->corner[1] = 0;
	all->corner[2] = 0;
	calculation(all);
	ft_bzero(all->str, X_WIN * 4 * Y_WIN);
	brezenhame(all);
	str_calculation(all);
	all->a = mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}
