#pragma once

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <fstream>
#include <iostream>


typedef cv::Mat Image;
typedef cv::Mat::Size ImageSize;

class MatHandler
{
	void MatHandler::ReadImage(Image& I);
	{
		I = cv::imread("C:/Users/hallgato/Downloads/cat.jpg");
	}
	void MatHandler::Create(Image& I, ImageSize& size, int type);
	{
		
	}
	void MatHandler::Release(Image& I);
	{
		I.release();
	}
	void MatHandler::Copy(Image& source, Image& destination);
	{
		source.copyTo(destination);
	}
	void MatHandler::Clone(Image& source, Image&, destination);
};

