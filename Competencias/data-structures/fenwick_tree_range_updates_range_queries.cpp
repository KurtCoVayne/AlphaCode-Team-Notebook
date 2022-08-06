struct fwtree{// 1-indexed - point update, range query

    vector<int> bit1;
    vector<int> bit2;
    fwtree(int n):n(n){
        bit1.assign(n+1, 0);
        bit2.assign(n+1, 0);
    }


    int rsq(vector &bit, int r){
        int sum = 0; for(; r; r -= r&-r ) sum += bit[r];
        return sum;
    }

    void upd(vector &bit,int r, int v){
        for (; r <= n; r+= r&-r) bit[r] += v;
    }

    int get_range(int a, int b){
        int p = b * rsq(bit1, b) - rsq(bit2, b);
        a = a-1;
        int q = a * rsq(bit1, a) - rsq(bit2, a);
        return p-q;
    }

    void update_range(int a, int b, int v){
        upd (bit1, a, v);
        upd (bit1, b+1, -v);
        upd (bit2, a, v*(a-1));
        upd (bit2, b+1, -b*v);
    }

}