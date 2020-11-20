#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

 // 利用哈希表 
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int>cntmap;
        int len = nums.size();
        unordered_map<int, int>::iterator it;
        for(int x : nums)
        {
            it = cntmap.find(x); // 存在键x，返回对应键值对的迭代器，否则返回cntmap.end()
            if(it == cntmap.end()) // 不存在该键，需要添加键值对
                cntmap[x] = 1;
            else // 存在该键，将对应值+1
                cntmap[x]++;
            if(cntmap[x] > (len / 2)) return x;
        }
        return -1;
    }
};

// 排序+双指针
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // 先排序
        int i = 0, j = 0;
        for( ; j < nums.size(); j++)
        {
            if(nums[i] != nums[j])
            {
                if((j - i) > (nums.size() / 2)) return nums[i];
                else i = j;
            }
        }
        if((j - i) > (nums.size() / 2)) return nums[i];
        return -1;
    }
};

// 摩尔投票法，不同的值相抵消
class Solution3 {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, number = 0; // 表示经过前i个元素抵消之后还有cnt个number
        int half = nums.size() / 2;
        for(int x : nums)
        {
            if(cnt == 0)
            {
                cnt = 1;
                number = x;
            }
            else if(number == x) cnt++;
            else cnt--;
        }
        if(cnt == 0) return -1; // 全部抵消
        // 如果有奇数个元素，且最后cnt=1时这个统计方法才有可能失效，
        // 如[1,1,1,2,2,2,1]最后cnt=1，number=1，此时number是主要元素
        // 如[1,2,3,4,5,6,7]最后cnt=1，number=7，但number不是主要元素
        else if((nums.size() & 1) && (cnt == 1))
        {
            int n = 0;
            for(int x : nums)
                if(x == number)
                    n++;
            if(n > half) return number;
            else return -1;
        }
        else return number;
    }
};

int main()
{
    int a = 3;
    bool f = a & 1;
    cout << f;
    return 0;
}