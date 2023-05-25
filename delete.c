#include <stdio.h>
int recursiveTest(int n) {
if (n == 0) {
return 0;
} else {
return n + recursiveTest(n - 1);
}
}

int main() {
int num = 5;
int result = recursiveTest(num);
printf("Result of %d is: %d\n", num, result);
return 0;
}
// the above code adds the first n numbers