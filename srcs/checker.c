/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:37:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/09/14 18:33:46 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_duplicate(t_ps *ps, int num)
{
	t_node		*current;
	intptr_t	current_value;
	int			count;

	count = 0;
	current = ps->a->top;
	while (current != NULL)
	{
		current_value = (intptr_t)(current->content);
		if (current_value == num)
		{
			count++;
			if (count > 1)
				return (1);
		}
		current = current->next;
	}
	return (0);
}

bool	is_sorted(t_ps *ps)
{
	t_node	*current;
	int		prev_value;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		return (TRUE);
	if (ps->a->size == 1)
		return (TRUE);
	current = ps->a->top;
	prev_value = (intptr_t)(current->content);
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
