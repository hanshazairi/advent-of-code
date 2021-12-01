/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:27:25 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/02 00:02:39 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static void	first(char **argv)
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

static void	second(char **argv)
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
	first(argv + 1);
	second(argv + 1);
	return (0);
}
