#include "s21_string.h"
#include <limits.h>
#include <math.h>
#include <stdarg.h>

s21_size_t s21_strlen(const char *str) {
    int lenght = 0;
    for (; *(str+lenght) != '\0'; lenght++) {}
    return lenght;
}

int s21_strcmp(const char *str1, const char *str2) {
    int res = 0;
    for (; res == 0 && (*str1 != '\0' || *str2 != '\0'); str1++, str2++)
        res = (int)*str1 - (int)*str2;
    return res;
}

char* s21_strchr(const char* str, int c) {
    for (; *str != '\0' && *str != c; ++str) {}
    return *str == c ? (char *) str : S21_NULL;
}

char *s21_strrchr(const char *str, int c) {
    char *res = S21_NULL;
    for (s21_size_t i = 0; *(str + i) != '\0'; i++)
        if (*(str + i) == (char)c)
            res = (char *)str + i;
    return res;
}

char *s21_strcpy(char *dest, const char *src) {
    if (src != S21_NULL) {
        *dest = *src;
        while (*src != '\0') *dest++=*src++;
        *dest++ = '\0';
    }
    return dest;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
    int idx = 0;
    while (*(src + idx) != '\0' && idx < (int)n) {
        *(dest + idx) = *(src + idx);
        idx++;
    }
    while (idx < (int)n) {
        *(dest + idx) = '\0';
        idx++;
    }
    return dest;
}

void *s21_memchr(const void *str, int c, s21_size_t n) {
    const unsigned char *res = str;
    int flag = 1;
    for (; res - (unsigned char *)str < (int)n && flag; res++) {
        if (*res == (unsigned char)c) {
            flag = 0;
        }
    }
    res = !flag ? res - 1 : S21_NULL;
    return (void *)res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
    const unsigned char *str_1 = str1;
    const unsigned char *str_2 = str2;
    int res = 0;
    for (s21_size_t idx = 0; idx < n && str_1 != S21_NULL
    && str_2 != S21_NULL && res == 0; idx++, str_1++, str_2++)
        res = (int)*str_1 - (int)*str_2;
    return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
    const unsigned char *str1 = src;
    unsigned char *str2 = dest;
    for (s21_size_t idx = 0; idx < n && str1 != S21_NULL; idx++, str1++, str2++)
        *str2 = *str1;
    return dest;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
    int res = 0;
    for (s21_size_t i = 0; i < n && res == 0 && (*str1 != '\0' || *str2 != '\0'); i++, str1++, str2++)
        res = (int)*str1 - (int)*str2;
    return res;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *res = S21_NULL;
    int flag = 0;
    for (; *str1 != '\0' && !flag; str1++)
        for (s21_size_t i = 0; *(str2 + i) != '\0' && !flag; i++)
            if (*str1 == *(str2 + i)) {
                flag = 1;
                res = (char *)str1;
            }
    return res;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *res = (char *)haystack;
    int flag = 0;
    for (s21_size_t i = 0; *(res + i) != '\0' && !flag; i++)
        for (s21_size_t j = 0; *(res + i + j) == *(needle + j) && !flag; j++)
            if (*(needle + j + 1) == '\0') {
                res += i;
               flag = 1;
            }
    res = flag || *needle == '\0' ? res : S21_NULL;
    return res;
}

char *s21_strtok(char *str, const char *delim) {
    static s21_size_t idx = 0;
    static char mus[1024];
    int flag = 1, null = 1, ft = 0;
    if (str == S21_NULL || str[0] == '\0') {
        if (idx == 0) null = 0;
    } else {
        s21_strcpy(mus, str);
        idx = 0;
        ft = 1;
  }
    s21_size_t tok = s21_strlen(delim), start_idx = idx;
    if (null) {
        while (flag && mus[idx] != '\0') {
                for (s21_size_t i = 0; i < tok; ++i) {
                    if (mus[idx] == delim[i]) {
                            mus[idx] = '\0';
                            flag = 0;
                        }
                }

            ++idx;
        }
    }
    char *answer = mus + start_idx;
    if ((flag == 1 && !ft) || null == 0) answer = S21_NULL;
    return answer;
}

char *s21_strcat(char *dest, const char *src) {
    char *res = dest;
    char *str = (char *)src;
    while (*res != '\0') {
        res++;
    }
    do {
        *res = *str;
        res++;
        str++;
    } while (*str != '\0');
    return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
    char *res = dest;
    int count = 0;
    char *str = (char *)src;
    while (*res != '\0') {
        res++;
    }
    do {
        *res = *str;
        res++;
        str++;
        count++;
    } while (*str != '\0' && count < (int)n);
    return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
    unsigned char *res = str;
    for (s21_size_t idx = 0; idx < n; idx++) {
        *(res + idx) = (unsigned char)c;
    }
    return str;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
    if (dest < src) {
        char *s = (char *)src;
        char *d = (char *)dest;
        for (s21_size_t idx = 0; idx < n; idx++) {
            *(d + idx) = *(s + idx);
        }
    } else {
        char *s = (char *)src + n;
        char *d = (char *)dest + n;
        for (int idx = n - 1; idx >= 0; idx--) {
            *--d = *--s;
        }
    }
    return dest;
}

void s21_reverse(char *str, s21_size_t len) {
    int i = 0, j = (int)len - 1, temp;

    while (i < j) {
        temp = (int)str[i];
        str[i++] = str[j];
        str[j--] = (char)temp;
    }
}

void s21_clear(char* str) {
    for (; *str;) {
        *str = 0;
        str++;
    }
}

char *s21_itoa(long long num) {
    static char buf[30];
    long long tmp = num;
    int i = 0;
    s21_clear(buf);
    if (num == 0) {
        buf[0] = 48;
    }
    while (tmp != 0) {
        if (tmp < 0) {
            buf[i++] = (tmp * (-1) % 10) + 48;
        } else {
            buf[i++] = (tmp % 10) + 48;
        }
        tmp /= 10;
    }
    if (num < 0) {
        buf[i] = 45;
    }
    s21_reverse(buf, s21_strlen(buf));
    return buf;
}

char *s21_strerror(int errnum) {
    static char buf[100];
#ifdef __APPLE__
    if (errnum > -1 && errnum < 107) {
        s21_strcpy(buf, STRERROR_ERRORS[errnum]);
    } else {
        s21_strcpy(buf, "Unknown error: ");
        char *str_num = s21_itoa(errnum);
        s21_strcat(buf, str_num);
        s21_strcat(buf, s21_itoa(errnum));
        buf[s21_strlen("Unknown error: ") + s21_strlen(str_num)] = '\0';
    }
#endif
#ifdef __linux__
    if (errnum > -1 && errnum < 134) {
        s21_strcpy(buf, STRERROR_ERRORS[errnum]);
    } else {
        s21_strcpy(buf, "Unknown error ");
        char *str_num = s21_itoa(errnum);
        s21_strcat(buf, str_num);
        buf[s21_strlen("Unknown error ") + s21_strlen(str_num)] = '\0';
    }
#endif
    return buf;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
    s21_size_t spn = 0, i = 0, j = 0;
    if ((str1 != S21_NULL) || (str2 != S21_NULL)) {
        while (*(str2 + j) != '\0') {
            if (*(str1 + i) == *(str2 + j)) {
                i++;
                j = -1;  // чтобы просмотреть строку сначала
                spn++;
            }
            j++;
        }
    }
    return spn;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
    s21_size_t spn = 0, i = 0, j = 0;
    if (str1 != S21_NULL && str2 != S21_NULL) {
        while (*(str1 + i) != *(str2 + j))
            if (*(str2 + j) == '\0') {
                spn++;
                i++;
                j = 0;
            } else {
                j++;
            }
    }
    return spn;
}


int s21_isdigit(int c) {
    int flag = 1;
    if ((c < 48) || (c > 57))
        flag = 0;
    return flag;
}

int s21_isspace(int c) {
    return c == 32 || (c > 8 && c < 14);
}

int s21_len(long long nb) {
    int len = 0;

    if (nb == 0) {
        len = 1;
    }
    if (nb < 0) {
        nb = nb * -1;
        len++;
    }
    while (nb > 0) {
        nb = nb / 10;
        len++;
    }
    return len;
}

void s21_utoa(unsigned long long num, char *str) {
    int i = 0;

    if (num == 0) {
        str[i++] = 48;
        str[i] = 0;
        return;
    }

    while (num != 0) {
        int rem = num % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 97 : rem + 48;
        num = num / 10;
    }

    str[i] = 0;

    s21_reverse(str, s21_strlen(str));
}

long long s21_pow(int x, unsigned n) {
    long long pow = 1;
    for (unsigned long i = 0; i < n; i++) {
        pow = pow * x;
    }
    return pow;
}

int s21_get_return(unsigned long long ret, int neg, const char *nptr) {
    int count = 0;
    while (*nptr < 48 || *nptr > 57)
        nptr++;
    while (s21_isdigit(*(nptr + count)))
        count++;
    if (count >= 19) {
        return neg == -1 ? 0 : -1;
    }
    if (ret > 9223372036854775807) {
        return neg == -1 ? 0 : -1;
    } else {
        return (int)(ret * neg);
    }
}

int s21_atoi(const char *nptr) {
    unsigned long long ret = 0;
    int len = 0;
    int x = -1;
    int neg = 1;

    while (s21_isspace(*nptr)) {
        nptr++;
    }
    while (nptr[len]) {
        len++;
    }
    while (++x <= len) {
        if (s21_isdigit(nptr[x])) {
            ret = (ret * 10) + (nptr[x] - 48);
        } else if (x == 0 && (nptr[x] == 45 || nptr[x] == 43)) {
            neg = nptr[x] == 45 ? -1 : 1;
        } else {
            return s21_get_return(ret, neg, nptr);
        }
    }
    return s21_get_return(ret, neg, nptr);
}

void s21_ftoa(long double f, char* buf, int precision) {
    char* ptr = buf;
    char* p = ptr;
    char* p1;
    char c;
    long intPart;
    long long temp = 0;

    if (f < 0) {
        f = -f;
        *ptr++ = 45;
    }
    if (precision <= 1) {
        long long aboba = (long long)f;
        long double tmp = f - (long long)f;

        for (int i = 0; i < 16; ++i) {
            tmp *= 10;
            if (i == 0 && (int)tmp == 0) {
                temp = 0;
                break;
            }
            temp += (long long)tmp;
            temp *= 10;
            tmp = tmp - (long long)tmp;
        }
        if ((temp > 50000000000000000 && (aboba%10)%2 == 0) ||
        (temp >= 50000000000000000 && (aboba%10)%2 == 1)) {
            f += 1;
        }
    } else {
        if (precision >= 0) {
            f += 0.5 / (long double)s21_pow(10, precision);
        }
    }

    intPart = (long)f;
    f -= intPart;

    if (!intPart) {
        *ptr++ = 48;
    } else {
        p = ptr;
        while (intPart) {
            *p++ = (char)(intPart % 10 + 48);
            intPart /= 10;
        }
        p1 = p;
        while (p > ptr) {
            c = *--p;
            *p = *ptr;
            *ptr++ = c;
        }
        ptr = p1;
    }
    if (precision) {
        *ptr++ = 46;
        while (precision--) {
            f *= 10.0;
            c = (char)f;
            *ptr++ = (char)(c + 48);
            f -= c;
        }
    }
    *ptr = 0;
}


void s21_putchar(char* str, char c, int len) {
    str[len] = c;
    str[len+1] = 0;
}

int s21_vsprintf(char *str, const char *format, va_list args) {
    int state = 0;
    int is_long = 0;
    int is_zero = 0;
    int is_short = 0;
    int is_positive = 0;
    int is_negative = 0;
    int is_space = 0;
    int afterPoint = -2;
    int beforePoint = 0;
    int length = 0;

    while (*format) {
        if (state == 0) {
            if (*format == 37) {
                if (format[1] == 37) {
                    s21_putchar(str, 37, length);
                    length++;
                    format++;
                    state = 0;
                } else {
                    state = 1;
                }
            } else {
                s21_putchar(str, *format, length);
                length++;
            }
        }
        if (state == 1) {
            if (beforePoint == 0 && (*format == 37 ||
            *format == 45 || *format == 43 || *format == 32)) {
                if (format[1] == 48) {
                    is_zero = 1;
                }
                char tmp[64] = "0";
                int j = 0;
                for (long unsigned int i = 1; i < s21_strlen(format); ++i) {
                    if (s21_isdigit(format[i])) {
                        tmp[j++] = format[i];
                        tmp[j] = 0;
                    } else {
                        beforePoint = s21_atoi(tmp);
                        break;
                    }
                }
            }
            if (afterPoint == -2 && *format == 46) {
                char tmp[64] = "-1";
                int j = 0;
                for (long unsigned int i = 1; i < s21_strlen(format); ++i) {
                    if (s21_isdigit(format[i])) {
                        tmp[j++] = format[i];
                        tmp[j] = 0;
                    } else {
                        afterPoint = s21_atoi(tmp);
                        break;
                    }
                }
            }
            switch (*format) {
                case 108: {
                    is_long = 1;
                    is_short = 0;
                    break;
                }
                case 104: {
                    is_short = 1;
                    is_long = 0;
                    break;
                }
                case 43: {
                    is_positive = 1;
                    break;
                }
                case 45: {
                    is_negative = 1;
                    break;
                }
                case 32: {
                    is_space = 1;
                    break;
                }
                case 99: {
                    char ch = va_arg(args, int);
                    if ((beforePoint - 1) > 0 && !is_negative) {
                        for (int i = beforePoint - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    s21_putchar(str, ch, length);
                    length++;
                    if ((beforePoint - 1) > 0 && is_negative) {
                        for (int i = beforePoint - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    afterPoint = -2;
                    beforePoint = 0;
                    state = 0;
                    break;
                }
                case 100: {
                    long long d;
                    char* buf;
                    if (is_long) {
                        d = va_arg(args, long long);
                        buf = s21_itoa((long long)d);
                    }
                    if (is_short) {
                        d = (short)va_arg(args, int);
                        buf = s21_itoa((short)d);
                    }
                    if (!is_short && !is_long) {
                        d = va_arg(args, int);
                        buf = s21_itoa((int)d);
                    }
                    s21_size_t len = s21_strlen(buf);
                    if ((afterPoint == -1 || afterPoint == 0) && d == 0) {
                        len = 0;
                    }
                    if (afterPoint == -2) {
                        afterPoint = s21_strlen(buf);
                    }
                    int tmp = afterPoint - len;
                    if (!is_negative && !is_positive && is_space) {
                        if (d != 0) {
                            len += 1;
                        }
                        s21_putchar(str, 32, length);
                        length++;
                    } else if (d >= 0 && is_space) {
                        if (d != 0) {
                            len += 1;
                        }
                        s21_putchar(str, 32, length);
                        length++;
                    }
                    if (afterPoint > 0) {
                        if (tmp > 0) {
                            len += tmp;
                        }
                    }
                    if ((beforePoint - len) > 0 && !is_negative && !is_positive) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            if (is_zero) {
                                s21_putchar(str, 48, length);
                                length++;
                            } else {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if ((beforePoint - len - 1) > 0 && !is_negative && is_positive) {
                        for (int i = beforePoint - len - 1; i > 0; i--) {
                            if (is_zero) {
                                s21_putchar(str, 48, length);
                                length++;
                            } else {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (is_positive && d >= 0) {
                        s21_putchar(str, 43, length);
                        length++;
                    }
                    if (tmp > 0) {
                        for (int i = 0; i < tmp; ++i) {
                            s21_putchar(str, 48, length);
                            length++;
                        }
                    }
                    if (len == 0) {
                        s21_putchar(str, 0, length);
                    }
                    for (int i = 0; (long unsigned int)i < len && buf[i]; i++) {
                        s21_putchar(str, buf[i], length);
                        length++;
                    }
                    if ((beforePoint - len) > 0 && is_negative && !is_positive && d < 0) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - len) > 0 && is_negative && !is_positive && d >= 0) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - len - 1) > 0 && is_negative && is_positive && d >= 0) {
                        for (int i = beforePoint - len - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    afterPoint = -2;
                    beforePoint = 0;
                    is_positive = 0;
                    is_space = 0;
                    is_short = 0;
                    is_long = 0;
                    state = 0;
                    break;
                }
                case 105: {
                    long long d = va_arg(args, long long);
                    if (beforePoint == 0) {
                        if (is_space) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    char* buf;
                    if (is_long) {
                        buf = s21_itoa((long long)d);
                    }
                    if (is_short) {
                        buf = s21_itoa((short)d);
                    }
                    if (!is_short && !is_long) {
                        buf = s21_itoa((int)d);
                    }
                    s21_size_t len = s21_strlen(buf);
                    if (afterPoint == -1 && d == 0) {
                        len = 0;
                    }
                    if (afterPoint == -2) {
                        afterPoint = s21_strlen(buf);
                    }
                    int temp = afterPoint - len;
                    if (temp > 0) {
                        len = afterPoint;
                    }
                    if (is_positive && d >= 0) {
                        len += 1;
                    }
                    if ((beforePoint - len) > 0 && !is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            if (is_zero) {
                                s21_putchar(str, 48, length);
                                length++;
                            } else {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (is_positive && d >= 0) {
                        s21_putchar(str, 43, length);
                        length++;
                    }
                    int tmp = afterPoint - s21_strlen(buf);
                    if (tmp > 0) {
                        for (long unsigned int i = 0; i < afterPoint - s21_strlen(buf); ++i) {
                            s21_putchar(str, 48, length);
                            length++;
                        }
                    }
                    for (int i = 0; (long unsigned int)i < len && buf[i]; i++) {
                        s21_putchar(str, buf[i], length);
                        length++;
                    }
                    if (len > 0) {
                        if ((beforePoint - s21_len(d)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - len; i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    } else {
                        if ((beforePoint - s21_len(d)) > 0 && is_negative && !is_positive) {
                            for (int i = beforePoint - s21_len(d); i > 0; i--) {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if ((beforePoint - s21_len(d) - 1) > 0 && is_negative && is_positive && d >= 0) {
                        for (int i = beforePoint - s21_len(d) - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    afterPoint = -2;
                    beforePoint = 0;
                    is_positive = 0;
                    is_space = 0;
                    state = 0;
                    break;
                }
                case 102: {
                    double f = va_arg(args, double);
                    char buf[32];
                    if (afterPoint == -1) {
                        s21_ftoa(f, buf, 0);
                    } else if (afterPoint >= 0) {
                        s21_ftoa(f, buf, afterPoint);
                    } else {
                        s21_ftoa(f, buf, 6);
                    }
                    s21_size_t len = s21_strlen(buf);
                    if ((beforePoint - len) > 0 && !is_negative && !is_positive) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            if (is_zero) {
                                s21_putchar(str, 48, length);
                                length++;
                            } else {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if ((beforePoint - len - 1) > 0 && !is_negative && is_positive) {
                        for (int i = beforePoint - len - 1; i > 0; i--) {
                            if (is_zero) {
                                s21_putchar(str, 48, length);
                                length++;
                            } else {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (beforePoint == 0) {
                        if (f >= 0 && is_space) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if (is_positive && f >= 0) {
                        s21_putchar(str, 43, length);
                        length++;
                    }
                    for (int i = 0; buf[i]; i++) {
                        s21_putchar(str, buf[i], length);
                        length++;
                    }
                    if ((beforePoint - s21_strlen(buf)) > 0 && is_negative && !is_positive) {
                        for (int i = beforePoint - s21_strlen(buf); i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    if ((beforePoint - s21_strlen(buf) - 1) > 0 && is_negative && is_positive && f > 0) {
                        for (int i = beforePoint - s21_strlen(buf) - 1; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    afterPoint = -2;
                    beforePoint = 0;
                    is_positive = 0;
                    is_space = 0;
                    state = 0;
                    break;
                }
                case 115: {
                    const char *s = va_arg(args, const char*);
                    s21_size_t len = s21_strlen(s);

                    if (afterPoint > 0 && (long unsigned int)afterPoint < len) {
                        len -= (s21_strlen(s) - afterPoint);
                    }
                    if (afterPoint == -1) {
                        len = 0;
                    }
                    if (afterPoint == -2) {
                        afterPoint = s21_strlen(s);
                    }
                    if ((beforePoint - len) > 0 && !is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    for (int i = 0; i < afterPoint && s[i]; ++i) {
                        s21_putchar(str, s[i], length);
                        length++;
                    }
                    if ((beforePoint - len) > 0 && is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    afterPoint = -2;
                    beforePoint = 0;
                    is_space = 0;
                    state = 0;
                    break;
                }
                case 117: {
                    unsigned long long u = va_arg(args, unsigned int);
                    char buf[32];
                    if (is_long) {
                        s21_utoa((unsigned long long)u, buf);
                    }
                    if (is_short) {
                        s21_utoa((unsigned short)u, buf);
                    }
                    if (!is_short && !is_long) {
                        s21_utoa((unsigned int)u, buf);
                    }
                    s21_size_t len = s21_strlen(buf);
                    int tmp = afterPoint - len;
                    if (tmp > 0) {
                        len += tmp;
                    }
                    if (afterPoint == 0 && u == 0) {
                        len = 0;
                    }
                    if (afterPoint == -1 && u == 0) {
                        len = 0;
                    }
                    if (afterPoint == -2) {
                        afterPoint = s21_strlen(buf);
                    }
                    if ((beforePoint - len) > 0 && !is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            if (is_zero) {
                                s21_putchar(str, 48, length);
                                length++;
                            } else {
                                s21_putchar(str, 32, length);
                                length++;
                            }
                        }
                    }
                    if (tmp > 0) {
                        for (long unsigned int i = 0; i < afterPoint - s21_strlen(buf); ++i) {
                            s21_putchar(str, 48, length);
                            length++;
                        }
                    }
                    for (int i = 0; (long unsigned int)i < len && buf[i]; i++) {
                        s21_putchar(str, buf[i], length);
                        length++;
                    }
                    if ((beforePoint - len) > 0 && is_negative) {
                        for (int i = beforePoint - len; i > 0; i--) {
                            s21_putchar(str, 32, length);
                            length++;
                        }
                    }
                    is_negative = 0;
                    beforePoint = 0;
                    afterPoint = -2;
                    is_positive = 0;
                    is_space = 0;
                    is_short = 0;
                    is_long = 0;
                    state = 0;
                    break;
                }
            }
        }
        format++;
    }
    return length;
}

int s21_sprintf(char *stream, const char *format, ...) {
    va_list args;
    va_start(args, format);
    stream[0] = 0;
    int len = s21_vsprintf(stream, format, args);
    va_end(args);
    return len;
}


void *s21_to_upper(const char* str) {
    char *buf = S21_NULL;
    if (str) {
        s21_size_t len = s21_strlen(str);
        buf = (char *)calloc(len, sizeof(char));
        if (buf != S21_NULL) {
            for (s21_size_t i = 0; i < len; i++) {
                if (str[i] >= 97 && str[i] <= 122) {
                    buf[i] = str[i] - 32;
                } else {
                    buf[i] = str[i];
                }
            }
        }
    }
    return buf;
}

void *s21_to_lower(const char* str) {
    char *buf = S21_NULL;
    if (str) {
        s21_size_t len = s21_strlen(str);
        buf = (char *)calloc(len, sizeof(char));
        if (buf != S21_NULL) {
            for (s21_size_t i = 0; i < len; i++) {
                if (str[i] >= 65 && str[i] <= 90) {
                    buf[i] = str[i] + 32;
                } else {
                    buf[i] = str[i];
                }
            }
        }
    }
    return buf;
}

void *s21_insert(const char* src, const char* str, s21_size_t start_index) {
    if (src == S21_NULL || str == S21_NULL) {
        return S21_NULL;
    }
    s21_size_t len = s21_strlen(src) + s21_strlen(str);
    void *buf = S21_NULL;
    if (start_index <= len) {
        buf = (char*)calloc(len + 1, sizeof(char));
        s21_strncpy(buf, src, start_index);
        s21_strcat(buf, str);
        s21_strcat(buf, src + start_index);
    }
    return buf;
}

void *s21_trim(const char* src, const char* trim_chars) {
    if (src == S21_NULL) {
        return S21_NULL;
    }
    char *trim_default = " \n\t\v\f\r";
    char *trim_chars_real = (char*)trim_chars;
    if (trim_chars == S21_NULL || *trim_chars == 0) {
        trim_chars_real = trim_default;
    }
    s21_size_t left_align = s21_strspn(src, trim_chars_real);
    char *buffer = (char*)calloc(s21_strlen(src + left_align) + 1, sizeof(char));
    s21_strcpy(buffer, src + left_align);
    s21_reverse(buffer, s21_strlen(buffer));
    s21_size_t right_align = s21_strspn(buffer, trim_chars_real);
    free(buffer);
    s21_size_t len = s21_strlen(src) - left_align - right_align;
    void *buf = (char*)calloc(len + 1, sizeof(char));
    s21_strncpy(buf, src + left_align, len);
    return buf;
}
