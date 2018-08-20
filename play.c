/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuyaninxele <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 07:16:22 by vuyaninxe         #+#    #+#             */
/*   Updated: 2018/08/20 12:59:48 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		anlys_piece(t_vars *head)
{
	head->len_r = head->piece_r;
	head->start_len = 0;
	while (head->piece[head->start_len + 1])
		if (!ft_strchr(head->piece[head->start_len], '*'))
			head->start_len += 1;
		else if (!ft_strchr(head->piece[head->len_r - 1], '*'))
			head->len_r -= 1;
		else
			break ;
	width_start(head);
	width_end(head);
}

void		add_moves(t_vars head, t_play *ply)
{
	if (ply->flg == 1 && !ply->ok && ply->i == head.len_r)
	{
		ply->moves[ply->m] = (int*)malloc(sizeof(int) * 2);
		ply->moves[ply->m][0] = ply->x - head.start_len;
		ply->moves[ply->m][1] = ply->y - head.w_start;
		ply->m++;
	}
	if (ply->flg)
		ply->flg = 0;
}

void		match(t_vars head, t_play *ply)
{
	ply->ok = 0;
	ply->i = head.start_len;
	ply->x_tmp = ply->x;
	while (ply->i < head.len_r && ply->x_tmp < head.map_r && !ply->ok)
	{
		ply->j = head.w_start;
		ply->y_tmp = ply->y;
		if (head.map[ply->x_tmp][ply->y_tmp] == head.eno)
			ply->ok = 1;
		while (ply->j <= head.w_end && ply->y_tmp < head.map_c && !ply->ok)
		{
			if (head.map[ply->x_tmp][ply->y_tmp] == head.eno)
				ply->ok = 1;
			if (head.map[ply->x_tmp][ply->y_tmp] == head.pno
					&& head.piece[ply->i][ply->j] == '*')
				ply->flg++;
			ply->j++;
			ply->y_tmp++;
		}
		ply->flg = (ply->j > head.w_end) ? ply->flg : 0;
		ply->i++;
		ply->x_tmp++;
	}
	add_moves(head, ply);
}

void		init_ply(t_play *ply)
{
	ply->h = 0;
	ply->x = 0;
	ply->m = 0;
	ply->flg = 0;
	ply->moves = (int**)malloc(sizeof(int*) * 150);
}

void		play(t_vars head)
{
	t_play	ply;

	anlys_piece(&head);
	init_ply(&ply);
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
	while (ply.h < ply.m && ply.moves[ply.h])
		free(ply.moves[ply.h++]);
	if (ply.moves)
		free(ply.moves);
}
