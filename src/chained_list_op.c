/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:42:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/12 17:42:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

t_list_char	*ft_lstcharnew(int content)
{
	t_list_char	*tmp;

	tmp = malloc(sizeof(*tmp));
	if (!tmp)
		exit (1);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}

t_list_char	*ft_lstcharlast(t_list_char *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lstcharadd_back(t_list_char **lst, t_list_char *new)
{
	t_list_char	*link;

	if (!(*lst))
		*lst = new;
	else
	{
		link = ft_lstcharlast(*lst);
		link->next = new;
	}
}

void	ft_lstcharprint(t_list_char *lst)
{
	while (lst->next != NULL)
	{
		ft_printf("%c", lst->content);
		lst = lst->next;
	}
	ft_printf("\n");
}

void	ft_lstchardelone(t_list_char *lst)
{
	if (lst)
		free(lst);
}
