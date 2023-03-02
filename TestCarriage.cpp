#include"Assistance.h"
#include"SeqQueue.h"
using namespace std;
int main() {
	SeqQueue<int>qa;
	int n, x, No = 1, k=1, d[1001];
	cout << "请输入车箱数：";
	cin >> n;
	cout << "请输入" << n << "节车厢的进站顺序:";
	for (int j = 1; j <= n; j++) {
		cin >> d[j];
	}
	for (int i = 1; i <= n; i++) {
		if (qa.GetHead(x) == SUCCESS && x == No) {
			cout << "第 " << x << " 号车厢从辅轨进入主轨右侧" << endl;
			qa.DelQueue(x);
			No++;
		}
		else if (k<=n) {
			while (No <= n && No != d[k]&&k<=n) {
				cout << "第 " << d[k] << " 号车厢从主轨左侧进入辅轨" << endl;
				qa.EnQueue(d[k]);
				k++;
			}
			if (No == d[k]&&k<=n) {
				cout << "第 " << No << " 号车厢从主轨左侧进入主轨右侧" << endl;
				No++;
				k++;
			}
		}
		else break;
	}
	if (qa.IsEmpty()) cout << "调度完成" << endl;
	else cout << "调度无法完成" << endl;
	return 0;
}