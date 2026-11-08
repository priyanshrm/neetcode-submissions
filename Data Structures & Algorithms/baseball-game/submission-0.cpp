class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> res;
        auto it = res.begin();
        for(int i = 0; i<operations.size(); i++){
            if(operations[i] != "+" && operations[i] != "D" && operations[i] != "C"){
                res.push_back(stoi(operations[i]));
                continue;
            }
            if(operations[i] == "+"){
                it = res.end()-1;
                int sum = *it;
                it--;
                sum += *it;
                res.push_back(sum);
                continue;
            }
            if(operations[i] == "D"){
                it = res.end() - 1;
                int prod = 2*(*it);
                res.push_back(prod);
                continue;
            }
            if(operations[i] == "C"){
                res.pop_back();
            }
        }
        int sum = 0;
        for(auto num: res){
            sum += num;
        }
        return sum;
    }
};