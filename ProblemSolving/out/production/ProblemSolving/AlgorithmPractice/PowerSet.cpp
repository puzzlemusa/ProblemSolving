#include <iostream>
#include <vector>

using namespace std;

vector<int> arr, r;
int counter = 0;

void showSubset() {
	if (counter == 0)
		cout << "{}" << endl;

	cout << "{";
	for (auto it = r.begin(); it != r.end(); ++it) {
		if (it + 1 != r.end())
			cout << *it << ", ";
		else
			cout << *it;
	}
	cout << "}" << endl;

	counter++;
}

void powerSet(int size, int index) {
	if (size == 0) {
		showSubset();
		return;
	}

	for (int i = index; i<arr.size(); i++) {
		r.push_back(arr[i]);
		powerSet(size-1, i + 1);
		r.pop_back();
	}
}

int main() {

	freopen("D://input.txt", "r", stdin);

	int n;
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		powerSet(i, 0);
	}

	return 0;
}