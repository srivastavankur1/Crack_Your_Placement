class Solution{
public:
	string removeDuplicates(string str) {
	    vector<int> ch(255,0);
	    string ans="";
	    int n = str.length();
	    for(int i=0;i<n;i++){
	        if(ch[str[i]]==0){
	            ans.push_back(str[i]);
	            ch[str[i]]++;
	        }
	    }
	    return ans;
	}
};