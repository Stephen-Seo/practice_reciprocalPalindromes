#ifndef SUM_OF_RECIPROCALS_OF_PALINDROMES_PALINDROME_GENERATOR_H_
#define SUM_OF_RECIPROCALS_OF_PALINDROMES_PALINDROME_GENERATOR_H_

typedef struct PGeneratorState {
    unsigned long long current;
} PGeneratorState;

PGeneratorState PGenerator_Init();
unsigned long long PGenerator_Next(PGeneratorState *state);

#endif
