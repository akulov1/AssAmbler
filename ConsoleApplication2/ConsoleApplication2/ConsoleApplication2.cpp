#include <iostream>
#include <omp.h>

using namespace std;

void pr2() {
	int i, n, s = 0;
#pragma omp parallel private (i,n) reduction(+:s)
	{
		n = omp_get_thread_num();
#pragma omp for
		for (i = 1; i < 10; i++) {
			s += i;
			cout << "Nit' " << n << " slozhila element s nomerom " << i << endl;
		}
	}
	cout << s;
}

void pr3() {
	const int N = 1000;
	int A[N], B[N], C[N], i, n;
	for (i = 0; i < N; i++) {
		A[i] = i;
		B[i] = 2 * i;
		C[i] = 0;
	}
	#pragma omp parallel shared(A,B,C) private(i,n)
	{
		n = omp_get_thread_num();
#pragma omp for
		for (int i = 0; i < N; i++) {
			C[i] = A[i] + B[i];
			cout << "Nit' " << n << " slozhila elem s nomerom" << i<<endl;
		}
	}
}

int main()
{
	pr3();

}
