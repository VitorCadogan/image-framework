/**
 * \class ImageListManager
 *
 * \brief Class to read a sequence of images within a folder.
 *
 * This class manages image acquisition from a sequence of images
 * through a path and provides image data one by one.
 *
 * \author Vitor de Castro $
 *
 * \date $Date: 2020/10/08 $
 *
 * Contact: oi.vitor@gmail.com
 *
 * Created on: Mon Oct 08 2020
 */
#pragma once

#include "IAcquisitionManager.h"

class ImageListManager : public IAcquisitionManager
{
public:
	ImageListManager();

	ImageListManager(cv::String imagesFolder);

	void getLastImage(cv::Mat& image) override;

private:
	cv::String m_imagesFolder;           //!< Image path where the image might be found.
	std::vector<cv::String> m_filenames; //!< Vector containing the names of every file inside a given folder.
	double m_imageCounter;               //!< Counter to keep a track of how many images we've already read.
};
