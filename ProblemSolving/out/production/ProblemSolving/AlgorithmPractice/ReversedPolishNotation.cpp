/*
ID: puzzlemusa
PROG:
LANG: C++
*/

#include <algorithm> 
#include <cctype> 
#include <cmath> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <deque> 
#include <iostream> 
#include <list> 
#include <map> 
#include <numeric> 
#include <queue> 
#include <set> 
#include <sstream> 
#include <stack> 
#include <string> 
#include <vector>
#include <unordered_map>
#include <functional>
#include <iomanip>

using namespace std;

#define frn(i,n) for(i=0;i<n;i++)
#define frN(i,n) for(i=1;i<=n;i++)
#define frr(i,n) for(i=n-1;i>=0;i--)
#define frv(i,a,n) for(i=a;i<n;i++)
#define frl(i,v) for(;i!=v.end();++i)
#define li(v) v.begin(), v.end()
#define sz(v) ((int)v.size())
#define emt(v) v.empty()
#define SET(v,a) memset(v,a,sizeof(v))
#define pi (2*acos(0))

typedef long long Long;
const int maxn = 1e9 + 10;

int calculate(int a, int b, const std::string &operation)
{
    if (operation == "+")
        return a + b;
    if (operation == "-")
        return a - b;
    if (operation == "*")
        return a * b;
    if (operation == "/")
        return a / b;
    return -1;
}

bool isOperation(const std::string& op)
{
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int RPN(std::vector<std::string> &notation) {
    std::stack<int> numbers;
    for (const auto& str : notation)
    {
        if (isOperation(str))
        {
            int n2 = numbers.top(); numbers.pop();
            int n1 = numbers.top(); numbers.pop();

            numbers.push(calculate(n1, n2, str));
        }
        else
            numbers.push(std::stoi(str));
    }
    return numbers.top();
}

std::vector<std::string> parse(const std::string& input)
{
    std::vector<std::string> vec;
    std::string current;
    for (char c : input)
    {
        if (isdigit(c))
            current += c;
        else if (c)
        {
            if (!current.empty())
            {
                vec.emplace_back(std::move(current));
                current = "";
            }

            if (c != ' ')
                vec.emplace_back(1, c);
        }
    }

    if (!current.empty())
        vec.push_back(std::move(current));

    return vec;
}

int main()
{
	ios_base::sync_with_stdio(0);
#ifdef localhost
	freopen("D://input.txt", "r", stdin);
	//freopen("D://output.txt","w",stdout);
#endif
    string s;
    cin >> s;
    std::vector<std::string> notation = parse(s);
    std::cout << RPN(notation) << '\n';
	return 0;
}