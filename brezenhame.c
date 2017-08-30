/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenhame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 21:04:02 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/13 21:04:05 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	part2(int ds[4], t_draw *all, t_ind *ptr1, t_ind *ptr2)
{
	int			d[3];
	int			a[3];
	double		color[3];

	d[0] = (ds[0] << 1) - ds[1];
	d[1] = ds[0] << 1;
	d[2] = (ds[0] - ds[1]) << 1;
	a[1] = ptr1->y0 + ds[3];
	a[0] = ptr1->x0;
	a[2] = 1;
	grad(ptr1, ptr2, 2, color);
	while (a[2] <= ds[1])
	{
		if (d[0] > 0)
		{
			d[0] += d[2];
			a[0] += ds[2];
		}
		else
			d[0] += d[1];
		put_color(a, ptr1, all, color);
		a[2] += 1;
		a[1] += ds[3];
	}
}

/*
** int a[3] x, y, i
*/

void	part1(int ds[4], t_draw *all, t_ind *ptr1, t_ind *ptr2)
{
	int			d[3];
	int			a[3];
	double		color[3];

	d[0] = (ds[1] << 1) - ds[0];
	d[1] = ds[1] << 1;
	d[2] = (ds[1] - ds[0]) << 1;
	a[0] = ptr1->x0 + ds[2];
	a[1] = ptr1->y0;
	a[2] = 1;
	grad(ptr1, ptr2, 1, color);
	while (a[2] <= ds[0])
	{
		if (d[0] > 0)
		{
			d[0] += d[2];
			a[1] += ds[3];
		}
		else
			d[0] += d[1];
		put_color(a, ptr1, all, color);
		a[2] += 1;
		a[0] += ds[2];
	}
}

/*
** int		ds[4]; dx dy sx sy
*/

void	create_line(t_ind *ptr1, t_ind *ptr2, t_draw *all)
{
	int		ds[4];

	ds[0] = fabs(ptr2->x0 - ptr1->x0);
	ds[1] = fabs(ptr2->y0 - ptr1->y0);
	ds[2] = (ptr2->x0 >= ptr1->x0) ? 1 : -1;
	ds[3] = (ptr2->y0 >= ptr1->y0) ? 1 : -1;
	if (ds[1] <= ds[0])
		part1(ds, all, ptr1, ptr2);
	else
		part2(ds, all, ptr1, ptr2);
}

void	brezenhame(t_draw *all)
{
	int		i;
	t_ind	*ptr1;
	t_ind	*ptr2;

	i = -1;
	ptr2 = NULL;
	while (++i < all->y_max - 1)
	{
		ptr1 = all->mass[i];
		ptr2 = all->mass[i + 1];
		while (ptr1->next)
		{
			create_line(ptr1, ptr1->next, all);
			create_line(ptr1, ptr2, all);
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		create_line(ptr1, ptr2, all);
	}
	ptr1 = all->mass[i];
	while (ptr1->next)
	{
		create_line(ptr1, ptr1->next, all);
		ptr1 = ptr1->next;
	}
}
