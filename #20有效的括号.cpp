class Solution {
public:
    bool isValid(string s) {
        bool res = true;
        stack<char> sta;
        for(char c : s){
            if(sta.empty() && c!='(' && c!='[' && c!='{'){
                return false;
            }
            switch (c){
                case '(':
                    sta.push('(');
                    break;
                case '[':
                    sta.push('[');
                    break;
                case '{':
                    sta.push('{');
                    break;
                case ')':
                    if(sta.top()=='(')
                        sta.pop();
                    else
                        res=false;
                    break;
                case ']':
                    if(sta.top() =='[')
                        sta.pop();
                    else
                        res=false;
                    break;
                case '}':
                    if(sta.top()=='{')
                        sta.pop();
                    else
                        res=false;
                    break;
                default:
                    res=false;
                    break;
            }
            if(!res)
                return false;
        }
        if(sta.empty())
            return true;
        else
            return false;
    }
};