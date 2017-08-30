/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_head_st.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/18 21:39:09 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/18 21:39:11 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_HEAD_ST_H
# define FDF_HEAD_ST_H

typedef struct			s_ind
{
	char				*line;
	int					x_max;
	int					y_max;
	int					len;
	int					x;
	int					y;
	int					z;
	char				*line_color;
	double				multiplication;
	double				x0;
	double				y0;
	double				z0;
	unsigned char		color[4];
	struct s_ind		*next;
}						t_ind;

typedef struct			s_draw
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*str;
	int					a;
	int					bpp;
	int					sl;
	int					endian;
	double				corner[3];
	double				multiplication;
	double				mul_z;
	int					x_max;
	int					y_max;
	int					shift_x;
	int					shift_y;
	t_ind				**mass;
	struct s_ind		*next;
}						t_draw;

#endif
