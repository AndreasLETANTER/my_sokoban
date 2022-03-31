/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** strncmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i != n) {
        i++;
    }
    return (s1[i] - s2[i]);
}
