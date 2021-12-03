/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:27:25 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/03 20:32:18 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	part_1(char **argv)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (argv[++i])
		if (atoi(argv[i]) > atoi(argv[i - 1]))
			++ret;
	printf("%d\n", ret);
}

static void	part_2(char **argv)
{
	int	i;
	int	ret;
	int	sum_1;
	int	sum_2;

	i = 0;
	ret = 0;
	while (argv[i + 3])
	{
		sum_1 = atoi(argv[i]) + atoi(argv[i + 1]) + atoi(argv[i + 2]);
		sum_2 = atoi(argv[i + 1]) + atoi(argv[i + 2]) + atoi(argv[i + 3]);
		if (++i && sum_2 > sum_1)
			++ret;
	}
	printf("%d\n", ret);
}

/* --- Day 1: Sonar Sweep --- */
int	main(int argc, char **argv)
{
	(void)argc;
	part_1(argv + 1);
	part_2(argv + 1);
	return (0);
}
