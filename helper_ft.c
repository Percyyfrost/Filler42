/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_ft.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:26:06 by vnxele            #+#    #+#             */
/*   Updated: 2018/08/20 12:34:04 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		width_start(t_vars *head)
{
	int		i;
	int		flag;

	head->w_start = 0;
	flag = 0;
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
}

void		width_end(t_vars *head)
{
	int		j;
	int		i;
	int		flag;

	j = -1;
	flag = 0;
	i = head->piece_c - 1;
	head->w_end = head->piece_c;
	while (head->w_end != -1)
	{
		j = head->len_r - 1;
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

void		swap(int *a, int *b)
{
	int		t;

	t = *a;
	*a = *b;
	*b = t;
}

int			partition(int *arr, int low, int high)
{
	int		pivot;
	int		i;
	int		j;

	i = (low - 1);
	pivot = arr[high];
	j = low;
	while (j <= high - 1)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
		j++;
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void		qicsort(int *arr, int low, int high)
{
	int		pi;

	if (low < high)
	{
		pi = partition(arr, low, high);
		qicsort(arr, low, pi - 1);
		qicsort(arr, pi + 1, high);
	}
}
