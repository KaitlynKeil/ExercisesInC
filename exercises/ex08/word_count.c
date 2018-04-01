#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gprintf.h>

int word_split(const gchar *text, gchar **split) {
	split = g_strsplit(text, " ", -1);
	return 0;
}

int make_hist(gchar **split, GHashTable *hist) {
	while(*split) {
		gpointer word = *split;

		if(g_hash_table_contains(hist, word)) {
			gpointer val = g_hash_table_lookup(hist, word);
			g_hash_table_insert(hist, word, val + 1);
		}
		else {g_hash_table_insert(hist, word, (gpointer) 1);}
		split++;
	}
	return 0;
}

int print_hist(GHashTable *hist) {
	GHashTableIter iter;
	gpointer key, value;
	puts("Word           \tCount");
	g_hash_table_iter_init (&iter, hist);
	while (g_hash_table_iter_next (&iter, &key, &value))
		{
			printf("%15s:%5d\n", (gchar*) key, (gint*) value);
		}
	return 0;
}

int main(int argc, char** argv) {
	GMappedFile *file = g_mapped_file_new(argv[1], FALSE, NULL);
	gsize len = g_mapped_file_get_length(file);
	gchar *text = g_mapped_file_get_contents(file);
	GHashTable *hist = g_hash_table_new(g_str_hash, g_str_equal);
	gchar **split = g_strsplit(text, " ", -1);
	int mh_succ = make_hist(split, hist);
	if(mh_succ){printf("Error making histogram, returned %d\n", mh_succ);}
	int ph_succ = print_hist(hist);
    return 0;
}