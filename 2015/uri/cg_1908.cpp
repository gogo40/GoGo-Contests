#include <cstdio>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
	srand(time(NULL));
	int N, K;
	N = 2 + rand() % 10000;
	K = 1 + rand() % 1000;

	printf("%d %d\n", N, K);
	for (int i = 0; i < K; ++i) {
		int L = 2 + rand() % 98;
		printf("%d", L);
		for (int k = 0; k < L; ++k) {
			int c  = 1 + rand() % N;
			printf(" %d", c);
		}
		printf("\n");
	}

	return 0;
}
