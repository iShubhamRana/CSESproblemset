
void heapify(vector<int> &arr , int size , int i) {
    if (2 * i + 1 >= size) return;

    int largest = arr[i], l = 2 * i + 1;
    if (l + 1 < size && arr[l + 1] > arr[l]) l++;

    if (largest < arr[l]) {
        swap(arr[i], arr[l]);
        heapify(arr , size , l);
    }
}


void heapsort(vector<int> &arr) {
    int n = arr.size();

    for (int i = n / 2 - 1 ; i >= 0; i--) {
        heapify(arr, n  ,  i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i ]);
        heapify(arr, i, 0);
    }

}
