/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:08:35 by vasferre          #+#    #+#             */
/*   Updated: 2023/08/03 15:11:31 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*ordena a stack a quando o tamanho e maior que 5 usa bits para
ordenar atraves das sua posicao*/
void	solve(t_stack **stack_a, int argc)
{
	int		index;
	int		max_index;
	int		i;
	t_stack	*stack_b;

	index = 0;
	max_index = 0;
	stack_b = NULL;
	while (((argc - 1) >> max_index) != 0)
		++max_index;
	while (index < max_index)
	{
		i = 0;
		while (i < (argc))
		{
			if ((((*stack_a)->order >> index) & 1) == 0)
				ft_push(stack_a, &stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
			i++;
		}
		while (stack_b)
			ft_push(&stack_b, stack_a, 'a');
		index++;
	}
}
