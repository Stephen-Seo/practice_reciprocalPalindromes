#include <stdlib.h>
#include <stdio.h>

#include "palindrome_generator.h"

#define LIMIT 128

// expects a const char* for "msg"
#define LOG(msg) do { \
        printf("%s:%u %s\n", __FILE__, __LINE__, msg); \
    } while (0);

int main(int argc, char **argv) {
    unsigned long long limit = LIMIT;

    if (argc == 1) {
        // do nothing
    } else if (argc == 2) {
        limit = strtoull(argv[1], NULL, 10);
        if (limit == 0) {
            LOG("ERROR: Failed to parse arg into unsigned long long");
            return 1;
        }
    } else {
        LOG("ERROR: Program requires one integer as its only argument, or no "
            "args");
        return 2;
    }

    printf("Generating sum of reciprocals of palindromes with \"limit\" of "
            "%llu\n",
        limit);

    double sum = 0.0;
    PGeneratorState state = PGenerator_Init();

    while(limit > 0) {
        --limit;
        sum += 1.0 / (double)(PGenerator_Next(&state));
    }

    printf("Resulting sum == %.16lf, last state is %llu\n", sum, state.current);

    return 0;
}
