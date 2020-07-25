class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>cur;
        cur.push_back(1);
        for(int i=1;i<=rowIndex;i++){
            vector<int>nextRow;
            nextRow.push_back(1);
            for(int j=0;j<i-1;j++)
                nextRow.push_back(cur[j]+cur[j+1]);
            for(int j=1;j<i;j++)
                cur[j]=nextRow[j];
            cur.push_back(1);   
        }
        return cur;
    }
};
