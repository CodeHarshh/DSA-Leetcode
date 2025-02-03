class Solution {
public:
// here we are taking top 2 elements sub (-1) and push them back & cnt++ 
    int maximumScore(int a, int b, int c) {
        priority_queue<int>pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        int cnt=0;
        while(true){
            int top1=pq.top(); pq.pop();
            int top2=pq.top(); pq.pop();
            if(top1==0 && top2==0 || top1!=0 && top2==0 || top1==0 && top2!=0 ){
                break;
            }
            top1=top1-1;
            top2=top2-1;
            pq.push(top1);
            pq.push(top2);
            cnt++;

        }
        return cnt;
    }
};