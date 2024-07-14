//Using stack
//T.C : O(n^2)
//S.C : O(n)

class Solution {
public:
    string countOfAtoms(string formula) {
        int n=formula.size();
        stack<unordered_map<string,int>>st;
        st.push(unordered_map<string,int>());
        int i=0;
        while(i<n){
            if(formula[i]=='('){
                st.push(unordered_map<string,int>());
                i++;
            }else if(formula[i]==')'){
                unordered_map<string,int>curr=st.top(); 
                st.pop();
                i++;

                string multi;
                while(i<n && isdigit(formula[i])){
                    multi+=formula[i];
                    i++;
                } 
                if(!multi.empty()){
                    int val=stoi(multi);
                    for(auto &it:curr){
                    curr[it.first]=val*it.second;  
                    }
                }
                //merge top stack into next one
                for(auto &it:curr){
                    st.top()[it.first]+=it.second;
                }

            }else{
                string pre;
                pre+=formula[i];
                i++;
                while(i<n && isalpha(formula[i]) &&  islower(formula[i])){
                    pre+=formula[i];
                    i++;
                }
                string c;
                while(i<n && isdigit(formula[i])){
                    c+=formula[i];
                    i++;
                }
                int count= c.empty()? 1:stoi(c);
                st.top()[pre]=count;

            }
        }
        //st will only one map
        map<string,int>mp(st.top().begin(),st.top().end());
        string res;
        for(auto it:mp){
            res+=it.first;
            if(it.second>1)
            {res+=to_string(it.second);}
        }
        return res;


    }
};