/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:00:40 by j                 #+#    #+#             */
/*   Updated: 2024/09/10 18:05:23 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mini_shell.h"

void	sigint_handler(int sig)
{
	(void)sig;
	ft_putstr_fd("\n", 1);
}

void	setup_signals(void)
{
	signal(SIGINT, sigint_handler); // handle ctrl c
	signal(SIGQUIT, SIG_IGN); // ignore ctrl+
}
