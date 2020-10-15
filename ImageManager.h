/**
 * \class ImageManager
 *
 * \brief Class to get one single image data
 *
 * This class manages image acquisition through a path
 * and provides image data.
 *
 * \author Vitor de Castro $
 *
 * \date $Date: 2020/08/31 $
 *
 * Contact: oi.vitor@gmail.com
 *
 * Created on: Mon Aug 31 2020
 */
#pragma once

#include "IAcquisitionManager.h"

class ImageManager : public IAcquisitionManager
{
public:
	ImageManager();

	ImageManager(std::string imagePath);

	void getLastImage(cv::Mat& image) override;

private:
	std::string m_imagePath; //!< Image path where the image might be found.
};
