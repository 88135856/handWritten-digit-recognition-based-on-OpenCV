#include"mycore.h"

int main()
{
	//ѵ��SVM
	//mySVM svmOnHand(10000, 1000, 1000, getMixedFeature, Size(28, 28));
	//svmOnHand.trainTestSVM(g_SVMtemp);

	cout << "��д����ʶ�� �汾1.0" << endl;
	int flag = 0;
	while (cout << "��ѡ������Ҫ�Ĺ���: 1 ��д���ֲ�ʶ�� 2 ��ͼƬ��ʶ������, 0 �˳�" << endl, scanf("%d", &flag), flag)
	{
		if (flag == 1)
		{
			handWritingRecognize();
		}
		else if (flag == 2)
		{
			cout << "ͼƬ��������������д�����ⲻҪ������ͼ������д���־������ʣ�����ɲο�����ͼƬ" << endl;
			imageRecognize();
		}
	}
	return 0;
}


