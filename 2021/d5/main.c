/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 07:34:41 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/06 02:19:02 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

static t_xy	*init(int argc, char **argv)
{
	int		i;
	t_xy	*ret;

	ret = malloc(sizeof(t_xy) * (argc * 2));
	if (!ret)
		return (0);
	i = -1;
	while (++i < argc)
	{
		ret[i * 2].x = atoi(argv[i * 3]);
		ret[i * 2].y = atoi(strchr(argv[i * 3], ',') + 1);
		ret[i * 2 + 1].x = atoi(argv[i * 3 + 2]);
		ret[i * 2 + 1].y = atoi(strchr(argv[i * 3 + 2], ',') + 1);
	}
	return (ret);
}

static void	part_1(int argc, t_xy *xy, int *vents, int len)
{
	int	i;
	int	udlr[4];

	i = -1;
	while (++i < argc)
	{
		get_udlr(xy[i * 2 + 0], xy[i * 2 + 1], udlr);
		if (udlr[2] == udlr[3])
			while (udlr[1] <= udlr[0])
				vents[udlr[2] * len + udlr[1]++] += 1;
		else if (udlr[0] == udlr[1])
			while (udlr[2] <= udlr[3])
				vents[(udlr[2]++) * len + udlr[0]] += 1;
	}
	printf("%d\n", get_points(vents, len));
}

static void	part_2(int argc, t_xy *xy, int *vents, int len)
{
	int	i;
	int	udlr[4];

	i = -1;
	while (++i < argc)
	{
		get_udlr(xy[i * 2 + 0], xy[i * 2 + 1], udlr);
		if (udlr[0] != udlr[1] && udlr[2] != udlr[3])
		{
			if ((xy[i * 2 + 0].x == udlr[2] && xy[i * 2 + 0].y == udlr[1]) \
					|| (xy[i * 2 + 0].x == udlr[3] \
					&& xy[i * 2 + 0].y == udlr[0]))
				while (udlr[1]++ <= udlr[0])
					vents[(udlr[2]++) * len + (udlr[1] - 1)] += 1;
			else
				while (udlr[2]++ <= udlr[3])
					vents[(udlr[2] - 1) * len + udlr[0]--] += 1;
		}
	}
	printf("%d\n", get_points(vents, len));
}

/* --- Day 5: Hydrothermal Venture --- */
int	main(int argc, char **argv)
{
	int		len;
	int		*vents;
	t_xy	*xy;

	xy = init((argc - 1) / 3, argv + 1);
	len = max((argc - 1) / 3 * 2, xy) + 1;
	vents = malloc(sizeof(int) * (len * len));
	if (!vents)
	{
		free(xy);
		return (1);
	}
	bzero(vents, sizeof(int) * (len * len));
	part_1((argc - 1) / 3, xy, vents, len);
	part_2((argc - 1) / 3, xy, vents, len);
	free(vents);
	free(xy);
	return (0);
}
