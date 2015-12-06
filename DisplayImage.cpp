#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(int argc, char** argv)
{

	String TEST_DIR = "data\\data_file\\test";
	String CAR_CXML = "data\\data_file\\cascade.xml";
	String NAME_WIN = "Entrenar OpenCV";

	CascadeClassifier car_detector;

	if (!car_detector.load(CAR_CXML)) { cout << "Error en el archivo: " + CAR_CXML << endl; return -1; };

	for (int i = 0; i < 20; i++)
	{
		std::stringstream number;
		number << i;

		String image_test = TEST_DIR + "\\test-" + number.str() + ".pgm";
		Mat image = imread(image_test, 1);

		if (!image.data) { cout << "No image data." << endl; return -1; }

		std::vector<Rect> rc;

		car_detector.detectMultiScale(image, rc, 1.5, 3);

		for (size_t i = 0; i < rc.size(); i++)
		{
			rectangle(image, Point(rc[i].x, rc[i].y), Point(rc[i].x + rc[i].width, rc[i].y + rc[i].height), CV_RGB(0, 255, 0), 1);
		}

		namedWindow(NAME_WIN, WINDOW_AUTOSIZE);
		imshow(NAME_WIN, image);
		waitKey(0);
	}

	return 0;
}