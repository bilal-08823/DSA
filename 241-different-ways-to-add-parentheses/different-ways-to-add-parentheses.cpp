class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char ch = expression[i];

            if (ch == '+' || ch == '-' || ch == '*') {
                vector<int> left =
                    diffWaysToCompute(expression.substr(0, i));

                vector<int> right =
                    diffWaysToCompute(expression.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (ch == '+')
                            ans.push_back(a + b);
                        else if (ch == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        if (ans.empty()) {
            ans.push_back(stoi(expression));
        }

        return ans;
    }
};