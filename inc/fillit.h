/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtranchi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 18:16:19 by jtranchi          #+#    #+#             */
/*   Updated: 2016/02/09 18:10:42 by jtranchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/includes/libft.h"
# include <fcntl.h>

typedef struct		s_piece
{
	char			**content;
	int				x_size;
	int				y_size;
	char			letter;
	int				used;
	struct s_piece	*next;
}					t_piece;

typedef struct		s_map
{
	char			**bestcontent;
	char			**actualcontent;
	t_piece			*lst;
	int				bestsize;
	int				actualsize;
}					t_map;

void				ft_check_cross2(t_piece *piece);
void				ft_error();
void				ft_print_best_map(t_map *map);
void				ft_check(char buffer, int i);
void				ft_clean(t_piece *lst);
void				ft_save(t_map *map);
void				ft_del_first_line(t_piece *piece);
void				ft_del_first_col(t_piece *piece);
void				ft_yclean(t_piece *piece);
void				ft_xclean(t_piece *piece);
void				ft_count(t_piece *piece);
int					ft_check_cross(t_piece *piece, int y, int x);
void				ft_process(t_piece *lst);
t_map				*ft_init_map(t_map *map, t_piece *lst);
int					ft_count_bestsize(t_piece *lst);
void				ft_clean_map(t_map *map);
void				ft_put_piece(t_map *map, t_piece *piece,
int ymap, int xmap);
void				ft_try_put_piece(t_map *map, t_piece *piece,
int y, int x);
void				ft_fillit(t_map *map);
int					ft_map_check_col(t_map *map, int line);
int					ft_map_check_line(t_map *map, int col);
void				ft_map_del_col(t_map *map, int line);
void				ft_map_del_line(t_map *map, int col);
void				ft_scale_map(t_map *map);
t_piece				*ft_create_piece(char letter);
t_piece				*ft_read(t_piece *lst, int fd);

#endif
