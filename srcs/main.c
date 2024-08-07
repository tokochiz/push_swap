/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctokoyod <ctokoyod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/08/06 23:09:01 by ctokoyod         ###   ########.fr       */
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

void free_ps(t_ps *ps)
{
	if(ps->a == NULL)
	{
		ft_lstclear(&(ps->a->top), NULL);
		free(ps->a);
	}
	if(ps->b == NULL)
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
	/****デバック用****/
	printf_stack(ps.a, 'A');
	printf_stack(ps.b, 'B');
    if (is_sorted(&ps) != TRUE)
    {
		printf("a\n");
        sort_stack(&ps);

        if (ps.a->size >= 2)
        {
            sa(&ps);
            printf("After sa:\n");
            printf_stack(ps.a, 'A');
            printf_stack(ps.b, 'B');
        }

        if (ps.a->size >= 1)
        {
            pb(&ps);
            printf("After pb:\n");
            printf_stack(ps.a, 'A');
            printf_stack(ps.b, 'B');
        }

        if (ps.operation_count != NULL)
            printf("Operation count: %d\n", *ps.operation_count);
    }
    else
    {
        printf("Already sorted\n");
    }
    // 操作の出力
    // print_operations(&stack);
    // メモリの解放
    // free_ps(&stack);
    // メモリの解放
    free_ps(&ps);
	return (0);
}

/* ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
 debag 目標は、スタックa内の数を昇順にソートすること。スタックBは最終的に空。貪欲法でソートを用いてソートします。
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
		printf("%lld ", (intptr_t)current->content);
		current = current->next;
	}
	printf("\n");
}
/* ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
 debag
＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊ */
