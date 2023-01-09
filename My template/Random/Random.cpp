#include<bits/stdc++.h>
//#include "ext/pb_ds/assoc_container.hpp" 
#include "ext/pb_ds/tree_policy.hpp" 
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
 
//************************************************DEFiNED FUNCTION//*********************************************
 
 
   #define int long long
   #define M   1000000007
   #define M1  998244353 
   #define pb   push_back
   #define desc greater<int>
   #define F first
   #define S second
   #define sz(x) ((int)(x).size())
   #define ina(a,n) for(int i = 0 ; i < n ; i ++){ cin >> a[i];}
   #define inv(a,n) for(int i = 0 ; i < n ; i ++){ int x; cin>>x; a.push_back(x);}
   #define len(x) x.length()
   #define all(v) v.begin(), v.end()
   #define allr(v) v.rbegin(),v.rend()
   #define fl(i, a, b) for(int i = a; i < b; i++)
   #define rfl(i, a, b) for(int i = a; i > b; i--)
   #define vll vector<int> 
   #define PIE 3.141592653589793238462
   #define set_bits __builtin_popcountll
   #define lld long double 
   #define string_to_int stoull(s, 0, 2)
   #define mem(arr, v) memset(arr, v, sizeof(arr))
  #define el "\n" 
   #define ull unsigned long long
   #define no cout<<"NO"<<el
   #define yes cout<<"YES"<<el
   #define INF 1e18
 
 
 
 
 

 
/*+++++++++++++++++++++++++++++++++++++++++++++++DEBUG++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#define pri(x);  _kasu(x); cout << endl
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
 

const int ch_MAX = 2;
string RandomString(int ch)
{
    char alpha[ch_MAX] = {'1','0'};
    string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_MAX];

    return result;
}
void random_bool_string(int n){
srand(time(NULL));
string a = "";
a +=RandomString(n);
      unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
 
std::shuffle(std::begin(a), std::end(a), std::default_random_engine(seed));
cout<<a<<"\n";
}
void random_permutaton(int n){
    vector<int> v(n,0);
    fl(i,0,n){
        v[i] = i+1;
    }
      unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
 
    std::shuffle(std::begin(v), std::end(v), std::default_random_engine(seed));
 
    pri(v);
}
const int ch_X = 26;
string RandString(int ch)
{
    char alpha[ch_X] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                          'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u',
                          'v', 'w', 'x', 'y', 'z' };
    string result = "";
    for (int i = 0; i<ch; i++)
        result = result + alpha[rand() % ch_X];

    return result;
}
void random_string(int n){
srand(time(NULL));
int ch = n;
string a = "";
a +=RandString(ch);
      unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();
 
std::shuffle(std::begin(a), std::end(a), std::default_random_engine(seed));
cout<<a<<"\n";
}
void rand_sortedvector(int n){
    vector<int> myVector;
srand((unsigned)time(NULL));
for (int i =0; i < n; i++){
        int b = rand() % 10 + 1;//size of element
        myVector.push_back(b);
    }
    sort(all(myVector));
    pri(sz(myVector));
    pri(myVector);
}
void rand_vector(int n){
        vector<int> myVector;
srand((unsigned)time(NULL));
for (int i =0; i < n; i++){
        int b = rand() % 10 + 1;//size of element
        myVector.push_back(b);
    }
    pri(sz(myVector));
    pri(myVector);
}
void random_number(){
   srand((unsigned)time(NULL));
   int k = rand()%10+1;
   pri(k);
}
void Ka_su(){
//test case analyse kro and then start kro solve krna...khud se ustadi nhiiiiii
int n = 8;//size
random_bool_string(n);
random_permutaton(n);
random_string(n);
rand_vector(n);
rand_sortedvector(n);
random_number();
}

signed main(){
 

              ios_base::sync_with_stdio(false);
              cin.tie(NULL);
auto start1 = high_resolution_clock::now();
              int t=1;
             // cin>>t;
              fl(i,0,t){
            //cout<<"Case"<<" "<<#<<i+1<<" ";
 Ka_su();
              }
auto stop1 = high_resolution_clock::now();
auto duration = duration_cast<microseconds>(stop1 - start1);
//cout << "Time"<<':' << duration.count() / 1000 << endl;
return 0;
}
