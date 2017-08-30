/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 21:08:05 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/18 21:08:07 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	hex_to_dec(t_ind *lst)
{
	int				i;
	int				j;
	unsigned char	res;
	char			*str;

	i = 0;
	j = -1;
	str = lst->line_color;
	while (str[i])
	{
		res = get_number(str[i], lst) * 16 + get_number(str[i + 1], lst);
		lst->color[++j] = res;
		i += 2;
	}
}

void	color_add(char *str, t_ind *lst)
{
	int len;

	len = ft_strlen(str);
	if (len > 6)
	{
		write(2, "ERROR in line:\n", 15);
		exit(ft_printf("%s\n", lst->line));
	}
	if (len == 2)
		lst->line_color = ft_strjoin("0000", str);
	else if (len == 4)
		lst->line_color = ft_strjoin("00", str);
	else if (len == 6)
		lst->line_color = ft_strdup(str);
	else
	{
		write(2, "ERROR in line:\n", 15);
		exit(ft_printf("%s\n", lst->line));
	}
	hex_to_dec(lst);
}

void	add_color(t_ind *lst)
{
	int		i;
	char	*str;

	i = 0;
	str = lst->line;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == 0)
	{
		lst->line_color = ft_strdup("FFFFFF");
		lst->color[0] = 255;
		lst->color[1] = 255;
		lst->color[2] = 255;
	}
	else if (str[i] == 44 && str[i + 1] == 48 && str[i + 2] == 120)
		color_add(str + i + 3, lst);
	else
	{
		write(2, "ERROR in line:\n", 15);
		exit(ft_printf("%s\n", str));
	}
}

void	valid_x_y_z_color(t_ind **mass_ind, int len_list)
{
	int			i;
	int			x;
	long long	a;
	t_ind		*ptr;

	i = -1;
	ptr = NULL;
	while (++i < len_list)
	{
		ptr = mass_ind[i];
		x = -1;
		while (ptr != NULL)
		{
			ptr->y = i;
			x++;
			ptr->x = x;
			valid_int(ptr->line);
			a = ft_atoi_ulli(ptr->line);
			if (a > 2147483647 || a < -2147483648)
				exit(write(2, "ERROR: number is not integer\n", 29));
			ptr->z = (int)a;
			add_color(ptr);
			ptr = ptr->next;
		}
	}
}

void	valid_len_line(t_ind **mass_ind, int len_list)
{
	int		len_mass[len_list];
	int		i;
	t_ind	*ptr;

	i = -1;
	while (++i < len_list)
	{
		ptr = mass_ind[i];
		len_mass[i] = size_ind(ptr);
	}
	i = 0;
	while (++i < len_list)
	{
		if (len_mass[i] != len_mass[i - 1])
		{
			exit(write(2, "ERROR: length lines is not equal\n", 33));
		}
	}
}
