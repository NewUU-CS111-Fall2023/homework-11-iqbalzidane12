/*
 * Author:
 * Date:
 * Name:
 */
//Muxtorov Abdulaziz
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        char d[128]{};
        d[' '] = ' ';
        char i = 'a';

        for (char& c : key) {
            if (!d[c]) {
                d[c] = i++;
            }
        }

        for (char& c : message) {
            c = d[c];
        }

        return message;
    }
};

int task_5 () {
    Solution solution;

    string key = "eljuxhpwnyrdgtqkviszcfmabo";
    string message = "zwx hnfx lqantp mnoeius ycgk vcnjrdb";

    string decodedMessage = solution.decodeMessage(key, message);
    cout << "Decoded Message: " << decodedMessage << endl;

    return 0;
}
