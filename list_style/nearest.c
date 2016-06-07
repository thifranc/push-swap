/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thifranc <thifranc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 10:47:27 by thifranc          #+#    #+#             */
/*   Updated: 2016/06/07 11:27:52 by thifranc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "all.h"

t_list	*nearest_b(t_list **a, int *goal, int pivot)
{//attention ne pas appeler si pivot = 0 => boucle infinie
	int		forw;
	int		rew;
	int		back;
	t_list	*tmp;

	forw = 0;
	rew = 0;
	tmp = *a;
	while (tmp->nbr >= goal[pivot])
	{
		forw++;
		tmp = tmp->next;
	}
	back = tmp->nbr;
	tmp = *a;
	while (tmp->nbr >= goal[pivot])
	{
		rew++;
		tmp = tmp->prev;
	}
	return (rew < forw ? tmp : get_value(&(*a), back));
}

int		nearest2(t_list **list, t_list *one, t_list *two)
{
	int		one_min;
	int		two_min;

	one_min = ft_abs(nearest(&(*list), one));
	two_min = ft_abs(nearest(&(*list), two));
	return (one_min <= two_min ? -1 : 1);
}

int		nearest(t_list **list, t_list *goal)
{
	t_list	*tmp;
	int		forward;
	int		rewind;

	forward = 0;
	rewind = 0;
	tmp = *list;
	while (tmp != goal)
	{
		tmp = tmp->next;
		forward++;
	}
	tmp = *list;
	while (tmp != goal)
	{
		tmp = tmp->prev;
		rewind++;
	}
	return (forward <= rewind ? forward : -rewind);
}