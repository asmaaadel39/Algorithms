#include <iostream>
using namespace std;

void checkResult(int a, int b, long long int &alicespoints, long long int &bobspoints) {
	if (a == 3 && b == 1) {
		bobspoints++;
	}
	else if (a == 1 && b == 3) {
		alicespoints++;
	}
	else {
		if (a > b) alicespoints++;
		if (b > a) bobspoints++;
	}
}
int main() {
	long long int k, bobspoints(0), alicespoints(0);
	int a, b, index1(0), index2(0), alice[3][3] = {}, bob[3][3] = {};
	cin >> k >> a >> b;
	index1 = a;
	index2 = b;
	checkResult(a,b,alicespoints,bobspoints);

	//cout << "Alice" << endl;
	int n1, n2, n3;
	for (int i = 0; i < 3; i++) {
		cin >> n1 >> n2 >> n3;
		alice[i][0] = n1;
		alice[i][1] = n2;
		alice[i][2] = n3;
	}
	//cout << "Bob" << endl;
	for (int i = 0; i < 3; i++) {
		cin >> n1 >> n2 >> n3;
		bob[i][0] = n1;
		bob[i][1] = n2;
		bob[i][2] = n3;
	}
	//we already know the first round while getting the input
	--k;
	//print how game goes
	//cout << "(" << a << ", " << b << ") ";

	for (int i = 0; i < k; i++) {
		a = alice[index1-1][index2-1];
		b = bob[index1-1][index2-1];
		index1 = a;
		index2 = b;
		checkResult(a, b, alicespoints, bobspoints);
		//cout << " (" << index1 << ", " << index2 << ") ";
	}
	cout << endl << alicespoints << " " << bobspoints << endl;
}
