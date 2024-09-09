/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/09/09 19:45:02 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	make_new_node(char *str, t_ps *ps)
{
	int		value;
	t_list	*new_node;

	// int		is_error;
	if (!is_valid_number(str))
		put_error_and_exit(ps);
		
	if(!ft_atoi_with_error(str, &value))
		put_error_and_exit(ps);
	printf("%d ", value);

	new_node = ft_lstnew((void *)(intptr_t)value);
	if (new_node == NULL)
		put_error_and_exit(ps);
	ft_lstadd_back((&ps->a->top), new_node);
}

void	parse_args(int argc, char *argv[], t_ps *ps)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (argv[i] == NULL)
			put_error_and_exit(ps);
		if (ft_strlen(argv[i]) != 0)
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
	parse_args(argc - 1, argv + 1, &ps);
	if (is_sorted(&ps) != TRUE)
		sort_stack(&ps);
	free_ps(&ps);
	return (0);
}
