#include <iostream>
#include <iomanip>

using namespace std;

void PrintArray(const int* a, const int size, int i);
int SumOfSquares(const int* a, const int size, int i);

template <typename T>
void PrintArray(const T* a, const int size, int i);

template <typename T>
T SumOfSquares(const T* a, const int size, int i);

int main()
{
    cout << "=== PROJECT 2: RECURSIVE METHOD ===\n" << endl;

    const int n = 5;
    int a[n] = { 2, -3, 5, 0, 4 };

    cout << "Array A (int): ";
    PrintArray(a, n, 0);
    cout << endl;

    int s1 = SumOfSquares(a, n, 0);
    cout << "Sum of squares (int function): " << s1 << endl;
    cout << "-----------------------------------" << endl;

    const int m = 5;
    double b[m] = { 1.5, 2.0, -1.5, 3.0, 0.5 };

    cout << "Array B (double): ";
    PrintArray(b, m, 0);
    cout << endl;

    double s2 = SumOfSquares(b, m, 0);
    cout << "Sum of squares (template function): " << s2 << endl;

    return 0;
}

void PrintArray(const int* a, const int size, int i)
{
    if (i < size)
    {
        if (i == 0) cout << "[ ";
        cout << setw(4) << a[i];
        PrintArray(a, size, i + 1);
    }
    else
    {
        cout << " ]";
    }
}

int SumOfSquares(const int* a, const int size, int i)
{
    if (i < size)
        return (a[i] * a[i]) + SumOfSquares(a, size, i + 1);
    else
        return 0;
}

template <typename T>
void PrintArray(const T* a, const int size, int i)
{
    if (i < size)
    {
        if (i == 0) cout << "[ ";
        cout << setw(6) << a[i];
        PrintArray(a, size, i + 1);
    }
    else
    {
        cout << " ]";
    }
}

template <typename T>
T SumOfSquares(const T* a, const int size, int i)
{
    if (i < size)
        return (a[i] * a[i]) + SumOfSquares(a, size, i + 1);
    else
        return T();
}