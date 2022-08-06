int n,m;
const ll neutro = -inf;
ll op(ll a, ll b){ return a+b;}
ll a[nax][nax],st[2*nax][2*nax];
void build(){
	forn(i,n)forn(j,m)st[i+n][j+m]=a[i][j];
	forn(i,n)for(int j=m-1;j;--j)
		st[i+n][j]=op(st[i+n][j<<1],st[i+n][j<<1|1]);
	for(int i=n-1;i;--i)forn(j,2*m)
		st[i][j]=op(st[i<<1][j],st[i<<1|1][j]);
}
void upd(int x, int y, ll v){
	st[x+n][y+m]=v;
	for(int j=y+m;j>1;j>>=1)st[x+n][j>>1]=op(st[x+n][j],st[x+n][j^1]);
	for(int i=x+n;i>1;i>>=1)for(int j=y+m;j;j>>=1)
		st[i>>1][j]=op(st[i][j],st[i^1][j]);
}
ll query(int x0, int x1, int y0, int y1){ // [x0, x1) , [y0,y1)
	ll r=neutro;
	for(int i0=x0+n,i1=x1+n;i0<i1;i0>>=1,i1>>=1){
		int t[4],q=0;
		if(i0&1)t[q++]=i0++;
		if(i1&1)t[q++]=--i1;
		forn(k,q)for(int j0=y0+m,j1=y1+m;j0<j1;j0>>=1,j1>>=1){
			if(j0&1)r=op(r,st[t[k]][j0++]);
			if(j1&1)r=op(r,st[t[k]][--j1]);
		}
	}
	return r;
}