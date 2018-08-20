
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuyaninxele <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:38:17 by vuyaninxe         #+#    #+#             */
/*   Updated: 2018/08/14 15:38:19 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

#ifndef FILLER_H
# define FILLEER_H

# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

typedef struct	s_vars
{
	int			i;
	char		pno;
	char		eno;
	char		*line;
	int			map_r;
	int			map_c;
	int			piece_r;
	int			piece_c;
	int			piece_r_dup;
	int			len_r;
	int			start_len;
	int			w_start;
	int			w_end;
	char		**map;
	char		**piece;
}				t_vars;

typedef struct	s_play
{
	int			y;
	int			x;
	int			y_tmp;
	int			x_tmp;
	int			flg;
	int			**moves;
	int			m;
	int			h;
	int			j;
	int			i;
	int			ok;
}				t_play;

typedef struct s_droid
{
	int			i;
	int			j;
	int			hlf;
	int			me;
	int			s;
	int			side;
	int			f;
}				t_droid;

void			play(t_vars head);
void			droid(t_vars head, t_play ply);
void			qicsort(int *arr, int low, int high);
void			width_start(t_vars *head);
void			width_end(t_vars *head);
void			init_droid(t_vars head, t_droid *dr);
void			en_pos(t_vars head, t_droid *dr);
int				side_check(t_vars head, int side);
int				area_check(t_vars head, int i, int j);

#endif
