/// Complexity: O(log(|N|))
/// Tested: https://tinyurl.com/y8yc52gv
ll eea(ll a, ll b, ll& x, ll& y) {
  ll xx = y = 0; ll yy = x = 1;
  while (b) {
    ll q = a / b; ll t = b; b = a % b; a = t;
    t = xx; xx = x - q * xx; x = t;
    t = yy; yy = y - q * yy; y = t;
  }
  return a;
}
// a*x+b*y = g
bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g) {
  g = eea(abs(a), abs(b), x0, y0);
  if (c % g) return false;

  x0 *= c / g;
  y0 *= c / g;
  if (a < 0) x0 = -x0;
  if (b < 0) y0 = -y0;
  return true;
}