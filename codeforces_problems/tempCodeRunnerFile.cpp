 int n;
        cin >> n;
        vector<int> arr(n);
        for (size_t i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<int> longest_subsequence(n);
        for (size_t i = 0; i < n; i++)
        {
            int added_length = 0;
            for (size_t j = 0; j < i; j++)
            {
                if (arr[j] < arr[i])
                    added_length = max(added_length, longest_subsequence[j]);
            }
            longest_subsequence[i] = 1 + added_length;
        }
        int ans = 0;
        for (size_t i = 0; i < n; i++)
        {
            ans = max(ans, longest_subsequence[i]);
        }
        cout << ans << endl;