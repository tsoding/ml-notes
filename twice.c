#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
};
#define train_count (sizeof(train)/sizeof(train[0]))

float rand_float(void)
{
    return (float) rand()/ (float) RAND_MAX;
}

// x1, x2, x3, ..., b
// w1, w2, w3, ...
// y = x1*w1 + x2*w2 + x3*w3 + ... + b

float cost(float w, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i) {
        float x = train[i][0];
        float y = x*w + b;
        float d = y - train[i][1];
        result += d*d;
    }
    result /= train_count;
    return result;
}

int main()
{
    srand(time(0));
    float w = rand_float()*10.0f;
    float b = rand_float()*5.0f;

    float eps = 1e-3;
    float rate = 1e-3;

    printf("%f\n", cost(w, b));
    for (size_t i = 0; i < 500; ++i) {
        float c = cost(w, b);
        float dw = (cost(w + eps, b) - c)/eps;
        float db = (cost(w, b + eps) - c)/eps;
        w -= rate*dw;
        b -= rate*db;
        printf("cost = %f, w = %f, b = %f\n", cost(w, b), w, b);
    }

    printf("------------------------------\n");
    printf("w = %f, b = %f\n", w, b);

    return 0;
}
