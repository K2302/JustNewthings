struct window_property{
	map<int,int> mp;
	void insert(int x){
		mp[x]++;
	}
	void remove(int x){
		mp[x]--;
		if(mp[x]==0){
			mp.erase(x);
		}
	}
	int distinct(){
		return mp.size();
	}
	bool can_take(int x){
		int will_inc_distinct = (mp.find(x)==mp.end()?1:0);
		return distinct()+will_inc_distinct <= k;
	}
};

void solve(){
	cin>>n;	
	cin>>k;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}

	long long ans = 0;
	// two pointers
	int head=-1,tail=0;
	// maintaining property
	window_property cur_win;

	while(tail<n){ // while start < n
		// process this start index.
		
		while( head+1<n && cur_win.can_take(arr[head+1])){ 
			// we can take more elements
			// if the next element exists and by taking it, we are not exceeding the limit of k 0's
			head++;
			cur_win.insert(arr[head]);
		}
		// [tail... head] we can take... tail -> head.
		// process answer for this window
		ans += head-tail+1;
		
		// move tail one step
		if(head<tail){ // .....[1]
			// edge case.
			tail++;
			head=tail-1;
		}else{
			// normal
			cur_win.remove(arr[tail]);
			tail++;
		}
	}
	cout<<ans<<endl;
