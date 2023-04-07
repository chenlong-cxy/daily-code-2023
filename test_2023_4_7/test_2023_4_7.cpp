#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int ma;
  cin>>ma;
  vector<int> num1(ma);
  for(int i = ma-1;i >= 0;i--)
  	cin>>num1[i];
  int mb;
  cin>>mb;
  vector<int> num2(mb);
  for(int i = mb-1;i >= 0;i--)
  	cin>>num2[i];
  vector<int> w(max(ma, mb));
  for(int i = 0;i < w.size();i++) {
    int a = i < ma?num1[i]:0;
    int b = i < mb?num2[i]:0;
    w[i] = max(2, max(a, b)+1);
  }
  int ret = 0;
  int tmp = 1;
  for(int i = 0;i < w.size();i++) {
    int n1 = i < ma?num1[i]:0;
    int n2 = i < mb?num2[i]:0;
    ret = (ret + (n1-n2)*tmp)%1000000007;
    tmp *= w[i];
  }
  cout<<ret<<endl;
  return 0;
}


/*
#include <iostream>
using namespace std;
int dp[200][200][200];
int main()
{
  int n, m;
  cin>>n>>m;
  //dp[i][j][k]表示遇i家店，j次花，剩k斗酒的可能种数
  dp[0][0][2] = 1;
  dp[0][1][1] = 1;
  dp[0][2][0] = 1;
  for(int i = 1;i <= n;i++) {
    for(int j = 0;j <= m;j++) {
      for(int k = 0;k <= m;k++) {
        if(k%2 == 0) {
        
          dp[i][j][k] += dp[i-1][j][k/2];
          dp[i][j][k] += dp[i][j-1][k+1];
        }
        else {
          dp[i][j][k] += dp[i][j-1][k+1];
        }
        dp[i][j][k] %= 1000000007;
      }
    }
  }
  cout<<dp[n][m-1][1]<<endl;
  return 0;
}
*/

//李白打酒 
/*
#include <iostream>
using namespace std;
void dfs(int remain, int house, int flower, int& count) {
  if(remain == 1&&house == 0) {
    if(flower == 1)
      count++;
    return;
  }
  if(house)
    dfs(remain*2, house-1, flower, count);
  if(flower)
    dfs(remain-1, house, flower-1, count);
}
int main()
{
  int count = 0;
  dfs(2, 5, 10, count);
  cout<<count<<endl;
  return 0;
}
*/


//推导部分和 
/*
#include <iostream>
#include <vector>
using namespace std;
long long findRoot(long long x, vector<long long>& parent, vector<long long>& weight) {
    if (parent[x] != x) { //压缩
        long long tmp = parent[x];
        parent[x] = findRoot(parent[x], parent, weight);
        weight[x] += weight[tmp];
    }
    return parent[x];
}
int main()
{
    long long n, m, q;
    cin >> n >> m >> q;
    vector<long long> parent(n + 1);
    for (long long i = 0; i <= n; i++)
        parent[i] = i;
    vector<long long> weight(n + 1, 0);
    for (long long i = 0; i < m; i++) {
        long long l, r, s;
        cin >> l >> r >> s;
        long long lParent = findRoot(l - 1, parent, weight), rParent = findRoot(r, parent, weight); //注意l-1
        //合并
        if (lParent != rParent) {
            parent[lParent] = rParent;
            weight[lParent] = weight[r] + s - weight[l - 1];
        }
    }
    for (long long i = 0; i < q; i++) {
        long long l, r;
        cin >> l >> r;
        long long lParent = findRoot(l - 1, parent, weight), rParent = findRoot(r, parent, weight); //注意l-1
        if (lParent != rParent)
            cout << "UNKNOWN" << endl;
        else
            cout << weight[l - 1] - weight[r] << endl;
    }
    return 0;
}
*/

//三体攻击 
/*
#include <iostream>
using namespace std;
int d[1000000];
int main()
{
  int A, B, C, m;
  cin>>A>>B>>C>>m;
  for(int i = 0;i < A*B*C;i++) {
    cin>>d[i];
  }
  int latV[m], ratV[m], lbtV[m], rbtV[m], lctV[m], rctV[m], htV[m];
  for(int i = 0;i < m;i++) {
    cin>>latV[i]>>ratV[i]>>lbtV[i]>>rbtV[i]>>lctV[i]>>rctV[i]>>htV[i];
  }
  for(int x = 0;x < m;x++) {
    int lat = latV[x], rat = ratV[x], lbt = lbtV[x], rbt = rbtV[x], lct = lctV[x], rct = rctV[x], ht = htV[x];
    for(int i = lat-1;i <= rat-1;i++) {
      for(int j = lbt-1;j <= rbt-1;j++) {
        for(int k = lct-1;k <= rct-1;k++) {
          int index = (i*B+j)*C+k;
          d[index] -= ht;
          if(d[index] < 0) {
            cout<<x+1<<endl;
            return 0;
          }
        }
      }
    }
  }
  return 0;
}
*/
