/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/15 19:53:15 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parse_args(int argc, char *argv[], t_ps *ps)
{
	int		i;
	int		value;
	int		error;
	t_list	*new_node;

	i = 0;
	while (i < argc)
	{
		value = ft_atoi_with_error(argv[i], &error);
		if (error != 0)
		{
			put_error_and_exit(ERR_LST1);
		}
		// value_p = malloc(sizeof(int));
		// if (value_p == NULL)
		// 	put_error_and_exit(ERR_LST2);
		// *value_p = value;
		// new_node = ft_lstnew(value_p);
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
	if (ps->a == NULL || ps->b == NULL)
		put_error_and_exit(ERR_MALLOC);
	ps->a->top = NULL;
	ps->a->size = 0;
	ps->b->top = NULL;
	ps->b->size = 0;
}

void	check_argc(int argc)
{
	if (argc < 2)
		put_error_and_exit(ERR_ARGS);
}
/*
 debag
*/

void	print_stack(t_stack *stack, char stack_name)
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

int	main(int argc, char *argv[])
{
	t_ps	ps;

	check_argc(argc);
	initialize(&ps);
	parse_args(argc - 1, argv + 1, &ps);
	/****デバック用****/
	print_stack(ps.a, 'A');
	print_stack(ps.b, 'B');
	// TODO : sort関数
	if (is_sorted(&ps) != TRUE)
	{
		sort_stack(&ps);
		printf("Not sorted\n");
	}
	else
		printf("Already sorted\n");
	// 操作の出力
	// print_operations(&stack);
	// メモリの解放
	// free_ps(&stack);
	return (0);
}
