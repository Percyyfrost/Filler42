
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
	int	i;
	char	pno;
	char	eno;
	char	*line;
	int	map_r;
	int	map_c;
	int	piece_r;
	int	piece_c;
	int	piece_r_dup;
	int	len_r;
	int	start_len;
	int	w_start;
	int 	w_end;
	char	**map;
	char	**piece;
}		t_vars;

typedef struct	s_play
{
	int	y;
	int	x;
	int	y_tmp;
	int	x_tmp;
	int	flg;
	int	**moves;
	int	m;
}		t_play;

void            play(t_vars head);
void		droid(t_vars head, t_play ply);
void            qicsort(int *arr, int low, int high);

#endif
