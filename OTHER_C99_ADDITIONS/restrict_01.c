//from cppreference.com

void fadd(double a[static restrict 10], const double b[static restrict 10])
{
    for (int i = 0; i < 10; i++) { // loop can be unrolled and reordered
        if (a[i] < 0.0) break;
        a[i] += b[i];
    }
}
