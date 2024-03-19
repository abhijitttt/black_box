 while (left <= right) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == target)
            return mid;

        // If the element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] < target)
            left = mid + 1;

        // If the element is larger than mid, then it can only be present in right subarray
        else
            right = mid - 1;
    }
