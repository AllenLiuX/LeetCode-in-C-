class Solution {
public:
    bool dig(string s){
        if(s!="+" && s!="-" && s!="/"&& s!="*")
            return true;
        return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string ss : tokens){
            if(dig(ss))
                s.push(stoi(ss));
            else{
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                char c = ss[0];
                switch(c){
                    case '+':
                        s.push(a+b);
                        break;
                    case '-':
                        s.push(b-a);
                        break;
                    case '*':
                        s.push(a*b);
                        break;
                    case '/':
                        s.push(b/a);
                        break;
                }
            }
        }
        return s.top();
    }
};