//������
//�м������߱���������������ַ�����֪�Ļ��Ĵ�֮�䣬���ҶԳƵ�
class Solution {
public:
	string longestPalindrome(string s) {
		string ss(s.length() * 2 + 2, '#');
		vector<int> rad(ss.length(), 1);//��뾶������
		ss[0] = '@';
		for (int i = 1; i <= s.length(); i++) {
			ss[i * 2] = s[i - 1];//@#s#s#s#s#s#
		}
		int r = 0;//��ǰ������������ұ߽�
		int mp = 0;//���뾶��λ��
		int max = 0;//��ǰ�����뾶ֵ
		int maxp = 0;//���뾶ֵ
		for (int j = 1; j < ss.length(); j++) {
			if (j < r) {
				rad[j] = min(rad[2 * mp - j],//�ұ߽�֮�� 
					r - j);//�ұ߽�֮��ģ��ضϡ�
			}
			while (ss[j + rad[j]] == ss[j - rad[j]]) {
				rad[j]++;//�м��������һ���
			}
			if (r < rad[j] + j) {//�����ұ߽�
				r = rad[j] + j;
				mp = j;
			}
			if (max < rad[mp]) {//�������뾶
				max = rad[mp];
				maxp = mp;
			}
		}
		return s.substr((maxp - max) / 2, max - 1);
	}
};