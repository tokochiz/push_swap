/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/18 21:08:51 by  ctokoyod        ###   ########.fr       */
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
	if (ps->a == NULL || ps->b == NULL || ps->operation_count == NULL)
		put_error_and_exit(ERR_MALLOC);
	ps->a->top = NULL;
	ps->a->size = 0;
	ps->b->top = NULL;
	ps->b->size = 0;
	*ps->operation_count = 0;
}

void	check_argc(int argc)
{
	if (argc < 2)
		put_error_and_exit(ERR_ARGS);
}

int	main(int argc, char *argv[])
{
	t_ps	ps;

	check_argc(argc);
	initialize(&ps);
	parse_args(argc - 1, argv + 1, &ps);
	/****デバック用****/
	printf_stack(ps.a, 'A');
	printf_stack(ps.b, 'B');
	if (is_sorted(&ps) != TRUE)
	{
		// sort_stack(&ps);
		printf("Performing sa operation:\n");
		sa(&ps);
		printf("After sa:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		pb(&ps);
		printf("After pb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		pb(&ps);
		printf("After pb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
				pb(&ps);
		printf("After pb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		pb(&ps);
		printf("After pb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		sb(&ps);
		printf("After sb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		ss(&ps);
		printf("After ss:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		pa(&ps);
		printf("After pa:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		ra(&ps);
		printf("After ra:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		rb(&ps);
		printf("After rb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		rr(&ps);
		printf("After rr:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
				rra(&ps);
		printf("After rra:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		rrb(&ps);
		printf("After rrb:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		rrr(&ps);
		printf("After rrr:\n");
		printf_stack(ps.a, 'A');
		printf_stack(ps.b, 'B');
		printf("Operation count: %d\n", *ps.operation_count);
	}
	else
		printf("Already sorted\n");
	// 操作の出力
	// print_operations(&stack);
	// メモリの解放
	// free_ps(&stack);
	// メモリの解放
	free(ps.a->array);
	free(ps.a);
	return (0);
}

/* ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
 debag
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊ */
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
/* ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
 debag
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊ */
