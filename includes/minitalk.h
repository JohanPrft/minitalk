/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:36:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/10 11:36:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

typedef struct s_list_char
{
	int					content;
	struct s_list_char	*next;
}	t_list_char;

t_list_char	*ft_lstcharnew(int content);
t_list_char	*ft_lstcharlast(t_list_char *lst);
void		ft_lstcharadd_back(t_list_char **lst, t_list_char *new);
void		ft_lstcharprint(t_list_char *lst);
void		ft_lstchardelone(t_list_char *lst);
void		ft_lstcharclear(t_list_char **lst);

void		client(char **argv);
void		server(void);

#endif