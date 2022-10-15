#include <iostream>
using namespace std;

bool CanReturn(int *A, int *B, int C,int j,int CF) {
	if (j == 0)return true;
	for (int k = j-1; k >= 0; k--)
	{
		int r1 = CF + A[k+1];
		r1 = r1>C ? C : r1;
		if (B[k]>r1) return false;
		CF = r1 - B[k];
	}
	return true;
}

int ForwardPath(int *A, int *B, int N, int C, int *F) {
	int farthest = 0;
	for (int i = 0; i < N; i++) F[i] = 0; 
	int j;
	for (j = 0; j<N; j++){
		int r1 = F[j] + A[j];
		r1 = r1>C ? C : r1;
		if (B[j]>r1) break;
		farthest = (j + 1) % N;
		F[farthest] = r1 - B[j];
	}
	return farthest;
}

int BackwordPath(int *A, int *B, int N, int C, int *F, int farthest) {
	if (farthest==0)return N - 1;
	int j;
	for (j = farthest; j>=0; j--){
		if (CanReturn(A, B, C, j, F[j]))break;
	}
	return j;
}

int main() {
	int N, C, *A, *B, *F;
	cout << "Please enter number of cities " << endl;
	cin >> N;
	cout << "Please enter tank capacity " << endl;
	cin >> C;
	A = new int[N];
	B = new int[N];
	F = new int[N];
	cout << "Please enter the amount of available fuel in each city " << endl;
	for (int i = 0; i<N; i++){
		cin >> A[i];
	}
	cout << "Please enter the amount of fuel consumed between each two cities " << endl;
	for (int i = 0; i<N; i++){
		cin >> B[i];
	}
	int farthest = ForwardPath(A, B, N, C, F);
	int nVisited = BackwordPath(A, B, N, C, F, farthest);
	cout << "Number of cities visited= " << nVisited << endl;
	delete A;
	delete B;
	delete F;
	return 0;
}