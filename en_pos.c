/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 14:14:25 by vnxele            #+#    #+#             */
/*   Updated: 2018/08/20 15:06:27 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_droid(t_vars head, t_droid *dr)
{
	dr->me = 0;
	dr->i = 0;
	dr->hlf = head.map_r / 2;
	dr->s = 0;
	dr->side = 0;
	dr->f = 0;
}

void	en_pos_set(t_vars head, t_droid *dr)
{
	if (dr->me > dr->hlf && !ft_strchr(head.map[head.map_r / 2], head.pno))
	{
		dr->i = 0;
		dr->j = 0;
	}
	if (dr->me > dr->hlf && !side_check(head, 0))
	{
		dr->i = head.map_r - 7;
		dr->j = 0;
	}
}

void	en_pos(t_vars head, t_droid *dr)
{
	while (dr->me < head.map_r)
	{
		if (ft_strchr(head.map[dr->me], head.pno))
			break ;
		dr->me++;
	}
	if (dr->me > dr->hlf)
		dr->i = head.map_r - 1;
	if (ft_strchr(head.map[0], head.pno))
	{
		dr->i = head.map_r - 1;
		dr->me = dr->hlf + 1;
	}
	while (dr->i > -1 && dr->i < head.map_r && !dr->f)
	{
		dr->j = -1;
		while (dr->j++ < head.map_c && !dr->f)
		{
			if (head.map[dr->i][dr->j] == head.eno
					&& area_check(head, dr->i, dr->j))
				dr->f = 1;
		}
		(dr->me < dr->hlf) ? dr->i++ : dr->i--;
	}
	en_pos_set(head, dr);
}
