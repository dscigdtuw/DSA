//1. Missing Number
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int real_sum=n*(n+1)/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        int missing_element=abs(real_sum-sum);
        return missing_element;
    }
};

//2. Remove Duplicates from Sorted Array
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        int i=0;
        for(int j=1;j<n;j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }
        return i+1;
    }
};

//3. Spiral Matrix
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
	const int row = matrix.size(), col = row?matrix[0].size():0;
	int left=0, right=col-1, top=0, bottom=row-1, idx=0;
	while(1){
		if(left>right || top>bottom ) 
            break;
		if(left==right && top==bottom){  
            ans.push_back(matrix[top][left]);  
            break;
        }
		for(idx=left;idx<=right;++idx){  
            ans.push_back(matrix[top][idx]);
        }
        ++top;
        
		for(idx=top;idx<=bottom;++idx){  
            ans.push_back(matrix[idx][right]); 
        }
        --right;
        
		if(left<=right && top<=bottom){
			for(idx=right;idx>=left;--idx) { 
                ans.push_back(matrix[bottom][idx]); 
            }
            --bottom;
			for(idx=bottom;idx>=top;--idx) { 
                ans.push_back(matrix[idx][left]);  
            }
            ++left;            
		}
	}
	return ans;
    }
};
