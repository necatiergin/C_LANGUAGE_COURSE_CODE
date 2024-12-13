#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* key = "MY_VAR";
    const char* value = "HelloWorld";

    // Set the environment variable
    if (setenv(key, value, 1) != 0) {
        perror("setenv failed");
        return 1;
    }

    // Retrieve and print the environment variable
    value = getenv(key);
    if (value) {
        printf("Environment variable %s = %s\n", key, value);
    }
    else {
        printf("Environment variable %s not found\n", key);
    }
}
