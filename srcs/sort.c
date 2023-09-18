/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:08:38 by vasferre          #+#    #+#             */
/*   Updated: 2023/08/03 15:11:19 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*Responsavel por ordenar o array de 3 integers fazendo o swap e os rotate
 ncessarios */
void	sort_three(t_stack **stack_a, int arr[3])
{
	if (arr[0] > arr[1] && arr[0] < arr[2])
		ft_swap(stack_a, 'a');
	else if (arr[0] > arr[1] && arr[0] > arr[2])
	{
		if (arr[1] > arr[2])
		{
			ft_swap(stack_a, 'a');
			ft_rrotate(stack_a, 'a');
		}
		else
			ft_rotate(stack_a, 'a');
	}
	else if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		ft_swap(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else
		ft_rrotate(stack_a, 'a');
}
/*encontra os 3 menores numeros da stack a e manda os para a stack b
  procura o node com menor valor e meto no topo da stack a e depois da push 
para a stack b*/

void	push_to_b(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	size_t	i;
	t_stack	*lowest_num;

	i = 0;
	while (i < size - 3)
	{
		lowest_num = find_lowest_num(*stack_a);
		if (lowest_num->pos > size / 2)
		{
			while ((*stack_a)->value != lowest_num->value)
				ft_rrotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->value != lowest_num->value)
				ft_rotate(stack_a, 'a');
		}
		ft_push(stack_a, stack_b, 'b');
		i++;
		free(lowest_num);
	}
}
/* ordena a staak a quando o temanho e 
maior que 2 e menor ou igual que 5
move os num para a stack b e depois ordena os 
3 maior elementos na stack a e deposi
move os elementos de volta para a stack a*/

void	sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int		arr[3];
	size_t	i;

	i = 0;
	if (size > 3)
		push_to_b(stack_a, stack_b, size);
	arr[0] = (*stack_a)->value;
	arr[1] = (*stack_a)->next->value;
	arr[2] = (*stack_a)->next->next->value;
	if (!check_order(*stack_a))
		sort_three(stack_a, arr);
	if (size > 3)
	{
		while (i < size - 3)
		{
			ft_push(stack_b, stack_a, 'a');
			i++;
		}
	}
}
