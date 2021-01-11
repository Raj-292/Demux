/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        char buf1[4];
        int rv = 4, read_count = 0;

        while (rv == 4 && n > 0) {
            rv = read4(buf1);
            rv = min(rv, n);
            n -= rv;

            // Copy it into the output buffer
            memcpy(buf + read_count, buf1, rv);
            read_count += rv;
        }

        return read_count;
    }
};