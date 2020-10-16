#include "Segmentation.h"

Segmentation::Segmentation()
{

}

Segmentation::~Segmentation()
{

}

void Segmentation::doSegmentation(cv::Mat& image)
{
	m_image = image;
}

//****************************************** Greyscale Images ************************************************

void Segmentation::doGlobalThresholdOpenCV(cv::Mat& imageSrc,cv::Mat& imageDst, int threshold, int maxValue)
{
	cv::threshold(imageSrc, imageDst, threshold, maxValue, cv::THRESH_BINARY);
}

void Segmentation::doGlobalThreshold(cv::Mat& imageSrc, cv::Mat& imageDst, double threshold, double maxValue)
{
	auto imgHeight = imageSrc.rows;
	auto imgWidth = imageSrc.cols;
	auto type = imageSrc.type();

	for (int i = 0; i < imgHeight; i++)
	{
		for (int j = 0; j < imgWidth; j++)
		{
			if (imageSrc.at<unsigned char>(i,j) > threshold)
			{
				imageDst.at<unsigned char>(i, j) = maxValue;
			}
			else
			{
				imageDst.at<unsigned char>(i, j) = 0;
			}
		}
	}
}