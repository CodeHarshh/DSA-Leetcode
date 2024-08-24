class Solution {
    // we can also use vector<pair> intead of
    class Car {
    public:
        int pos, speed;
        Car(int p, int s) : pos(p), speed(s){};
    };
    static bool mycomp(Car& a, Car& b) { return a.pos < b.pos; }

public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<Car> cars;
        for (int i = 0; i < position.size(); i++) {
            Car car(position[i], speed[i]);
            cars.push_back(car);
        }
        sort(cars.begin(), cars.end(), mycomp);

        stack<float> st;

        for (auto it : cars) {
            float time = (float)(target - it.pos) / it.speed;
            // time >> so it will take more time to
            while (!st.empty() && time >= st.top()) {
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};