#include <iostream>
#include <vector>
using namespace std;
int main()
{
  long long A, B, C, m;
  cin>>A>>B>>C>>m;
  //vector<vector<vector<int>>>* pd = new vector<vector<vector<int>>>(A, vector<vector<int>>(B, vector<int>(C)));
  vector<vector<vector<long long>>> d;
  for(long long i = 0;i < A;i++) {
    vector<vector<long long>> tmp1;
    for(long long j = 0;j < B;j++) {
      vector<long long> tmp2(C);
      for(long long k = 0;k < C;k++)
        cin>>tmp2[k];
      tmp1.push_back(tmp2);
    }
    d.push_back(tmp1);
  }
  long long ans = -1;
  for(long long x = 0;x < m;x++) {
    long long lat, rat, lbt, rbt, lct, rct, ht;
    cin>>lat>>rat>>lbt>>rbt>>lct>>rct>>ht;
    if(ans == -1) {
    	for(long long i = lat-1;i < rat;i++) {
        for(long long j = lbt-1;j < rbt;j++) {
          for(long long k = lct-1;k < rct;k++) {
            d[i][j][k] -= ht;
            if(d[i][j][k] < 0) {
              ans = x+1;
            }
          }
        }
	  	}
    }
  }
  cout<<ans<<endl;
  return 0;
}

//卡片换位 
/*
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bfs(const string& s) {
  int a = s.find('A'), b = s.find('B'); //A和B的初始位置
  unordered_set<string> visited; //记录遍历过的状态
  visited.insert(s); //初始状态设置为遍历过
  queue<string> q;
  q.push(s); //将初始状态入队列
  int count = 0; //交换的次数
  while(!q.empty()) {
    int size = q.size();
    for(int i = 0;i < size;i++) { //每次循环出一层
      string front = q.front();
      q.pop();
      int aPos = front.find('A'), bPos = front.find('B'); //当前A和B的位置
      if(aPos == b&&bPos == a) //交换成功
        return count;
      int spacePos = front.find(' '); //空格的位置
      int x = spacePos/3, y = spacePos%3; //空格的坐标
      for(int j = 0;j < 4;j++) { //空格尝试与四个方向的字符交换
        int nx = x+dirs[j][0], ny = y+dirs[j][1];
        if(nx >=0&&nx < 2&&ny >= 0&&ny < 3) { //坐标合法性判断
          int linePos = nx*3+ny;
          swap(front[spacePos], front[linePos]); //交换
          if(!visited.count(front)) { //如果没有遍历过该状态，则入队列（之前走的一定比当前步数少）
            visited.insert(front); //记录为遍历过
            q.push(front);
          }
          swap(front[spacePos], front[linePos]); //还原
        }
      }
    }
    count++; //本层得到的状态都需要新交换一次得到
  }
  return 0; //不会走到这里
}
int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  string s = s1 + s2; //将两个字符串拼接在一起
  int count = bfs(s);
  cout<<count<<endl;
  return 0;
}
*/

//路径之谜 
/*
#include <iostream>
#include <vector>
using namespace std;
const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool dfs(vector<vector<int>>& visited, vector<int>& rowNum, vector<int>& colNum, int x, int y, vector<int>& ans) {
  int n = rowNum.size();
  if(x == n-1&&y == n-1) { //到达右下角
    for(const auto& e : rowNum) { //箭靶必须要对应
      if(e)
        return false;
    }
    for(const auto& e : colNum) { //箭靶必须要对应
      if(e)
        return false;
    }
    return true;
  }
  for(int i = 0;i < 4;i++) {
    int nx = x+dirs[i][0], ny = y+dirs[i][1];
    if(nx >= 0&&nx < n&&ny >= 0&&ny < n&&!visited[nx][ny]) { //该点没有被走过
      if(rowNum[ny]&&colNum[nx]) { //根据箭靶判断该点是否可以走
        visited[nx][ny] = 1; //标记为走过
        //更新箭靶
        rowNum[ny]--;
        colNum[nx]--;
        ans.push_back(nx*n+ny); //压入路径
        if(dfs(visited, rowNum, colNum, nx, ny, ans)) //找到正确路径则直接返回
          return true;
        //回溯
        visited[nx][ny] = 0;
        rowNum[ny]++;
        colNum[nx]++;
        ans.pop_back(); //恢复路径
      }
    }
  }
  return false;
}
int main()
{
  int N;
  cin>>N;
  vector<int> rowNum(N);
  for(int i = 0;i < N;i++)
    cin>>rowNum[i];
  vector<int> colNum(N);
  for(int i = 0;i < N;i++)
    cin>>colNum[i];
  vector<vector<int>> visited(N, vector<int>(N, 0));
  visited[0][0] = 1;
  vector<int> ans;
  //起始位置处理
  ans.push_back(0);
  rowNum[0]--;
  colNum[0]--;
  dfs(visited, rowNum, colNum, 0, 0, ans);
  for(const auto& e : ans)
    cout<<e<<" ";
  cout<<endl;
  return 0;
}
*/

//日志统计 
/*
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
  int N, D, K;
  cin>>N>>D>>K;
  vector<pair<int, int>> v(N);
  for(int i = 0;i < N;i++) {
    int ts, id;
    cin>>ts>>id;
    v[i] = {ts, id};
  }
  sort(v.begin(), v.end());
  unordered_map<int, int> idToNum;
  int left = 0, right  = 0;
  set<int> ans; //id去重+排序
  while(right < N) { //右边界不能移就直接结束
    //右边界移到不能移
    while(right < N&&v[right].first - v[left].first < D) {
      int id = v[right].second;
      idToNum[id]++;
      if(idToNum[id] >= K)
        ans.insert(id);
      right++;
    }
    //左边界向右移动一次
    idToNum[v[left].second]--;
    left++;
  }
  for(const auto& e : ans)
    cout<<e<<endl;

  return 0;
}
*/

//数位排序 
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
  int n, m;
  cin>>n>>m;
  vector<int> v(n);
  for(int i = 0;i < n;i++)
    v[i] = i+1;
  auto getSum = [](int num)->int{
    int sum = 0;
    while(num) {
      sum += num%10;
      num /= 10;
    }
    return sum;
  };
  sort(v.begin(), v.end(), [&getSum](const int& n1, const int& n2)->bool{
    int sum1 = getSum(n1);
    int sum2 = getSum(n2);
    if(sum1 == sum2)
      return n1 < n2;
    else
      return sum1 < sum2;
  });
  cout<<v[m-1]<<endl;
  return 0;
}
*/

//k倍区间 
/*#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0;i < n;i++) {
		cin>>v[i];
	}
	int sum = 0; //前缀和
	vector<int> modNum(k, 0);
	modNum[0] = 1;
	long long ans = 0;
	for(int i = 0;i < n;i++) {
		sum += v[i];
		sum %= k;
		ans += modNum[sum];
		modNum[sum]++;
	} 
	cout<<ans<<endl;
	return 0;
}
*/
/*
(sum[j]-sum[i])%k = 0
sum[j]%k = sum[i]%k
*/
//timeout 
/*
#include <iostream>
#include <vector>
using namespace std;
int main() {
	int n, k;
	cin>>n>>k;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin>>v[i];
	vector<int> tmp(n+1, 0);
	//dp[i]表示前i个数的K倍区间的数目 
	vector<int> dp(n+1, 0);
	dp[0] = 0;
	for(int i = 1;i <= n;i++) {
		int count = 0;
		for(int j = 1;j <= i;j++) { //tmp[j]表示从第j个数到第i-1个数的和 
			if((tmp[j]+v[i-1])%k == 0)
				count++;
			tmp[j] += v[i-1]; 
		}
		dp[i] = dp[i-1] + count;
	}
	cout<<dp[n]<<endl;
	return 0;
} 
*/ 

//最少砝码 
/*
#include <iostream>
using namespace std;
int main() {
	int n = 0;
	cin>>n;
	int count = 1;
	int maxNum = 1;
	while(maxNum < n) {
		count++;
		maxNum = maxNum*3 + 1;
	}
	cout<<count<<endl;
	return 0;
}
/*
/*
1        1
1,3      2-4
1,3,9    5-13
1,3,6,27 14-40
*/

//特殊时间 
/*
1011 1011年11月10日11时10分

1110 4*4*4
1112 4*3*4
1113 4*1*3
1114 4*1*3
1115 4*1*3
1116 4*1*2
1117 4*1*2
1118 4*1*2
1119 4*1*2
2220 4*1*4
2221 4*1*4
4*4*4 + 4*3*4 + 4*1*3*3 + 4*1*2*4 + 4*1*4*2
64+48+36+32+32=128+96=212

*/

//数字三角形 
/*
#include <iostream> 
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int main() {
	int N;
	cin>>N;
	vector<vector<int>> v(N, vector<int>(N));
	for(int i = 0;i < N;i++) {
		for(int j = 0;j <= i;j++)
			cin>>v[i][j];
	}
	vector<int> dp(N, 0);
	dp[0] = v[0][0];
	for(int i = 1;i < N;i++) {
		dp[i] = dp[i-1] + v[i][i];
		for(int j = i-1;j >= 1;j--)
			dp[j] = max(dp[j-1], dp[j]) + v[i][j];
		dp[0] = dp[0] + v[i][0];
		cout<<"debug: ";
		for(int k = 0;k <= i;k++)
			cout<<dp[k]<<" ";
		cout<<endl;
	}
	if(N%2 == 1)
		cout<<dp[N/2]<<endl;
	else
		cout<<max(dp[N/2-1], dp[N/2])<<endl;
	return 0;
}
*/

