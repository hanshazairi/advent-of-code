/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaddrul <hbaddrul@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:46:30 by hbaddrul          #+#    #+#             */
/*   Updated: 2021/12/05 07:17:49 by hbaddrul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	calculate_score(int *board)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < 25)
		if (board[i] != -1)
			ret += board[i];
	return (ret);
}

static int	row_is_bingo(int *board, int bingo)
{
	int	i;
	int	j;
	int	sum;

	i = 0;
	while (i < 25)
	{
		sum = 0;
		j = -1;
		while (++j < 5)
			sum += board[i + j];
		if (sum == -5 && !bingo)
			return (1);
		i += 5;
	}
	return (0);
}

static int	col_is_bingo(int *board, int bingo)
{
	int	i;
	int	j;
	int	sum;

	i = -1;
	while (++i < 5)
	{
		sum = 0;
		j = 0;
		while (j < 25)
		{
			sum += board[i + j];
			j += 5;
		}
		if (sum == -5 && !bingo)
			return (1);
	}
	return (0);
}

int	check_bingo(int argc, int **boards, int *bingos)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < argc / 25)
	{
		if (row_is_bingo(boards[i], bingos[i]) && ++bingos[i])
			ret = calculate_score(boards[i]);
		else if (col_is_bingo(boards[i], bingos[i]) && ++bingos[i])
			ret = calculate_score(boards[i]);
	}
	return (ret);
}
