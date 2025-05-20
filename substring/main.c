#include <stdio.h>

char * is_substring(char *haystack, char *needle);

int main() {
    char *haystack = "cacarroca";
    char *needle = "carro";

    printf("Esta eh a string: %s", is_substring(haystack, needle));

    return 0;
}

char * is_substring(char *haystack, char *needle) {
    while (*haystack) {
        char *h = haystack, *n = needle;

        while (*h && *n && *h == *n) {
            h++; n++;
        }
        if (*n == '\0') return needle;

        haystack++;
    }
    return NULL;
}
