class Solution {
public:
// m1 string
    // string longestCommonPrefix(vector<string>& strs) {
        // string ans = "";

        // for (int i = 0; i < strs[0].size(); i++) {
        //     char curr = strs[0][i];
        //     bool match = true;

        //     for (int j = 1; j < strs.size(); j++) {
        //         if (curr != strs[j][i]) {
        //             match = false;
        //             break;
        //         }
        //     }
        //     if (match == false) {
        //         break;
        //     } else {
        //         ans.push_back(curr);
        //     }
        // }
        // return ans;



        //m2 Tries
        // jab tak tries ke single child hai jao and insert krlo  jb multiple child mile toh return
        
class Trienode{
   public:
   char value;
   unordered_map<char,Trienode*>children;
   bool isEndnode;
   
   Trienode(char data){
        value=data;
        isEndnode=false;
   }
};

void insertintoTries(Trienode* root, string word){
       if(word.size()==0){
           root->isEndnode=true;
           return;
       }
       Trienode* child;
       char ch=word[0];
       if(root->children.count(ch)==1){ //  if present then  case
           child=root->children[ch];
       }
       else{ // absent case
           child=new Trienode(ch);
           root->children[ch]=child;
       }
       
       insertintoTries(child,word.substr(1)); // reccursion
   }

   void findLCP(Trienode *root,string &ans){
      if (root->children.size() != 1 || root->isEndnode) {
        return;
    }
    auto it=root->children.begin();
    ans=ans+it->first;
      findLCP(it->second,ans);
   }
   
string longestCommonPrefix(vector<string>& strs) {
   Trienode * root=new Trienode('-');

   for(auto it:strs){ //insert all word into the tries
    insertintoTries(root,it);
   }

   string ans="";
   findLCP(root,ans);
   return ans;
}
};