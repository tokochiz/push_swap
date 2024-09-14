/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/09/14 17:36:21 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_new_node(char *str, t_ps *ps)
{
	int		value;
	t_node	*new_node;

	if (!ft_atoi_with_error(str, &value))
		put_error_and_exit(ps);
	new_node = ft_lstnew((void *)(intptr_t)value);
	if (new_node == NULL)
		put_error_and_exit(ps);
	ft_lstadd_back((&ps->a->top), new_node);
	if (is_duplicate(ps, value))
		put_error_and_exit(ps);
}

void	parse_args(int argc, char *argv[], t_ps *ps)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] == NULL)
			put_error_and_exit(ps);
		make_new_node(argv[i], ps);
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
		put_error_and_exit(ps);
	ps->a->top = NULL;
	ps->a->size = 0;
	ps->b->top = NULL;
	ps->b->size = 0;
	*ps->operation_count = 0;
	ps->costs->type = 1;
}

void	check_argc(int argc, t_ps *ps)
{
	if (argc == 1)
		normal_exit();
	if (argc < 2)
		put_error_and_exit(ps);
}

int	main(int argc, char *argv[])
{
	t_ps	ps;

	check_argc(argc, &ps);
	initialize(&ps);
	parse_args(argc, argv, &ps);
	if (is_sorted(&ps) != TRUE)
		sort_stack(&ps);
	free_ps(&ps);
	return (0);
}
