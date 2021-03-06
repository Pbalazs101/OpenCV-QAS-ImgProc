//így fordítod te nimród: 
//g++ -O3 -std=c++11 form.cpp `pkg-config --cflags --libs tesseract opencv4` -o form
//így futtatod te nimród:
//./form input.png

//lastname: 240, 180, 670, 200

#include <string>
#include <iostream>
#include <fstream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;
using namespace tesseract;

struct hallgato
{
	string nev;
	string neptunkod;
	string szak;
	string telefon;
	string email;
};

int main(int argc, char* argv[])
{
	//initialize stuff
	string path = argv[1];
	string targy, oktato, datum, terem;
	hallgato hallgatok[6];

	Mat img = imread(path, 1);
	TessBaseAPI *ocr = new TessBaseAPI();

	ocr -> Init(NULL, "hun", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	//--------------------------------------
	//crop basic form related info
	Rect targyCrop_roi(175, 175, 315, 22);
	Rect oktatoCrop_roi(175, 205, 315, 32);
	Rect datumCrop_roi(560, 175, 180, 30);
	Rect teremCrop_roi(560, 205, 180, 32);

	Mat targyCrop = img(targyCrop_roi);
	Mat oktatoCrop = img(oktatoCrop_roi);
	Mat datumCrop = img(datumCrop_roi);
	Mat teremCrop = img (teremCrop_roi);

	//read basic info from crops
	ocr -> SetImage(targyCrop.data, targyCrop.cols, targyCrop.rows, 3, targyCrop.step);
	targy = ocr -> GetUTF8Text();
	cout << targy << endl;

	ocr -> SetImage(oktatoCrop.data, oktatoCrop.cols, oktatoCrop.rows, 3, oktatoCrop.step);
	oktato = ocr -> GetUTF8Text();
	cout << oktato << endl;

	ocr -> SetImage(datumCrop.data, datumCrop.cols, datumCrop.rows, 3, datumCrop.step);
	datum = ocr -> GetUTF8Text();
	cout << datum << endl;

	ocr -> SetImage(teremCrop.data, teremCrop.cols, teremCrop.rows, 3, teremCrop.step);
	terem = ocr -> GetUTF8Text();
	cout << terem << endl;

	ocr -> End();

	//--------------------------------------
	//crop details of students
	Rect hallgato1NevCrop_roi(60, 285, 200, 45);
	Rect hallgato1NeptunkodCrop_roi(264, 284, 90, 50);
	Rect hallgato1SzakCrop_roi(400, 284, 45, 45);
	Rect hallgato1TelefonCrop_roi(490, 284, 168, 50);
	Rect hallgato1EmailCrop_roi(658, 284, 240, 50);

	Rect hallgato2NevCrop_roi(60, 335, 200, 45);
	Rect hallgato2NeptunkodCrop_roi(264, 334, 136, 50);
	Rect hallgato2SzakCrop_roi(400, 334, 45, 50);
	Rect hallgato2TelefonCrop_roi(490, 334, 168, 50);
	Rect hallgato2EmailCrop_roi(658, 334, 240, 50);

	Rect hallgato3NevCrop_roi(60, 385, 200, 45);
	Rect hallgato3NeptunkodCrop_roi(264, 384, 136, 50);
	Rect hallgato3SzakCrop_roi(400, 384, 45, 50);
	Rect hallgato3TelefonCrop_roi(490, 384, 168, 50);
	Rect hallgato3EmailCrop_roi(658, 434, 240, 50);

	Rect hallgato4NevCrop_roi(60, 435, 200, 45);
	Rect hallgato4NeptunkodCrop_roi(264, 434, 136, 50);
	Rect hallgato4SzakCrop_roi(400, 434, 45, 50);
	Rect hallgato4TelefonCrop_roi(490, 434, 168, 50);
	Rect hallgato4EmailCrop_roi(658, 484, 240, 50);

	Rect hallgato5NevCrop_roi(60, 485, 200, 45);
	Rect hallgato5NeptunkodCrop_roi(264, 484, 136, 50);
	Rect hallgato5SzakCrop_roi(400, 484, 45, 50);
	Rect hallgato5TelefonCrop_roi(490, 484, 168, 50);
	Rect hallgato5EmailCrop_roi(658, 534, 240, 50);

	Rect hallgato6NevCrop_roi(60, 535, 200, 45);
	Rect hallgato6NeptunkodCrop_roi(264, 534, 136, 50);
	Rect hallgato6SzakCrop_roi(400, 534, 45, 50);
	Rect hallgato6TelefonCrop_roi(490, 534, 168, 50);
	Rect hallgato6EmailCrop_roi(658, 526, 240, 50);

	Mat hallgato1NevCrop = img(hallgato1NevCrop_roi);
	Mat hallgato1NeptunkodCrop = img(hallgato1NeptunkodCrop_roi);
	Mat hallgato1SzakCrop = img(hallgato1SzakCrop_roi);
	Mat hallgato1TelefonCrop = img(hallgato1TelefonCrop_roi);
	Mat hallgato1EmailCrop = img(hallgato1EmailCrop_roi);

	Mat hallgato2NevCrop = img(hallgato2NevCrop_roi);
	Mat hallgato2NeptunkodCrop = img(hallgato2NeptunkodCrop_roi);
	Mat hallgato2SzakCrop = img(hallgato2SzakCrop_roi);
	Mat hallgato2TelefonCrop = img(hallgato2TelefonCrop_roi);
	Mat hallgato2EmailCrop = img(hallgato2EmailCrop_roi);

	Mat hallgato3NevCrop = img(hallgato3NevCrop_roi);
	Mat hallgato3NeptunkodCrop = img(hallgato3NeptunkodCrop_roi);
	Mat hallgato3SzakCrop = img(hallgato3SzakCrop_roi);
	Mat hallgato3TelefonCrop = img(hallgato3TelefonCrop_roi);
	Mat hallgato3EmailCrop = img(hallgato3EmailCrop_roi);

	Mat hallgato4NevCrop = img(hallgato4NevCrop_roi);
	Mat hallgato4NeptunkodCrop = img(hallgato4NeptunkodCrop_roi);
	Mat hallgato4SzakCrop = img(hallgato4SzakCrop_roi);
	Mat hallgato4TelefonCrop = img(hallgato4TelefonCrop_roi);
	Mat hallgato4EmailCrop = img(hallgato4EmailCrop_roi);

	Mat hallgato5NevCrop = img(hallgato5NevCrop_roi);
	Mat hallgato5NeptunkodCrop = img(hallgato5NeptunkodCrop_roi);
	Mat hallgato5SzakCrop = img(hallgato5SzakCrop_roi);
	Mat hallgato5TelefonCrop = img(hallgato5TelefonCrop_roi);
	Mat hallgato5EmailCrop = img(hallgato5EmailCrop_roi);

	Mat hallgato6NevCrop = img(hallgato6NevCrop_roi);
	Mat hallgato6NeptunkodCrop = img(hallgato6NeptunkodCrop_roi);
	Mat hallgato6SzakCrop = img(hallgato6SzakCrop_roi);
	Mat hallgato6TelefonCrop = img(hallgato6TelefonCrop_roi);
	Mat hallgato6EmailCrop = img(hallgato6EmailCrop_roi);

	//--------------------------------------
	//read the text from each crop

	ocr -> Init(NULL, "hun", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato1NevCrop.data, hallgato1NevCrop.cols, hallgato1NevCrop.rows, 3, hallgato1NevCrop.step);
	hallgatok[0].nev = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "eng", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato1NeptunkodCrop.data, hallgato1NeptunkodCrop.cols, hallgato1NeptunkodCrop.rows, 3, hallgato1NeptunkodCrop.step);
	hallgatok[0].neptunkod = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato1SzakCrop.data, hallgato1SzakCrop.cols, hallgato1SzakCrop.rows, 3, hallgato1SzakCrop.step);
	hallgatok[0].szak = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato1TelefonCrop.data, hallgato1TelefonCrop.cols, hallgato1TelefonCrop.rows, 3, hallgato1TelefonCrop.step);
	hallgatok[0].telefon = ocr -> GetUTF8Text();
	ocr -> SetImage(hallgato1EmailCrop.data, hallgato1EmailCrop.cols, hallgato1EmailCrop.rows, 3, hallgato1EmailCrop.step);
	hallgatok[0].email = ocr -> GetUTF8Text();


	ocr -> SetImage(hallgato2NevCrop.data, hallgato2NevCrop.cols, hallgato2NevCrop.rows, 3, hallgato2NevCrop.step);
	hallgatok[1].nev = ocr -> GetUTF8Text();
	ocr -> SetImage(hallgato2NeptunkodCrop.data, hallgato2NeptunkodCrop.cols, hallgato2NeptunkodCrop.rows, 3, hallgato2NeptunkodCrop.step);
	hallgatok[1].neptunkod = ocr -> GetUTF8Text();  
	ocr -> SetImage(hallgato2SzakCrop.data, hallgato2SzakCrop.cols, hallgato2SzakCrop.rows, 3, hallgato2SzakCrop.step); 
	hallgatok[1].szak = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato2TelefonCrop.data, hallgato2TelefonCrop.cols, hallgato2TelefonCrop.rows, 3, hallgato2TelefonCrop.step);
	hallgatok[1].telefon = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato2EmailCrop.data, hallgato2EmailCrop.cols, hallgato2EmailCrop.rows, 3, hallgato2EmailCrop.step);
	hallgatok[1].email = ocr -> GetUTF8Text();


	ocr -> SetImage(hallgato3NevCrop.data, hallgato3NevCrop.cols, hallgato3NevCrop.rows, 3, hallgato3NevCrop.step);
	hallgatok[2].nev = ocr -> GetUTF8Text();
	ocr -> SetImage(hallgato3NeptunkodCrop.data, hallgato3NeptunkodCrop.cols, hallgato3NeptunkodCrop.rows, 3, hallgato3NeptunkodCrop.step); 
	hallgatok[2].neptunkod = ocr -> GetUTF8Text();
	ocr -> SetImage(hallgato3SzakCrop.data, hallgato3SzakCrop.cols, hallgato3SzakCrop.rows, 3, hallgato3SzakCrop.step); 
	hallgatok[2].szak = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato3TelefonCrop.data, hallgato3TelefonCrop.cols, hallgato3TelefonCrop.rows, 3, hallgato3TelefonCrop.step);
	hallgatok[2].telefon = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato3EmailCrop.data, hallgato3EmailCrop.cols, hallgato3EmailCrop.rows, 3, hallgato3EmailCrop.step);
	hallgatok[2].email = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "hun", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato4NevCrop.data, hallgato4NevCrop.cols, hallgato4NevCrop.rows, 3, hallgato4NevCrop.step);
	hallgatok[3].nev = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "eng", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato4NeptunkodCrop.data, hallgato4NeptunkodCrop.cols, hallgato4NeptunkodCrop.rows, 3, hallgato4NeptunkodCrop.step); 
	hallgatok[3].neptunkod = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato4SzakCrop.data, hallgato4SzakCrop.cols, hallgato4SzakCrop.rows, 3, hallgato4SzakCrop.step); 
	hallgatok[3].szak = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato4TelefonCrop.data, hallgato4TelefonCrop.cols, hallgato4TelefonCrop.rows, 3, hallgato4TelefonCrop.step); 
	hallgatok[3].telefon = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato4EmailCrop.data, hallgato4EmailCrop.cols, hallgato4EmailCrop.rows, 3, hallgato4EmailCrop.step);
	hallgatok[3].email = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "hun", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato5NevCrop.data, hallgato5NevCrop.cols, hallgato5NevCrop.rows, 3, hallgato5NevCrop.step);
	hallgatok[4].nev = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "eng", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato5NeptunkodCrop.data, hallgato5NeptunkodCrop.cols, hallgato5NeptunkodCrop.rows, 3, hallgato5NeptunkodCrop.step); 
	hallgatok[4].neptunkod = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato5SzakCrop.data, hallgato5SzakCrop.cols, hallgato5SzakCrop.rows, 3, hallgato5SzakCrop.step); 
	hallgatok[4].szak = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato5TelefonCrop.data, hallgato5TelefonCrop.cols, hallgato5TelefonCrop.rows, 3, hallgato5TelefonCrop.step); 
	hallgatok[4].telefon = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato5EmailCrop.data, hallgato5EmailCrop.cols, hallgato5EmailCrop.rows, 3, hallgato5EmailCrop.step);
	hallgatok[4].email = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "hun", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);

	ocr -> SetImage(hallgato6NevCrop.data, hallgato6NevCrop.cols, hallgato6NevCrop.rows, 3, hallgato6NevCrop.step);
	hallgatok[5].nev = ocr -> GetUTF8Text();

	ocr -> End();

	ocr -> Init(NULL, "eng", OEM_LSTM_ONLY);
	ocr -> SetPageSegMode(PSM_AUTO);
	
	ocr -> SetImage(hallgato6NeptunkodCrop.data, hallgato6NeptunkodCrop.cols, hallgato6NeptunkodCrop.rows, 3, hallgato6NeptunkodCrop.step); 
	hallgatok[5].neptunkod = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato6SzakCrop.data, hallgato6SzakCrop.cols, hallgato6SzakCrop.rows, 3, hallgato6SzakCrop.step); 
	hallgatok[5].szak = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato6TelefonCrop.data, hallgato6TelefonCrop.cols, hallgato6TelefonCrop.rows, 3, hallgato6TelefonCrop.step); 
	hallgatok[5].telefon = ocr -> GetUTF8Text(); 
	ocr -> SetImage(hallgato6EmailCrop.data, hallgato6EmailCrop.cols, hallgato6EmailCrop.rows, 3, hallgato6EmailCrop.step);
	hallgatok[5].email = ocr -> GetUTF8Text();

	ocr -> End();

	//write the results to file
	ofstream output;
	output.open("out.txt");

	output << "Tárgy: " << targy;
	output << "Oktató: " << oktato;
	output << "Dátum: " << datum;
	output << "Terem: " << terem;
	output << endl;

	for (int i = 0; i < 6; ++i)
	{
		output << "Név: " << hallgatok[i].nev;
		output << "Neptun kód: " << hallgatok[i].neptunkod;
		output << "Szak: " << hallgatok[i].szak;
		output << "Telefonszám: " << hallgatok[i].telefon;
		output << "E-mail cím: " << hallgatok[i].email;
		output << endl;
	}

	output.close();

	/*
	imshow("1", hallgato5NevCrop);
	imshow("2", hallgato5NeptunkodCrop);
	imshow("3", hallgato5SzakCrop);
	imshow("4", hallgato5TelefonCrop);
	imshow("5", hallgato5EmailCrop);
	waitKey();
	*/

	return 0;
}

/*
//prototyping
int main(int argc, char* argv[])
{
	string path = argv[1];
	string lastname = "you shouldn't see this";

	Mat form = imread(path, 1);
	tesseract::TessBaseAPI *ocr = new tesseract::TessBaseAPI();

	Rect roi(240, 180, 430, 25);

	Mat crop = form(roi);

	ocr->Init(NULL, "hun", tesseract::OEM_LSTM_ONLY);
	ocr->SetPageSegMode(tesseract::PSM_AUTO);
	ocr->SetImage(crop.data, crop.cols, crop.rows, 3, crop.step);

	lastname = string(ocr->GetUTF8Text());
	cout << lastname << endl;

	ocr->End();

	//imshow("test", form);
	//imshow("crop?", crop);
	waitKey();

	return 0;
}
*/