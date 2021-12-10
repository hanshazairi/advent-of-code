/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:48:31 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/10 20:38:23 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	get_digit(int score)
{
	if (score == 17)
		return ('1');
	else if (score == 25)
		return ('7');
	else if (score == 30)
		return ('4');
	else if (score == 34)
		return ('2');
	else if (score == 37)
		return ('5');
	else if (score == 39)
		return ('3');
	else if (score == 41)
		return ('6');
	else if (score == 42)
		return ('0');
	else if (score == 45)
		return ('9');
	else
		return ('8');
}

static int	decode(char *pattern, char *outputs)
{
	int		score;
	int		counters[3];
	char	ret[5];
	char	*output;

	counters[0] = -1;
	output = strsep(&outputs, " ");
	while (output)
	{
		score = 0;
		counters[1] = -1;
		while (output[++counters[1]])
		{
			counters[2] = -1;
			while (pattern[++counters[2]])
				if (pattern[counters[2]] == output[counters[1]])
					++score;
		}
		ret[++counters[0]] = get_digit(score);
		output = strsep(&outputs, " ");
	}
	ret[4] = 0;
	return (atoi(ret));
}

static void	part_1(FILE *file)
{
	int		ret;
	char	*tmp;
	char	*line;
	char	*signals[3];
	size_t	linecap;

	ret = 0;
	line = 0;
	while (getline(&line, &linecap, file) != -1)
	{
		tmp = line;
		signals[0] = strsep(&tmp, "|");
		signals[1] = strsep(&tmp, "\n") + 1;
		signals[2] = strsep(&signals[1], " ");
		while (signals[2])
		{
			if (strlen(signals[2]) == 2 || strlen(signals[2]) == 3 \
					|| strlen(signals[2]) == 4 || strlen(signals[2]) == 7)
				++ret;
			signals[2] = strsep(&signals[1], " ");
		}
	}
	free(line);
	printf("%d\n", ret);
}

static void	part_2(FILE *file)
{
	int		ret;
	char	*tmp;
	char	*line;
	char	*signals[2];
	size_t	linecap;

	ret = 0;
	line = 0;
	while (getline(&line, &linecap, file) != -1)
	{
		tmp = line;
		signals[0] = strsep(&tmp, "|");
		signals[1] = strsep(&tmp, "\n") + 1;
		ret += decode(signals[0], signals[1]);
	}
	free(line);
	printf("%d\n", ret);
}

/* --- Day 8: Seven Segment Search --- */
int	main(int argc, char **argv)
{
	FILE	*file;

	(void)argc;
	file = fopen(argv[1], "r");
	if (!file)
		return (1);
	part_1(file);
	fseek(file, 0, SEEK_SET);
	part_2(file);
	fclose(file);
	return (0);
}
