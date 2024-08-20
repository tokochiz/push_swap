/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/20 23:26:33 by ctokoyod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	if (argc < 2)
		put_error_and_exit(ERR_ARGS);
}

void	free_ps(t_ps *ps)
{
	if (ps->a == NULL)
	{
		ft_lstclear(&(ps->a->top), NULL);
		free(ps->a);
	}
	if (ps->b == NULL)
	{
		ft_lstclear(&(ps->b->top), NULL);
		free(ps->b);
	}
	free(ps->operation_count);
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
		if (is_sorted(&ps) == TRUE)
			ft_printf("OK\n");
	}
	else
	{
		printf("Error\n");
	}
	free_ps(&ps);
	return (0);
}

/* ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
 debag 目標は、スタックa内の数を昇順にソートすること。スタックBは最終的に空。貪欲法でソートを用いてソート
		// ~~ cost ~~
		// printf("cost 1 : %d \n", ps->costs->cost1);
		// printf("cost 2 : %d \n", ps->costs->cost2);
		// printf("cost 3 : %d \n", ps->costs->cost3);
		// printf("cost 4 : %d \n", ps->costs->cost4);
		// printf("!![%d] target_p ;%d current->cost;%d type:%d\n",
		// 	(int)(intptr_t)current->content, target_p, current->cost,
		// 	current->type);

// 	reverse_operations(ps, ra_count, rra_count);
// printf("~~reverse~~~~~~~~~~~~~\n");
// 	printf_stack(ps->a, 'A');
// 	printf_stack(ps->b, 'B');

// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }

	if (ps.operation_count != NULL)
		printf("Operation count: %d\n", *ps.operation_count);
	printf("~~~~~~sort~~~~~~~\n");
	printf_stack(ps.a, 'A');
	printf_stack(ps.b, 'B');
*/
void	printf_stack(t_stack *stack, char stack_name)
{
	t_node	*current;

	if (stack == NULL)
	{
		printf("Error: Invalid stack\n");
		return ;
	}
	current = stack->top;
	printf("Stack %c (size: %d): ", stack_name, stack->size);
	while (current != NULL)
	{
		printf("%ld ", (intptr_t)current->content);
		current = current->next;
	}
	printf("\n");
}
/*
 debag
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊ */
