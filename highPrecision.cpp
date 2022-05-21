/*
高精度算法：高精度加法，高精度减法，高精度乘法，高精度除法
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> add(vector<int>& A, vector<int>& B) {
    if (A.size() < B.size()) return add(B, A);
    vector<int> ans;
    // i是位数，由低到高分别是个位->最高位，t是进位
    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        int cur = A[i] + (i < B.size() ? B[i] : 0) + t;
        ans.push_back(cur % 10);
        t = cur / 10;
    }
    if (t) ans.push_back(t);
    return ans;
}

// 判断A大于等于B
bool cmp(vector<int>& A, vector<int>& B) {
    if (A.size() != B.size()) return A.size() > B.size();
    for (int i = A.size() - 1; i >= 0; --i) {
        if (A[i] > B[i]) return true;
        else if (A[i] < B[i]) return false;
        else continue;
    }
    return true;
}

vector<int> sub(vector<int>& A, vector<int>& B) {
    vector<int> ans;
    // 这里就已经保证了A是大于等于B的
    for (int i = 0, t = 0; i < A.size(); ++i) {
        int cur = A[i] - (i < B.size() ? B[i] : 0) - t;
        if (cur >= 0) {
            t = 0;
        } else {
            cur += 10;
            t = 1;
        }
        ans.push_back(cur);
    }
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    return ans;
}

vector<int> mul(vector<int>& A, int b) {
    if (b == 0) return {0};
    vector<int> ans;
    for (int i = 0, t = 0; i < A.size() || t; ++i) {
        if (i < A.size()) t += A[i] * b;
        ans.push_back(t % 10);
        t /= 10;
    }
    return ans;
}

vector<int> div(vector<int>& A, int b, int& r) {
    // A 除 b，r是余数
    if (b == 0) return {};
    r = 0;
    vector<int> ans;
    // 这里依旧是高位表示的是高位
    for (int i = A.size() - 1; i >= 0; --i) {
        r = r * 10 + A[i];
        ans.push_back(r / b);
        r = r % b;
    }
    reverse(ans.begin(), ans.end());
    while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
    return ans;
}

int main() {
    string a, b;
    // 1234567在数组中对应着
    // [7,6,5,4,3,2,1]
    cout << "----高精度加法----" << endl;
    a = "12345678";
    b = "12345678";
    vector<int> A, B;
    for (int i = a.length() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for (int i = b.length() - 1; i >= 0; --i) B.push_back(b[i] - '0');
    vector<int> C = add(A, B);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    cout << endl;
    cout << "----高精度减法----" << endl;
    a = "987654321";
    b = "123456789";
    A.clear(), B.clear();
    for (int i = a.length() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    for (int i = b.length() - 1; i >= 0; --i) B.push_back(b[i] - '0');
    if (cmp(A, B)) {
        C = sub(A, B);
        for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    } else {
        C = sub(B, A);
        cout << '-';
        for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    }
    cout << endl;
    cout << "----高精度乘法----" << endl;
    A.clear();
    a = "12345678";
    for (int i = a.length() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    C = mul(A, 12);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    cout << endl;
    cout << "----高精度除法----" << endl;
    A.clear();
    int r;  // 余数
    a = "1212121212";
    for (int i = a.length() - 1; i >= 0; --i) A.push_back(a[i] - '0');
    C = div(A, 12, r);
    for (int i = C.size() - 1; i >= 0; --i) cout << C[i];
    cout << endl;

    return 0;
}