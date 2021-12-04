/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:44:23 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/05 07:21:35 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	check_bingo(int argc, int **boards, int *bingos);

static int	**init(int argc, char **argv)
{
	int	i;
	int	**ret;

	ret = malloc(sizeof(int *) * (argc / 25));
	if (!ret)
		return (0);
	i = -1;
	while (++i < argc / 25)
	{
		ret[i] = malloc(sizeof(int) * 25);
		if (!ret[i])
		{
			while (--i >= 0)
				free(ret[i]);
			free(ret);
			return (0);
		}
	}
	i = -1;
	while (argv[++i])
		ret[i / 25][i % 25] = atoi(argv[i]);
	return (ret);
}

static void	part_1_and_2(int argc, char *strs, int **boards, int *bingos)
{
	int		i;
	int		score;
	int		first_score;
	int		final_score;
	char	*str;

	score = 0;
	first_score = -1;
	str = strsep(&strs, ",");
	while (str)
	{
		i = -1;
		while (++i < argc)
			if (boards[i / 25][i % 25] == atoi(str))
				boards[i / 25][i % 25] = -1;
		score = check_bingo(argc, boards, bingos);
		if (first_score == -1 && score)
			first_score = score * atoi(str);
		if (score)
			final_score = score * atoi(str);
		str = strsep(&strs, ",");
	}
	printf("%d\n%d\n", first_score, final_score);
}

/* --- Day 4: Giant Squid --- */
int	main(int argc, char **argv)
{
	int	i;
	int	*bingos;
	int	**boards;

	bingos = malloc(sizeof(int) * ((argc - 2) / 25));
	if (!bingos)
		return (1);
	bzero(bingos, sizeof(int) * ((argc - 2) / 25));
	boards = init(argc - 2, &argv[2]);
	if (!boards)
	{
		free(bingos);
		return (2);
	}
	part_1_and_2(argc - 2, argv[1], boards, bingos);
	i = -1;
	while (++i < argc / 25)
		free(boards[i]);
	free(boards);
	free(bingos);
	return (0);
}
