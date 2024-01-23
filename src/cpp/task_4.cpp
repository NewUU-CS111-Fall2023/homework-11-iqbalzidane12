/*
 * Author:
 * Date:Abdulaziz
 * Name:
 */
class task_4 {
private:
    static const int MOD = 1337;

    int powMod(int a, int b) {
        if (b == 0) return 1;
        a = a % MOD;
        int res = a;
        for (int i = 1; i < b; i++)
            res = (res * a) % MOD;
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        a = a % MOD;
        if (a == 0) return a;
        if (b.empty()) return 1;
        int res = powMod(a, b[0]);
        for (int i = 1; i < b.size(); i++)
            res = (powMod(res, 10) * powMod(a, b[i])) % MOD;
        return res;
    }
};

