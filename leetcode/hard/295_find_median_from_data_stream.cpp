//using binary search tree
struct Node{
    int val;
    int count;
    Node* left;
    Node *right;

    Node(int v){
        val = v;
        count = 1;
        left = NULL;
        right = NULL;
    }
};
class MedianFinder {
private:
    Node* root=NULL;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    void addNum(int num) {
        Node* cur = root;
        if(root==NULL){
            root = new Node(num);
            return;
        }
        while(true){
            cur->count++;
            if(cur->val>num){
                if(cur->left==NULL){
                    cur->left = new Node(num);
                    return;
                }
                cur = cur->left;
            }
            else{
                if(cur->right==NULL){
                    cur->right = new Node(num);
                    return;
                }
                cur = cur->right;
            }
        }
    }
    int getNthNumber(int nth){
        Node* cur = root;
        while(true){
            int lNum = 0, rNum = 0;
            if(cur->left){
                lNum += cur->left->count;
            }
            if(cur->right){
                rNum += cur->right->count;
            }
            if(lNum>=nth){
                cur = cur->left;
            }
            else if(nth == lNum+1){
                break; 
            }
            else{
                nth -= lNum+1;
                cur = cur->right;
            }
        }
        return cur->val;
    }
    double findMedian() {
        int cnt = root->count;
        
        if(cnt%2 ==0){
            double result = (double)getNthNumber(cnt/2);
            result += (double)getNthNumber(cnt/2+1);
            return result/2;   
        }
        else{
            return (double)getNthNumber(cnt/2+1);
        }
    }
};

//two heap

