class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> s;
        queue<string> q;

        int count = 0;
        q.push(startGene);
        s.insert(startGene);

        while(!q.empty()) {
            string temp = q.front();
            q.pop();

            if(endGene == temp) return count;

            for(auto ch : "ACGT") {
                for(int j=0; j<temp.size(); j++) {
                    string temp2 = temp;
                    temp2[j] = ch;
                    if(s.find(temp2) == s.end() && find(bank.begin(), bank.end(), temp2) != bank.end()) {
                        q.push(temp2);
                        s.insert(temp2);
                    }
                }
            }

            count++;
        }

        return -1;
    }
};
