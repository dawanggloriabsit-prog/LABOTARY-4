#include <iostream>
using namespace std;

// ----- Linear Search -----
int linearSearch(int data[], int count, int value) {
    for (int i = 0; i < count; i++) {
        if (data[i] == value) {
            return i;
        }
    }
    return -1;
}

// ----- Binary Search -----
int binarySearch(int data[], int count, int value) {
    int left = 0;
    int right = count - 1;

    while (left <= right) {
        int middle = left + (right - left) / 2;

        if (data[middle] == value)
            return middle;
        else if (data[middle] > value)
            right = middle - 1;
        else
            left = middle + 1;
    }

    return -1;
}

// ----- Interpolation Search -----
int interpolationSearch(int data[], int count, int value) {
    int low = 0;
    int high = count - 1;

    while (low <= high && value >= data[low] && value <= data[high]) {
        if (low == high) {
            return (data[low] == value ? low : -1);
        }

        int pos = low + ( (double)(value - data[low]) *
                          (high - low) / (data[high] - data[low]) );

        if (data[pos] == value)
            return pos;
        else if (data[pos] < value)
            low = pos + 1;
        else
            high = pos - 1;
    }

    return -1;
}

int main() {
    int arr[] = {10, 18, 27, 33, 41, 52, 63, 75, 88, 99};
    int size = 10;
    int target;
    int option;

    cout << "Enter number to search: ";
    cin >> target;

    cout << "\nChoose search method:\n";
    cout << "1 - Linear Search\n";
    cout << "2 - Binary Search\n";
    cout << "3 - Interpolation Search\n";
    cout << "Selection: ";
    cin >> option;

    int result = -1;

    if (option == 1)
        result = linearSearch(arr, size, target);
    else if (option == 2)
        result = binarySearch(arr, size, target);
    else if (option == 3)
        result = interpolationSearch(arr, size, target);
    else {
        cout << "\nInvalid choice!\n";
        return 0;
    }

    if (result != -1)
        cout << "\nElement found at index: " << result << endl;
    else
        cout << "\nElement not found!\n";

    return 0;
}
