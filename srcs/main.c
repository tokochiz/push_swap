/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  ctokoyod < ctokoyod@student.42tokyo.jp    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:03:54 by  ctokoyod         #+#    #+#             */
/*   Updated: 2024/07/03 22:10:55 by  ctokoyod        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void check_argc(int argc)
{
	if(argc < 2)
		return(0);
}

int main(int argc, char *argv[])
{
	t_stack stack;
	
	//TODO :  数字を受け取る
	check_argc(argc);
	
	// TODO ; initialize stackA & stackB
	//TODO :  リストでつなげる?
	// TODO : sort関数
		//TODO :  スタックAからスタックBに移動させる
		//TODO :  スタックBからスタックAに移動させる　この時にルールを守って操作
}
