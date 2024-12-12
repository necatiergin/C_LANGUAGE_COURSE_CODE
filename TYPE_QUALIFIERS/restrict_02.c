
double g;
    
void foo(void);

int main()
{
    double *dp = &g;
    double sum = 0.;

    for (int i = 0; i < 100; ++i) {
        sum += *dp;
        foo(); //foo may change *dp
    }
    
    //
}
