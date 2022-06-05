class TextEditor {
    stack<char> s1,s2;
public:
    TextEditor() {
        stack<char> s;
        s1=s2=s;
    }
    
    void addText(string text) {
        for(auto i:text){
            s1.push(i);
        }
    }
    
    int deleteText(int k) {
        int ans=0;
        while(k-- && !s1.empty()){
            s1.pop();
            ans++;
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        string ans="";
        while(k-- && !s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=10;
        while(x-- && !s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            s1.push(i);
        }
        return ans;
    }
    
    string cursorRight(int k) {
        string ans="";
        while(!s2.empty() && k--){
            s1.push(s2.top());
            s2.pop();
        }
        int x=10;
        while(x-- && !s1.empty()){
            ans.push_back(s1.top());
            s1.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto i:ans){
            s1.push(i);
        }
        return ans;
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */