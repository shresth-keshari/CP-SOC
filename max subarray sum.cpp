long long maxSubarraySum(vector<int>& arr,int n)
{
    n = arr.size();
    int max_so_far = 0; // Initialize the maximum sum as 0 to consider the empty subarray case
    int max_ending_here = 0;

    for (int i = 0; i < n; ++i) {
        max_ending_here += arr[i];
        
        // If max_ending_here is negative, set it to 0 (discard the subarray)
        if (max_ending_here < 0)
            max_ending_here = 0;
        
        // Update the maximum sum found so far
        max_so_far = max(max_so_far, max_ending_here);
    }
    
    return max_so_far;
}
