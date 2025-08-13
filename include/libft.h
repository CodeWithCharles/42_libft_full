/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpoulain <cpoulain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 18:31:31 by cpoulain          #+#    #+#             */
/*   Updated: 2025/08/13 14:23:59 by cpoulain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* ========================================================================= */
/*                                TYPEDEFS                                   */
/* ========================================================================= */

/** @brief Unsigned byte type. */
typedef unsigned char	t_byte;

/** @brief Singly linked list structure. */
typedef struct s_list
{
	void			*content; /**< Pointer to content. */
	struct s_list	*next;    /**< Pointer to next element. */
}					t_list;

/**
 * @brief Comparator function type for sorting/comparison functions.
 * @param a Pointer to first element.
 * @param b Pointer to second element.
 * @return Negative, zero, or positive depending on order.
 */
typedef int	(*t_comparator)(void *a, void *b);

/* ========================================================================= */
/*                             CHARACTER CHECKS                              */
/* ========================================================================= */

/**
 * @brief Check if a character is alphabetic.
 */
int		ft_isalpha(
			int c
		);

/**
 * @brief Check if a character is a digit.
 */
int		ft_isdigit(
			int c
		);

/**
 * @brief Check if a character is alphanumeric.
 */
int		ft_isalnum(
			int c
		);

/**
 * @brief Check if a character is ASCII.
 */
int		ft_isascii(
			int c
		);

/**
 * @brief Check if a character is printable.
 */
int		ft_isprint(
			int c
		);

/**
 * @brief Check if a character is whitespace.
 */
int		ft_isspace(
			const char c
		);

/**
 * @brief Convert lowercase to uppercase.
 */
int		ft_toupper(
			int c
		);

/**
 * @brief Convert uppercase to lowercase.
 */
int		ft_tolower(
			int c
		);

/* ========================================================================= */
/*                             STRING FUNCTIONS                              */
/* ========================================================================= */

/**
 * @brief Get the length of a string.
 */
size_t	ft_strlen(
			const char *s
		);

/**
 * @brief Locate first occurrence of a character in a string.
 */
char	*ft_strchr(
			const char *s,
			int c
		);

/**
 * @brief Locate last occurrence of a character in a string.
 */
char	*ft_strrchr(
			const char *s,
			int c
		);

/**
 * @brief Compare two strings up to n characters.
 */
int		ft_strncmp(
			const char *s1,
			const char *s2,
			size_t n
		);

/**
 * @brief Compare two strings.
 */
int		ft_strcmp(
			const char *s1,
			const char *s2
		);

/**
 * @brief Copy string to destination buffer.
 */
size_t	ft_strlcpy(
			char *dst,
			const char *src,
			size_t size
		);

/**
 * @brief Concatenate string to destination buffer.
 */
size_t	ft_strlcat(
			char *dst,
			const char *src,
			size_t size
		);

/**
 * @brief Locate substring within length limit.
 */
char	*ft_strnstr(
			const char *big,
			const char *little,
			size_t len
		);

/**
 * @brief Duplicate a string.
 */
char	*ft_strdup(
			const char *s
		);

/**
 * @brief Duplicate n characters of a string.
 */
char	*ft_strndup(
			const char *s,
			size_t n
		);

/**
 * @brief Concatenate string to another using pointer.
 */
void	ft_strcat(
			char **dst_ptr,
			const char *src
		);

/**
 * @brief Extract substring from a string.
 */
char	*ft_substr(
			const char *s,
			unsigned int start,
			size_t len
		);

/**
 * @brief Join two strings.
 */
char	*ft_strjoin(
			const char *s1,
			const char *s2
		);

/**
 * @brief Trim characters from start and end of string.
 */
char	*ft_strtrim(
			const char *s1,
			char const *set
		);

/**
 * @brief Split string by delimiter into array.
 */
char	**ft_split(
			char const *s,
			char c
		);

/**
 * @brief Free a split string array.
 */
void	ft_free_split(
			char ***split
		);

/**
 * @brief Map function over string, returning new string.
 */
char	*ft_strmapi(
			const char *s,
			char (*f)(unsigned int, char)
		);

/**
 * @brief Apply function to each character of string (in place).
 */
void	ft_striteri(
			char *s,
			void (*f)(unsigned int, char*)
		);

/* ========================================================================= */
/*                              MEMORY FUNCTIONS                             */
/* ========================================================================= */

/**
 * @brief Fill memory with a constant byte.
 */
void	*ft_memset(
			void *s,
			int c,
			size_t n
		);

/**
 * @brief Zero memory.
 */
void	ft_bzero(
			void *s,
			size_t n
		);

/**
 * @brief Copy memory.
 */
void	*ft_memcpy(
			void *dest,
			const void *src,
			size_t n
		);

/**
 * @brief Move memory (handles overlap).
 */
void	*ft_memmove(
			void *dest,
			const void *src,
			size_t n
		);

/**
 * @brief Locate byte in memory.
 */
void	*ft_memchr(
			const void *s,
			int c,
			size_t n
		);

/**
 * @brief Compare memory blocks.
 */
int		ft_memcmp(
			const void *s1,
			const void *s2,
			size_t n
		);

/**
 * @brief Swap two memory blocks.
 */
void	ft_memswap(
			void *_a,
			void *_b,
			size_t n
		);

/**
 * @brief Allocate zero-initialized memory.
 */
void	*ft_calloc(
			size_t nmemb,
			size_t size
		);

/**
 * @brief Reallocate array with size tracking.
 */
void	*ft_reallocarray(
			void *ptr,
			size_t nmemb,
			size_t size,
			size_t old_nmemb
		);

/* ========================================================================= */
/*                           CONVERSION FUNCTIONS                            */
/* ========================================================================= */

/**
 * @brief Convert string to integer.
 */
int		ft_atoi(
			const char *nptr
		);

/**
 * @brief Convert string to integer using custom base.
 */
int		ft_atoi_base(
			const char *str,
			int base
		);

/**
 * @brief Convert integer to string.
 */
char	*ft_itoa(
			int n
		);

/**
 * @brief Convert double to string with precision.
 */
char	*ft_dtoa(
			double value,
			int precision
		);

/* ========================================================================= */
/*                              OUTPUT FUNCTIONS                             */
/* ========================================================================= */

/**
 * @brief Write character to file descriptor.
 */
void	ft_putchar_fd(
			char c,
			int fd
		);

/**
 * @brief Write string to file descriptor.
 */
void	ft_putstr_fd(
			char *s,
			int fd
		);

/**
 * @brief Write string followed by newline to file descriptor.
 */
void	ft_putendl_fd(
			char *s,
			int fd
		);

/**
 * @brief Write integer to file descriptor.
 */
void	ft_putnbr_fd(
			int n,
			int fd
		);

/**
 * @brief Write character multiple times to file descriptor.
 */
void	ft_putnchr_fd(
			int fd,
			char c,
			int count
		);

/* ========================================================================= */
/*                            UTILITY FUNCTIONS                              */
/* ========================================================================= */

/**
 * @brief Return the maximum of two integers.
 */
int		max(
			int a,
			int b
		);

/**
 * @brief Return the minimum of two integers.
 */
int		min(
			int a,
			int b
		);

/**
 * @brief Resolve relative path to absolute.
 */
char	*ft_realpath(
			const char *relative_path
		);

/* ========================================================================= */
/*                               ALGORITHMS                                  */
/* ========================================================================= */

/**
 * @brief Quick sort implementation.
 */
void	ft_qsort(
			void *base,
			size_t nmemb,
			size_t size,
			t_comparator cmp
		);

/* ========================================================================= */
/*                           FILE I/O FUNCTIONS                              */
/* ========================================================================= */

/**
 * @brief Read a line from a file descriptor.
 */
char	*get_next_line(
			int fd
		);

/* ========================================================================= */
/*                              FT_PRINTF                                    */
/* ========================================================================= */

/**
 * @brief Print formatted output to stdout.
 */
int		ft_printf(
			const char *fmt,
			...
		);

/**
 * @brief Print formatted output to a file descriptor.
 */
int		fd_printf(
			int fd,
			const char *fmt,
			...
		);

/**
 * @brief Print formatted output to file descriptor using va_list.
 */
int		ft_printf_base(
			const int fd,
			const char *fmt,
			va_list *args
		);

/* ========================================================================= */
/*                            LINKED LIST BONUS                              */
/* ========================================================================= */

/**
 * @brief Create new list node.
 */
t_list	*ft_lstnew(
			void *content
		);

/**
 * @brief Add node to front of list.
 */
void	ft_lstadd_front(
			t_list **lst,
			t_list *new
		);

/**
 * @brief Add node to back of list.
 */
void	ft_lstadd_back(
			t_list **lst,
			t_list *new
		);

/**
 * @brief Get last node of list.
 */
t_list	*ft_lstlast(
			t_list *lst
		);

/**
 * @brief Get size of list.
 */
int		ft_lstsize(
			t_list *lst
		);

/**
 * @brief Delete one node.
 */
void	ft_lstdelone(
			t_list *lst,
			void (*del)(void *)
		);

/**
 * @brief Clear and free list.
 */
void	ft_lstclear(
			t_list **lst,
			void (*del)(void *)
		);

/**
 * @brief Apply function to each node.
 */
void	ft_lstiter(
			t_list *lst,
			void (*f)(void *)
		);

/**
 * @brief Map function to list, creating new list.
 */
t_list	*ft_lstmap(
			t_list *lst,
			void *(*f)(void *),
			void (*del)(void *)
		);

/**
 * @brief Remove node(s) from list using free function.
 */
void	ft_lstremove(
			t_list **lst,
			void (*del)()
		);

#endif /* LIBFT_H */
