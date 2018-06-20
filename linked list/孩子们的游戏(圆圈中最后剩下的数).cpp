/*
每年六一儿童节,牛客都会准备一些小礼物去看望孤儿院的小朋友,今年亦是如此。
HF作为牛客的资深元老,自然也准备了一些小游戏。其中,有个游戏是这样的:首先,让小朋友们围成一个大圈。
然后,他随机指定一个数m,让编号为0的小朋友开始报数。每次喊到m-1的那个小朋友要出列唱首歌,然后可以在礼品箱中任意的挑选礼物,
并且不再回到圈中,从他的下一个小朋友开始,继续0...m-1报数....这样下去....
直到剩下最后一个小朋友,可以不用表演,并且拿到牛客名贵的“名侦探柯南”典藏版(名额有限哦!!^_^)。
请你试着想下,哪个小朋友会得到这份礼品呢？(注：小朋友的编号是从0到n-1)
*/
/*
用啥list啊，用vector也行吧，就是要查找或删除过程中要自己接起来
*/
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1||m<1)
            return -1;
        list<int> src;
        for(int i=0;i<n;i++)
            src.push_back(i);
        auto iter=src.begin();
        while(src.size()>1)
        {
            for(int i=1;i<=m-1;i++)  //这个m-1得在脑子里转转圈
            {
                iter++;
                if(iter==src.end())
                    iter=src.begin();
            }
            
            iter=src.erase(iter);
            if(iter==src.end())    //我忘写了这两句，万一删除完iter指向末尾了，那不符合逻辑
                iter=src.begin();
        }
        iter=src.begin();
        return *iter;
    }
};
