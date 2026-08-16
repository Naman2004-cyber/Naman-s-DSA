class Solution {
public:
    using cd = complex<double>;
    const double PI = acos(-1.0);

    void fft(vector<cd>& a, bool invert) {
        int n = a.size();

        // Bit reversal
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;

            while (j & bit) {
                j ^= bit;
                bit >>= 1;
            }

            j ^= bit;

            if (i < j)
                swap(a[i], a[j]);
        }

        // FFT
        for (int len = 2; len <= n; len <<= 1) {
            double ang = 2 * PI / len * (invert ? -1 : 1);
            cd wlen(cos(ang), sin(ang));

            for (int i = 0; i < n; i += len) {
                cd w(1);

                for (int j = 0; j < len / 2; j++) {
                    cd u = a[i + j];
                    cd v = a[i + j + len / 2] * w;

                    a[i + j] = u + v;
                    a[i + j + len / 2] = u - v;

                    w *= wlen;
                }
            }
        }

        if (invert) {
            for (cd& x : a)
                x /= n;
        }
    }

    vector<long long> convolution(
        const vector<int>& a,
        const vector<int>& b
    ) {
        int need = a.size() + b.size() - 1;

        int sz = 1;
        while (sz < need)
            sz <<= 1;

        vector<cd> A(sz), B(sz);

        for (int i = 0; i < a.size(); i++)
            A[i] = a[i];

        for (int i = 0; i < b.size(); i++)
            B[i] = b[i];

        fft(A, false);
        fft(B, false);

        for (int i = 0; i < sz; i++)
            A[i] *= B[i];

        fft(A, true);

        vector<long long> res(need);

        for (int i = 0; i < need; i++)
            res[i] = llround(A[i].real());

        return res;
    }

    int minOperations(string s) {
        int n = s.size();

        /*
            total[t] =
            total cost of ordered pairs (i,j)
            such that i + j = t.
        */
        vector<long long> total(2 * n - 1, 0);

        for (int c = 0; c < 26; c++) {

            vector<int> A(n), B(n);

            // A[i] = 1 if s[i] == c
            for (int i = 0; i < n; i++) {
                if (s[i] - 'a' == c)
                    A[i] = 1;
            }

            /*
                B[j] = cost of changing character c
                       into s[j].
            */
            for (int j = 0; j < n; j++) {
                int x = abs(c - (s[j] - 'a'));
                B[j] = min(x, 26 - x);
            }

            vector<long long> cur = convolution(A, B);

            for (int t = 0; t < cur.size(); t++)
                total[t] += cur[t];
        }

        int ans = INT_MAX;

        /*
            Rotation by k.

            Palindrome pairs satisfy:
                i + j ≡ 2k - 1 (mod n)
        */
        for (int k = 0; k < n; k++) {

            int rem = (2 * k - 1 + n) % n;

            long long sum = 0;

            for (int t = rem; t < 2 * n - 1; t += n)
                sum += total[t];

            // Every pair counted twice: (i,j) and (j,i)
            long long palindromeCost = sum / 2;

            long long operations = k + palindromeCost;

            ans = min(ans, (int)operations);
        }

        return ans;
    }
};