#include "palindrome_generator.h"

PGeneratorState PGenerator_Init() {
    return (PGeneratorState){0};
}

// TODO needs testing
int PGeneratorInternal_IsPalindrome(unsigned long long n) {
    unsigned int digits = 0;

    for (unsigned long long i = n; i > 0; i /= 10) {
        ++digits;
    }

    if (digits == 0) {
        // invalid state
        return 1;
    }

    // end as in "least signifciant digit end"
    unsigned int end = 0;
    // start as in "most significant digit start"
    unsigned int start = digits - 1;
    unsigned long long temp, temp2, temp3;
    while (end < start) {
        // get end value
        temp = n;
        temp2 = 0;
        while (temp2 < end) {
            ++temp2;
            temp /= 10;
        }
        temp %= 10;

        // get start value
        temp2 = n;
        temp3 = 0;
        while (temp3 < start) {
            ++temp3;
            temp2 /= 10;
        }
        temp2 %= 10;

        // compare
        if (temp != temp2) {
            // mismatch, we now know it's not a palindrome
            return 0;
        } else {
            // matches, cannot yet prove it is a palindrome until convergence
            ++end;
            --start;
        }
    }

    // no mismatches, at this point it has to be a palindrome
    return 1;
}

unsigned long long PGenerator_Next(PGeneratorState *state) {
    do {
        ++state->current;
    } while(!PGeneratorInternal_IsPalindrome(state->current));
    return state->current;
}
