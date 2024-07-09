/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/09 21:54:16 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	parse_args(int argc, char *argv[], t_ps *stack)
{
	int		i;
	int		value;
	int		error;
	int		*value_p;
	t_list	*new_node;

	i = 0;
	while (i < argc)
	{
		value = ft_atoi_with_error(argv[i], &error);
		if (error != 0)
		{
			put_error_and_exit(ERR_LST1);
		}
		value_p = malloc(sizeof(int));
		if (value_p == NULL)
			put_error_and_exit(ERR_LST2);
		*value_p = value;
		
		new_node = ft_lstnew(value_p);
		if (new_node == NULL)
		{
			free(value_p);
			put_error_and_exit(ERR_LST2);
		}
		ft_lstadd_back(&(stack->a->top), new_node);
		i++;
	}
	stack->a->size = ft_lstsize(stack->a->top);
}

void	initialize(t_ps *stack)
{
	stack->a = (t_stack *)malloc(sizeof(t_stack));
	stack->b = (t_stack *)malloc(sizeof(t_stack));
	if (stack->a == NULL || stack->b == NULL)
		put_error_and_exit(ERR_MALLOC);
	stack->a->top = NULL;
	stack->a->size = 0;
	stack->b->top = NULL;
	stack->a->size = 0;
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

	current = stack->top;
	printf("Stack %c (size: %d): ", stack_name, stack->size);
	while (current != NULL)
	{
		printf("%d ", (int)current->content);
		current = current->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_ps	stack;

	check_argc(argc);
	initialize(&stack);
	parse_args(argc - 1, argv + 1, &stack);
	/****デバック用****/
	print_stack(stack.a, 'A');
	print_stack(stack.b, 'B');

	// TODO : sort関数
	if (is_sorted(&stack) != TRUE)
	{
		sort_stack(&stack);
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
