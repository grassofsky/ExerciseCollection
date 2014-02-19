/* Calculate the greatest common divisor
 * Euclid's algorithm:
 *   if u is greater than v then the
 *   greatest common divisor of u and v
 *   is the same as the greatest common
 *   divisor of v and u-v
 */

#include <stdio.h>
int gcd(int u, int v, char* a)
{
    int t;

    while (u > 0) {
        if (a) {
            printf("(%d, %d)\t", u, v);
        }
        if (u < v) {
            t = v; v = u; u = t;
        }
        u = u - v;
    }
    return v;
}
