#include "minunit.h"
#include "util.h"


socklen_t salen = 20;
struct sockaddr_in  sa1;      /* IPv4 socket address structure */
struct sockaddr_in  sa2;
/* fill in serv{} */

int tests_run = 0;

static char *test1() {
	bind(2, (struct sockaddr *) &sa1, sizeof(sa1));
	bind(2, (struct sockaddr *) &sa2, sizeof(sa2));
	sa1.sin_family = AF_INET;
	sa2.sin_family = AF_UNIX;
    int res = sock_cmp_addr((struct sockaddr *)&sa1,(struct sockaddr *)&sa2, salen);
    char *message = "test1 failed: sock_cmp_addr should not return 0 (families not the same)";
    mu_assert(message, res != 0);
    return NULL;
}

static char *test2() {
	bind(2, (struct sockaddr *) &sa1, sizeof(sa1));
	bind(2, (struct sockaddr *) &sa2, sizeof(sa2));
	sa1.sin_family = AF_INET;
	sa2.sin_family = AF_INET;
    int res = sock_cmp_addr((struct sockaddr *)&sa1,(struct sockaddr *)&sa2, salen);
    char *message = "test2 failed: sock_cmp_addr should return 0 (families the same)";
    mu_assert(message, res == 0);
    return NULL;
}

static char * all_tests() {
    mu_run_test(test1);
    mu_run_test(test2);
    return NULL;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != NULL) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}