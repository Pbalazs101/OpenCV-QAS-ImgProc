
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/imgproc.hpp>

using namespace cv;
using namespace std;



	int main()
	{
		Mat src = imread("KL.jpg");

		if (!src.data)
		{
			cout << "Error. Can't open picture.";
			return EXIT_FAILURE;
		}

		//        imshow("src", src);

			// Átméretezés, hogy kezelhetõbb legyen
		
		Mat rsz;
		Size size(1000, 1332);
		resize(src, rsz, size);

		//        imshow("rsz", rsz);

		Mat gray;
		cvtColor(rsz, gray, COLOR_BGR2GRAY);

		// Adaptív küszöbölés. Bitenként: ~ Ha nem bitenként küszöbölnénk, akkor a pontosság romlik.
		Mat bw;
		adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

		// Dilattálás. Ha ezt nem vgezzük el, túl finom marad a vonalak széle, így nem ismeri fel megfelelõen.
		Mat kernel = Mat::ones(2, 2, CV_8UC1);
		dilate(bw, bw, kernel);

		// Itt már a kész bináris kép lesz a bw-ben-
		imshow("bin", bw);



		// Új képet készítünk, amibõl majd a vízszintes vonalakat szedjük ki.
			Mat horizontal = bw.clone();



		// Vonalak mérete. Vagy konstansként, vagy adaptívan megadva

		//int horizontalsize = horizontal.cols / 70;
		int horizontalsize = 25;

		// Morfológiai operátorok segítségével fogjuk kiszedni a vonalakat, ezért kell  a horizontalStructure
		Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontalsize, 4.5));

		// Morfológiai operátorok
		erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
		dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));

		// A talált vonalak, melyek megfelelnek a korábbi kritériumoknak
		imshow("horizontal", horizontal);

		// Kontúrkeresés
		vector<Vec4i> hierarchy;
		std::vector<std::vector<cv::Point> > contours;
		cv::findContours(horizontal, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE, Point(0, 0));



		vector<vector<Point> > contours_poly(contours.size());
		vector<Rect> boundRect(contours.size());
		for (size_t i = 0; i < contours.size(); i++)
		{
			approxPolyDP(Mat(contours[i]), contours_poly[i], 3, true);
			boundRect[i] = boundingRect(Mat(contours_poly[i]));
		}

		for (size_t i = 0; i < contours.size(); i++)
		{
			double length = arcLength(cv::Mat(contours[i]), true);
			// Vonal hosszúság érzékenység. 18-cal jól mûködik, de lehet vele kísérletezni.
			if (length < 18)
				continue;

			// A zöld határolónégyzetek létrehozása, és elcsúsztatása. Azért szükséges, hogy ne magát a megtalával a 
			//megtalált vonallal, hanem a felette lévõ, kitöltendõ hellyel dolgozzunk. 
			//A size a méretét változtatja, a Point pedig egy offset, hogy ne csússzon el
			if (length > 18)
			{
				boundRect[i] += Size(0, -30); 
				boundRect[i] -= Point(0, 3); 
			}
			else {
				boundRect[i] += Size(0, 30);
				boundRect[i] -= Point(0, -4);
			}

			drawContours(rsz, contours, i, Scalar(255, 0, 255), 1, 8, vector<Vec4i>(), 0, Point()); //A megtalált vonalakat lilával (vagy rózsaszínnel, én max 8 színt tudok megkülönböztetni) jelöltem
			rectangle(rsz, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 1, 8, 0);	// A feldolgozandó területet zöld négyzettel.
		}

		imshow("src", rsz);


		waitKey(0);
		return 0;
	}