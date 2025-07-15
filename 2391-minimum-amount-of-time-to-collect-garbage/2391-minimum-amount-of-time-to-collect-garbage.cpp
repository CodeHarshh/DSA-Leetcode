class Solution {
public:
    // int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    //     // Papper Truck Picking time,Travling Time, LastHousePostion
    //     int pickp = 0, travelp = 0, lasthousep = 0;

    //     // Metal Truck  Picking time,Travling Time, LastHousePostion
    //     int pickm = 0, travelm = 0, lasthousem = 0;
        
    //     // Glass Truck  Picking time,Travling Time, LastHousePostion
    //     int pickg = 0, travelg = 0, lasthouseg = 0;

    //     for (int i = 0; i < garbage.size(); i++) {
    //         string currHouse = garbage[i];
    //         for (int j = 0; j < currHouse.size(); j++) {
    //             char garbagetype = currHouse[j];
    //             if (garbagetype == 'P') {
    //                 pickp++;
    //                 lasthousep = i;
    //             }
    //             if (garbagetype == 'G') {
    //                 pickg++;
    //                 lasthouseg = i;
    //             }
    //             if (garbagetype == 'M') {
    //                 pickm++;
    //                 lasthousem = i;
    //             }
    //         }
    //     }
    //     for (int i = 0; i < lasthousep; i++) {
    //         travelp = travelp + travel[i];
    //     }
    //     for (int i = 0; i < lasthouseg; i++) {
    //         travelg = travelg + travel[i];
    //     }
    //     for (int i = 0; i < lasthousem; i++) {
    //         travelm = travelm + travel[i];
    //     }
    //     int totalpickingtime = pickp + pickm + pickg;
    //     int totaltraveltime = travelp + travelg + travelm;
    //     int ans = totalpickingtime + totaltraveltime;
    //     return ans;
    // }



     int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP=0, TotalTimeP=0, LastHouseP=0;
        int pickM=0, TotalTimeM=0, LastHouseM=0;
        int pickG=0, TotalTimeG=0, LastHouseG=0;

        for(int i=0;i<garbage.size();i++){
            string currentHouse=garbage[i];
            for(int j=0;j<currentHouse.size();j++){
                if(currentHouse[j]=='G'){
                pickG++;
                LastHouseG=i;
                }
                if(currentHouse[j]=='M'){
                    pickM++;
                    LastHouseM=i;
                
               }
                if(currentHouse[j]=='P'){
                    pickP++;
                    LastHouseP=i;
               }
           }
        }
        for(int i=0;i<LastHouseP;i++){
            TotalTimeP=TotalTimeP+travel[i];
        }
           for(int i=0;i<LastHouseG;i++){
            TotalTimeG=TotalTimeG+travel[i];
        }
           for(int i=0;i<LastHouseM;i++){
            TotalTimeM=TotalTimeM+travel[i];
        }

    int totalTimeTake= (TotalTimeP+TotalTimeG+TotalTimeM) + (pickP+pickM+pickG);
    return totalTimeTake;
    }
};