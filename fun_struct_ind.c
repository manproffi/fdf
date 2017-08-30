/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun_struct_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 20:08:45 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/09 20:08:47 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	add_ind(t_ind **alst, t_ind *new)
{
	t_ind	*list;

	if (*alst == NULL)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

t_ind	*create_list_ind(char *str, int i)
{
	t_ind	*list;

	list = (t_ind*)malloc(sizeof(t_ind));
	if (!list)
		return (NULL);
	list->line = ft_strdup(str);
	list->len = i;
	list->x_max = 0;
	list->y_max = 0;
	list->x = 0;
	list->y = 0;
	list->z = 0;
	list->line_color = NULL;
	list->multiplication = 0;
	list->x0 = 0;
	list->y0 = 0;
	list->z0 = 0;
	list->next = NULL;
	return (list);
}

int		size_ind(t_ind *begin_list)
{
	int		count;
	t_ind	*list;

	count = 0;
	list = begin_list;
	if (list)
	{
		while (list)
		{
			count++;
			list = list->next;
		}
		return (count);
	}
	else
		return (0);
}

void	del_list_ind_part(t_ind **list)
{
	if (*list)
	{
		del_list_ind_part(&(*list)->next);
		ft_strdel(&(*list)->line);
		ft_strdel(&(*list)->line_color);
		free(*list);
	}
}

void	del_mass_ind(t_ind **mass_ind, int len_list)
{
	int		i;
	t_ind	*ptr;

	i = -1;
	while (++i < len_list)
	{
		ptr = mass_ind[i];
		del_list_ind_part(&ptr);
	}
	free(mass_ind);
	mass_ind = NULL;
}
