class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) { 
        vector<pair<int, int>> cars;
        for (int i = 0; i < position.size(); i++) {
            cars.push_back({position[i], speed[i]});
        }
        // Closest to destination first
        sort(cars.rbegin(), cars.rend());
        int fleets = 0;
        double lastTime = 0;
        for (auto& car : cars) {
            int pos = car.first;
            int spd = car.second;
            double time = (double)(target - pos) / spd;
            if (time > lastTime) {
                fleets++;
                lastTime = time;}}
        return fleets;}};