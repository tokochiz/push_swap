/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:37:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/08 22:20:47 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_ps *stack)
{
	t_node	*current;
	int		prev_value;

	if (stack == NULL || stack->a == NULL || stack->a->top == NULL)
		return (TRUE);
	if (stack->a->size <= 1)
		return (TRUE);
	// current ポインタをスタックAの先頭に設定、
	current = stack->a->top;
	if (current == NULL || current->content == NULL)
		return (FALSE);
	// 現在の要素＝先頭の要素の値をprevに設定、
	prev_value = *(int *)(current->content);
	current = current->next;
	while (current != NULL)
	{
		if (*(int *)(current->content) < prev_value)
			return (FALSE);
		prev_value = *(int *)(current->content);
		current = current->next;
	}
	return (TRUE);
}
