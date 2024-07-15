/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:37:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/15 19:18:17 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_ps *ps)
{
	t_node	*current;
	int		prev_value;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		return (FALSE);
	if (ps->a->size <= 1)
		return (FALSE);
	// current ポインタをスタックAの先頭に設定、
	current = ps->a->top;
	if (current == NULL || current->content == NULL)
		return (FALSE);
	// 現在の要素＝先頭の要素の値をprevに設定、
	prev_value = (intptr_t)(current->content);
	// current ポインタを次の要素に移動
	current = current->next;
	while (current != NULL)
	{
		if ((intptr_t)(current->content) < prev_value)
			return (FALSE);
		prev_value = (intptr_t)(current->content);
		current = current->next;
	}
	return (TRUE);
}
