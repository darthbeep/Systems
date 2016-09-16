#include <stdio.h>
#include <math.h>

long thisWorks(long willItWork) {
    long zero = 0;
    for (int i = 1; i <= 20; i++) {
        if (willItWork % i != 0) {
            return zero;
        }
    }
    return willItWork;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long ans = 0;
    for (long i = 1; i < 121645100408832000 && ans == 0; i++) {
        ans = thisWorks( i );
    }
    printf("%ld", ans);
    return 0;
}