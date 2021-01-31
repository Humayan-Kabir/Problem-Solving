#include<iostream>
namespace algorithm {
    template<typename T, typename C> 
    void merge(T *arr, int b, int mid, int e, C compare) {
        int n1 = mid - b + 1;
        int n2 = e - mid;

        T L[n1];
        T R[n2];

        for(int i = 0; i < n1; i++) L[i] = arr[b + i];
        for(int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

        int i = 0, j = 0, k = b;

        while(i < n1 && j < n2) {
            if(compare(L[i], R[j])) {
                arr[k++] = L[i++];
            } else {
                arr[k++] = R[j++];
            }
        }

        while(i < n1) {
            arr[k++] = L[i++];
        }
        while(j < n2) {
            arr[k++] = R[j++];
        }
    }

    template<typename T, typename C>
    void sort(T *arr, int b, int e, C compare) {
        if(b < e) {
            int mid = (b + e) / 2;
            sort(arr, b, mid, compare);
            sort(arr, mid + 1, e, compare);
            merge(arr, b, mid, e, compare);
        }
    }
}

 struct data {
    int money;
    int friendship;
    data() {}
};

using namespace std;
using namespace algorithm;

bool compare(data &a, data &b) {
    return a.money < b.money;
}

int main() {
    int n, d;
    cin >> n >> d;
    data *arr = new data[n];
    for(int i = 0; i < n; i++) cin >> arr[i].money >> arr[i].friendship;
    sort(arr, 0, n - 1, compare);
    long long dx = 0, dy = 0, ans = 0, sliding = 0;
    while(dy < n) {
        while(dy < n && arr[dy].money - arr[dx].money < d) {
            sliding += arr[dy].friendship;
            dy++;
        }
        ans = max(ans, sliding);
        while(dx < dy && arr[dy].money - arr[dx].money >= d) {
            sliding -= arr[dx].friendship;
            dx++;
        }
    }
    cout << ans << endl;
    return 0;
}

