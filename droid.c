/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 07:02:28 by vnxele            #+#    #+#             */
/*   Updated: 2018/08/20 15:22:42 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			distance(int x, int x2, int y, int y2)
{
	int		r;

	r = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	return (r);
}

int			side_check(t_vars head, int side)
{
	int		i;

	i = 0;
	while (i < head.map_r)
		if (head.map[i++][side] == head.pno)
			return (1);
	return (0);
}

int			area_check(t_vars head, int i, int j)
{
	int		y;
	int		x;
	int		tick;

	y = (i == 0) ? 0 : i - 1;
	tick = 0;
	while (y <= i + 1 && y < head.map_r)
	{
		x = (j == 0) ? 0 : j - 1;
		while (x <= j + 1 && x < head.map_r)
		{
			if (head.map[y][x] == '.')
				tick++;
			x++;
		}
		y++;
	}
	if (tick > 1)
		return (1);
	return (0);
}

void		droid(t_vars head, t_play ply)
{
	t_droid	dr;
	int		arr[ply.m];
	int		arr2[ply.m];

	init_droid(head, &dr);
	en_pos(head, &dr);
	while (dr.s < ply.m)
	{
		arr[dr.s] = distance(dr.i, ply.moves[dr.s][0],
							dr.j, ply.moves[dr.s][1]);
		arr2[dr.s] = distance(dr.i, ply.moves[dr.s][0],
							dr.j, ply.moves[dr.s][1]);
		dr.s++;
	}
	qicsort(arr, 0, dr.s - 1);
	dr.s = -1;
	while (arr2[dr.s++])
		if (arr2[dr.s] == arr[0])
			break ;
	ft_putnbr(ply.moves[dr.s][0]);
	write(1, " ", 1);
	ft_putnbr(ply.moves[dr.s][1]);
	write(1, "\n", 1);
}
