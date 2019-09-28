#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool sortcol( const vector<double>& v1,
              const vector<double>& v2 ) {
    return v1[1] > v2[1];
}


int main() {
    int amountOfPortions;
    int amountOfFood;
    cin >> amountOfFood;
    cin >> amountOfPortions;

    vector<vector<double>> foodsAtBuffet(amountOfFood);
    for(int i = 0;i < amountOfFood; i++){
        vector<double> food(2);
        string nameOfFood; // does not matter
        cin >> nameOfFood;
        cin >> food[0];
        cin >> food[1];
        foodsAtBuffet[i] = food;
    }
    sort(foodsAtBuffet.begin(), foodsAtBuffet.end(),sortcol);


    double score = 0;
    int portionsAlreadyTaken = 0;
    int currentIndex = 0;
    while(portionsAlreadyTaken < amountOfPortions){
        if(foodsAtBuffet[currentIndex][0] <= 0){
            currentIndex++;
        }
        score += foodsAtBuffet[currentIndex][1];
        foodsAtBuffet[currentIndex][0]--;
        portionsAlreadyTaken++;
    }

    cout << score << endl;
    return 0;
}
