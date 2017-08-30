/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 21:05:20 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/18 21:05:22 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	shift_coordinate(t_ind **mass_ind, int len_list)
{
	int		i;
	int		x_aver;
	int		y_aver;
	double	mul;
	t_ind	*ptr;

	ptr = mass_ind[0];
	x_aver = ptr->x_max / 2;
	y_aver = ptr->y_max / 2;
	mul = ptr->multiplication;
	ptr = NULL;
	i = -1;
	while (++i < len_list)
	{
		ptr = mass_ind[i];
		while (ptr)
		{
			ptr->x -= x_aver;
			ptr->y -= y_aver;
			ptr->x0 = mul * ptr->x + X_WIN / 2;
			ptr->y0 = mul * ptr->y + Y_WIN / 2;
			ptr = ptr->next;
		}
	}
}

void	valid_int(char *str)
{
	int		len;
	int		i;

	i = -1;
	len = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (ft_isdigit(str[++i]))
		len++;
	if (len > 11)
		exit(write(2, "ERROR: incorrect int\n", 21));
}

void	len_x_multiplication(t_ind **mass_ind, int len_list)
{
	t_ind	*lst;
	int		len;

	lst = mass_ind[0];
	len = 0;
	while (lst)
	{
		len++;
		lst = lst->next;
	}
	lst = mass_ind[0];
	lst->x_max = len;
	lst->y_max = len_list;
	if (lst->x_max >= lst->y_max)
		lst->multiplication = ((double)X_WIN - 300) / lst->x_max;
	else
		lst->multiplication = ((double)Y_WIN - 300) / lst->y_max;
}

int		len_number(int a)
{
	int		result;

	result = 0;
	if (a < 0)
		result++;
	if (a > -10 && a < 10)
		return (1);
	while (a != 0)
	{
		result++;
		a = a / 10;
	}
	return (result);
}

int		get_number(char c, t_ind *lst)
{
	if (c >= 48 && c < 58)
		return (c - 48);
	else if (c >= 65 && c <= 70)
		return (c - 65 + 10);
	else if (c >= 97 && c <= 102)
		return (c - 97 + 10);
	else
	{
		write(2, "ERROR in line:\n", 15);
		ft_printf("%s\n", lst->line);
		exit(ft_printf("line y = %d column x = %d\n", lst->y + 1, lst->x + 1));
	}
}
