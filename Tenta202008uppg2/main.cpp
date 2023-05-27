#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <list>
#include <iomanip>
using namespace std;


class Values {
public:
	string date;
	string time;

	double timeStamp;
	float temperature;
	float x_accell;
	float y_accell;
	float z_accell;

};
vector<Values> dataLista;

void getValues() {

	string line;
	ifstream Myvalues("sensor-data.log");
	Values values;
	while (getline(Myvalues, line)) {
		stringstream ss(line);
		getline(ss, values.date, ',');
		getline(ss, values.time, ',');

		string timeStampStr;
		getline(ss, timeStampStr, ',');
		values.timeStamp = stod(timeStampStr);

		string temperatureStr;
		getline(ss, temperatureStr, ',');
		values.temperature = stof(temperatureStr);

		string xAccelStr;
		getline(ss, xAccelStr, ',');
		values.x_accell = stof(xAccelStr);

		string yAccelStr;
		getline(ss, yAccelStr, ',');
		values.y_accell = stof(yAccelStr);

		string zAccelStr;
		getline(ss, zAccelStr, ',');
		values.z_accell = stof(zAccelStr);

		dataLista.push_back(values);
	}


}

void printDate() {
	cout << "Start date and time: " << dataLista.front().date << " " << dataLista.front().time << endl;
	cout << "Last date and time: " << dataLista.back().date << " " << dataLista.back().time << endl;
	
}
void printFirstFive() {

	for (int i = 0; i < 5; i++) {
		Values obj = dataLista[i];
		cout << setw(5) << obj.date << setw(10) << obj.time << setw(10) << obj.timeStamp << setw(10) << obj.temperature << setw(10) << obj.x_accell << setw(10) << obj.y_accell << setw(10) << obj.z_accell << endl;

	}
}

double medelTemp() {
	int antal_temp = 0;
	double tot_temp = 0;
	for (int i = 0; i < size(dataLista); i++) {
		Values tempObj = dataLista[i];
		tot_temp += tempObj.temperature;
		antal_temp++;
	}
	return  tot_temp / antal_temp;


}

float maxVariationX() {
	float highest = 0;
	float lowest = 0;

	for (int i = 0; i < size(dataLista); i++) {
		Values accel = dataLista[i];

		if (accel.x_accell > highest) {
			highest = accel.x_accell;

		}
		else if (accel.x_accell < lowest) {
			lowest = accel.x_accell;
		}
		else {
			continue;
		}

	}
	return highest - lowest;
}

float maxVariationY() {
	float highest = 0;
	float lowest = 0;

	for (int i = 0; i < size(dataLista); i++) {
		Values accel = dataLista[i];

		if (accel.x_accell > highest) {
			highest = accel.y_accell;

		}
		else if (accel.x_accell < lowest) {
			lowest = accel.y_accell;
		}
		else {
			continue;
		}

	}
	return highest - lowest;
}
float maxVariationZ() {
	float highest = 0;
	float lowest = 0;

	for (int i = 0; i < size(dataLista); i++) {
		Values accel = dataLista[i];

		if (accel.x_accell > highest) {
			highest = accel.z_accell;

		}
		else if (accel.x_accell < lowest) {
			lowest = accel.z_accell;
		}
		else {
			continue;
		}

	}
	return highest - lowest;
}
int main() {
	
	getValues();
	printDate();
	printFirstFive();
	cout << "Medeltemperaturen var: " << medelTemp() <<endl;
	cout << "Maximal variation X-axel: " << maxVariationX() << endl;
	cout << "Maximal variation Y-axel: " << maxVariationY()<< endl;
	cout << "Maximal variation Z-axel: " << maxVariationZ()<< endl;
}