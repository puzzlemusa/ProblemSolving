#include <iostream>
#include <string>

using namespace std;

string reverse(string s) {

	if (s.size() == 1)
		return s;

	return reverse(s.substr(1, s.size() - 1)) + s.at(0);

}

int main() {
	string s;
	cin >> s;

	cout << reverse(s);
	return 0;
}