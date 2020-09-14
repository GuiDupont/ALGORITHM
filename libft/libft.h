#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef struct	s_list 
{
	void		*content;
	struct s_list	*next;
}		t_list;

char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(char const *s1, int c);
char	*ft_strcpy(char *dest, char const *source);
char	*ft_strdup(char const *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, char const *src, unsigned int nb);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*ft_strnew(int size);
char	*ft_strnstr(char const *s, char const *to_find, unsigned int n);
char	*ft_strrchr(char const *s1, int c);
char	*ft_strstr(char const *s, char const *to_find);
char	*ft_substr(char const *s, unsigned int start, unsigned int len);
char	*ft_strtrim(char const *s, char const *set);
char	*ft_itoa(int n);

char	**ft_split(char const *s, char c);

int	ft_atoi(char const *s);
int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);
int	ft_lstsize(t_list *lst);
int	ft_memcmp(const void *s1, const void *s2, unsigned int n);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strequ(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
int	ft_strnequ(const char *s1, const char *s2, unsigned int n);
int	ft_strlen(const char *s);
int	ft_tolower(int c);
int	ft_toupper(int c);

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);

unsigned int	ft_strlcat(char *dest, const char *src, unsigned int size);	
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);	

void	ft_bzero(void *s, int size);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
void	ft_memdel(void **ap);
void	ft_putchar(char c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);
void	ft_putnbr(int n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(char const *c);
void	ft_putstr_fd(char const *c, int fd);
void	ft_strclr(char *s);
void	ft_strdel(char **as);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

void	*ft_calloc(unsigned int nmemb, unsigned int size);
void	*ft_memalloc(int size);
void	*ft_memccpy(void *dest, const void *src, int c, unsigned int n);
void	*ft_memcpy(void *dest, const void *src, unsigned int n);
void	*ft_memchr(const void *s, int c, unsigned int n);
void	*ft_memmove(void *dest, const void *src, unsigned int n);
void	*ft_memset(void *s, int c, unsigned n);

#endif
