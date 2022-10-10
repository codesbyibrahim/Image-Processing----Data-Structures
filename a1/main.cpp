#include"Run length code.h"
int main()
{
	string arr[] = { "002","004","015","017","018","019","020","021","022","024","033","038","039","040","041","042","043","044","050","075","078" ,"091","015","118","139","140","144","149","169","171","177","206","211","243","328","331","339","376","379","386","394","395","396","427","429","432" };
	char again = 'N';
	do
	{

		cout << "+==========================================================================+\n";
		cout << "|                         MUHAMMAD IBRAHIM SULTAN                          |\n";
		cout << "|                                 21i-0582                                 |\n";
		cout << "|                                   CS-E                                   |\n";
		cout << "|                               ASSIGNMENT 1                               |\n";
		cout << "+==========================================================================+\n";

		int r = 0, c = 0;
		cv::Mat A;
		int choice = 0;
		int** result = NULL;
		string filename;
		do
		{
			cout << "\n\n[1] CONNCETED COMPONENT LABELING\n[2] K-MEANS CLUSTERING\n[3] DICE COEFFIECIENT\n[4] RUN LENGTH CODE\n\nENTER YOUR CHOICE : ";
			cin >> choice;
		} while (choice < 1 || choice>4);
		cout << "Enter the name of the file (ONLY NUMBER) : ";
		cin >> filename;
		switch (choice)
		{
		case 1:
			result = Task1(r, c, filename);
			A = cv::Mat(r, c, CV_8UC1);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
					A.data[A.step[0] * i + A.step[1] * j] = unsigned char(result[i][j]);
			cv::namedWindow("title", cv::WINDOW_NORMAL);
			cv::imshow("title", A);
			cv::waitKey();
			break;
		case 2:
			result = Task2(r, c, filename);
			A = cv::Mat(r, c, CV_8UC1);
			for (int i = 0; i < r; i++)
				for (int j = 0; j < c; j++)
				{
					if (result[i][j])
						A.data[A.step[0] * i + A.step[1] * j + 0] = 255;
					else
						A.data[A.step[0] * i + A.step[1] * j + 0] = 0;

				}
			cv::namedWindow("title", cv::WINDOW_NORMAL);
			cv::imshow("title", A);
			cv::waitKey();
			break;
		case 3:
			cout << "[1] CALCULATE FOR ALL IMAGES\n[2] CALCULATE FOR ONE IMAGE \nENTER CHOICE : ";
			cin >> choice;
			cout << setw(30) << left << "Image name" << setw(20) << "Task 1" << setw(20) << "Task 2\n\n";
			if (choice == 1)
			{
				for (string i : arr)
					task3(i);
			}
			else
				task3(filename);
			break;
		case 4:
			task4(filename);
			break;
		}
		cout << "DO YOU WANT TO RUN AGAIN (Y/N)? : ";
		cin >> again;
		system("cls");
	} while (again == 'y' || again == 'Y');
}