/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnxele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/15 14:26:06 by vnxele            #+#    #+#             */
/*   Updated: 2018/08/15 14:26:09 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void            swap(int *a, int *b)
{
        int             t;

        t = *a;
        *a = *b;
        *b = t;
}

int                     partition(int *arr, int low, int high)
{
        int             pivot;
        int             i;
        int             j;

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

void            qicsort(int *arr, int low, int high)
{
        int             pi;

        if (low < high)
        {
                pi = partition(arr, low, high);
                qicsort(arr, low, pi - 1);
                qicsort(arr, pi + 1, high);
        }
}
