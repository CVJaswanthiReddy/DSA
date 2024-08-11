class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;
        bool sol = false;  // Initialize sol to avoid undefined behavior
        int i = 0;

        while (i < expression.length()) {
            char c = expression[i];
            if (c == '(' || c == '!' || c == '&' || c == '|' || c == 't' || c == 'f') {
                s.push(c);
            } else if (c == ')') {
                vector<bool> ans;
                // Pop until '(' is found
                while (s.top() != '(') {
                    if (s.top() == 'f') {
                        ans.push_back(false);
                    } else if (s.top() == 't') {
                        ans.push_back(true);
                    }
                    s.pop();
                }
                
                s.pop(); // Remove '('

                char op = s.top();
                s.pop(); // Remove operator

                if (op == '&') {
                    sol = true;
                    for (auto i : ans) {
                        sol &= i;
                    }
                } else if (op == '|') {
                    sol = false;
                    for (auto i : ans) {
                        sol |= i;
                    }
                } else if (op == '!') {
                    sol = !ans[0];
                }
                
                // Push the result into the stack
                s.push(sol ? 't' : 'f');
            }
            i++;
        }
        
        // Return the final result
        return s.top() == 't';
    }
};