#include  "push_swap.h"

int  check_isdigit(char **args)
{
    int i;
    int j;

    i = 0;
    while (args[i])
    {
        j = 0;
        while (args[i][j])
        {   
            if (args[i][j] == '-' || args[i][j] == '+')
            {
                if (!args[i][j + 1] || args[i][j + 1] == '0')
                    return (0);
                j++;
            }
            if (!ft_isdigit(args[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
int  check_duplicate(char **args, int ac)
{
    int i;
    int j;

    i = 0;
    while (i < ac)
    {
        j = i + 1;
        while (j < ac)
        {
            if (ft_strcmp(args[i], args[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
int  check_args_limits(char **args, int ac)
{
    int i;
    long long temp;

    i = 0;
    while (i < ac)
    {
        temp = ft_atol(args[i]);
        if (temp > 2147483647 || temp < -2147483648)
            return (0);
        i++;
     }
    return (1);
}

void check_args(char **args, int ac)
{
    if(!check_isdigit(args))
    {
        free_args(NULL, args);
        print_error(NULL, "Error\n");
    }

    if(check_duplicate(args, ac))
    {
        free_args(NULL, args);
        print_error(NULL, "Error\n");
    }

    if(!check_args_limits(args, ac))
    {
        free_args(NULL, args);
        print_error(NULL, "Error\n");
    }
}
