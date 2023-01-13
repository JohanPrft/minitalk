/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:36:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/10 11:36:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

void	reset_static(int *char_in_binary, int *bitshift)
{
	*char_in_binary = 0;
	*bitshift = 7;
}

void	handler_sigusr(int signum)
{
	static int			char_in_binary = 0;
	static int			bitshift = 7;
	static t_list_char	*str_received = NULL;

	if (signum == SIGUSR1)
		;
	else if (signum == SIGUSR2)
	{
		char_in_binary >>= bitshift;
		char_in_binary++;
		char_in_binary <<= bitshift;
	}
	bitshift--;
	if (bitshift == -1)
	{
		ft_lstcharadd_back(&str_received, ft_lstcharnew(char_in_binary));
		reset_static(&char_in_binary, &bitshift);
		if (ft_lstcharlast(str_received)->content == '\0')
		{
			ft_lstcharprint(str_received);
			ft_lstcharclear(&str_received);
		}
	}
}

void	server(void)
{
	struct sigaction	sa;

	ft_printf("%d\n", getpid());
	sa.sa_handler = handler_sigusr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

int	main(void)
{
	server();
	return (1);
}
