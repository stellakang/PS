class Solution {
public:
    string countAndSay(int n) {
        string prev_sequence = "1"; 
        
        for(int i=2;i<=n;i++){
            int start = 0;
            string sequence;
            for(int j=1;j<prev_sequence.length();j++){
                if(prev_sequence[j]!=prev_sequence[j-1]){
                    sequence+=to_string(j-start);
                    sequence+=prev_sequence[j-1];
                    start=j;
                }
            }
            sequence+=to_string(prev_sequence.length()-start);
            sequence+=prev_sequence[prev_sequence.length()-1];
            cout<<sequence<<endl;
            prev_sequence=sequence;
        }
        return prev_sequence;
    }
};
