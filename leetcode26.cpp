class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        
        if(!nums.size())    //特殊情况
            return 0;
        
        
        // //借助vector 的api erase
        // int flag = nums[0]; //设重复的元素为flag
        // for (int i=1;i<nums.size();) {
        //     if (nums[i]==flag) {    //遇到重复元素
        //         nums.erase(nums.begin()+i); //数组左移一位，相当于i右移一位故这里没有i++
        //     } else {
        //         flag = nums[i]; //非重复元素,重新确立flag的值并将i++
        //         i++;
        //     }
        // }
        // return nums.size(); //返回新数组的长度
        
        //双指针法
        int i=0,j=1;        //慢指针i,快指针j
        
        while(j<nums.size()){   
            if(nums[j]!=nums[i]){   //扫描快指针，如果快指针位置的值不等于慢指针的值说明该值不是重复元素，进行赋值
                nums[++i] = nums[j];    //注意这里是++i,因为nums[0]的值是确定的，后面每次检查有新元素要先进行自增再赋值，否则会漏掉第一个值即nums[0]
            }
            j++;
        }
        return i+1; //注意+1
    }
};