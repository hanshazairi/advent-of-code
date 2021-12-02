/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:12:34 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/02 23:26:13 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

static int	check(char **argv, int r, int d)
{
	int	len;
	int	ret;
	int	x;
	int	y;

	x = 0;
	y = 0;
	len = strlen(argv[0]);
	ret = 0;
	while (argv[y + d])
	{
		x += r;
		if (x > len - 1)
			x -= len;
		if (argv[y + d][x] == '#')
			++ret;
		y += d;
	}
	return (ret);
}

static void	first(char **argv)
{
	int	ret;

	ret = check(argv, 3, 1);
	printf("%d\n", ret);
}

static void	second(char **argv)
{
	long	ret[5];

	ret[0] = check(argv, 1, 1);
	ret[1] = check(argv, 3, 1);
	ret[2] = check(argv, 5, 1);
	ret[3] = check(argv, 7, 1);
	ret[4] = check(argv, 1, 2);
	printf("%ld\n", ret[0] * ret[1] * ret[2] * ret[3] * ret[4]);
}

int	main(int argc, char **argv)
{
	(void)argc;
	first(argv + 1);
	second(argv + 1);
	return (0);
}
