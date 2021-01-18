// Using global

vector<int> freq(256, 0);

bool compare(char a, char b) {
	if (freq[a] == freq[b]) return a < b;
	return freq[a] > freq[b];
}

class Solution {
public:
	string frequencySort(string s) {
		// Frequency array
		// sort the s on the basis of frequency
		for (int i = 0; i < 256; i++) freq[i] = 0;  //Since we are making use of global vector we must reset it for each test case that each function call to the frequencySort function
		for (char c : s) freq[c]++;
		sort(s.begin(), s.end(), compare);
		return s;
	}
};

// Using Lambda function

// vector<int> freq(256,0);

// bool compare(char a,char b){
//     if(freq[a]==freq[b]) return a<b;
//     return freq[a]>freq[b];
// }

class Solution {
public:
	string frequencySort(string s) {
		// Frequency array
		// sort the s on the basis of frequency
		vector<int> freq(256, 0);
		for (char c : s) freq[c]++;
		// Lambda function
		// [Scope] (variables) {body}
		sort(s.begin(), s.end(), [&freq](char a, char b) { //Instead of [&freq], we may use [=] to pass everything outside
			if (freq[a] == freq[b]) return a < b;
			return freq[a] > freq[b];
		});
		return s;
	}
};