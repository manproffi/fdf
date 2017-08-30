/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 19:57:59 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/12 19:58:01 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	turn_x(t_draw *all, double a)
{
	t_ind	*ptr;
	int		i;
	double	y;
	double	z;

	ptr = NULL;
	i = -1;
	all->corner[0] += a;
	while (++i < all->y_max)
	{
		ptr = all->mass[i];
		while (ptr)
		{
			y = ptr->y;
			z = ptr->z;
			ptr->y0 = (y * cos(ACU[0]) + z * sin(ACU[0])) * AMU + X_WIN / 2;
			ptr->z0 = (-y * sin(ACU[0]) + z * cos(ACU[0])) * AMU + Y_WIN / 2;
			ptr = ptr->next;
		}
	}
	ft_bzero(all->str, X_WIN * 4 * Y_WIN);
	str_calculation(all);
	all->a = mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

void	turn_y(t_draw *all, double a)
{
	t_ind	*ptr;
	int		i;
	double	x;
	double	z;

	ptr = NULL;
	i = -1;
	all->corner[1] += a;
	while (++i < all->y_max)
	{
		ptr = all->mass[i];
		while (ptr)
		{
			x = ptr->x;
			z = ptr->z;
			ptr->x0 = (x * cos(ACU[1]) + z * sin(ACU[1])) * AMU + X_WIN / 2;
			ptr->z0 = (-x * sin(ACU[1]) + z * cos(ACU[1])) * AMU + Y_WIN / 2;
			ptr = ptr->next;
		}
	}
	ft_bzero(all->str, X_WIN * 4 * Y_WIN);
	str_calculation(all);
	all->a = mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}

void	turn_z(t_draw *all, double a)
{
	t_ind	*ptr;
	int		i;
	double	x;
	double	y;

	ptr = NULL;
	i = -1;
	all->corner[2] += a;
	while (++i < all->y_max)
	{
		ptr = all->mass[i];
		while (ptr)
		{
			x = ptr->x;
			y = ptr->y;
			ptr->x0 = (x * cos(ACU[2]) - y * sin(ACU[2])) * AMU + X_WIN / 2;
			ptr->y0 = (x * sin(ACU[2]) + y * cos(ACU[2])) * AMU + Y_WIN / 2;
			ptr = ptr->next;
		}
	}
	ft_bzero(all->str, X_WIN * 4 * Y_WIN);
	str_calculation(all);
	all->a = mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
}
