class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> no;
        int fact = 1;

        for(int i=1;i<n;i++){
            fact = fact * i;
            no.push_back(i);
        }
        no.push_back(n);

        k = k-1;
        string ans = "";
        while(true){
            ans = ans + to_string(no[k/fact]);
            no.erase(no.begin() + k/fact);

            if(no.size() == 0){
                break;
            }

            k = k % fact;
            fact = fact / no.size();
        }

        return ans;
    }
};