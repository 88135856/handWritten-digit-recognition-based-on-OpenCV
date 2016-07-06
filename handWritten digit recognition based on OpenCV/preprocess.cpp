#include"preprocess.h"

void preProcess(const Mat& srcImage, Mat& dstImage)
{
	Mat tmpImage = srcImage.clone();
	if (tmpImage.type() != CV_8UC1)
	{
		cvtColor(tmpImage, tmpImage, CV_BGR2GRAY);
	}
	//��˹�˲�Ԥ�������
	GaussianBlur(tmpImage, tmpImage, Size(3, 3), 0, 0, BORDER_DEFAULT);
	//��̬ѧ�˲� ������Ԥ����
	Mat element = getStructuringElement(MORPH_RECT, Size(7,7));
	morphologyEx(tmpImage, tmpImage, MORPH_OPEN, element);

	//imshow("fff", tmpImage);
	//waitKey(500);
	
	//canny��ȡ����
	Canny(tmpImage, dstImage, 75, 100, 3);
	//imshow("qq", dstImage);
	//waitKey(500);
	//��̬ѧ�˲����������մ���
	Mat tmpImage4 = dstImage.clone();
	element = getStructuringElement(MORPH_RECT, Size(10, 10));
	morphologyEx(dstImage, tmpImage4, MORPH_DILATE, element);

	//imshow("hhh", tmpImage4);
	//waitKey(500);

	threshold(tmpImage4, dstImage, 0, 255, THRESH_OTSU + THRESH_BINARY);

	//imshow("hhh2", dstImage);
	//waitKey(0);
}