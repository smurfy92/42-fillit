/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:46:05 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/15 17:46:10 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		ft_del_first_line(t_piece *piece)
{
	int y;
	int x;

	y = 0;
	while (++y < piece->y_size)
	{
		x = -1;
		while (++x < piece->x_size)
			piece->content[y - 1][x] = piece->content[y][x];
	}
	piece->y_size--;
}

void		ft_del_first_col(t_piece *piece)
{
	int y;
	int x;

	x = 0;
	while (++x < piece->x_size)
	{
		y = -1;
		while (++y < piece->y_size)
			piece->content[y][x - 1] = piece->content[y][x];
	}
	piece->x_size--;
}

void		ft_yclean(t_piece *piece)
{
	int x;
	int y;
	int test;

	y = -1;
	while (++y < piece->y_size)
	{
		x = -1;
		test = 1;
		while (++x < piece->x_size)
			if (piece->content[y][x] == '#')
				test = 0;
		if (test)
		{
			if (y == 0)
			{
				ft_del_first_line(piece);
				y = -1;
			}
			else
				piece->y_size = y;
		}
	}
}

void		ft_xclean(t_piece *piece)
{
	int x;
	int y;
	int test;

	x = -1;
	while (++x < piece->x_size)
	{
		y = -1;
		test = 1;
		while (++y < piece->y_size)
			if (piece->content[y][x] == '#')
				test = 0;
		if (test)
		{
			if (x == 0)
			{
				ft_del_first_col(piece);
				x = -1;
			}
			else
				piece->x_size = x;
		}
	}
}

void		ft_count(t_piece *piece)
{
	int x;
	int y;
	int count;

	count = 0;
	y = -1;
	while (++y < piece->y_size)
	{
		x = -1;
		while (++x < piece->x_size)
			if (piece->content[y][x] == '#')
				count++;
	}
	if (count != 4)
		ft_error();
}
