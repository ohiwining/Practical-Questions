#include <iostream>

using namespace std;

//Calculate 1!+2!+...+50!
//Due to considerable result, must use array to get it done.

const int N = 50;

void plus(int sum[], const int a[]) {
    // sum += a
    for (int i = 0; i < 65; ++i) {
        sum[i] += a[i];
        if (sum[i] >= 10) {
            sum[i] -= 10;
            sum[i + 1] += 1;
        }
    }
}

void multiply(int a[], int times) {
    // a *= times
    for (int i = 0; i < 65; ++i) {
        a[i] *= times;
    }
    for (int i = 0; i < 65; ++i) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
}

void print(const int a[], int which) {
    // Show result of an array
    int i = 65;
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
    int a[66] = {0};
    int sum[66] = {0};
    a[0] = 1;
    for (int i = 1; i <= N; ++i) {
        multiply(a, i);
        print(a, i);
        ::plus(sum, a);
    }
    cout << "\nResult == \n";
    print(sum, -1);//-1 means doesn't need prefix
}