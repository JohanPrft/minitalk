/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_list_op2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:43:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/12 17:43:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	ft_lstcharclear(t_list_char **lst)
{
	t_list_char	*tmp;
	t_list_char	*addr;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (tmp)
	{
		addr = tmp-> next;
		ft_lstchardelone(tmp);
		tmp = addr;
	}
	*lst = NULL;
}
