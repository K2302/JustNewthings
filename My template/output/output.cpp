#define print(x);  _kasu(x); cout << endl
void     _kasu(int t) {cout << t;}
void     _kasu(string t) {cout << t;}
void     _kasu(char t) {cout << t;}
void     _kasu(lld t) {cout << t;}
void     _kasu(double t) {cout << t;}
void     _kasu(ull t) {cout << t;}
template <class T> void     _kasu(stack<T> v){while(!v.empty()){    _kasu(v.top()); cout<<' ' ; v.pop();}}
template <class T> void     _kasu(list<T> v) {  for(auto i: v){    _kasu(i);cout << ' ' ;} }
template <class T, class V> void     _kasu(pair <T, V> p) {     _kasu(p.first); cout <<' ';_kasu(p.second);}
template <class T> void     _kasu(vector <T> v) {  for (T i : v) {    _kasu(i);cout<<' '; } }
template <class T> void     _kasu(set <T> v) {  for (T i : v) {    _kasu(i); cout << ' ';}  }
template <class T> void     _kasu(multiset <T> v) {  for (T i : v) {    _kasu(i); cout << ' ';} }
template<class T1, class T2> void _kasu(map<T1,T2> m) {for(auto x:m) cout<<x.F<<"->"<<x.S<<el; cout<<el;}
template<class T1, class T2> void _kasu(unordered_map<T1,T2> m) {for(auto x:m) cout<<x.F<<"->"<<x.S<<el; cout<<el;}
template<class T1, class T2> void _kasu(map<T1,vector<T2>> m) {for(auto x:m) {cout<<x.F<<"->";_kasu(x.S);} cout<<el;}
template<class T1, class T2> void _kasu(unordered_map<T1,vector<T2>> m) {for(auto x:m) {cout<<x.F<<"->";_kasu(x.S);} cout<<el;}
