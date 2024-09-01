/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 20:37:09 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/09/01 17:15:07 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_duplicate(t_ps *ps, int num)
{
	t_node	*current;

	current = ps->a->top;
	while (current != NULL)
	{
		if (*(int *)(current->content) == num)
			return (1);
		current = current->next;
	}
	return (0);
}

bool	is_sorted(t_ps *ps)
{
	t_node	*current;
	int		prev_value;

	if (ps == NULL || ps->a == NULL || ps->a->top == NULL)
		return (FALSE);
	if (ps->a->size <= 1)
		return (FALSE);
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

int	is_valid_number(const char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}
