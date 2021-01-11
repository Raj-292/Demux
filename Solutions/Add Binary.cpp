class Solution {
public:
	string addBinary(string a, string b) {
		int i = a.size() - 1, j = b.size() - 1, carry = 0, curr_bit, curr_char_a, curr_char_b;
		string res = "";

		while (i >= 0 && j >= 0) {
			// copy the current bit
			curr_bit = (a[i] - '0' + b[j] - '0' + carry) % 2;
			res += (char)(curr_bit + '0');

			// Update carry
			carry = (a[i] - '0' + b[j] - '0' + carry) / 2;
			i--; j--;
		}

		// Process the remaining characters of the longer string
		while (i >= 0) {
			curr_bit = (a[i] - '0' + carry) % 2;
			res += (char)(curr_bit + '0');
			carry = (a[i] - '0' + carry) / 2;
			i--;
		}

		while (j >= 0) {
			curr_bit = (b[j] - '0' + carry) % 2;
			res += (char)(curr_bit + '0');
			carry = (b[j] - '0' + carry) / 2;
			j--;
		}

		// Copy the last carry
		if (carry)
			res += (char)(carry + '0');

		// reverse the string and return it
		i = 0, j = res.size() - 1;
		while (i <= j) {
			swap(res[i], res[j]);
			i++; j--;
		}


		return res;
	}
};