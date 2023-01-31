    while (tail < n)
    {   
        while ((head + 1 < n) && (mp[arr[head + 1]]>0 || cnt + 1 <= k))
        {
            head++;
            //cout<<mp[arr[head]]<<" ";
//             mp[arr[head]]++;
//             if (mp[arr[head]] == 1)
//                 cnt++;
        }
        // update ans for [tail to head]
        int x = (head - tail + 1);
        ans += x; 
 
        if (tail <= head)
        { 
          // for a non empty window
          //Condition can change
          //delete the last element
            mp[arr[tail]]--;
            if(mp[arr[tail]]==0){
                cnt--;
            }
            tail++;
        }
        else
        {//for empty subarray
            tail++;
            head = tail - 1;
        }
    }
