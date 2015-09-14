#include <stdio.h>
#include <string.h>
#include <time.h>

const int MAX = 1000000000 + 7;
const int MAX_SQ_ROOT = 31623;

bool primes[MAX];

void gen_primes()
{
    int i = 0, j = 0;
    clock_t tStart = clock();

    memset(primes, true, sizeof(bool) * MAX);

    primes[0] = false;
    primes[1] = false;
    primes[2] = true;
    for (i = 2 + 2; i < MAX; i += 2) {
        primes[i] = false;
    }
    for (i = 3; i < MAX_SQ_ROOT; i += 2) {
        if (primes[i] == true) {
            //printf("%d\n", i);
            for (j = i + i; j < MAX; j += i)
                if (primes[j] == true)
                    primes[j] = false;
        }
    }
    printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

}

int print_primes()
{
    for (int i = 2; i < MAX; ++i) {
        if (primes[i] == true)
            printf("%d\n", i);
    }
}

int main()
{
    clock_t t = clock();
    gen_primes();
    //print_primes();
    clock_t e = clock();
    printf("Time taken: %.2fs\n", (double)(e - t)/CLOCKS_PER_SEC);
    return 0;
}
