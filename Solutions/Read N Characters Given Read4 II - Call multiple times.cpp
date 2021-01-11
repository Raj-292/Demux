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
    char prev_buf[4];
    int len_buf;

    Solution() {
        len_buf = 0;
    }
    int read(char *buf, int n) {
        int rv = 4, read_count = 0, last_read_count;
        char buf1[4];

        // Consume the remaining characters from prev buf
        memcpy(buf1, prev_buf, len_buf);

        // rv <- Number of character that needs to be copied
        // last_read_count <- Number of characters you have

        rv = min(n, len_buf);
        last_read_count = len_buf;

        memcpy(buf, buf1, rv);
        n -= rv;
        read_count += rv;

        // Consume more from read4
        if (n > 0)
            rv = 4;

        while (rv == 4 && n > 0) {
            rv = read4(buf1);
            last_read_count = rv;

            rv = min(rv, n);

            memcpy(buf + read_count, buf1, rv);
            n -= rv;
            read_count += rv;
        }

        // Spill the extra character to prev buf
        if (last_read_count - rv > 0) {
            memcpy(prev_buf, buf1 + rv, last_read_count - rv);
            len_buf = last_read_count - rv;
        }
        else
            len_buf = 0;

        return read_count;

    }
};