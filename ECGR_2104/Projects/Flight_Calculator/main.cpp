#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>

#define PI 3.1416
#define RADIUS 3958.8
#define MPH 500

using namespace std;

double start_location(int input, double long1, double lat1, string destination[10], double longitude[10], double latitude[10]);
double final_location(int input, double long2, double lat2, string destination[10], double longitude[10], double latitude[10]);
double haversine(double long1, double lat1, double long2, double lat2, double distance);
double getFlightTime(double distance, double flight_time);

int main(){
        string destination[10] = {"Miami Beach, FL", "Fargo, ND", "Idaho City, ID", "Newport, KY", "Chester, PA", "Savannah, GA", "Las Vegas, NV", "Chesapeake, VA", "Richfield, MN", "Mill Valley, CA"};
        double longitude[10] = {-80.14, -96.79, -115.84, -84.50, -75.36, -81.09, -115.17, -76.29, -93.29, -122.54};
        double latitude[10] = {25.79, 46.88, 43.83, 39.09, 39.85, 32.08, 36.12, 36.78, 44.88, 37.91};
        int input; 
        double long1, long2, lat1, lat2, flight_time, distance;
        
        cout << "Hello! This program is designed to take a start location and desired end location and calculate the time it would take to fly an airplane between the two." << endl;
        cout << "Select a starting location by typing the corresponding number." << endl;
        for(int i = 0; i < 10; i++){
            cout << i + 1 << ". " << destination[i] << endl;
        } 
        cin >> input;
        start_location(input, long1, lat1, destination, longitude, latitude);
        
        cout << "Now chose a destination." << endl;
        for(int i = 0; i < 9; i++){
                cout << i + 1 << ". " << destination[i] << endl;
        }       
        cin >> input;
        final_location(input, long2, lat2, destination, longitude, latitude);
        
        haversine(long1, lat1, long2, lat2, distance);
        getFlightTime(distance, flight_time);
        
        cout << "\n" << endl;
        cout << "The distance between the two locations is " << setprecision(2) << distance << " miles." << endl;
        cout << "The total amount of time the flight will take is " << setprecision(2) << flight_time << " hours." << endl;
        
    return 0;
}

double start_location(int input, double long1, double lat1, string destination[10], double longitude[10], double latitude[10]){
        cout << "\n" << endl;
        for(int i = 0; i < 10; i++){
                if(i == input){
                        long1 = longitude[i];
                        lat1 = latitude[i];
                        cout << "Starting Destination: " << destination[i] << endl;
                        cout << "Latitude: " << lat1 << endl;
                        cout << "Longitude: " << long1 << endl;
                        break;
                }
                else if((i == 10) && (i =! input)){
                        cout << "Error. Please make a selection between 1-10." << endl;
                        for(int i = 0; i < 10; i++){
                                cout << i + 1 << ". " << destination[i] << endl;
                        } 
                        cin >> input;
                }
        }
        return 0;
}



double final_location(int input, double long2, double lat2, string destination[10], double longitude[10], double latitude[10]){
        cout << "\n" << endl;
        for(int i = 0; i < 9; i++){
                if(i == input){
                        long2 = longitude[i];
                        lat2 = latitude[i];
                        cout << "Starting Destination: " << destination[i] << endl;
                        cout << "Latitude: " << lat2 << endl;
                        cout << "Longitude: " << long2 << endl;
                        break;
                }
                if((i == 9) && (i =! input)){
                        cout << "Error. Please make a selection between 1-10." << endl;
                        for(int i = 0; i < 9; i++){
                                cout << i + 1 << ". " << destination[i] << endl;
                        } 
                        cin >> input;
                }
        }
        return 0;
}


double haversine(double long1, double lat1, double long2, double lat2, double distance){
    long1 = long1 * (PI / 180);
    lat1 = lat1 * (PI / 180);
    long2 = long2 * (PI / 180);
    lat2 = lat2 * (PI / 180);
    distance = 2 * RADIUS * (asin(sqrt(pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2))));
    return distance;
}

double getFlightTime(double distance, double flight_time){
        flight_time = distance / MPH;
        return flight_time;
}