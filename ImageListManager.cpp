#include <opencv2/highgui/highgui.hpp>

#include "ImageListManager.h"

// ImageListManager Default Constructor
ImageListManager::ImageListManager()
: m_imagesFolder(cv::String("data/grey")),
  m_filenames(),
  m_imageCounter( 0 )
{
    cv::glob(m_imagesFolder, m_filenames);
}

// ImageListManager Constructor receiving a path
ImageListManager::ImageListManager(cv::String imagesFolder)
: m_imagesFolder(cv::String(imagesFolder)),
  m_filenames(),
  m_imageCounter(0)
{
    cv::glob(m_imagesFolder, m_filenames);
}

// Load image into the buffer in cv::Mat format
void ImageListManager::getLastImage(cv::Mat& image)
{
    image.release();
	// Read the image 
    if (m_imageCounter < m_filenames.size())
    {
        image = cv::imread(m_filenames[m_imageCounter], cv::IMREAD_UNCHANGED);
        m_imageCounter++;
    }
    else
    {
        m_imageCounter = 0;
        // TODO: "end of images reached" message
    }
}