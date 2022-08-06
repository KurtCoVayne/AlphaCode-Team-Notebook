// O(mod) -- mod debe ser un primo
const int mod;
int inv[mod];
void precalc(){
  inv[1] = 1;
  fore(i,2,mod-1) inv[i] = (mod - (mod/i) * inv[mod%i] % mod) % mod;
}

/////////////////////////////////////
ll inverse(ll a, ll n) {
  ll x, y;
  ll g = eea(a, n, x, y);
  if(g > 1)
    return -1; // "No solution!"
  return (x % n + n) % n;
}