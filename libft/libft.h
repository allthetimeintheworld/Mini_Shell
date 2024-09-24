/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jadyar <jadyar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:52:14 by jadyar            #+#    #+#             */
/*   Updated: 2024/09/24 13:58:55 by jadyar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void				*ft_memset(void *s, int c, size_t n);
char				*ft_strtok(char *str, const char *delim);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char *s, int fd);
char				*ft_strcpy(char *dest, const char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_isspace(char c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strdup(const char *s);
char				*ft_strcat(char *dest, const char *src);
char				*ft_itoa(int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnstr(const char *big, const char *little,
						size_t len);
char				*ft_substr(char const *s, unsigned int start, size_t len);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
int					ft_isascii(int c);
size_t				ft_strlen(const char *str);
int					ft_atoi(const char *nptr);
int					ft_isalpha(int c);
int					ft_isprint(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

typedef struct s_list
{
	int					content;
	struct s_list		*next;
}	t_list;

void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst);
void				ft_lstclear(t_list **lst);
t_list				*ft_lstnew(int content);
void				ft_lstiter(t_list *lst, void (*f)(int));
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);

#endif