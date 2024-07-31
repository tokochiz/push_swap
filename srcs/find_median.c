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
		j++;
	}
	swap(&array[i + 1], &array[right]);
	return (i + 1);
}

// 配列からｋ番目(中央値)に小さい要素を見つけるアルゴリズム
int	quick_sort(int *array, int left, int right, int k)
{
	int	pivot_i;
	int	len;

	while (left <= right)
	{
		if (left == right)
			return (array[left]);
		pivot_i = partition(array, left, right);
		len = pivot_i - left + 1;
		if (k == len)
			return (array[pivot_i]);
		else if (k < len)
			right = pivot_i - 1;
		else
		{
			k = k - len;
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

  printf("Debug: Entering find_median\n");
    printf("Debug: stack = %p, stack->top = %p\n", (void*)stack, (void*)(stack ? stack->top : NULL));

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_MALLOC);
		  printf("Debug: stack->size = %d\n", stack->size);

    printf("Debug: Allocating memory for values array\n");
	// 　スタックの要素を配列にコピー
	values = (int *)malloc(sizeof(int) * stack->size);
	if (values == NULL)
		put_error_and_exit(ERR_MALLOC);
	printf("Debug: Copying stack elements to array\n");
	current = stack->top;
	i = 0;
	while (i < stack->size && current != NULL)
	{
		  printf("Debug: Element %d: current = %p, content = %p\n", i, (void*)current, (void*)current->content);
		values[i] = (int)(intptr_t)current->content; // 数値として直接扱う
		current = current->next;
		i++;
	}
	    printf("Debug: Allocating memory for values array1\n");
	if(i != stack->size)
	{
		free(values);\
		put_error_and_exit(ERR_MALLOC);
	}
	    printf("Debug: Allocating memory for values array2\n");
	median = quick_sort(values, 0, stack->size - 1, stack->size / 2);
	free(values);
	    printf("Debug: Allocating memory for values array3\n");
	return (median);
}
今日2024 7/31 
中央値の数が正確に求められていない
