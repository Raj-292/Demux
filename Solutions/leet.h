//2d vector input of format [[1,2,3],[1,2],[4,5,8]]

std::vector<std::vector<int>> take2d() {

	std::string str;
	std::cin >> str;

	std::stringstream ss{str};
	auto it = std::istream_iterator<char> {ss};

	std::vector<std::vector<int>> output;
	std::vector<int> inner;

	while (it != std::istream_iterator<char> {})
	{
		++it;

		// If we encounter a digit, push it into the inner vector
		if (std::isdigit(*it))
		{
			inner.push_back(*it - 48);
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
std::vector<int> take1d() {

	std::string str;
	std::cin >> str;

	std::stringstream ss{str};
	auto it = std::istream_iterator<char> {ss};

	std::vector<int> v;
	while (it != std::istream_iterator<char> {})
	{
		++it;

		if (std::isdigit(*it))
		{
			v.push_back(*it - 48);
		}


	}
	return v;
}




//2d vector input of format [[a,b,c],[p,q,r,s,t],[x,y,z]]
std::vector<std::vector<char>> take2dc() {

	std::string str;
	std::cin >> str;

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

		std::vector<char>::iterator itr;
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

//1d vector input of format [a,b,c]

std::vector<char> take1dc() {

	std::string str;
	std::cin >> str;

	std::stringstream ss{str};
	auto it = std::istream_iterator<char> {ss};

	std::vector<char> v;
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