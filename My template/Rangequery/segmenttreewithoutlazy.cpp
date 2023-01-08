// Building the Segment Tree - S.build(a), a must be a vector and 1-indexed
// Point updates - S.update(index, value) ;
// Range updates - S.updateRange(starting_pos, ending_pos, value, "type");
// type - "add" , adds value to each element from starting_pos to ending_pos
// type - "set" , sets every element to value from starting_pos to ending_pos
// Query - S.query(starting_pos, ending_pos)  ;

template <typename T>
struct SegTree
{
     int n, type;
     T CNST;
     vector<T> tree;
     vector<bool> isSet;
     SegTree(int x)
     {
          n = x;
          tree.resize(4 * n + 5);
          isSet.resize(4 * n + 5);
          CNST = 0;
     }
     inline T merge(T a, T b)
     {
          return a + b;
     }
     inline T merge1(T a, T b)
     {
          return a | b;
     }
     void _build(int level, int start, int end, vector<T> &a)
     {
          if (start == end)
          {
               tree[level] = a[start];
               return;
          }
          _build(level << 1, start, start + end >> 1, a);
          _build(level << 1 | 1, (start + end >> 1) + 1, end, a);
          tree[level] = merge(tree[level << 1], tree[level << 1 | 1]);
     }
     void _update(int level, int start, int end, int idx, T data)
     {
          if (start == end)
          {
               tree[level] = data;
               return;
          }
          if (start <= idx and idx <= (start + end >> 1))
               _update(level << 1, start, start + end >> 1, idx, data);
          else
               _update(level << 1 | 1, (start + end >> 1) + 1, end, idx, data);
          tree[level] = merge(tree[level << 1], tree[level << 1 | 1]);
     }
     inline void update(int idx, T val) { _update(1, 1, n, idx, val); }
     inline void build(vector<T> &a) { _build(1, 1, n, a); }

         T _query(int level, int sta, int e,int l, int r) {
             if(l > r) return CNST ;
             if(l <= sta && e <= r) return tree[level] ;
            // push(v) ;
             int m = sta+e >> 1;
             return merge(_query(level<<1,sta,m,l,min(r,m)),_query(level<<1|1,m+1,e,max(l,m+1),r)) ;
         }
     inline T query(int l, int r) { return _query(1,1,n,l,r); }
};
