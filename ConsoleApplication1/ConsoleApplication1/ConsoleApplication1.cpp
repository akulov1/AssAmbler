#include <iostream>

using namespace std;

void aplusfiveb() {
    int a, b, sum;
    cout << "Input A" << endl;
    cin >> a;
    cout << "Input B" << endl;
    cin >> b;
    _asm {
        mov eax, a
        mov ecx, 5
        m: add eax, b
        loop m
        mov sum, eax
    }
    cout << endl << sum;
}

void findmaxof3() {
    int a, b, c, max;
    cout << "Input A" << endl;
    cin >> a;
    cout << "Input B" << endl;
    cin >> b;
    cout << "Input C" << endl;
    cin >> c;
    _asm {
        mov eax, a
        mov ebx, b
        cmp eax, ebx
        jg m1
        mov eax, ebx
        m1 : mov ebx, c
        cmp eax, ebx
        jg m2
        mov eax, ebx
        m2 : mov max, eax
    }
    cout << endl << max;
}

int main()
{
    int a, b, c,max,total;
    cout << "Input A" << endl;
    cin >> a;
    cout << "Input B"<<endl;
    cin >> b;
    cout << "Input C" << endl;
    cin >> c;
    _asm {
        mov eax, a
        mov ebx, b
        add ebx, eax
        cmp eax, ebx
        jg m1
        mov eax, ebx
        add eax, eax
        m1 : mov max, eax
        mov eax, a
        mov ebx, c
        cmp eax, ebx
        jmp m2
        mov eax, ebx
        m2: mov ebx, c
        cmp eax, ebx
        jmp m3
        mov eax, ebx
        m3: add eax, max
        mov total, eax
    }
    cout << endl << "2*max+min " << total;
}

