/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vparis <vparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/02 22:22:13 by vparis            #+#    #+#             */
/*   Updated: 2017/12/21 17:57:26 by vparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

/*
** Own defines of stdlibs
*/

# if !defined(SUCCESS) && !defined(ERROR)
#  define SUCCESS			(0)
#  define ERROR				(-1)
# endif

# ifndef NULL
#  define NULL				((void *)0)
# endif

# define STDIN				STDIN_FILENO
# define STDOUT				STDOUT_FILENO
# define STDERR				STDERR_FILENO

# define NULL_STR			"(null)"

/*
** Common charsets, and some usefull constants
*/

# define CHARSET_DIGIT		"0123456789"
# define CHARSET_LALPHA		"abcdefghijklmnopqrstuvwxyz"
# define CHARSET_UALPHA		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# define CHARSET_SPACE		" \t\n\v\r\f"
# define CHARSET_BASE_2		"01"
# define CHARSET_BASE_8		"01234567"
# define CHARSET_BASE_10	"0123456789"
# define CHARSET_BASE_16L	"0123456789abcdef"
# define CHARSET_BASE_16U	"0123456789ABCDEF"
# define CHARSET_BASE_16	"0123456789abcdefABCDEF"
# if !defined(INT_MIN) && !defined(INT_MAX)
#  define INT_MIN			(-INT_MAX -1)
#  define INT_MAX			(+2147483647)
# endif
# if !defined(INT64_MIN) && !defined(INT64_MAX)
#  define INT64_MIN			(-INT64_MAX -1L)
#  define INT64_MAX			(+9223372036854775807L)
# endif

/*
** Own types
*/

typedef void				t_void;
typedef char				t_i8;
typedef unsigned char		t_u8;
typedef unsigned short		t_u16;
typedef short				t_i16;
typedef int					t_i32;
typedef unsigned int		t_u32;
typedef long int			t_i64;
typedef unsigned long int	t_u64;
typedef float				t_f32;
typedef double				t_f64;
typedef enum				e_bool
{
	FALSE, TRUE
}							t_bool;

/*
** Maths, 32bits AND 64bits routines TODO
*/

# define ZERO_INT			(0)
# define ZERO_FLOAT			(0.0)
# ifndef PI
#  define PI				(3.141592653589793)
# endif

t_u32				ft_abs(t_i32 n);
t_i32				ft_min(t_i32 a, t_i32 b);
t_i32				ft_max(t_i32 a, t_i32 b);
t_i32				ft_min3(t_i32 a, t_i32 b, t_i32 c);
t_i32				ft_max3(t_i32 a, t_i32 b, t_i32 c);
t_u32				ft_factorial(t_u32 n);
t_u32				ft_fibonacci(t_u32 n);
t_i32				ft_power(t_i32 n, t_i32 power);
t_u32				ft_sqrt(t_u32 n);
int					ft_isprime(t_u32 n);
t_u32				ft_find_next_prime(t_u32 n);

/*
** Lists
*/

typedef struct		s_list {
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstshift(t_list **lst, void (*del)(void *, size_t));
void				ft_lstdel_raw(void *data, size_t size);

/*
** Input
*/

# define BUFF_SIZE			(1024)

typedef	struct		s_fd_l {
	struct s_fd_l	*next;
	struct s_fd_l	*previous;
	t_list			*data;
	ssize_t			pos;
	int				fd;
}					t_fd_list;

int					ft_gnl(int const fd, char **line);

/*
** Memory manipulation
*/

void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memalloc_fast(size_t size);
void				*ft_memchr_fast(const void *s, int c);
void				*ft_memccpy_fast(void *dest, const void *src, int c);
void				*ft_memrealloc(void *src, size_t old, size_t size);
void				*ft_memrealloc_fast(void *src, size_t old, size_t size);

/*
** String manipulation
*/

size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t size);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_strrev(char *s);
char				*ft_strcat2(char *dest, const char *src1, const char *src2);
char				*ft_strnew_fast(size_t size);
char				**ft_strsplit_whitespaces(char const *s);
char				**ft_strsplit_str(char const *s, char const *charset);

/*
** Number/String conversion
*/

int					ft_atoi(const char *nptr);
char				*ft_itoa(int n);
int					ft_atoi_base(char const *nptr, char const *base);

/*
** ASCII Characters checking
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isxdigit(int c);
int					ft_isspace(int c);
int					ft_isblank(int c);
int					ft_ispunct(int c);
int					ft_iscntrl(int c);
int					ft_isgraph(int c);
int					ft_ischarset(int c, char const *charset);

/*
** Outputs
*/

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd_fast(char const *s, int fd);
void				ft_putendl_fd_fast(char const *s, int fd);
void				ft_putrevendl(char const *s);
void				ft_putrevendl_fd(char const *s, int fd);
void				ft_putrevstr(char const *s);
void				ft_putrevstr_fd(char const *s, int fd);
void				ft_putchar_nonprint(char c);
void				ft_putchar_nonprint_fd(char c, int fd);
void				ft_putstr_nonprint(char const *s);
void				ft_putstr_nonprint_fd(char const *s, int fd);

#endif
