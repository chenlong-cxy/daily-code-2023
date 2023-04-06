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

//��Ƭ��λ 
/*
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
using namespace std;
const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int bfs(const string& s) {
  int a = s.find('A'), b = s.find('B'); //A��B�ĳ�ʼλ��
  unordered_set<string> visited; //��¼��������״̬
  visited.insert(s); //��ʼ״̬����Ϊ������
  queue<string> q;
  q.push(s); //����ʼ״̬�����
  int count = 0; //�����Ĵ���
  while(!q.empty()) {
    int size = q.size();
    for(int i = 0;i < size;i++) { //ÿ��ѭ����һ��
      string front = q.front();
      q.pop();
      int aPos = front.find('A'), bPos = front.find('B'); //��ǰA��B��λ��
      if(aPos == b&&bPos == a) //�����ɹ�
        return count;
      int spacePos = front.find(' '); //�ո��λ��
      int x = spacePos/3, y = spacePos%3; //�ո������
      for(int j = 0;j < 4;j++) { //�ո������ĸ�������ַ�����
        int nx = x+dirs[j][0], ny = y+dirs[j][1];
        if(nx >=0&&nx < 2&&ny >= 0&&ny < 3) { //����Ϸ����ж�
          int linePos = nx*3+ny;
          swap(front[spacePos], front[linePos]); //����
          if(!visited.count(front)) { //���û�б�������״̬��������У�֮ǰ�ߵ�һ���ȵ�ǰ�����٣�
            visited.insert(front); //��¼Ϊ������
            q.push(front);
          }
          swap(front[spacePos], front[linePos]); //��ԭ
        }
      }
    }
    count++; //����õ���״̬����Ҫ�½���һ�εõ�
  }
  return 0; //�����ߵ�����
}
int main()
{
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  string s = s1 + s2; //�������ַ���ƴ����һ��
  int count = bfs(s);
  cout<<count<<endl;
  return 0;
}
*/

//·��֮�� 
/*
#include <iostream>
#include <vector>
using namespace std;
const int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool dfs(vector<vector<int>>& visited, vector<int>& rowNum, vector<int>& colNum, int x, int y, vector<int>& ans) {
  int n = rowNum.size();
  if(x == n-1&&y == n-1) { //�������½�
    for(const auto& e : rowNum) { //���б���Ҫ��Ӧ
      if(e)
        return false;
    }
    for(const auto& e : colNum) { //���б���Ҫ��Ӧ
      if(e)
        return false;
    }
    return true;
  }
  for(int i = 0;i < 4;i++) {
    int nx = x+dirs[i][0], ny = y+dirs[i][1];
    if(nx >= 0&&nx < n&&ny >= 0&&ny < n&&!visited[nx][ny]) { //�õ�û�б��߹�
      if(rowNum[ny]&&colNum[nx]) { //���ݼ����жϸõ��Ƿ������
        visited[nx][ny] = 1; //���Ϊ�߹�
        //���¼���
        rowNum[ny]--;
        colNum[nx]--;
        ans.push_back(nx*n+ny); //ѹ��·��
        if(dfs(visited, rowNum, colNum, nx, ny, ans)) //�ҵ���ȷ·����ֱ�ӷ���
          return true;
        //����
        visited[nx][ny] = 0;
        rowNum[ny]++;
        colNum[nx]++;
        ans.pop_back(); //�ָ�·��
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
  //��ʼλ�ô���
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

//��־ͳ�� 
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
  set<int> ans; //idȥ��+����
  while(right < N) { //�ұ߽粻���ƾ�ֱ�ӽ���
    //�ұ߽��Ƶ�������
    while(right < N&&v[right].first - v[left].first < D) {
      int id = v[right].second;
      idToNum[id]++;
      if(idToNum[id] >= K)
        ans.insert(id);
      right++;
    }
    //��߽������ƶ�һ��
    idToNum[v[left].second]--;
    left++;
  }
  for(const auto& e : ans)
    cout<<e<<endl;

  return 0;
}
*/

//��λ���� 
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

//k������ 
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
	int sum = 0; //ǰ׺��
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
	//dp[i]��ʾǰi������K���������Ŀ 
	vector<int> dp(n+1, 0);
	dp[0] = 0;
	for(int i = 1;i <= n;i++) {
		int count = 0;
		for(int j = 1;j <= i;j++) { //tmp[j]��ʾ�ӵ�j��������i-1�����ĺ� 
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

//�������� 
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

//����ʱ�� 
/*
1011 1011��11��10��11ʱ10��

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

//���������� 
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

