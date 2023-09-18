/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:08:32 by vasferre          #+#    #+#             */
/*   Updated: 2023/08/03 15:09:34 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i < 0)
	{
		ft_rrotate(stack_a, 's');
		ft_rrotate(stack_b, 's');
		write(1, "rrr\n", 4);
	}
	else
	{
		ft_rotate(stack_a, 's');
		ft_rotate(stack_b, 's');
		write(1, "rr\n", 4);
	}
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack	*first;
	t_stack	*last;
	int		last_content;
	size_t	last_order;

	if (c == 'a' || c == 'b')
		print_action('r', c, 1);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(first);
	last_content = last->value;
	last_order = last->order;
	last->value = first->value;
	last->order = first->order;
	while (first->next != last)
	{
		first->value = first->next->value;
		first->order = first->next->order;
		first = first->next;
	}
	first->value = last_content;
	first->order = last_order;
}

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack	*first;
	t_stack	*last;
	int		first_content;
	size_t	first_order;

	if (c == 'a' || c == 'b')
		print_action('r', c, -1);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(first);
	first_content = first->value;
	first_order = first->order;
	first->value = last->value;
	first->order = last->order;
	while (last->prev != first)
	{
		last->value = last->prev->value;
		last->order = last->prev->order;
		last = last->prev;
	}
	last->value = first_content;
	last->order = first_order;
}
