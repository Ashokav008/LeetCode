//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string s, string e, vector<string>& arr) {
        // Code here
        queue<string>q;
        q.push(s);
        unordered_set<string>st;
        for(auto &str: arr)     st.insert(str);
        
        st.erase(s);
        int step=1;
        while(!q.empty()){
            
            int sz=q.size();
            while(sz--){
                
                string front=q.front();
                q.pop();
                if(front==e)
                    return step;
                string curr=front;
                for(int i=0;i<front.size();i++){
                    char ch=curr[i];
                    for(char c='a';c<='z';c++){
                        if(c!=ch)
                            curr[i]=c;
                        if(st.find(curr)!=st.end()){
                            if(curr==e)
                                return step+1;
                            q.push(curr);
                            st.erase(curr);
                            // cout<<curr<<" ";
                        }
                        
                    }
                    // break;
                    curr[i]=ch;
                    
                    // cout<<endl;
                      
                }
                
            }
            step++;
            
            
            
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends