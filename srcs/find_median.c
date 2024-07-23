/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-07-23 12:59:06 by ctokoyod          #+#    #+#             */
/*   Updated: 2024-07-23 12:59:06 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	partition(int *array, int left, int right)
{
	int	pivot;
	int	i;
	int	j;

	pivot = array[right]; // 配列の最後の要素をピボットとして選択する
	i = left - 1;
	j = left;
	j = left;
	while (j < right)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[right]);
	return (i + 1);
}

// 配列からｋ番目(中央値)に小さい要素を見つけるアルゴリズム
int	quick_sort(int *array, int left, int right, int k)
{
	int	pivot_i;
	int	length;

	while (left <= right)
	{
		if (left == right)
			return (array[left]);
		pivot_i = partition(array, left, right);
		length = pivot_i - left + 1;
		if (k == length)
			return (array[pivot_i]);
		else if (k < length)
			right = pivot_i - 1;
		else
		{
			k = k - length;
			left = pivot_i + 1;
		}
	}
	return (-1);
}

int	find_median(t_stack *stack)
{
	int		i;
	int		median;
	int		*values;
	t_list	*current;

	current = stack->top;
	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_MALLOC);
	// 　スタックの要素を配列にコピー
	values = (int *)malloc(sizeof(int) * stack->size);
	if (values == NULL)
		put_error_and_exit(ERR_MALLOC);
	i = 0;
	while (i < stack->size)
	{
		values[i] = *(int *)current->content;
		current = current->next;
		i++;
	}
	median = quick_sort(values, 0, stack->size - 1, stack->size / 2);
	free(values);
	return (median);
}
