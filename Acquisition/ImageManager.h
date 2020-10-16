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
	/*! \brief Class default constructor.
	*/
	ImageManager();

	/*! \brief Class constructor.
	*
	*   \param[in] The path of the required image.
	*/
	ImageManager(cv::String imagePath);

	/*! \brief Read image using parsed matrix in the parameter.
	*
	*   \param[out] The path of the required image.
	*/
	void getLastImage(cv::Mat& image) override;

private:
	std::string m_imagePath; //!< Image path where the image might be found.
};
