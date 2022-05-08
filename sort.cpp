#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 冒泡
void bullble_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        bool check = false;
        for (int j = 1; j < n - i + 1; ++j) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
                check = true;
            }
        }
        if (!check) break;
    }
}

// 插入
void insert_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 1; i < n; ++i) {
        for (int j = i; j > 0 && nums[j] < nums[j - 1]; --j) {
            swap(nums[j], nums[j - 1]);
        }
    }
}

// 选择
void select_sort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        int idx = i;
        for (int j = i; j < n; ++j) {
            if (nums[j] < nums[idx]) idx = j;
        }
        swap(nums[i], nums[idx]);
    }
}

// 快速
void quick_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int x = nums[(l + r) >> 1];
    int i = l, j = r;
    while (i <= j) {
        while (i <= r && nums[i] < x) ++i;
        while (j >= 0 && nums[j] > x) --j;
        if (i >= j) break;
        swap(nums[i++], nums[j--]);
    }
    quick_sort(nums, l, j);
    quick_sort(nums, j + 1, r);
}

// 归并
void merge_sort(vector<int>& nums, int l, int r) {
    if (l >= r) return;
    int mid = (l + r) >> 1;
    merge_sort(nums, l, mid);
    merge_sort(nums, mid + 1, r);
    int n = r - l + 1;
    int tmp[n];
    int idx = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        tmp[idx++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    }
    while (i <= mid) tmp[idx++] = nums[i++];
    while (j <= r) tmp[idx++] = nums[j++];
    for (int i = 0; i < n; ++i) {
        nums[l + i] = tmp[i];
    }
}

// 堆
void heap_sort(vector<int>& nums) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i : nums) q.push(i);
    for (int& i : nums) {
        i = q.top();
        q.pop();
    }
}

// 计数
void cnt_sort(vector<int>& nums) {
    int n = nums.size();
    int cnts[100];
    memset(cnts, 0, sizeof cnts);
    for (int i = 0; i < n; ++i) {
        cnts[nums[i]]++;
    }
    int idx = 0;
    for (int i = 0; i < 100; ++i) {
        while (cnts[i] > 0) {
            nums[idx++] = i;
            cnts[i]--;
        }
    }
}

int main() {
    vector<int> nums({4,3,5,7,3,1,2,75,8});
    // bullble_sort(nums);
    // insert_sort(nums);
    // select_sort(nums);
    // quick_sort(nums, 0, nums.size() - 1);
    // merge_sort(nums, 0, nums.size() - 1);
    // heap_sort(nums);
    cnt_sort(nums);
    for (int num : nums) cout << num << " ";
    cout << endl;

    return 0;
}