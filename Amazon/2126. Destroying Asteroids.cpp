class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {

       long long int planet = mass;
       sort(asteroids.begin(), asteroids.end());

        for(int i=0; i<asteroids.size(); i++) {
            if(planet >= asteroids[i]) {
                planet += asteroids[i];
            } else {
                return false; 
            }
        }

        return true;
    }
};
