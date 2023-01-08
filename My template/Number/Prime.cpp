vector<int> primeFact(int n)
{
   vector<int>v;
     for (int i = 2; i * i <= n; i++)
     {
          if (n % i == 0)
          {
               while (n % i == 0)
               {
                    v.push_back(i);
                    n = n / i;
               }
          }
     }
     if (n > 1)
     {
          v.push_back(n);
     }
     return v;
}
void sieve(int n)
{
 
siv.resize(n+5);
siv.assign(n,0);
siv[0]=1;
   siv[1]=1;//returns 1 if not prime
    for(int i=4;i<1000001;i+=2){
        siv[i]=1;
    }
    for(int i=3;i<1000001;i+=2){
        for(int j=3*i;j<1000001;j+=2*i){
            siv[j]=1;
        }
    }
  return;
}
