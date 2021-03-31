#include <iostream>

using namespace std;

//Calculate 1!+2!+...+n!
//Due to considerable result, must use array to get it done.

const int N = 50;

const int array_length = 66;
// Approximately how long 50! needs, precisely = log(n!)

void plus(int sum[], const int a[]) {
    // sum += a
    for (int i = 0; i < array_length - 1; ++i) {
        sum[i] += a[i];
        if (sum[i] >= 10) {
            sum[i] -= 10;
            sum[i + 1] += 1;
        }
    }
}

void multiply(int a[], int times) {
    // a *= times
    for (int i = 0; i < array_length - 1; ++i) {
        a[i] *= times;
    }
    for (int i = 0; i < array_length - 1; ++i) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
}

void print(const int a[], int which) {
    // Show result of an array
    int i = array_length - 1;
    if (which != -1)
        cout << which << "! == ";
    for (; i >= 0; --i)
        if (a[i] != 0)
            break;
    for (; i >= 0; --i)
        cout << a[i];
    cout << "\n";
}

int main() {
    int a[array_length] = {0};
    int sum[array_length] = {0};
    a[0] = 1;
    for (int i = 1; i <= N; ++i) {
        multiply(a, i);
        print(a, i);
        ::plus(sum, a);
    }
    cout << "\nResult: \n1!+2!+...+" << N << "! == \n";
    print(sum, -1);//-1 means doesn't need to print prefix
}