class LList{
public:
    LList *next;
    LList *prev;
    char val;
    LList(char c){
        val=c;
        next=NULL;
        prev=NULL;
    }
};
class TextEditor {
public:
    bool bl=false;
    LList *cur,*head;
    TextEditor() {
        cur=NULL;head=NULL;
        bl=false;
    }
    
    void addText(string text) {
        // cout<<text<<' ';
        // if(cur==NULL)cout<<0<<'\n';
        // else {
        //     cout<<cur->val<<' ';
        //     if(cur->next)cout<<cur->next->val;
        //     cout<<'\n';
        // }
        for(auto i:text){
            if(cur==NULL){
                cur=new LList(i);
                if(bl==false){
                    head=cur;
                }
                else{
                    cur->next=head;
                    head->prev=cur;
                    head=cur;
                    bl=false;
                }
                continue;
            }
            LList *temp=cur->next,*temp2=cur;
            cur->next=new LList(i);
            cur=cur->next;
            cur->prev=temp2;
            cur->next=temp;
            if(temp)
                temp->prev=cur;
        }
    }
    
    int deleteText(int k) {
        int ans=0;
        while(cur && (k--)){
            ++ans;
            if(cur->prev){
                LList *temp=cur->next;
                cur=cur->prev;
                cur->next=temp;
                if(temp)
                    temp->prev=cur;
            }
            else{
                if(cur->next){
                    head=cur->next;
                    head->prev=NULL;
                    bl=true;
                }
                else{
                    head=NULL;
                    bl=false;
                }
                cur=NULL;
                return ans;
            }
        }
        return ans;
    }
    
    string cursorLeft(int k) {
        while(cur && (k--)){
            if(cur->prev){
                cur=cur->prev;
            }
            else{
                bl=true;
                cur=NULL;
                break;
            }
        }
        LList *temp=cur;
        int x=10;
        string ans="";
        while(x-- && temp){
            ans.push_back(temp->val);
            temp=temp->prev;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    string cursorRight(int k) {
        if(cur==NULL && bl){
            cur=head;
            bl=false;
            k--;
        }
        while(cur && cur->next && (k--)){
            cur=cur->next;
        }
        // cout<<1<<'\n';
        LList *temp=cur;
        int x=10;
        string ans="";
        while(x-- && temp){
            ans.push_back(temp->val);
            temp=temp->prev;
        }
        reverse(ans.begin(),ans.end());
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