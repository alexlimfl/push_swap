/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:25:37 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:25:38 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_node **a, t_node **b, t_node **otpt, int print)
{
	if (*a == NULL || (*a)->next == NULL || *b == NULL || (*b)->next == NULL)
		clear_ll_exit(a, b, otpt, 0);
	rra(a, b, otpt, 0);
	rrb(b, b, otpt, 0);
	if (print == 1)
		insert_back(otpt, 11);
}

void	print_output(t_node **otpt)
{
	t_node		*curr;
	const char	*str[11];

	str[0] = "sa";
	str[1] = "sb";
	str[2] = "ss";
	str[3] = "pa";
	str[4] = "pb";
	str[5] = "ra";
	str[6] = "rb";
	str[7] = "rr";
	str[8] = "rra";
	str[9] = "rrb";
	str[10] = "rrr";
	curr = *otpt;
	while (curr != NULL)
	{
		if (curr->x != 0)
			ft_printf("%s\n", str[curr->x - 1]);
		curr = curr->next;
	}
}

int	optimizer(t_node **otpt, int find, int substi)
{
	t_node	*curr;

	if (*otpt == NULL)
		return (0);
	curr = double_ll_convert(otpt);
	while (curr != NULL && curr->x != 4 && curr->x != 5)
		curr = curr->prev;
	if (curr == NULL)
		return (0);
	curr = curr->next;
	while (curr != NULL && curr->x != 4 && curr->x != 5)
	{
		if (curr->x == find)
		{
			curr->x = substi;
			return (1);
		}
		curr = curr->next;
	}
	return (0);
}

void	mega_sort(t_node **a, t_node **b, t_node **otpt)
{	
	t_node	*curr;
	t_var	r;

	curr = *a;
	(*otpt)->num_chunk = 10;
	label_ranking(a);
	inner_chunk_maker(otpt, c_n(*a));
	outer_chunk_maker(otpt, c_n(*a));
	lable_chunk(a, otpt);
	push_top_chunk(a, b, &r, otpt);
	quick_sort(a, b, otpt);
	final_sort(a, b, otpt);
}
