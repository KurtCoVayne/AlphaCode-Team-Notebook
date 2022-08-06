//Time complexity O(log n)

ll mulmod(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}

ll binpow(ll b, ll e, ll m){// b = numero - e = exponente - m = modulo
  ll r = 1;
  while(e){
    if(e&1) r = mulmod(r, b,m);
    b = mulmod(b,b,m);
    e = e/2;
  }
  return r;
}

//----------------------------------------------------------------

int binpow(int b, int e) {
	int ans = 1;
	for (; e; b = 1LL*b * b % mod, e /= 2)
		if (e&1) ans = 1LL*ans * b % mod;
	return ans;
}