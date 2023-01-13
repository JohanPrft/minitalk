/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprofit <jprofit@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 09:47:00 by jprofit           #+#    #+#             */
/*   Updated: 2023/01/11 09:47:00 by jprofit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../libft/libft.h"

//print each binary with ft_printf("%i", (c >> i) & 1); then after while
// ft_printf("\n"); for easier understanding
void	send_char_to_pid(int pid, char c)
{
	int	i;
	int	j;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		j = 5;
		while (--j > 0)
			usleep(10);
	}
}

void	send_str_to_pid(int pid, char *str_to_send)
{
	int	i;

	i = 0;
	while (str_to_send[i])
	{
		send_char_to_pid(pid, str_to_send[i]);
		i++;
	}
	send_char_to_pid(pid, '\0');
}

void	client(char **argv)
{
	int		pid;
	char	*str_to_send;

	pid = ft_atoi(argv[1]);
	str_to_send = argv[2];
	send_str_to_pid(pid, str_to_send);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		client(argv);
	else
		ft_printf("Please input PID and a string\n");
	return (0);
}
