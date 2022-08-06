// Complejidad aprox O(1)
struct dsu{
  vi parents, range; int num_sets;
  void init(int n){
    parents.assign(n, 0), range.assign(n, 1), num_sets = n;
    iota(all(parents), 0);
  }
  int find_set(int i){
    return (parents[i] == i ? i : parents[i] = find_set(parents[i]));
  }
  bool is_same_set(int i, int j){
    return find_set(i) == find_set(j);
  }
  void union_set(int i, int j){
    int x = find_set(i), y = find_set(j);
    if(x == y) return;
    if(range[x] > range[y]) swap(x, y);
    parents[x] = y;
    range[y] += range[x], range[x] = 0;
    --num_sets;
  }
};