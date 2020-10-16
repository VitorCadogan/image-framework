#include <opencv2/highgui/highgui.hpp>

#include "ImageManager.h"

// Image Manager Default Constructor
ImageManager::ImageManager()
{
	m_imagePath = cv::samples::findFile("data/grey/threshold.png");
}

// Image Manager Constructor
ImageManager::ImageManager(cv::String imagePath)
{
	m_imagePath = cv::samples::findFile(imagePath);
}

// Load image into the buffer in cv::Mat format
void ImageManager::getLastImage(cv::Mat& image)
{
	// Read the image 
	image = cv::imread(m_imagePath, cv::IMREAD_UNCHANGED); // TODO : Check before if path exists
}