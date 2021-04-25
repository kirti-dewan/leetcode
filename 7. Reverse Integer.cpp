class Solution {
public:
    int reverse(int x) 
    {
        if(x==0)
        {//check if 0
            return 0;
        }
        bool sign=false;
        if(x<0)
        {//check sign
            sign=true;
            x=abs(x);
        }
        long long int ans=0;
        while(x!=0)
        {
            ans=ans*10+x%10;
            //check for out of range number
            if(ans> (INT_MAX) || ans< (INT_MIN))
            {
                return 0;
            }
            x/=10;
        }
        
        if(sign)
        {
            return (-1*ans);
        }
        return ans;
    }
};