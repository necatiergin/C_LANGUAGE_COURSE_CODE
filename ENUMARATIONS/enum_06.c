enum Operation {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,

    OP_COUNT
};

typedef int (*OperationFunc)(int, int);

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
int div_(int a, int b) { return a / b; }

static OperationFunc operations[OP_COUNT] = {
    [OP_ADD] = add,
    [OP_SUB] = sub,
    [OP_MUL] = mul,
    [OP_DIV] = div_
};
