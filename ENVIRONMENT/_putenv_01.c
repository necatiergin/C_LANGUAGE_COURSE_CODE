#include <stdio.h>
#include <stdlib.h>

int main() {
    const char* varName = "MY_VAR";
    const char* varValue = "HelloWindows";

    // Construct the environment string "NAME=VALUE"
    char envString[256];
    snprintf(envString, sizeof(envString), "%s=%s", varName, varValue);

    // Set the environment variable
    if (_putenv(envString) != 0) {
        perror("_putenv failed");
        return 1;
    }

    // Retrieve and print the environment variable
    const char* value = getenv(varName);
    if (value) {
        printf("Environment variable %s = %s\n", varName, value);
    }
    else {
        printf("Environment variable %s not found\n", varName);
    }

    // Remove the environment variable
    snprintf(envString, sizeof(envString), "%s=", varName); // Format "NAME="
    if (_putenv(envString) != 0) {
        perror("_putenv failed to remove variable");
        return 1;
    }

    // Check if it was removed
    value = getenv(varName);
    if (!value) {
        printf("Environment variable %s was successfully removed\n", varName);
    }
    else {
        printf("Environment variable %s still exists\n", varName);
    }

    return 0;
}
