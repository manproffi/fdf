/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brezenhame2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 20:57:44 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/18 21:00:47 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	grad(t_ind *ptr1, t_ind *ptr2, int flag, double color[3])
{
	double k;

	if (flag == 1)
		k = ptr2->x0 - ptr1->x0;
	else
		k = ptr2->y0 - ptr1->y0;
	k = fabs(k);
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	ptr2->color[0] - P1C[0] != 0 ? color[0] = (ptr2->color[0] - P1C[0]) / k : 0;
	ptr2->color[1] - P1C[1] != 0 ? color[1] = (ptr2->color[1] - P1C[1]) / k : 0;
	ptr2->color[2] - P1C[2] != 0 ? color[2] = (ptr2->color[2] - P1C[2]) / k : 0;
}

void	color_fun(int color[3], t_ind *ptr1, t_ind *ptr2)
{
	color[0] = (ptr2->color[0] - ptr1->color[0]) / (ptr2->y0 - ptr1->y0);
	color[1] = (ptr2->color[1] - ptr1->color[1]) / (ptr2->y0 - ptr1->y0);
	color[2] = (ptr2->color[2] - ptr1->color[2]) / (ptr2->y0 - ptr1->y0);
}

void	put_color(int a[3], t_ind *ptr, t_draw *all, double col[3])
{
	if (a[0] >= 0 && a[0] < X_WIN && a[1] >= 0 && a[1] < Y_WIN)
	{
		all->str[a[1] * X_WIN * 4 + a[0] * 4 + 2] = PC[0] + col[0] * a[2];
		all->str[a[1] * X_WIN * 4 + a[0] * 4 + 1] = PC[1] + col[1] * a[2];
		all->str[a[1] * X_WIN * 4 + a[0] * 4 + 0] = PC[2] + col[2] * a[2];
	}
}
