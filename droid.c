/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   droid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 07:02:28 by vnxele            #+#    #+#             */
/*   Updated: 2018/08/19 22:35:48 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int                     distance(int x, int x2, int y, int y2)
{
	int             r;

	r = sqrt((x2 - x) * (x2 - x) + (y2 - y) * (y2 - y));
	return (r);
}

int		side_check(t_vars head, int side)
{
	int i;

	i = 0;
	while (i < head.map_r)
		if (head.map[i++][side] == head.pno)
			return (1);
	return (0);
}

int		area_check(t_vars head, int i, int j)
{
	int y;
	int x;
	int tick;

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
	int i;
	int j;
	int hlf;
	int me;
	int s;
	int	arr[ply.m];
	int	arr2[ply.m];
	int	side;

	me = 0;
	i = 0;
	hlf = head.map_r / 2;
	s = 0;
	side = 0;
	while (me < head.map_r)
	{
		if (ft_strchr(head.map[me], head.pno))
			break ;
		me++;
	}
	if (me > hlf)
		i = head.map_r - 1;
	if (ft_strchr(head.map[0], head.pno))
	{
		i = head.map_r - 1;
		me = hlf + 1;
	}
	int f = 0;
	while (i > -1 && i < head.map_r && !f)
	{
		j = 0;
		while (j < head.map_c && !f)
		{
			if (head.map[i][j] == head.eno && area_check(head, i, j))
				f = 1;
			j++;
		}
		(me < hlf) ? i++ : i--;
	}
	if (me > hlf && !ft_strchr(head.map[head.map_r/2], head.pno))
	{
		i = 0;
		j = 0;
	}
	if (me > hlf && !side_check(head, 0))
	{
		i = head.map_r - 7;
		j = 0;
	}

	while(s < ply.m)
	{
		arr[s] = distance(i, ply.moves[s][0], j, ply.moves[s][1]);
		arr2[s] = distance(i, ply.moves[s][0], j, ply.moves[s][1]);
		s++;
	}
	qicsort(arr, 0, s -1);
	s = 0;
	while (arr2[s])
	{
		if(arr2[s] == arr[0])
			break ;
		s++;
	}
	ft_putnbr(ply.moves[s][0]);
	write(1, " ", 1);
	ft_putnbr(ply.moves[s][1]);
	write(1, "\n", 1);
}
