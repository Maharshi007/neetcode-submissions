class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, double>> cars;
        for (int i = 0; i < n; i++) {
            cars.push_back({position[i], static_cast<double>(target - position[i]) / speed[i]});
        }
        sort(cars.begin(), cars.end(), greater<>());
        int fleets = 0;
        double fleetTime = 0.0;
        for (const auto& [pos, time] : cars) {
            if (time > fleetTime) {
                fleets++;
                fleetTime = time;
            }
        }
        return fleets;
    }
};