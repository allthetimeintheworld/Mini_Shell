/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: j <j@student.42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:04:33 by j                 #+#    #+#             */
/*   Updated: 2024/09/18 16:13:55 by j                ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
#define BUILTINS_H

// Function prototypes for built-in commands
void ft_cd(char **args);
void ft_pwd(void);
void ft_echo(char **args);
void ft_export(char **args);
void ft_unset(char **args);
void ft_env(void);
void ft_exit(char **args);


#endif