#include "push_swap.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}
char *ft_strjoin(char *s1, char *s2)
{
    char *str;
    int i;
    int j;

    if (!s1)
        s1 = "";
    i = 0;
    j = 0;
    str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }

    while (s2[j])
        str[i++] = s2[j++];
    str[i] = '\0';
    return (str);
}
long ft_atol(const char *str)
{
	long long	result;
	int	sign;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		str++;
	}
	return (result * sign);
}
void bublesort(int *arr, int len)
{
    int i;
    int tmp;

    while (len > 1)
    {
        i = 0;
        while (i < len - 1)
        {
            if (arr[i] > arr[i + 1])
            {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;           
            }
            i++;
        }
        len--;
    }
}
