#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long encryptMessage(long long message, long long keyIndex, vector<long long> sortedKeys){
    return message - sortedKeys[keyIndex-1];
}

int main() {
    //input
    long long amountKeys;
    long long amountMessages;
    cin >> amountKeys;
    cin >> amountMessages;
    vector<long long> unsortedKeys(amountKeys);
    vector<vector<long long>> messages(amountMessages);
    for(long long i= 0; i < amountKeys;i++){
        cin >> unsortedKeys[i];
    }
    for(long long i = 0; i < amountMessages; i++){
        vector<long long> message(2);
        cin >> message[0];
        cin >> message[1];
        messages[i] = message;
    }
    sort(unsortedKeys.begin(),unsortedKeys.end());
    vector<long long> encryptedMessages(amountMessages);

    for(long long i = 0; i < amountMessages;i++){
        encryptedMessages[i] = encryptMessage(messages[i][0], messages[i][1], unsortedKeys);
    }
    for(long long encryptedMessage:encryptedMessages){
        cout << encryptedMessage << endl;
    }
    return 0;
}
