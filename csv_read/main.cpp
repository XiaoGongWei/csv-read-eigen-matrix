#include <iostream>
#include <fstream>
#include "Eigen/Dense"

using namespace Eigen;
using namespace std;

Eigen::MatrixXd readCSV(std::string file) {

	std::ifstream in(file);

	std::string line;

	int row = 0;
	int col = 0;

	Eigen::MatrixXd res(1,1);
	Eigen::RowVectorXd rowVector(1);

	if (in.is_open()) {

		while (std::getline(in, line)) {

			char *ptr = (char *)line.c_str();
			int len = line.length();

			col = 0;

			char *start = ptr;
			for (int i = 0; i < len; i++) {

				if (ptr[i] == ',') {
					//res(row, col++) = atof(start);
					rowVector(col++) = atof(start);
					start = ptr + i + 1;
					rowVector.conservativeResize(col + 1);
				}
			}
			//res(row++, col) = atof(start);
			rowVector(col) = atof(start);
			res.conservativeResize(row + 1, col + 1);
			res.row(row++) = rowVector;
		}
		in.close();
	}
	return res;
}

int main() {
	MatrixXd mat;

	mat = readCSV("test.csv");

	cout << mat << endl;

	return 0;
}