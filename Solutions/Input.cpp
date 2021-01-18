// #include <bits/stdc++.h>

// using namespace std;

// #define ll long long

// //2d vector input of format [[1,2,3],[1,2],[4,5,8]]

// vector<vector<int>> take2d() {

// 	string str;
// 	cin >> str;

// 	std::stringstream ss{str};
// 	auto it = std::istream_iterator<char> {ss};

// 	std::vector<std::vector<int>> output;
// 	std::vector<int> inner;

// // Loop through the string, one character at a time
// 	while (it != std::istream_iterator<char> {})
// 	{
// 		++it;

// 		// If we encounter a digit, push it into the inner vector
// 		if (std::isdigit(*it))
// 		{
// 			// Dirty hack to convert char to integer (assumes ASCII)
// 			inner.push_back(*it - 48);
// 		}

// 		// If you encounter a ']' char, then push inner vector into the outer vector
// 		// and then clear the inner vector

// 		// For the final ']', the inner vector will be size 0, ignore this case
// 		if (*it == ']')
// 		{
// 			if (inner.size() != 0)
// 			{
// 				output.push_back(inner);
// 			}
// 			inner.clear();
// 		}
// 	}

// 	return output;
// }

// //1d vector input of format [1,2,3]

// vector<int> take1d() {

// 	string str;
// 	cin >> str;

// 	std::stringstream ss{str};
// 	auto it = std::istream_iterator<char> {ss};

// 	// std::vector<std::vector<int>> output;
// 	std::vector<int> inner;

// // Loop through the string, one character at a time
// 	while (it != std::istream_iterator<char> {})
// 	{
// 		++it;

// 		// If we encounter a digit, push it into the inner vector
// 		if (std::isdigit(*it))
// 		{
// 			// Dirty hack to convert char to integer (assumes ASCII)
// 			inner.push_back(*it - 48);
// 		}

// 		// If you encounter a ']' char, then push inner vector into the outer vector
// 		// and then clear the inner vector

// 		// For the final ']', the inner vector will be size 0, ignore this case
// 		// if (*it == ']')
// 		// {
// 		// 	if (inner.size() != 0)
// 		// 	{
// 		// 		output.push_back(inner);
// 		// 	}
// 		// 	inner.clear();
// 		// }
// 	}

// 	return inner;
// }



// int main() {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

// 	ios_base::sync_with_stdio(false);
// 	cin.tie(NULL);

// 	//2d vector
// 	// vector<vector<int>> x = take2d();

// 	// cout << "Size of the vector is : " << x.size() << endl;


// 	// for (int i = 0; i < x.size(); i++) {
// 	// 	for (int j = 0; j < x[i].size(); j++) {
// 	// 		cout << x[i][j] << " ";
// 	// 		if (j == x[i].size() - 1) {
// 	// 			cout << endl;
// 	// 		}
// 	// 	}
// 	// }

// 	vector<int> y = take1d();

// 	cout << "Size of the vector is : " << y.size() << endl;

// 	for (int i = 0; i < y.size(); i++) {
// 		cout << y[i] << " ";
// 	}

// 	cout << endl;

// }


// Using templates to make it more generic (Too Complex)

#include <bits/stdc++.h>

using namespace std;

#define ll long long

//2d vector input of format [[1,2,3],[1,2],[4,5,8]]
vector<vector<char>> take2dc() {

	string str;
	cin >> str;

	std::stringstream ss{str};
	auto it = std::istream_iterator<char> {ss};

	std::vector<std::vector<char>> output;
	std::vector<char> inner;

	while (it != std::istream_iterator<char> {})
	{
		++it;

		// if (std::isdigit(*it))
		// {
		// 	inner.push_back(*it - 48);
		// }

		if (*it == ',' || *it == '[') {
			continue;
		}
		inner.push_back(*it);

		vector<char>::iterator itr;
		itr = inner.end() - 1;

		if (inner[inner.size() - 1] == ']') {
			inner.erase(itr);
		}

		if (*it == ']')
		{
			if (inner.size() != 0)
			{
				output.push_back(inner);
			}
			inner.clear();
		}
	}

	return output;
}

//1d vector input of format [1,2,3]

vector<char> take1dc() {

	string str;
	cin >> str;

	std::stringstream ss{str};
	auto it = std::istream_iterator<char> {ss};

	vector<char> v;
	while (it != std::istream_iterator<char> {})
	{
		++it;

		// if (std::isdigit(*it))
		// {
		// 	v.push_back(*it - 48);
		// }
		if (*it == ',' || *it == ']') {
			continue;
		}
		v.push_back(*it);

	}
	return v;
}



int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	//2d vector
	vector<vector<char>> x = take2dc();

	cout << "Size of the vector is : " << x.size() << endl;


	for (int i = 0; i < x.size(); i++) {
		for (int j = 0; j < x[i].size(); j++) {
			cout << x[i][j] << " ";
			if (j == x[i].size() - 1) {
				cout << endl;
			}
		}
	}

	// vector<char> y = take1dc();

	// cout << "Size of the vector is : " << y.size() << endl;

	// for (int i = 0; i < y.size(); i++) {
	// 	cout << y[i] << " ";
	// }

	// cout << endl;

}