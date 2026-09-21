class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> qR;
        queue<int> qD;
        int i = 0;
        for(char ch : senate){
            if(ch=='R'){
                qR.push(i);
                i++;
            }
            else{
                qD.push(i);
                i++;
            }
        }
        while(!qR.empty() && !qD.empty()){
            if(qR.front()<qD.front()){
                int idx = qR.front();
                qR.pop();
                qD.pop();
                qR.push(idx+i);
            }
            else{
                int idx = qD.front();
                qR.pop();
                qD.pop();
                qD.push(idx+i);
            }
        }
        return !qR.empty() ? "Radiant" : "Dire";
    }
};