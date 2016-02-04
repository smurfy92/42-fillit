/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:46:17 by jtranchi          #+#    #+#             */
/*   Updated: 2015/12/15 17:46:19 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		ft_put_piece(t_map *map, t_piece *piece, int ymap, int xmap)
{
	int		y;
	int		x;

	y = -1;
	while (++y < piece->y_size)
	{
		x = -1;
		while (++x < piece->x_size)
			if (piece->content[y][x] != '.')
				map->actualcontent[ymap + y][xmap + x] = piece->letter;
	}
	piece->used = 1;
	if (piece->x_size + xmap > map->actualsize)
		map->actualsize = piece->x_size + xmap;
	if (piece->y_size + ymap > map->actualsize)
		map->actualsize = piece->y_size + ymap;
}

void		ft_clear_piece(t_map *map, t_piece *piece, int ymap, int xmap)
{
	int		y;
	int		x;

	y = -1;
	while (++y < piece->y_size)
	{
		x = -1;
		while (++x < piece->x_size)
			if (piece->content[y][x] != '.')
				map->actualcontent[ymap + y][xmap + x] = '.';
	}
	y = -1;
	piece->used = 0;
	ft_scale_map(map);
}

void		ft_save(t_map *map)
{
	int		y;
	int		x;

	y = -1;
	while (++y < map->actualsize)
	{
		x = -1;
		while (++x < map->actualsize)
			map->bestcontent[y][x] = map->actualcontent[y][x];
	}
	map->bestsize = map->actualsize;
}

void		ft_try_put_piece(t_map *map, t_piece *piece, int y, int x)
{
	int		ytmp;
	int		xtmp;

	ytmp = -1;
	if (piece->y_size + y < map->bestsize && piece->x_size + x < map->bestsize)
	{
		while (++ytmp < piece->y_size)
		{
			xtmp = -1;
			while (++xtmp < piece->x_size)
				if (map->actualcontent[y + ytmp][x + xtmp] != '.' &&
				piece->content[ytmp][xtmp] != '.')
					return ;
		}
		ft_put_piece(map, piece, y, x);
		ft_fillit(map);
		ft_clear_piece(map, piece, y, x);
	}
}

void		ft_fillit(t_map *map)
{
	int		y;
	int		x;
	t_piece	*tmp;

	tmp = map->lst;
	while (tmp->used == 1 && tmp->next)
		tmp = tmp->next;
	if (tmp->used == 1 && tmp->next == NULL)
	{
		if (map->actualsize < map->bestsize)
			ft_save(map);
		return ;
	}
	y = -1;
	while (++y < map->bestsize)
	{
		x = -1;
		while (++x < map->bestsize)
			ft_try_put_piece(map, tmp, y, x);
	}
	if (tmp->letter == 'A')
		ft_print_best_map(map);
}
