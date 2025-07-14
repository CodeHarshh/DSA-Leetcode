class Solution {
public:

// Short Logic Summary:

// Split the path by / and process each part.
// Skip "" and ".", which mean current directory.
// If "..", pop from stack (go up one level).
// Otherwise, push the valid directory name to the stack.
// Join stack contents with / to form the simplified path.



 string simplifyPath(string path) {
        stack<string>st;
        string ans="";


        for(int i=0;i<path.size();i++){
            if(path[i]=='/') {continue;}
            
               string temp;
                while(i<path.size() && path[i]!='/'){
                temp=temp+path[i];
                i++;
                }
                if(temp==".."){
                     if(!st.empty()) st.pop();
                }
                else if(temp=="."){
                    continue;
                    }else{
                    st.push(temp);
                }  
        }

        while(!st.empty()){
                  ans=+"/"+st.top()+ans;
            st.pop();
        }

   return  ans.size()>0? ans:"/";
    }



















    // string simplifyPath(string path) {
    //     stack<string> st;
    //     int i = 0;
    //     while (i < path.size()) {
    //         int start = i;
    //         int end = i + 1;
    //         while (end < path.size() && path[end] != '/') {
    //             end++;
    //         }
    //         string minpath = path.substr(start, end - start);
    //         i = end;
    //         if (minpath == "/" || minpath == "/.")
    //             continue;
    //         if (minpath != "/..")
    //             st.push(minpath);
    //         else if (minpath == "/.." && !st.empty())
    //             st.pop();
    //     }
    //     string ans = path.empty() ? "/" : "";
    //     while (!st.empty()) {
    //         ans =  st.top() + ans;
    //         st.pop();
    //     }

    //     return ans.empty()? "/":ans;
    // }




    
};