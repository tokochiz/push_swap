/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_medina.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 23:03:29 by ctokoyod          #+#    #+#             */
/*   Updated: 2024/07/22 23:03:29 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int find_median(t_stack *stack)
{
    int i;
    int middle;
    int median;
    int *values;
    t_list *current;

    current = stack->top;
    if (stack == NULL || stack->top = NULL)
        return 0;
    // 　スタックの要素を配列にコピー
    values = (int *)malloc(sizeof(int) * stack->size);
    if (values == NULL)
        return 0;

    i = 0;
    while (i < stack->size)
    {
        values[i] = current->content;
        current = current->next;
        i++;
    }

    middle = size / 2;
    median = quick_select(values, 0, stack->size - 1, middle);
    free(values);
    return median;
}

// 配列からｋ番目に小さい要素を見つけるアルゴリズム
int quick_select(int *array, int left, int right, int m)
{
    
}