/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 22:14:24 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/06 23:14:06 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	get_small_sides(char *argv, int small_sides[2])
{
	int	i;
	int	sides[3];

	sides[0] = atoi(argv);
	sides[1] = atoi(strchr(argv, 'x') + 1);
	sides[2] = atoi(strrchr(argv, 'x') + 1);
	i = -1;
	while (++i < 3)
	{
		if (sides[i] <= small_sides[0])
		{
			small_sides[1] = small_sides[0];
			small_sides[0] = sides[i];
		}
		else if (sides[i] < small_sides[1] && sides[i] != small_sides[0])
			small_sides[1] = sides[i];
	}
}

static void	part_1(char **argv)
{
	int	i;
	int	ret;
	int	sides[3];
	int	small_sides[2];

	ret = 0;
	i = -1;
	while (argv[++i])
	{
		sides[0] = atoi(argv[i]);
		sides[1] = atoi(strchr(argv[i], 'x') + 1);
		sides[2] = atoi(strrchr(argv[i], 'x') + 1);
		ret += 2 * sides[0] * sides[1] + 2 * sides[0] * sides[2] \
				+ 2 * sides[1] * sides[2];
		small_sides[0] = INT_MAX;
		small_sides[1] = INT_MAX;
		get_small_sides(argv[i], small_sides);
		ret += small_sides[0] * small_sides[1];
	}
	printf("%d\n", ret);
}

static void	part_2(char **argv)
{
	int	i;
	int	ret;
	int	sides[3];
	int	small_sides[2];

	ret = 0;
	i = -1;
	while (argv[++i])
	{
		sides[0] = atoi(argv[i]);
		sides[1] = atoi(strchr(argv[i], 'x') + 1);
		sides[2] = atoi(strrchr(argv[i], 'x') + 1);
		ret += sides[0] * sides[1] * sides[2];
		small_sides[0] = INT_MAX;
		small_sides[1] = INT_MAX;
		get_small_sides(argv[i], small_sides);
		ret += 2 * small_sides[0] + 2 * small_sides[1];
	}
	printf("%d\n", ret);
}

int	main(int argc, char **argv)
{
	(void)argc;
	part_1(argv + 1);
	part_2(argv + 1);
	return (0);
}
