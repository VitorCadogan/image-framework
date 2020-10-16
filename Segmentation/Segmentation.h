#pragma once

#include "opencv2/core/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

class Segmentation
{
public:
	Segmentation();

	~Segmentation();

	void doSegmentation(cv::Mat& image);

	//******************************************* Greyscale Images
	void doGlobalThresholdOpenCV(cv::Mat& imageSrc, cv::Mat& imageDst, int treshold, int maxValue);

	void doGlobalThreshold(cv::Mat& imageSrc, cv::Mat& imageDst, double threshold, double maxValue);

protected:
	cv::Mat m_image;
};
