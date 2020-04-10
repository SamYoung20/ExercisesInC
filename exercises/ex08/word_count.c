#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <gmodule.h>
#include <string.h>

void hash_pairs(const char *key, const char *value) {
  g_print("%s: %s\n", key, value);
}

int main(int argc, char** argv) {
    char x[1024]; //max size of word is 1024
    char value[1024];
    FILE *fp;
    int counter;
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
    fp = fopen("moon_chant.txt", "r");
    while (fscanf(fp, " %1023s", x) == 1) {
        if (g_hash_table_lookup(hash, x)) {
            counter = atoi(g_hash_table_lookup(hash, x)); //convert string to int
            counter++;
            sprintf(value, "%d", counter); //convert int back to string
            g_hash_table_insert(hash, g_strdup(x), g_strdup(value)); //insert copy of strings into hash table
            counter = 0;
        }
        else{
          g_hash_table_insert(hash, g_strdup(x), "1"); //initialize with copy of string
        }
    }
    printf("There are %d keys in the hash\n", g_hash_table_size(hash));
    g_hash_table_foreach(hash, (GHFunc)hash_pairs, NULL); // print all the strings
    return 0;

}
