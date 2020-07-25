public:
    int lengthOfLongestSubstring(string s) {
        vector<bool>alphabat;
        alphabat.resize(200);
        int longest_substr=0;
        int start_indx=0;
        for(int i=0;i<s.length();i++){
            int alphabat_to_indx = s[i];
            if(alphabat[alphabat_to_indx]==false)
                alphabat[alphabat_to_indx]=true;
            else{
                while(alphabat[alphabat_to_indx]==true){
                    int start_alphabat_to_indx = s[start_indx++];
                    alphabat[start_alphabat_to_indx]=false;
                }
                alphabat[alphabat_to_indx]=true;
            }
            
            if(longest_substr<i-start_indx+1)
                longest_substr = i-start_indx+1; 
        }
            
        return longest_substr;
    }
};
