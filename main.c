
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int hash_str(HashTable *h, void *data)
{
    char *str = (char *)data;

    long hash_val = 0;
    int base = 127;

    for (size_t i = 0; i < strlen(str); i++)
        hash_val = (base * hash_val + str[i]) % hash_table_size(h);

    return hash_val;
}

int cmp_str(void *a, void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    HashTable *h = hash_table_construct(10, hash_str, cmp_str);

    hash_table_set(h, "nome", "filipe");
    hash_table_set(h, "idade", "32");
    hash_table_set(h, "altura", "1.96");
    hash_table_set(h, "idade", "33");

    printf("%s\n", (char *)hash_table_get(h, "nome"));
    printf("%s\n", (char *)hash_table_get(h, "idade"));
    printf("%s\n", (char *)hash_table_get(h, "altura"));

    printf("%s\n", (char *)hash_table_pop(h, "nome"));
    printf("%s\n", (char *)hash_table_pop(h, "idade"));
    printf("%s\n", (char *)hash_table_pop(h, "altura"));

    hash_table_destroy(h);

    return 0;
}