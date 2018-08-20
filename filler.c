/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vuyaninxele <marvin@42.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 18:38:01 by vuyaninxe         #+#    #+#             */
/*   Updated: 2018/08/19 06:11:06 by vnxele           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void                    piece_dimensions(t_vars *head)
{
	char    **split;

	if (head->line[ft_strlen(head->line)] == ':')
		head->line[ft_strlen(head->line) - 1] = '\0';
	split = ft_strsplit(head->line, ' ');
	head->piece_r = ft_atoi(split[1]);
	head->piece_r_dup = ft_atoi(split[1]);
	head->piece_c = ft_atoi(split[2]) + 1;
}

void                    map_dimensions(t_vars *head)
{
	char    **split;
	if (head->line[ft_strlen(head->line)] == ':')
		head->line[ft_strlen(head->line) - 1] = '\0';
	split = ft_strsplit(head->line, ' ');
	head->map_r = ft_atoi(split[1]);
	head->map_c = ft_atoi(split[2]);
	head->map = (char**)malloc(sizeof(char*) * head->map_r);
}

void	player_no(t_vars *head)
{
		head->pno = (ft_strstr(head->line, "$$$ exec p1")) ? 'O' : 'X';
		head->eno = (head->pno == 'O') ? 'X' : 'O';
}

int	main(void)
{
	t_vars	head;
	//int fd = open("output.txt",  O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	int fdi = 0;//open("text1.txt", O_RDONLY);
	int	i;

	i = 0;
	head.i = 0;
	get_next_line(fdi, &head.line);
	player_no(&head);
	get_next_line(fdi, &head.line);
	map_dimensions(&head);
	while (get_next_line(fdi, &head.line))
	{
		if (ft_isdigit(head.line[0]) && ft_isspace(head.line[3]))
			head.map[head.i++] = ft_strsub(head.line, 4, head.map_c);
		if (head.piece_r_dup && head.piece_c)
		{
			head.piece_r_dup--;
			head.piece[i++] = ft_strsub(head.line, 0, head.piece_c);
		}
		if (ft_strstr(head.line, "Piece"))
			piece_dimensions(&head);
		if (!head.piece_r_dup && i)
		{
			play(head);
			i = 0;
			head.i = 0;
		}
		free(head.line);
	}
	return(0);
}
