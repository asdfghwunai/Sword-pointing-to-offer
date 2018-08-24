class Solution {
public:
    int sqrt(int x) {
        long long int l=0;
        long long int r=x;
        long long int mid;
        while(l<=r)
        {
            mid=(l+r)/2;
            if(mid*mid==x)
                return mid;
            else if(mid*mid>x)
                r=mid-1;
            else
                l=mid+1;
        }
        return r;
    }
};
