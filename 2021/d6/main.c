/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 02:24:32 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/06 19:58:10 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	count(long *fishes, int days)
{
	int		i;
	int		j;
	long	tmp[9];

	i = -1;
	while (++i < days)
	{
		bzero(tmp, sizeof(long) * 9);
		j = -1;
		while (++j < 9)
		{
			if (j == 0)
			{
				tmp[6] += fishes[j];
				tmp[8] += fishes[j];
			}
			else
				tmp[j - 1] += fishes[j];
		}
		memcpy(fishes, tmp, sizeof(long) * 9);
	}
}

static void	part_1(long fishes[9])
{
	int		i;
	long	ret;

	count(fishes, 80);
	ret = 0;
	i = -1;
	while (++i < 9)
		ret += fishes[i];
	printf("%ld\n", ret);
}

static void	part_2(long fishes[9])
{
	int		i;
	long	ret;

	count(fishes, 256);
	ret = 0;
	i = -1;
	while (++i < 9)
		ret += fishes[i];
	printf("%ld\n", ret);
}

int	main(int argc, char **argv)
{
	int		i;
	long	fishes[9];
	long	tmp[9];

	(void)argc;
	bzero(fishes, sizeof(long) * 9);
	i = -1;
	while (++i < (int)((strlen(argv[1]) + 1) / 2))
		fishes[atoi(&argv[1][i * 2])] += 1;
	memcpy(tmp, fishes, sizeof(long) * 9);
	part_1(tmp);
	memcpy(tmp, fishes, sizeof(long) * 9);
	part_2(tmp);
	return (0);
}
