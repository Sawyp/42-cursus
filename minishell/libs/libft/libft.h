/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aronez <aronez@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 23:10:34 by aronez            #+#    #+#             */
/*   Updated: 2022/12/04 23:10:34 by aronez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                             Math Functions                               /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Returns the smallest int.
int			ft_min(int a, int b);
//! @brief Returns the smallest size_t.
size_t		ft_smin(size_t a, size_t b);
//! @brief Returns the smallest long.
long		ft_lmin(long a, long b);
//! @brief Returns the smallest long long.
long long	ft_llmin(long long a, long long b);

//! @brief Returns the largest int.
int			ft_max(int a, int b);
//! @brief Returns the largest size_t.
size_t		ft_smax(size_t a, size_t b);
//! @brief Returns the largest long.
long		ft_lmax(long a, long b);
//! @brief Returns the largest long long.
long long	ft_llmax(long long a, long long b);

//! @brief Returns the absolute value of an int. Returns INT_MAX if n is
//! INT_MIN.
int			ft_abs(int n);
//! @brief Returns the absolute value of a long. Returns LONG_MAX if n is
//! LONG_MIN.
long		ft_labs(long n);
//! @brief Returns the absolute value of a long long. Returns LLONG_MAX if n is
//! LLONG_MIN.
long long	ft_llabs(long long n);

//! @brief Computes the base-10 logarithm of the given number. An input in
//! [-(base-1), base-1] gives 0, etc. The value of base must be more than one.
int			ft_log(long long n, int base);
//! @brief Computes the base-10 logarithm of the given number. An input in
//! [0, base-1] gives 0, etc. The value of base must be more than one.
int			ft_ulog(unsigned long long n, int base);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                             Char Functions                               /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Checks if the given character is an upper-case letter.
int			ft_isupper(int ch);
//! @brief Checks if the given character is a lower-case letter.
int			ft_islower(int ch);
//! @brief Checks if the given character is a letter.
int			ft_isalpha(int ch);

//! @brief Checks if the given character is a digit.
int			ft_isdigit(int ch);
//! @brief Checks if the given character is a hexadecimal digit (lower and
//! upper-case).
int			ft_isxdigit(int ch);

//! @brief Checks if the given character is alphanumeric.
int			ft_isalnum(int ch);
//! @brief Checks if the given character is a control character.
int			ft_iscntrl(int ch);
//! @brief Checks if the given character is a space.
int			ft_isspace(int ch);
//! @brief Checks if the given character is a space or a tab.
int			ft_isblank(int ch);
//! @brief Checks if the given character is a punctuation (!"#$%&'()*+,-./:;<=>?
//! @[\]^_`{|}~) character.
int			ft_ispunct(int ch);

//! @brief Checks if the given character has a graphical representation.
int			ft_isgraph(int ch);
//! @brief Checks if the given character can be displayed.
int			ft_isprint(int ch);

//! @brief Checks if the given character is within the ASCII table.
int			ft_isascii(int ch);

//! @brief Converts the character to upper-case if it is a lower-case letter.
int			ft_toupper(int ch);
//! @brief Converts the character to lower-case if it is an upper-case letter.
int			ft_tolower(int ch);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                    String-Alpha Conversions Functions                    /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Converts the char stream into an integer stored as an int.
int			ft_atoi(const char *str);
//! @brief Converts the char stream into an integer stored as a long.
long		ft_atol(const char *str);
//! @brief Converts the char stream into an integer stored as a long long.
long long	ft_atoll(const char *str);

/**
 * Takes in a string of characters describing an int, and a pointer to where to
 * put the value read from the string. If either is NULL, returns -1.
 * The string can start with an arbitrary amount of spaces (see ft_isspace()).
 * It can then contain an optional sign, either a + or a -.
 * Finally it must contain at least one digit. If scanning following these rules
 * finds no digit, -2 is returned.
 * The scanning stops at the first non-digit character found.
 * The digits are then converted to an int. If it would overflow, -3 is
 * returned. Otherwise 0 is returned and the value is stored in out.
 * In all failure cases the value in out may have been altered.
 * Examples : "   -3eaea2342" is -3, "++3" is invalid (returns -2), "a-43" is
 * invalid (returns -2) and "10000000000000000000000000000" is probably invalid
 * (returns -3).
 * @brief Tries to read an int from a string.
 * @param str A string of characters.
 * @param out A pointer to a writable memory location.
 * @return 0 in case of success, a negative value in case of failure.
 */
int			ft_s_atoi(const char *str, int *out);
/**
 * Takes in a string of characters describing a long, and a pointer to where to
 * put the value read from the string. If either is NULL, returns -1.
 * The string can start with an arbitrary amount of spaces (see ft_isspace()).
 * It can then contain an optional sign, either a + or a -.
 * Finally it must contain at least one digit. If scanning following these rules
 * finds no digit, -2 is returned.
 * The scanning stops at the first non-digit character found.
 * The digits are then converted to a long. If it would overflow, -3 is
 * returned. Otherwise 0 is returned and the value is stored in out.
 * In all failure cases the value in out may have been altered.
 * Examples : "   -3eaea2342" is -3, "++3" is invalid (returns -2), "a-43" is
 * invalid (returns -2) and "100000000000000000000000000000" is probably invalid
 * (returns -3).
 * @brief Tries to read a long from a string.
 * @param str A string of characters.
 * @param out A pointer to a writable memory location.
 * @return 0 in case of success, a negative value in case of failure.
 */
int			ft_s_atol(const char *str, long *out);
/**
 * Takes in a string of characters describing a long long, and a pointer to
 * where to put the value read from the string. If either is NULL, returns -1.
 * The string can start with an arbitrary amount of spaces (see ft_isspace()).
 * It can then contain an optional sign, either a + or a -.
 * Finally it must contain at least one digit. If scanning following these rules
 * finds no digit, -2 is returned.
 * The scanning stops at the first non-digit character found.
 * The digits are then converted to a long long. If they would overflow, -3 is
 * returned. Otherwise 0 is returned and the value is stored in out.
 * In all failure cases the value in out may have been altered.
 * Examples : "   -3eaea2342" is -3, "++3" is invalid (returns -2), "a-43" is
 * invalid (returns -2) and "100000000000000000000000000000" is probably invalid
 * (returns -3).
 * @brief Tries to read a long long from a string.
 * @param str A string of characters.
 * @param out A pointer to a writable memory location.
 * @return 0 in case of success, a negative value in case of failure.
 */
int			ft_s_atoll(const char *str, long long *out);

//! @brief Allocates a null-terminated string containing the base-10 sequence of
//! the digits of n.
char		*ft_itoa(int n);
//! @brief Allocates a null-terminated string containing the base-10 sequence of
//! the digits of n.
char		*ft_lltoa(long long n);
//! @brief Allocates a null-terminated string containing the representation of
//! a number in a given base. If the base contains +, -, several times the same
//! character, or has less than two characters, it is considered invalid and
//! the function returns NULL.
char		*ft_lltoa_base(long long n, const char *base);
//! @brief Allocates a null-terminated string containing the representation of
//! a number in a given base. If the base contains +, -, several times the same
//! character, or has less than two characters, it is considered invalid and
//! the function returns NULL.
char		*ft_ulltoa_base(unsigned long long n, const char *base);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                           String Copy Functions                          /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Copies the contents of src to dest, including the null terminator.
char		*ft_strcpy(char *dest, const char *src);
//! @brief Copies up to count chars from src to dest, stopping at the null
//! terminator.
char		*ft_strncpy(char *dest, const char *src, size_t count);
/**
 * Copies the null-terminated byte string src in the buffer dest of size size.
 * If there is not enough room for the entirety of src (null terminator
 * included) in dest, stops one byte before size and null-terminates.
 * @brief Copies src into the buffer dest of size size.
 * @param dest A buffer of size size.
 * @param src A null-terminated string.
 * @param size The length of dest in bytes.
 * @return Returns the length of the string that should have been created, equal
 * to the length of src.
 */
size_t		ft_strlcpy(char *dest, const char *src, size_t size);
//! @brief Copies the contents of the null-terminated string src into a newly
//! allocated buffer.
char		*ft_strdup(const char *src);
//! @brief Copies up to count characters from the byte string src into  a newly
//! allocated buffer.
char		*ft_strndup(const char *src, size_t count);

//! @brief Appends src to dest, starting at the null terminator at the end of
//! dest.
char		*ft_strcat(char *dest, const char *src);
//! @brief Appends up to count chars from src to dest, starting at the null
//! terminator at the end of dest.
char		*ft_strncat(char *dest, const char *src, size_t count);
/**
 * Appends the null-terminated byte string src to the end of the null-terminated
 * buffer dest of size size. If there is not enough room for the entirety of src
 * (null terminator included) in dest, stops one byte before size and
 * null-terminates. If dest is not null-terminated within size bytes, returns
 * without doing anything, and dest remains as is.
 * @brief Appends src to the buffer dest of size size.
 * @param dest A null-terminated buffer of size size.
 * @param src A null-terminated string.
 * @param size The length of dest in bytes.
 * @return If there is no null terminator within size bytes in dest, returns
 * size. Otherwise returns the length of the string that should have been
 * created, equal to the combined lengths of dest and src.
 */
size_t		ft_strlcat(char *dest, const char *src, size_t size);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                       String Exploration Functions                       /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Counts the number of characters until the first null character.
size_t		ft_strlen(const char *str);
//! @brief Counts the number of characters until the first null character,
//! stopping at count characters.
size_t		ft_strnlen(const char *str, size_t count);
//! @brief Returns an integer, the sign of which corresponding to the difference
//! of the characters that differ in the strings.
int			ft_strcmp(const char *lhs, const char *rhs);
//! @brief Returns an integer the sign of which corresponds to the comparison of
//! the first different characters. The exploration stops at count characters.
int			ft_strncmp(const char *lhs, const char *rhs, size_t count);
/**
 * Finds the first occurrence of ch in the given null-terminated string. If the
 * character is not present, returns NULL. Otherwise returns a pointer to the
 * character occurrence in the string.
 * @brief Finds the first occurrence of a character in a string.
 * @param str A null-terminated string of characters.
 * @param ch A character that must be in the range of the ASCII table.
 * @return NULL if the character is not found, otherwise a pointer into str.
 */
char		*ft_strchr(const char *str, int ch);
/**
 * Finds the first occurrence of ch in the given string, stopping at the first
 * null-terminator or after scanning count characters. If the character was not
 * found, returns NULL. Otherwise returns a pointer to the first occurrence in
 * the string.
 * @brief Finds the first occurrence of a character in a sized string.
 * @param str A byte string of characters.
 * @param ch A character to look for.
 * @param count The maximum number of characters to scan.
 * @return NULL if the character is not found, otherwise a pointer into str.
 */
char		*ft_strnchr(const char *str, int ch, size_t count);
/**
 * Finds the last occurrence of ch in the given null-terminated string. If the
 * character is not present, returns NULL. Otherwise returns a pointer to the
 * character occurrence in the string.
 * @brief Finds the last occurrence of a character in a string.
 * @param str A null-terminated string of characters.
 * @param ch A character that must be in the range of the ASCII table.
 * @return NULL if the character is not found, otherwise a pointer into str.
 */
char		*ft_strrchr(const char *str, int ch);

//! @brief Finds the first occurrence of substr in str, and returns the first
//! matching char's address in str, or NULL if nothing was found.
char		*ft_strstr(const char *str, const char *substr);
//! @brief Finds the first occurrence of substr in the first len bytes of str,
//! and returns the first matching char's address in str, or NULL if nothing was
//! found.
char		*ft_strnstr(const char *str, const char *substr, size_t len);

//! @brief Allocates and fills a null-terminated string containing the results
//! of applying the passed function to the characters in str.
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));
//! @brief Calls the given function on each of the characters in str.
void		ft_striteri(char *str, void (*f)(unsigned int, char *));

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                  String Splitting and Joining Functions                  /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

/**
 * Allocates a string of size len. Copies at most len bytes from of str to this
 * new string starting at start. Stops early if a null-terminator is
 * encountered. Behavior is undefined if start and len are such that the read of
 * str overflows.
 * @brief Creates a substring of str of size len, starting at start.
 * @param str A string from which a substring is extracted.
 * @param start The starting index of the substring's contents.
 * @param len The length of the substring.
 * @return NULL if the allocation fails, otherwise a null-terminated string.
 */
char		*ft_substr(const char *str, size_t start, size_t len);
//! @brief Allocates a new string of the combined size of the null-terminated
//! strings s1 and s2, and fills it with their contents. Returns NULL if the
//! allocation fails.
char		*ft_strjoin(const char *s1, const char *s2);
//! @brief Joins count null-terminated strings together into a single
//! null-terminated string. Returns NULL if the allocation fails.
char		*ft_strsnjoin(const char **strs, size_t count);

//! @brief Allocates a copy of str with the characters in set removed from its
//! beginning and its end.
char		*ft_strtrim(const char *str, const char *set);

//! @brief Allocates and fills a null-terminated array of the substrings in str
//! delimited by the character c and the edges of str. Returns NULL if the
//! allocation fails.
char		**ft_split(const char *str, char c);
//! @brief Frees all pointers in the pointer array until a NULL pointer is
//! encountered, then frees the pointer array itself.
void		ft_free_strs(char **strs);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                     Memory Area Management Functions                     /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Sets the bytes in the buffer b of size len to zero.
void		ft_bzero(void *b, size_t len);
//! @brief Finds the first occurrence of the byte ch in the first count bytes of
//! ptr.
void		*ft_memchr(const void *ptr, int ch, size_t count);
//! @brief Compares the first count bytes in the two buffer, and returns the
//! first non-zero difference.
int			ft_memcmp(const void *lhs, const void *rhs, size_t count);
//! @brief Copies the character ch in the count first unsigned chars in buffer
//! dest.
void		*ft_memset(void *dest, int ch, size_t count);
//! @brief Copies count bytes from buffer src to buffer dest.
void		*ft_memcpy(void *dest, const void *src, size_t count);
//! @brief Copies count bytes from buffer src to buffer dest, which can overlap.
void		*ft_memmove(void *dest, const void *src, size_t count);
//! @brief Exchanges the count bytes pointed to by a and b.
void		ft_memswap(void *a, void *b, size_t count);

//! @brief Allocates memory for num objects of size size and zeros out memory.
void		*ft_calloc(size_t num, size_t size);
//! @brief Allocates size + additional_size of memory, where the size first
//! bytes are copied from mem, and frees mem.
void		*ft_realloc(void *mem, size_t size, size_t additional_size);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                     File Descriptor Output Functions                     /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Writes a char to a file descriptor.
void		ft_putchar_fd(char c, int fd);
//! @brief Writes a null-terminated string to a file descriptor.
void		ft_putstr_fd(const char *str, int fd);
//! @brief Writes a string of maximum length count to a file descriptor.
void		ft_putstrn_fd(const char *str, size_t count, int fd);
//! @brief Writes a null-terminated str and a newline to a file descriptor.
void		ft_putendl_fd(const char *str, int fd);
//! @brief Writes an integer to a file descriptor.
void		ft_putnbr_fd(int n, int fd);
//! @brief Writes an integer to a file descriptor.
void		ft_putllnbr_fd(long long n, int fd);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                              The Holy Printf                             /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

/**
 * Writes the format string to standard output, interpreting all % characters as
 * control character tokens and translating them to their value as given in the
 * variadic parameter list. The supported control characters are :
 * - % : writes %
 * - c : writes a single character
 * - s : writes a null-terminated string
 * - p : writes the pointer's value in hexadecimal, preceded by 0x, or (nil) if
 *       the pointer points to NULL
 * - d, i : writes a signed int
 * - u : writes an unsigned int
 * - x : writes an unsigned int in lower-case hexadecimal
 * - X : writes an unsigned int in upper_case hexadecimal
 * Any other symbol (including \0) following a % is undefined behavior. There
 * must be at least as many variadic arguments as there are control characters,
 * %% excluded.
 * Returns the number of characters printed. If this value exceeds INT_MAX,
 * returns INT_MAX.
 * @brief Writes a formatted string on the standard output.
 * @param format A format string.
 * @param ... A variadic list of values replacing control codes.
 * @return The number of characters printed, capped at INT_MAX.
 */
int			ft_printf(const char *format, ...);

/**
 * Writes the format string to the given open fd, interpreting all % characters
 * as control character tokens and translating them to their value as given in
 * the variadic parameter list. The supported control characters are :
 * - % : writes %
 * - c : writes a single character
 * - s : writes a null-terminated string
 * - p : writes the pointer's value in hexadecimal, preceded by 0x, or (nil) if
 *       the pointer points to NULL
 * - d, i : writes a signed int
 * - u : writes an unsigned int
 * - x : writes an unsigned int in lower-case hexadecimal
 * - X : writes an unsigned int in upper_case hexadecimal
 * Any other symbol (including \0) following a % is undefined behavior. There
 * must be at least as many variadic arguments as there are control characters,
 * %% excluded.
 * Returns the number of characters printed. If this value exceeds INT_MAX,
 * returns INT_MAX. If writing to fd failed, returns -1.
 * @brief Writes a formatted string on the standard output.
 * @param fd An open file descriptor that can be written to.
 * @param format A format string.
 * @param ... A variadic list of values replacing control codes.
 * @return The number of characters printed, capped at INT_MAX.
 */
int			ft_fdprintf(int fd, const char *format, ...);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                               File Reading                               /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

/**
 * Given a file descriptor already opened and only ever read from within this
 * function, returns the next segment of characters ending with a line break or
 * EOF. The line break is included, and the string is null-terminated. The last
 * line of the file may not have a line break at its end.
 * Once the whole file has been read, the function will return NULL. It is
 * undefined behavior to call it again with the same file descriptor. It can
 * then be used to read the contents of another file, or of the same file if it
 * has been closed and re-opened.
 * @brief Reads a file line by line.
 * @param fd A file descriptor to the file to read from.
 * @return Null-terminated strings, including a trailing return line if there is
 * one to include, or NULL if EOF is reached.
 */
char		*ft_get_next_line(int fd);

/*////////////////////////////////////////////////////////////////////////////*/
/*/                                                                          /*/
/*/                                                                          /*/
/*/                              Vectors (oof)                               /*/
/*/                                                                          /*/
/*/                                                                          /*/
/*////////////////////////////////////////////////////////////////////////////*/

//! @brief Models an XD equivalent of std::vector<long>.
typedef struct s_ft_lvec
{
	long	*data;
	size_t	length;
	size_t	capacity;
}	t_ft_lvec;

//! @brief Takes a pointer to a t_ft_lvec, sets its length to 0, its capacity
//! to DEFAULT_NEW_ALLOC_SIZE (10 by default) and allocates data for that
//! amount of elements.
int			ft_lvec_new(t_ft_lvec *lvec);
//! @brief Same as ft_lvec_new, but the initial capacity and allocation size can
//! be passed.
int			ft_lvec_with_capacity(t_ft_lvec *lvec, size_t capacity);
//! @brief Creates dst as a new t_ft_lvec, while setting its length, capacity
//! and data to the contents of src.
int			ft_lvec_clone(const t_ft_lvec *src, t_ft_lvec *dst);
//! @brief Same as clone, but dst is already a valid t_ft_lvec, and its contents
//! are to be replaced by src. If the capacity in dst is enough, no allocation
//! happens.
int			ft_lvec_assign(const t_ft_lvec *src, t_ft_lvec *dst);
//! @brief Deallocates the data pointer.
void		ft_lvec_free(t_ft_lvec *lvec);

//! @brief Returns 1 if the vec contains elem, 0 otherwise.
int			ft_lvec_contains(const t_ft_lvec *lvec, long elem);

//! @brief Appends new_elem to the end of data, incrementing the length by one.
//! Re-allocates if needed.
int			ft_lvec_push_back(t_ft_lvec *lvec, long new_elem);
//! @brief If the length is zero, returns -2. Otherwise drops the last value in
//! data, decrements the length by one and puts the value in prev_back_val.
int			ft_lvec_pop_back(t_ft_lvec *lvec, long *prev_back_val);

//! @brief Models an XD equivalent of std::vector<size_t>.
typedef struct s_ft_svec
{
	size_t	*data;
	size_t	length;
	size_t	capacity;
}	t_ft_svec;

//! @brief Takes a pointer to a t_ft_lvec, sets its length to 0, its capacity
//! to DEFAULT_NEW_ALLOC_SIZE (10 by default) and allocates data for that
//! amount of elements.
int			ft_svec_new(t_ft_svec *svec);
//! @brief Same as ft_lvec_new, but the initial capacity and allocation size can
//! be passed.
int			ft_svec_with_capacity(t_ft_svec *svec, size_t capacity);
//! @brief Creates dst as a new t_ft_lvec, while setting its length, capacity
//! and data to the contents of src.
int			ft_svec_clone(const t_ft_svec *src, t_ft_svec *dst);
//! @brief Same as clone, but dst is already a valid t_ft_lvec, and its contents
//! are to be replaced by src. If the capacity in dst is enough, no allocation
//! happens.
int			ft_svec_assign(const t_ft_svec *src, t_ft_svec *dst);
//! @brief Deallocates the data pointer.
void		ft_svec_free(t_ft_svec *svec);

//! @brief Returns 1 if the vec contains elem, 0 otherwise.
int			ft_svec_contains(const t_ft_svec *svec, size_t elem);

//! @brief Appends new_elem to the end of data, incrementing the length by one.
//! Re-allocates if needed.
int			ft_svec_push_back(t_ft_svec *svec, size_t new_elem);
//! @brief If the length is zero, returns -2. Otherwise drops the last value in
//! data, decrements the length by one and puts the value in prev_back_val.
int			ft_svec_pop_back(t_ft_svec *svec, size_t *prev_back_val);

#endif //LIBFT_H
