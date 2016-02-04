/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:47:10 by jtranchi          #+#    #+#             */
/*   Updated: 2016/01/28 19:45:17 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		ft_check(char buffer, int i)
{
	if (buffer != '.' && buffer != '#' && buffer != '\n')
		ft_error();
	if ((i % 5 == 4 || i == 20) && buffer != '\n')
		ft_error();
	if (i % 5 != 4 && i != 20 && buffer != '.' && buffer != '#')
		ft_error();
}

t_piece		*ft_create_piece(char letter)
{
	int		i;
	t_piece	*piece;

	i = 0;
	piece = (t_piece*)malloc(sizeof(t_piece));
	piece->content = (char**)malloc(sizeof(char*) * 4);
	piece->x_size = 4;
	piece->y_size = 4;
	piece->letter = letter;
	piece->used = 0;
	while (i < 4)
		piece->content[i++] = (char*)malloc(sizeof(char) * 4);
	piece->next = NULL;
	return (piece);
}

t_piece		*ft_read(t_piece *lst, int fd)
{
	char	buffer;
	char	letter;
	int		i;
	t_piece *piece;

	i = -1;
	piece = NULL;
	letter = 'A';
	piece = ft_create_piece(letter++);
	lst = piece;
	while ((read(fd, &buffer, 1)))
	{
		ft_check(buffer, ++i);
		if (i == 20)
		{
			piece->next = ft_create_piece(letter++);
			piece = piece->next;
			i = -1;
		}
		else if (i % 5 != 4)
			piece->content[i / 5][i % 5] = buffer;
	}
	if (i != 19)
		ft_error();
	return (lst);
}

int			ft_check_cross(t_piece *piece, int y, int x)
{
	if (y > 0)
		if (piece->content[y - 1][x] == '#')
			return (1);
	if (y < piece->y_size)
		if (piece->content[y + 1][x] == '#')
			return (1);
	if (x > 0)
		if (piece->content[y][x - 1] == '#')
			return (1);
	if (x < piece->x_size)
		if (piece->content[y][x + 1] == '#')
			return (1);
	return (0);
}

void		ft_clean(t_piece *lst)
{
	int y;
	int x;
	int i;

	i = 0;
	while (lst)
	{
		ft_xclean(lst);
		ft_yclean(lst);
		ft_count(lst);
		ft_check_cross2(lst);
		y = -1;
		while (++y < lst->y_size)
		{
			x = -1;
			while (++x < lst->x_size)
				if (lst->content[y][x] == '#')
					if (ft_check_cross(lst, y, x) == 0)
						ft_error();
		}
		i++;
		lst = lst->next;
	}
	if (i > 26)
		ft_error();
}
