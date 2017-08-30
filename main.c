/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprotsen <sprotsen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 13:45:56 by sprotsen          #+#    #+#             */
/*   Updated: 2017/07/09 13:46:30 by sprotsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_head.h"

void	validation_ind(t_ind **mass_ind, int len_list)
{
	valid_len_line(mass_ind, len_list);
	valid_x_y_z_color(mass_ind, len_list);
	len_x_multiplication(mass_ind, len_list);
	shift_coordinate(mass_ind, len_list);
	drawing(mass_ind);
}

void	validation_map(t_list *lst, int len_list, int i, int j)
{
	t_ind	**mass_ind;
	char	**mass;
	t_list	*ptr;
	t_ind	*tmp;

	i = -1;
	ptr = lst;
	if (!(mass_ind = (t_ind**)malloc(sizeof(t_ind*) * len_list)))
		exit(write(2, "ERROR: memory is not allocated\n", 31));
	while (++i < len_list)
	{
		j = -1;
		mass = ft_strsplit(ptr->content, ' ');
		tmp = NULL;
		while (mass[++j])
			add_ind(&tmp, create_list_ind(mass[j], j));
		mass_ind[i] = tmp;
		ptr = ptr->next;
		ft_strdel_char_mass(mass);
	}
	if (!mass_ind[0])
		exit(write(2, "ERROR\n", 6));
	validation_ind(mass_ind, len_list);
	del_mass_ind(mass_ind, len_list);
}

void	del_list_list(t_list **list)
{
	if (*list)
	{
		del_list_list(&(*list)->next);
		ft_memdel(&(*list)->content);
		free(*list);
		*list = NULL;
	}
}

t_list	*read_from_file(char **argv)
{
	int		fd;
	int		k;
	char	*line;
	t_list	*list;

	list = NULL;
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		exit(write(2, "ERROR\n", 6));
	while ((k = get_next_line(fd, &line)) > 0)
	{
		ft_lstaddend(&list, ft_lstnew(line, ft_strlen(line) + 1));
		ft_strdel(&line);
	}
	if (k == -1)
	{
		write(2, "ERROR: incorrect input file\n", 28);
		ft_strdel(&line);
		del_list_list(&list);
	}
	ft_strdel(&line);
	return (list);
}

int		main(int argc, char **argv)
{
	t_list	*list;

	list = NULL;
	if (argc == 1)
		return (write(2, "Usage : ./fdf <filename>\n", 25));
	if (argc > 2)
		return (write(2, "ERROR: too many input parameter\n", 32));
	list = read_from_file(argv);
	if (!list)
		exit(write(2, "ERROR: empty file\n", 18));
	validation_map(list, ft_lstsize(list), 0, 0);
	del_list_list(&list);
	return (0);
}
