  long long cnt = 0;
    int diff = 0;
    void merge(vector<long> &arr,int low,int mid,int high){
        long long temp[arr.size()];
        int i = low;
        int j = mid+1;
        int k = low;
        
        while(i<=mid and j<=high){
            long long a = arr[j];
            if(arr[i]-a<=diff){
                cnt += high-j+1;
                i++;
             }
             else{
                 j++;
             }
          }
        
         i = low;
         j = mid+1;
         while(i<=mid and j<=high){
             if(arr[i]<=arr[j]){
                 temp[k++] = arr[i++];
             }
             else{
                 temp[k++] = arr[j++];

             }
         }
         while(i<=mid){
             temp[k++] = arr[i++];
         }
         while(j<=high){
             temp[k++] = arr[j++];
         }
         for(int z = low; z<=high; z++){
             arr[z] = temp[z];
         }
        
    }
    
    void mergeSort(int low , int high ,vector<long> &nums){
        if(low<high){
            int mid = low + (high-low)/2;
            mergeSort(low , mid ,nums);
            mergeSort(mid+1, high,nums);
            merge(nums,low,mid,high);
        }
    }
    
    
