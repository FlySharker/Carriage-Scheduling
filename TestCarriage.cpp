#include"Assistance.h"
#include"SeqQueue.h"
using namespace std;
int main() {
	SeqQueue<int>qa;
	int n, x, No = 1, k=1, d[1001];
	cout << "�����복������";
	cin >> n;
	cout << "������" << n << "�ڳ���Ľ�վ˳��:";
	for (int j = 1; j <= n; j++) {
		cin >> d[j];
	}
	for (int i = 1; i <= n; i++) {
		if (qa.GetHead(x) == SUCCESS && x == No) {
			cout << "�� " << x << " �ų���Ӹ�����������Ҳ�" << endl;
			qa.DelQueue(x);
			No++;
		}
		else if (k<=n) {
			while (No <= n && No != d[k]&&k<=n) {
				cout << "�� " << d[k] << " �ų�������������븨��" << endl;
				qa.EnQueue(d[k]);
				k++;
			}
			if (No == d[k]&&k<=n) {
				cout << "�� " << No << " �ų�������������������Ҳ�" << endl;
				No++;
				k++;
			}
		}
		else break;
	}
	if (qa.IsEmpty()) cout << "�������" << endl;
	else cout << "�����޷����" << endl;
	return 0;
}