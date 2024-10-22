// from cppreference.com

extern int n;
int A[n];            // Error: file scope VLA
extern int (*p2)[n]; // Error: file scope VM
int B[100];          // OK: file-scope array of constant known size
void fvla(int m, int C[m][m]); // OK: prototype-scope VLA
