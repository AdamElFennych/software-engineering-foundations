#include <iostream>
using namespace std;

void swap_Ref(int& n1, int& n2) {
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void swap_Poin(int* n1, int* n2) {
    int temp;
    temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

int main() {
    int a = 1;
    int b = 2;

    cout << "Before swapping (by reference)" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    swap_Ref(a, b);

    cout << "After swapping (by reference)" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl << endl;

    int s = 4;
    int r = 5;

    cout << "Before swapping (by pointer)" << endl;
    cout << "s = " << s << endl;
    cout << "r = " << r << endl;

    // الباراميتر من نوع Pointer * فيحتاج Address
    swap_Poin(&s, &r);

    cout << "After swapping (by pointer)" << endl;
    cout << "s = " << s << endl;
    cout << "r = " << r << endl;

    return 0;
}
