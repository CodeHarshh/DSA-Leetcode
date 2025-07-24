class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>RadiantQ ,DireQ;

        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R'){
                RadiantQ.push(i);
            }
            else{
                DireQ.push(i);
            }
        }


        while(!RadiantQ.empty() && !DireQ.empty()){
            int r1=RadiantQ.front();
            RadiantQ.pop();
            int d1=DireQ.front();
            DireQ.pop();

            if(r1<d1){
                RadiantQ.push(r1 +senate.size());
            }
            else{
                DireQ.push(d1 +senate.size());
            }


        }
        return RadiantQ.size()>DireQ.size()?"Radiant":"Dire";
    }
};