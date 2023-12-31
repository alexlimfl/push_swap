/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: folim <folim@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 23:20:49 by folim             #+#    #+#             */
/*   Updated: 2023/08/07 23:20:51 by folim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	last_node_value(t_node *lst)
{
	t_node	*curr;

	curr = lst;
	while (curr->next != NULL)
		curr = curr->next;
	return (curr->x);
}

void	exit_message(void)
{
	ft_printf("Error\n");
	exit(1);
}

long	ft_atoi(const char *str)
{
	long	sign;
	int		i;
	long	otpt;

	i = 0;
	sign = 1;
	otpt = 0;
	while (str[i] != 0 && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		otpt = (otpt * 10) + (str[i] - '0');
		i++;
	}
	return (otpt * sign);
}

t_node	*ll_convert(char **str)
{
	t_node	*head;
	long	nb;
	int		c;
	int		d;

	head = NULL;
	c = 0;
	d = 0;
	while (str[c])
	{
		nb = ft_atoi(str[c]);
		if (nb < -2147483648 || nb > 2147483647)
		{
			delete_list(&head);
			exit_message();
		}
		insert_back(&head, nb);
		c++;
	}
	return (head);
}

void	clear_ll_exit(t_node **a, t_node **b, t_node **otpt, int s)
{
	delete_list(a);
	delete_list(b);
	delete_list(otpt);
	if (s == 2)
		ft_printf("Quit program\n");
	if (s == 1)
		ft_printf("OK\n");
	if (s == 0)
		ft_printf("KO\n");
	exit(0);
}
	// system("leaks -q checker");