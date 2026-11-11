class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> vec;

        for(int i = 0; i < position.size(); i++){
            double time = (double)(target - position[i]) / speed[i];
            vec.push_back({position[i], time});
        }

        sort(vec.rbegin(), vec.rend());

        int fleets = 0;
        double curr_time = 0;

        for(auto item : vec){
            if(item.second > curr_time){
                curr_time = item.second;
                fleets++;
            }
        }

        return fleets;
    }
};