//“多重背包”通用模板
const int MAX_V = 100004;
//v、n、w：当前所处理的这类物品的体积、个数、价值
//V：背包体积， MAX_V：背包的体积上限值
//f[i]：体积为i的背包装前几种物品，能达到的价值上限。
inline void pack(int f[], int V, int c, int n, int w){// v是体积，w是价值
    if (n == 0 || c == 0) return;
    if (n == 1){               //01背包
        for (int i = V; i >= c; --i)
            if (f[i] < f[i - c] + w)
                f[i] = f[i - c] + w;
        return;
    }
    if(n * c >= V - c + 1){   //完全背包(n >= V / v)
        for (int i = c; i <= V; ++i){
            if (f[i] < f[i - c] + w)
                f[i] = f[i - c] + w;
        }
        return;
    }
    int va[MAX_V], vb[MAX_V];   //va/vb: 主/辅助队列
    for (int j = 0; j < c; ++j) {     //多重背包
        int *pb = va, *pe = va - 1;     //pb/pe分别指向队列首/末元素
        int *qb = vb, *qe = vb - 1;     //qb/qe分别指向辅助队列首/末元素
        for (int k = j, i = 0; k <= V; k += c, ++i) {
            if (pe  == pb + n) {       //若队列大小达到指定值，第一个元素X出队。
                if (*pb == *qb) ++qb;//若辅助队列第一个元素等于X，该元素也出队。
                ++pb;
            }
            int tt = f[k] - i * w;
            *++pe = tt;                  //元素X进队
            //删除辅助队列所有小于X的元素，qb到qe单调递减，也可以用二分法
            while(qe >= qb && *qe < tt) --qe;
            *++qe = tt;              //元素X也存放入辅助队列
            f[k] = *qb + i * w;      //辅助队列首元素恒为指定队列所有元素的最大值
        }
    }
}
void check(int f[], int V, int c, int num){
    for(int i = 0; i <= V; i++){
        if(f[i] >= 0) f[i] = num;
        else f[i] = -1;
    }
    for(int i = 0; i <= V-c; i++){
        if(f[i] > 0)
            f[i+c] = max(f[i+c], f[i] - 1);
    }
}//check用来判断答案是否存在的问题
