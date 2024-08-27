/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/27 21:28:19 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_ps(t_ps *ps)
{
	if (ps != NULL)
	{
		if (ps->a != NULL)
		{
			if (ps->a->top != NULL)
				ft_lstclear(&(ps->a->top), NULL);
			free(ps->a);
			//ps->a = NULL;
		}
		if (ps->b != NULL)
		{
			if (ps->b->top != NULL)
				ft_lstclear(&(ps->b->top), NULL);
			free(ps->b);
			//ps->b = NULL;
		}
		if (ps->operation_count != NULL)
		{
			free(ps->operation_count);
			//ps->operation_count = NULL;
		}
		if (ps->costs != NULL)
		{
			free(ps->costs);
			//ps->costs = NULL;
		}
	}
}

void	parse_args(int argc, char *argv[], t_ps *ps)
{
	int		i;
	int		value;
	int		is_error;
	t_list	*new_node;

	i = 0;
	while (i < argc)
	{
		value = ft_atoi_with_error(argv[i], &is_error);
		if (is_error != 0)
			put_error_and_exit(ERR_LST1);
		new_node = ft_lstnew((void *)(intptr_t)value);
		if (new_node == NULL)
		{
			free_ps(ps);
			put_error_and_exit(ERR_LST2);
		}
		ft_lstadd_back(&(ps->a->top), new_node);
		i++;
	}
	ps->a->size = ft_lstsize(ps->a->top);
}

void	initialize(t_ps *ps)
{
	ps->a = (t_stack *)malloc(sizeof(t_stack));
	ps->b = (t_stack *)malloc(sizeof(t_stack));
	ps->operation_count = malloc(sizeof(int));
	ps->costs = (t_costs *)malloc(sizeof(t_costs));
	if (ps->a == NULL || ps->b == NULL || ps->operation_count == NULL
		|| ps->costs == NULL)
		put_error_and_exit(ERR_MALLOC);
	ps->a->top = NULL;
	ps->a->size = 0;
	ps->b->top = NULL;
	ps->b->size = 0;
	*ps->operation_count = 0;
	ps->costs->type = 1;
}

void	check_argc(int argc)
{
	if (argc == 1)
		normal_exit();
	if (argc < 2)
		put_error_and_exit(ERR_ARGS);
}

int	main(int argc, char *argv[])
{
	t_ps	ps;

	check_argc(argc);
	initialize(&ps);
	parse_args(argc - 1, argv + 1, &ps);
	if (is_sorted(&ps) != TRUE)
	{
		sort_stack(&ps);
	}
	free_ps(&ps);
	return (0);
}
