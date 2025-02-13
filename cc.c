#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>

typedef struct s_stack
{
    long            nbr;
    long            index;
    struct s_stack *next;
    struct s_stack *prev;
} t_stack;

void ft_error(t_stack **stack)
{
    if (stack && *stack)
    {
        while (*stack)
        {
            t_stack *temp = *stack;
            *stack = (*stack)->next;
            free(temp);
        }
    }
    write(2, "Error\n", 6);
    exit(1);
}

t_stack *ft_lstlast(t_stack *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}

size_t ft_strlen(const char *s)
{
    size_t i = 0;
    while (s[i])
        i++;
    return (i);
}

static int count_words(const char *str, char c)
{
    int i = 0, trigger = 0;
    while (*str)
    {
        if (*str != c && trigger == 0)
        {
            trigger = 1;
            i++;
        }
        else if (*str == c)
            trigger = 0;
        str++;
    }
    return (i);
}

static char *word_dup(const char *str, int start, int finish)
{
    char *word = malloc((finish - start + 1) * sizeof(char));
    int i = 0;
    while (start < finish)
        word[i++] = str[start++];
    word[i] = '\0';
    return (word);
}

char **ft_split(char const *s, char c)
{
    size_t i = 0, j = 0, start = 0;
    char **split = malloc((count_words(s, c) + 1) * sizeof(char *));
    if (!s || !split)
        return (NULL);
    while (i <= ft_strlen(s))
    {
        if (s[i] != c && start == 0)
            start = i;
        else if ((s[i] == c || i == ft_strlen(s)) && start != 0)
        {
            split[j++] = word_dup(s, start, i);
            start = 0;
        }
        i++;
    }
    split[j] = NULL;
    printf("Split result: "); // Debugging print statement
    for (size_t k = 0; k < j; k++)
    {
        printf("%s ", split[k]);
    }
    printf("\n");
    return (split);
}

int ft_isdigit(int c)
{
    return (c >= '0' && c <= '9');
}

t_stack *ft_stack_new(int content)
{
    t_stack *new = malloc(sizeof(t_stack));
    if (!new)
        ft_error(NULL);
    new->nbr = content;
    new->next = NULL;
    new->prev = NULL;
    return (new);
}

void ft_add_back(t_stack **stack, t_stack *stack_new)
{
    t_stack *last;
    if (!stack)
        return;
    if (!*stack)
        *stack = stack_new;
    else
    {
        last = ft_lstlast(*stack);
        last->next = stack_new;
        stack_new->prev = last;
    }
}

int ft_atoi2(const char *str){
    int mod = 1;
    long long int i = 0;
    printf("Processing string: %s\n", str); // Debugging print statement
    while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f' || *str == '\v' || *str == '\r')
        str++;
    if (*str == '-')
    {
        mod = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    while (*str)
    {
        if (!ft_isdigit(*str))
            ft_error(NULL);
        i = i * 10 + (*str - '0');
        str++;
    }
    if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
        ft_error(NULL);
    printf("Converted value: %lld\n", mod * i); // Debugging print statement
    return (mod * i);}

t_stack *ft_sub_process(char **argv)
{
    t_stack *a = NULL;
    char **tmp = ft_split(argv[1], ' ');
    int i = 0;
    while (tmp[i])
    {
        int j = ft_atoi2(tmp[i]);
        printf("Processing value: %d\n", j); // Debugging print statement
        ft_add_back(&a, ft_stack_new(j));
        free(tmp[i]);
        i++;
    }
    free(tmp);
    return (a);
}

t_stack *ft_process(int argc, char **argv)
{
    t_stack *a = NULL;
    int i = 1;
    if (argc < 2)
        ft_error(NULL);
    if (argc == 2)
        a = ft_sub_process(argv);
    else
    {
        while (i < argc)
        {
            int j = ft_atoi2(argv[i]);
            printf("Processing value: %d\n", j); // Debugging print statement
            ft_add_back(&a, ft_stack_new(j));
            i++;
        }
    }
    return (a);
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%ld ", stack->nbr);
        stack = stack->next;
    }
    printf("\n");
}

void ft_free_stack(t_stack **stack)
{
    t_stack *temp;
    while (*stack)
    {
        temp = *stack;
        *stack = (*stack)->next;
        free(temp);
    }
}

int main()
{
    char *arr[] = {"./program", "1 2 3 4 5 6 7 8 9", NULL}; // محاكاة `argv`
    t_stack *a;

    a = ft_process(2, arr);
    if (!a)
    {
        printf("خطأ: `ft_process` أعاد NULL\n");
        return (1);
    }
    printf("المكدس بعد المعالجة: ");
    print_stack(a);
    ft_free_stack(&a);
    return (0);
}
