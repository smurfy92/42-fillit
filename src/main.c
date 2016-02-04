/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:46:46 by jtranchi          #+#    #+#             */
/*   Updated: 2016/02/03 21:35:26 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void		ft_error(void)
{
	ft_putendl("error");
	exit(0);
}

void		ft_scale_map(t_map *map)
{
	int i;

	i = -1;
	while (++i < map->actualsize)
	{
		if (map->actualcontent[i][map->actualsize - 1] != '.')
			return ;
		if (map->actualcontent[map->actualsize - 1][i] != '.')
			return ;
	}
	map->actualsize--;
	if (map->actualsize == 0)
		return ;
	ft_scale_map(map);
}

void		ft_print_best_map(t_map *map)
{
	int y;
	int x;

	y = -1;
	while (++y < map->bestsize)
	{
		x = -1;
		while (++x < map->bestsize)
			ft_putchar(map->bestcontent[y][x]);
		ft_putchar('\n');
	}
}

void		ft_process(t_piece *lst)
{
	t_piece	*tmp;
	t_map	*map;

	map = NULL;
	tmp = lst;
	map = ft_init_map(map, lst);
	ft_clean_map(map);
	if (!lst->next)
	{
		ft_put_piece(map, lst, 0, 0);
		ft_save(map);
		ft_print_best_map(map);
	}
	ft_fillit(map);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_piece	*lst;

	fd = 0;
	lst = NULL;
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 1)
			ft_error();
		lst = ft_read(lst, fd);
		ft_clean(lst);
		ft_process(lst);
	}
	else
		ft_error();
	return (0);
}
