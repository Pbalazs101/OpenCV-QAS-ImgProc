
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

			// �tm�retez�s, hogy kezelhet�bb legyen
		
		Mat rsz;
		Size size(1000, 1332);
		resize(src, rsz, size);

		//        imshow("rsz", rsz);

		Mat gray;
		cvtColor(rsz, gray, COLOR_BGR2GRAY);

		// Adapt�v k�sz�b�l�s. Bitenk�nt: ~ Ha nem bitenk�nt k�sz�b�ln�nk, akkor a pontoss�g romlik.
		Mat bw;
		adaptiveThreshold(~gray, bw, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 15, -2);

		// Dilatt�l�s. Ha ezt nem vgezz�k el, t�l finom marad a vonalak sz�le, �gy nem ismeri fel megfelel�en.
		Mat kernel = Mat::ones(2, 2, CV_8UC1);
		dilate(bw, bw, kernel);

		// Itt m�r a k�sz bin�ris k�p lesz a bw-ben-
		imshow("bin", bw);



		// �j k�pet k�sz�t�nk, amib�l majd a v�zszintes vonalakat szedj�k ki.
			Mat horizontal = bw.clone();



		// Vonalak m�rete. Vagy konstansk�nt, vagy adapt�van megadva

		//int horizontalsize = horizontal.cols / 70;
		int horizontalsize = 25;

		// Morfol�giai oper�torok seg�ts�g�vel fogjuk kiszedni a vonalakat, ez�rt kell  a horizontalStructure
		Mat horizontalStructure = getStructuringElement(MORPH_RECT, Size(horizontalsize, 4.5));

		// Morfol�giai oper�torok
		erode(horizontal, horizontal, horizontalStructure, Point(-1, -1));
		dilate(horizontal, horizontal, horizontalStructure, Point(-1, -1));

		// A tal�lt vonalak, melyek megfelelnek a kor�bbi krit�riumoknak
		imshow("horizontal", horizontal);

		// Kont�rkeres�s
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
			// Vonal hossz�s�g �rz�kenys�g. 18-cal j�l m�k�dik, de lehet vele k�s�rletezni.
			if (length < 18)
				continue;

			// A z�ld hat�rol�n�gyzetek l�trehoz�sa, �s elcs�sztat�sa. Az�rt sz�ks�ges, hogy ne mag�t a megtal�val a 
			//megtal�lt vonallal, hanem a felette l�v�, kit�ltend� hellyel dolgozzunk. 
			//A size a m�ret�t v�ltoztatja, a Point pedig egy offset, hogy ne cs�sszon el
			if (length > 18)
			{
				boundRect[i] += Size(0, -30); 
				boundRect[i] -= Point(0, 3); 
			}
			else {
				boundRect[i] += Size(0, 30);
				boundRect[i] -= Point(0, -4);
			}

			drawContours(rsz, contours, i, Scalar(255, 0, 255), 1, 8, vector<Vec4i>(), 0, Point()); //A megtal�lt vonalakat lil�val (vagy r�zsasz�nnel, �n max 8 sz�nt tudok megk�l�nb�ztetni) jel�ltem
			rectangle(rsz, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 1, 8, 0);	// A feldolgozand� ter�letet z�ld n�gyzettel.
		}

		imshow("src", rsz);


		waitKey(0);
		return 0;
	}