/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:58:43 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/08 01:01:29 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	*init(char *argv, int len)
{
	int		i;
	int		*ret;
	char	*str;

	ret = malloc(sizeof(int) * len);
	if (!ret)
		return (0);
	i = -1;
	str = strsep(&argv, ",");
	while (str)
	{
		ret[++i] = atoi(str);
		str = strsep(&argv, ",");
	}
	return (ret);
}

static void	sort(int *nums, int len)
{
	int	i;
	int	j;
	int	min;
	int	tmp;

	i = -1;
	while (++i < len - 1)
	{
		min = i;
		j = i;
		while (++j < len)
			if (nums[j] < nums[min])
				min = j;
		tmp = nums[i];
		nums[i] = nums[min];
		nums[min] = tmp;
	}
}

static void	part_1(int *nums, int len)
{
	int			i;
	int			ret;
	const int	med = nums[len / 2];

	ret = 0;
	i = -1;
	while (++i < len)
		ret += abs(med - nums[i]);
	printf("%d\n", ret);
}

static void	part_2(int *nums, int len)
{
	int	i;
	int	sum;
	int	mean;
	int	ret[2];
	int	tmp[2];

	sum = 0;
	bzero(ret, sizeof(int) * 2);
	i = -1;
	while (++i < len)
		sum += nums[i];
	mean = sum / len;
	i = -1;
	while (++i < len)
	{
		tmp[0] = abs(mean - nums[i]);
		ret[0] += tmp[0] * (tmp[0] + 1) / 2;
		tmp[1] = abs(mean + 1 - nums[i]);
		ret[1] += tmp[1] * (tmp[1] + 1) / 2;
	}
	if (ret[0] < ret[1])
		printf("%d\n", ret[0]);
	else
		printf("%d\n", ret[1]);
}

/* --- Day 7: The Treachery of Whales --- */
int	main(int argc, char **argv)
{
	int	i;
	int	len;
	int	*nums;

	(void)argc;
	len = 1;
	i = -1;
	while (argv[1][++i])
		if (argv[1][i] == ',')
			++len;
	nums = init(argv[1], len);
	if (!nums)
		return (1);
	sort(nums, len);
	part_1(nums, len);
	part_2(nums, len);
	free(nums);
	return (0);
}
