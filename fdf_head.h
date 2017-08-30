/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 19:18:23 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/09 19:18:26 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEAD_H
# define FDF_HEAD_H

# include "libft/libft.h"
# include "ft_printf/printhead.h"
# include "fdf_head_st.h"

# include <mlx.h>
# include <math.h>
# include <fcntl.h>

# define TRUE 1
# define FALSE 0

# define X_WIN 1000
# define Y_WIN 1000

# define P1C ptr1->color
# define PC ptr->color
# define AMU all->multiplication
# define ACU all->corner
# define PX ptr->x0

t_ind	*create_list_ind(char *str, int i);
void	add_ind(t_ind **alst, t_ind *new);
int		size_ind(t_ind *begin_list);
void	del_mass_ind(t_ind **mass_ind, int len_list);
void	drawing(t_ind **mass_ind);
void	image(t_draw *all);
void	turn_x(t_draw *all, double a);
void	turn_y(t_draw *all, double a);
void	turn_z(t_draw *all, double a);
void	str_calculation(t_draw *all);
void	brezenhame(t_draw *all);
int		expose_hook(void *st);
int		end(void);
void	calculation(t_draw *all);
void	str_calculation(t_draw *all);
void	new_image(t_draw *all);
void	grad(t_ind *ptr1, t_ind *ptr2, int flag, double color[3]);
void	color_fun(int color[3], t_ind *ptr1, t_ind *ptr2);
void	put_color(int a[3], t_ind *ptr, t_draw *all, double col[3]);
void	shift_coordinate(t_ind **mass_ind, int len_list);
void	valid_int(char *str);
void	len_x_multiplication(t_ind **mass_ind, int len_list);
int		len_number(int a);
int		get_number(char c, t_ind *lst);
void	hex_to_dec(t_ind *lst);
void	color_add(char *str, t_ind *lst);
void	add_color(t_ind *lst);
void	valid_x_y_z_color(t_ind **mass_ind, int len_list);
void	valid_len_line(t_ind **mass_ind, int len_list);

#endif
