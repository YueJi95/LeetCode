struct node{
    int left;
    int right;
    int val;
    node* lc;
    node* rc;
    node* p;
};

class rangetree{
public:
    node* root;
    
    rangetree(int l){
        root = new node;
        root->val = 0;
        root->left = 0;
        root->right = l-1;
        root->lc = nullptr;
        root->rc = nullptr;
    }
    
    void update(int l, int r, int v, node* rt){
        if(rt == nullptr) return;
        if(rt->left == l && rt->right == r){
            rt->val = rt->val + v;
            return;
        }
        int mid = (rt->left + rt->right) / 2;
        if(r <= mid){
            if(rt->lc == nullptr){
                node* a = new node;
                a->lc = nullptr;
                a->rc = nullptr;
                a->left = rt->left;
                a->right = mid;
                a->val = 0;
                rt->lc= a;
            }
            update(l, r, v, rt->lc);
        }
        else if(l > mid){
            if(rt->rc == nullptr){
                node* a = new node;
                a->lc = nullptr;
                a->rc = nullptr;
                a->left = mid+1;
                a->right = rt->right;
                a->val = 0;
                rt->rc= a;
            }
            update(l, r, v, rt->rc);
        }
        else{
            if(rt->lc == nullptr){
                node* a = new node;
                a->lc = nullptr;
                a->rc = nullptr;
                a->left = rt->left;
                a->right = mid;
                a->val = 0;
                rt->lc= a;
            }
            if(rt->rc == nullptr){
                node* a = new node;
                a->lc = nullptr;
                a->rc = nullptr;
                a->left = mid+1;
                a->right = rt->right;
                a->val = 0;
                rt->rc= a;
            }
            update(l, mid, v, rt->lc);
            update(mid+1, r, v, rt->rc);
        }
    }
    
    int lookup(int x){
        int result = 0;
        node* pos = root;
        while(pos != nullptr){
            if(pos->left == pos->right){
                result = result + pos->val;
                break;
            }
            int mid = (pos->left + pos->right) / 2;
            if(x <= mid){
                if(pos->lc == nullptr){
                    result = result + pos->val;
                    break;
                }
                else{
                    result = result + pos->val;
                    pos = pos->lc;
                }
            }
            else{
                if(pos->rc == nullptr){
                    result = result + pos->val;
                    break;
                }
                else{
                    result = result + pos->val;
                    pos = pos->rc;
                }
            }
        }
        return result;
    }
    
};

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> result;
        if(length == 0) return result;
        rangetree t(length);
        for(int i = 0; i < updates.size(); i++){
            t.update(updates[i][0], updates[i][1], updates[i][2], t.root);
        }
        for(int i = 0; i < length; i++){
            result.push_back(t.lookup(i));
        }
        return result;
    }
    
};