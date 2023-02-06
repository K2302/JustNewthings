int ans = 0;
	// two pointers
	int head=-1,tail=0;
	// maintaining property
	int count0 = 0;

	while(tail<n){ // while start < n
		// process this start index.
		
		while( head+1<n && (count0 + (arr[head+1]==0?1:0) )<= k){ 
			// we can take more elements
			// if the next element exists and by taking it, we are not exceeding the limit of k 0's
			head++;
			if(arr[head]==0){
				count0++;
			}
		}
		// [tail... head] we can take... tail -> head.
		// process answer for this window
		ans = max(ans,(head-tail+1));
		
		// move tail one step
		if(head<tail){ // .....[1]
			// edge case.
			tail++;
			head=tail-1;
		}else{
			// normal
			if(arr[tail]==0)count0--;
			tail++;
		}
	}
	cout<<ans<<endl;
