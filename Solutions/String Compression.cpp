class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size(), i, j, curr_char, curr_count;

        // First chunk
        curr_char = chars[0];
        curr_count = 1;
        // j stores the first positon where I can insert
        j = 0;

        for (i = 1; i <= n; i++) {
            if (i < n && chars[i] == curr_char)
                curr_count++;
            else {
                // Time to insert this string
                // Insert the character
                chars[j] = curr_char;
                j++;
                // Insert the count
                if (curr_count > 1) {
                    string count_str = to_string(curr_count);
                    int len = 0;

                    while (len < count_str.size()) {
                        chars[j] = count_str[len];
                        j++;
                        len++;
                    }
                }

                // Update curr_char and curr_count for the next iteration
                if (i < n) {
                    curr_char = chars[i];
                    curr_count = 1;
                }
            }
        }

        return j;
    }
};