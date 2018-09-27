/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syamada <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 13:46:49 by syamada           #+#    #+#             */
/*   Updated: 2018/09/27 15:39:13 by syamada          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src,
								size_t n);
void				*ft_memccpy(void *dst, const void *src, int c,
									size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src,
								size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_puterr(char c);
void				ft_putstrerr(char *str);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void	const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
int					ft_lstsize(t_list *lst);

void				ft_printlist(t_list *list);
char				*ft_strinit(char *str);
t_list				*ft_samplelist(size_t len);
char				*ft_strrev(char *str);
void				ft_lstpush(t_list **alst, void *content, size_t size);
int					ft_wordcount(char *s, char d);
char				*ft_strjoin_with(char const *s1, char const *s2, char c);
char				*ft_strjoinfree_with(char *s1, char *s2, char c);
char				*ft_strndup(char *str, int i, int n);
char				*ft_charstr(char c);
char				*ft_strappend(char *str, char c);
char				*ft_strprepend(char *str, char c);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strlast(char *str, char c);
int					ft_strchr_i(char *str, char c);
char				*ft_replace(char *str, char *target, char *rep);
void				ft_tdstrdel(char ***tdstr);
int					ft_tdstrnum(char **tdstr);

char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_imaxtoa(intmax_t n);
char				*ft_uimaxtoa_base(uintmax_t n, unsigned int base,
									int is_cap);
char				*ft_sizetoa_base(size_t num, unsigned int base, int is_cap);
char				*ft_itoa_base(int num, int base, int is_cap);
char				*ft_ltoa_base(long num, int base, int is_cap);
char				*ft_lltoa_base(long long num, int base, int is_cap);
char				*ft_uitoa_base(unsigned int num, unsigned int base,
									int is_cap);
char				*ft_ultoa_base(unsigned long num, unsigned int base,
									int is_cap);
char				*ft_ulltoa_base(unsigned long long num,
									unsigned int base, int is_cap);
long				ft_atol(const char *str);

#endif
