class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {

        vector<vector<int>> rest = restaurants;
        vector<int> res;

        if (veganFriendly == 1) {
            //sort restasurants and eliminate all which !veganFriendly

            sort(rest.begin(), rest.end(), [ = ](vector<int> x, vector<int> y) {
                return x[2] < y[2];
            });

            int idx = 0;
            while (rest[idx][2] == 0) {
                idx++;
                if (idx == rest.size()) {
                    break;
                }
            }

            //clearing from 0 to idx
            vector<vector<int>>::iterator itr = rest.begin();
            rest.erase(itr, itr + idx);

        }

        //sort by price and remove all greater than max price

        sort(rest.begin(), rest.end(), [ = ](vector<int> x, vector<int> y) {
            return x[3] > y[3];
        });

        if (rest.size() > 0) {

            int idx = 0;
            while (rest[idx][3] > maxPrice) {
                idx++;
                if (idx == rest.size()) {
                    break;
                }
            }

            //clearing from 0 to idx
            vector<vector<int>>::iterator itr = rest.begin();

            rest.erase(itr, itr + idx);

        }

        //sort by distance and remove all greater than max distance

        sort(rest.begin(), rest.end(), [ = ](vector<int> x, vector<int> y) {
            return x[4] > y[4];
        });

        if (rest.size() > 0) {
            idx = 0;
            while (rest[idx][4] > maxDistance) {
                idx++;
                if (idx == rest.size()) {
                    break;
                }
            }

            //clearing from 0 to idx

            itr = rest.begin();
            rest.erase(itr, itr + idx);

        }


        //sort by rating and if rating is same, higher id comes first
        sort(rest.begin(), rest.end(), [](vector<int> x, vector<int> y) {
            if (x[1] == y[1]) {
                return x[0] > y[0];
            }
            return x[1] > y[1];
        });

        for (auto x : rest) {
            res.push_back(x[0]);
        }

        return res;
    }
};

Runtime: 492 ms, faster than 5.36 % of C++ online submissions for Filter Restaurants by Vegan - Friendly, Price and Distance.
Memory Usage : 141.1 MB, less than 5.36 % of C++ online submissions for Filter Restaurants by Vegan - Friendly, Price and Distance.

Demux Instructors solution :

    class Solution {
    public:
        vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
                vector<vector<int>> filteredRest;
                vector<int> finalRest;

                for (int i = 0; i < restaurants.size(); i++) {
                    // vegan
                    if ((veganFriendly && restaurants[i][2] == 1) && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                        filteredRest.push_back(restaurants[i]);
                    } // Not vegan
                    else if (!veganFriendly && restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance) {
                        filteredRest.push_back(restaurants[i]);
                    }
                }


                // Sortig using rating (if same then id) in descending order
                sort(filteredRest.begin(), filteredRest.end(), [](vector<int> a, vector<int> b) {
                    return a[1] > b[1] || (a[1] == b[1] && a[0] > b[0]);
                });

                // Push the id of filtered restaurants inside finalRes
                for (int i = 0; i < filteredRest.size(); i++) {
                    finalRest.push_back(filteredRest[i][0]);
                }

                return finalRest;

            }
        };

Sample 132ms solution :
class Solution {
    static bool cmp(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] == v2[1] ? v1[0] > v2[0] : v1[1] > v2[1];
    }

public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> res;

        for (int i = 0; i < restaurants.size(); i++) {
            if (!restaurants[i][2] && veganFriendly) continue;//be careful
            if (restaurants[i][3] > maxPrice) continue;
            if (restaurants[i][4] > maxDistance) continue;
            res.push_back(restaurants[i]);
        }

        sort(res.begin(), res.end(), cmp);

        vector<int> ids;
        for (int i = 0; i < res.size(); i++) ids.push_back(res[i][0]);
        return ids;
    }
};

C++ Simple Vector - pair Solution

class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& res, int veg, int mp, int md) {
        vector<vector<int>>out;
        for (int i = 0; i < res.size(); i++) {
            if (res[i][2] >= veg) {
                if (res[i][3] <= mp && res[i][4] <= md) {
                    out.push_back({res[i][1], res[i][0]});
                }
            }
        }
        sort(out.begin(), out.end(), greater());
        vector<int>ans;
        for (int i = 0; i < out.size(); i++) {
            ans.push_back(out[i][1]);
        }
        return ans;
    }
};

