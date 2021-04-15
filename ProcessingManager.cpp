#include "ProcessingManager.h"
#include "Acquisition/ImageListManager.h"
#include "Acquisition/VideoManager.h"

#include "opencv2/core/core.hpp"

ProcessingManager::ProcessingManager() :
	m_imageManagerPtr( std::make_unique<ImageManager>() ),
	m_segmentationPtr( std::make_unique<Segmentation>() ),
	m_image( cv::Mat::zeros(1, 1, CV_8UC3) ), // TODO: Verify this type is the best dafault option for every kinf of images
	m_isImageValid( false )
{
	m_imageManagerPtr = std::make_unique<VideoManager>("data/video/1CM1_1_R_#217.avi");
}

void ProcessingManager::initialize()
{

}

void ProcessingManager::updateApplication()
{
	updateAcquisition();
	updateProcessing();
	updateOutput();
}

void ProcessingManager::updateAcquisition()
{
	if (!m_imageManagerPtr)
	{
		std::cout << "imageManagerPtr is null !! " << std::endl;
		return;
	}	
	m_imageManagerPtr->getLastImage(m_image);

	if (m_image.empty())
	{
		std::cout << "Could not read the image! " << std::endl;
		m_isImageValid = false;
		return;
	}

	m_isImageValid = true;
}

void ProcessingManager::updateProcessing()
{
	if (m_isImageValid)
	{
		// Call segmentation functions
		int thresh = 0;
		int maxValue = 255;

		//m_segmentationPtr->doGlobalThresholdOpenCV(m_image, m_image, thresh, maxValue);
		cv::Mat imgDst(m_image);
		//m_image.copyTo(imgDst);
		m_segmentationPtr->doGlobalThreshold(m_image, imgDst, thresh, maxValue);
		m_image = imgDst;
	}
}

void ProcessingManager::updateOutput()
{
	if (m_isImageValid)
	{
		cv::imshow("Display window", m_image);
		int k = cv::waitKey(1); // Wait for a keystroke in the window

		if (k == 's')
		{
			cv::imwrite("segmented_img.png", m_image);
		}
	}
}