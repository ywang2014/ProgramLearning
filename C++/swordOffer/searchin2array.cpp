/*
* 题目描述
* 在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的
* 顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数
*/

bool Find(vector<vector<int> > array,int target) {
        int len_r = array[0].size();
        int len_c = array.size();
        int lo_l = 0;
        int hi_l = len_c;
        int lo_r = 0;
        int hi_r = len_c;
        while (lo_l < hi_l)
            {
            int mid_l = (lo_l + hi_l) >> 1;
            if (target < array[mid_l][0])
                {
                hi_l = mid_l;
            }
            else
                {
                lo_l = mid_l + 1;
            }
            
            int mid_r = (lo_r + hi_r) >> 1;
            if (target > array[mid_r][len_r -1])
                {
                lo_r = mid_r + 1;
            }
            else
                {
                hi_r = mid_r; 
            }
        }
        lo_r--;
        if (lo_r < 0)
            {
            lo_r = 0;
        }
        if (lo_l == len_c)
            {
            lo_l--;
        }
        
        int newlo = lo_r;
        int newhi = lo_l;
   
        for (int i = newlo; i < newhi + 1; i++)
            {
            int lo = 0;
        	int hi = len_r;
            while(lo < hi)
                {
                int mid = (lo + hi) >> 1;
                if (target < array[i][mid])
                    {
                    hi = mid;
                }
                else
                    {
                    lo = mid + 1;
                }
            }
            if (lo == len_r)
                {
                lo--;
            }
            if (array[i][lo] == target)
                {
                return true;
            }
        }
        return false;
    }