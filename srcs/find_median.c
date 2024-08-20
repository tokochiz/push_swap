/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:59:06 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/08/20 23:12:24 by ctokoyod         ###   ########.fr       */
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

	pivot = array[right];
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

	if (stack == NULL || stack->top == NULL)
		put_error_and_exit(ERR_MALLOC);
	values = (int *)malloc(sizeof(int) * stack->size);
	if (values == NULL)
		put_error_and_exit(ERR_MALLOC);
	current = stack->top;
	i = 0;
	while (i < stack->size && current != NULL)
	{
		values[i] = (int)(intptr_t)current->content;
		current = current->next;
		i++;
	}
	if (i != stack->size)
	{
		free(values);
		put_error_and_exit(ERR_MALLOC);
	}
	quick_sort(values, 0, stack->size - 1, stack->size / 2);
	if (stack->size % 2 == 0)
		median = (values[stack->size / 2 - 1] + values[stack->size / 2]) / 2;
	else
	{
		median = values[stack->size / 2];
	}
	free(values);
	return (median);
}
