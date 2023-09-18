/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasferre <vasferre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:08:41 by vasferre          #+#    #+#             */
/*   Updated: 2023/08/03 15:10:37 by vasferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*verifica se o paramtro num ja existe na stack*/
int	duo_verify(t_stack **stack_a, int num)
{
	t_stack	*tmp;

	if (!*stack_a)
		return (0);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->value == num)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}
/*cria um novo node na stack com base  na string dada por argv
 tal que e converitda em valor numerico*/

t_stack	*new_node(char *argv, size_t *pos)
{
	char	*tmp;
	t_stack	*tmp_stack;
	long	num;

	num = 0;
	tmp = ft_strdup(argv);
	if (ft_n_atoi(tmp, &num))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	tmp_stack = ft_stacknew(num, *pos - 1, -1);
	if (tmp_stack)
		return (tmp_stack);
	return (NULL);
}

/*procura o valor numerico mais pequeno e ordena*/
void	find_lowest(t_stack **stack_a, size_t size)
{
	t_stack			*lowest_num;
	t_stack			*tmp;
	size_t			i;

	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		lowest_num = find_next_lowest_num(*stack_a);
		while (tmp)
		{
			if ((tmp)->value == lowest_num->value)
			{
				(tmp)->order = i;
				break ;
			}
			(tmp) = (tmp)->next;
		}
		free(lowest_num);
		i++;
	}
}
/**/

t_stack	*fill_stack(size_t size, char **argv)
{
	size_t	i;
	t_stack	*tmp;
	t_stack	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		tmp = new_node (argv[i], &i);
		if (!tmp || duo_verify(&stack_a, tmp->value))
		{
			if (tmp)
				free(tmp);
			ft_stackclear(&stack_a);
			return (NULL);
		}
		ft_stackadd_back(&stack_a, tmp);
		i++;
	}
	find_lowest(&stack_a, size);
	return (stack_a);
}
