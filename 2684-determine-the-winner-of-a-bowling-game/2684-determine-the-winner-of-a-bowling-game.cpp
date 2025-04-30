class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int s1 = player1[0];
        int s2 = player2[0];

        if (player1.size() == 1) {
            return s1 == s2 ? 0 : (s1 > s2 ? 1 : 2);
        }

        s1 += (player1[0] == 10) ? 2 * player1[1] : player1[1];
        s2 += (player2[0] == 10) ? 2 * player2[1] : player2[1];

        for (int i = 2; i < player1.size(); i++) {
            if (player1[i - 1] == 10 || player1[i - 2] == 10) {
                s1 += 2 * player1[i];
            } else {
                s1 += player1[i];
            }
            if (player2[i - 1] == 10 || player2[i - 2] == 10) {
                s2 += 2 * player2[i];
            } else {
                s2 += player2[i];
            }
        }

        return s1 == s2 ? 0 : (s1 > s2 ? 1 : 2);
    }
};
