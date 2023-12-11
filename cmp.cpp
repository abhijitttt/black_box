bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    // Compare first elements
    if (a.first < b.first)
        return true;
    else if (a.first == b.first)
        // If first elements are equal, compare second elements
        return a.second < b.second;
    else
        return false;
}
