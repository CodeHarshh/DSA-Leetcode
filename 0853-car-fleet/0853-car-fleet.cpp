class Solution {
    public:
//     // we can also use vector<pair> intead of
//     class Car {
//     public:
//         int pos, speed;
//         Car(int p, int s) : pos(p), speed(s){};
//     };
//     static bool mycomp(Car& a, Car& b) { return a.pos < b.pos; }

// public:
//     int carFleet(int target, vector<int>& position, vector<int>& speed) {
//         vector<Car> cars;
//         for (int i = 0; i < position.size(); i++) {
//             Car car(position[i], speed[i]);
//             cars.push_back(car);
//         }
//         sort(cars.begin(), cars.end(), mycomp);

//         stack<float> st;

//         for (auto it : cars) {
//             float time = (float)(target - it.pos) / it.speed;
//             // time >> so it will take more time to
//             while (!st.empty() && time >= st.top()) {
//                 st.pop();
//             }
//             st.push(time);
//         }
//         return st.size();
//     }




    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float>fleets;
        vector<pair<int,float>>v;

        for(int i=0;i<position.size();i++){
          v.push_back({position[i], float(target - position[i]) / speed[i]}); // (postion , time to reach)
        }

       // Sort by position descending using rbegin/rend
        sort(v.begin(), v.end());

        for(int i=0;i<position.size();i++){
          float temp=v[i].second;   // time to reach to destination

          while(!fleets.empty() && temp>=fleets.top()){
            fleets.pop();
          }      

          fleets.push(temp);

         }

    return fleets.size();

    }
};