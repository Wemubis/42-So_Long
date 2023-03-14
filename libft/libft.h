/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-boud <mle-boud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:44:52 by mle-boud          #+#    #+#             */
/*   Updated: 2022/11/18 14:20:19 by mle-boud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 256

/*			Text Color			*/
# define BLACK   "\033[30m"
# define RED     "\033[31m"
# define GREEN   "\033[32m"
# define YELLOW  "\033[33m"
# define BLUE    "\033[34m"
# define PURPLE  "\033[35m"
# define CYAN    "\033[36m"
# define WHITE   "\033[37m"
/*		Background Color		*/
# define BLACKB  "\033[40m"
# define REDB    "\033[41m"
# define GREENB  "\033[42m"
# define YELLOWB "\033[43m"
# define BLUEB   "\033[44m"
# define PURPLEB "\033[45m"
# define CYANB   "\033[46m"
# define WHITEB  "\033[47m"
/*			Underline			*/
# define U       "\033[4m"
# define U_OFF   "\033[24m"
/*			Bold			*/
# define B       "\033[1m"
# define B_OFF   "\033[22m"
/*			Italic			*/
# define I       "\033[3m"
# define I_OFF   "\033[23m"

/*-------------------------HEAD-------------------------*/
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <limits.h>

/*-------------------------FCTN-------------------------*/

/*---------------PRINTF---------------*/
int		ft_printf(const char *format, ...);
int		ft_putnbr_printf(int n);
int		ft_nbr_b_printf(long nb, char *base);
int		ft_putnbr_unsigned_printf(unsigned int n);
int		ft_ptr_b_printf(void *n, char *base);
int		ft_putstr_printf(char *s);

/*-----------------GNL----------------*/
char	*get_next_line(int fd);
size_t	gnl_strlen(char *str);
char	*gnl_strdup(char *s);
char	*gnl_strchr(char *s, int c);
char	*gnl_strjoin(char *s1, char *s2);
char	*keep_left(char *s);

/*----------------CHAR----------------*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_toupper(int c);

/*-----------------MEM----------------*/
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);

/*---------------STRING---------------*/
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	ft_find_char(const char *s, int c);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_chrtrim(char const *s1, char c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);

/*--------------CONV-PUT--------------*/
int		ft_atoi(const char *str);
char	*ft_itoa(int n);
int		ft_putchar(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putnbr_base(int n, char *base);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);

/*-------------------------LIST-------------------------*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
