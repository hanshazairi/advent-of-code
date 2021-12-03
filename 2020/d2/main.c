/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:04:54 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/03 20:48:43 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	part_1(char **argv)
{
	int	i;
	int	j;
	int	ret;
	int	tmp;
	int	range[2];

	i = 0;
	ret = 0;
	while (argv[i])
	{
		j = 0;
		tmp = 0;
		range[0] = atoi(argv[i]);
		range[1] = atoi(strchr(argv[i], '-') + 1);
		while (argv[i + 2][j])
			if (argv[i + 2][j++] == *argv[i + 1])
				++tmp;
		if (tmp >= range[0] && tmp <= range[1])
			++ret;
		i += 3;
	}
	printf("%d\n", ret);
}

static void	part_2(char **argv)
{
	int	i;
	int	ret;
	int	range[2];

	i = 0;
	ret = 0;
	while (argv[i])
	{
		range[0] = atoi(argv[i]);
		range[1] = atoi(strchr(argv[i], '-') + 1);
		if ((argv[i + 2][range[0] - 1] == *argv[i + 1]) \
				^ (argv[i + 2][range[1] - 1] == *argv[i + 1]))
			++ret;
		i += 3;
	}
	printf("%d\n", ret);
}

/* --- Day 2: Password Philosophy --- */
int	main(int argc, char **argv)
{
	(void)argc;
	part_1(argv + 1);
	part_2(argv + 1);
	return (0);
}
