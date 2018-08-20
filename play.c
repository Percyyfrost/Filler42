/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuyaninxele <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 07:16:22 by vuyaninxe         #+#    #+#             */
/*   Updated: 2018/08/19 07:05:32 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		anlys_piece(t_vars *head)
{
	int i;
	int j;
	int flag;

	flag = 0;
	head->len_r = head->piece_r;
	head->start_len = 0;
	while (head->piece[head->start_len + 1])
		if (!ft_strchr(head->piece[head->start_len], '*'))
			head->start_len += 1;
		else if (!ft_strchr(head->piece[head->len_r - 1], '*'))
			head->len_r -= 1;
		else
			break ;
	j = -1;
	head->w_start = 0;
	while (head->w_start < head->piece_c)
	{
		i = head->start_len;
		while (i < head->len_r)
		{
			if (head->piece[i][head->w_start] == '*')
				flag = 1;
			i++;
		}
		if (flag)
			break ;
		head->w_start++;
	}
	flag = 0;
	i = head->piece_c - 1;
	head->w_end = head->piece_c;
	while (head->w_end != -1)
	{
		j = head->len_r -1;
		if (head->piece[j][head->w_end] == '*')
			break ;
		while (j != -1)
		{
			if (head->piece[j][head->w_end] == '*')
				flag = 1;
			j--;
		}
		if (flag)
			break ;
		head->w_end--;
	}
}

void		match(t_vars head, t_play *ply)
{
	int	i;
	int	j;
	int	ok;

	ok = 0;
	i = head.start_len;
	ply->x_tmp = ply->x;
	while (i < head.len_r && ply->x_tmp < head.map_r && !ok)
	{
		j = head.w_start;
		ply->y_tmp = ply->y;
		if (head.map[ply->x_tmp][ply->y_tmp] == head.eno)
			ok = 1;
		while (j <= head.w_end && ply->y_tmp < head.map_c && !ok)
		{
			if (head.map[ply->x_tmp][ply->y_tmp] == head.eno)
				ok = 1;
			if (head.map[ply->x_tmp][ply->y_tmp] == head.pno && head.piece[i][j] == '*'){
				ply->flg++;
			}
			j++;
			ply->y_tmp++;
		}
		ply->flg = (j > head.w_end) ? ply->flg : 0;
		i++;
		ply->x_tmp++;
	}
	if (ply->flg == 1 && !ok && i == head.len_r)
	{
		ply->moves[ply->m] = (int*)malloc(sizeof(int) * 2);
		ply->moves[ply->m][0] = ply->x - head.start_len;
		ply->moves[ply->m][1] = ply->y - head.w_start;
		ply->m++;
	}
	if (ply->flg)
		ply->flg = 0;
}

void		play(t_vars head)
{
	t_play ply;
	
	anlys_piece(&head);
	ply.x = 0;
	ply.m = 0;
	ply.flg = 0;
	ply.moves = (int**)malloc(sizeof(int*) * 150);
	while (ply.x < head.map_r)
	{
		ply.y = 0;
		while (ply.y < head.map_c)
		{
			if (head.map[ply.x][ply.y] != head.eno)
				match(head, &ply);
			ply.y++;
		}
		ply.x++;
	}
	if (ply.m)
		droid(head, ply);
	else
		ft_putendl("0 0");
	int h = 0;
	while (h < ply.m && ply.moves[h])
		free(ply.moves[h++]);
	if (ply.moves)
		free(ply.moves);
}
