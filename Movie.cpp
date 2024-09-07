#include <iostream>
#include <vector>
using namespace std;

class Movie{
    private :
    string MovieName;
    int MovieDuration;
    bool is3D;

    public:

    void AssignMovieDetails(string title, int timetaken, bool screen){
        this->MovieName=title;
        this->MovieDuration=timetaken;
        this->is3D=screen;
    }

    void MovieDetailsDisplay(){
        cout<<"Movie name: "<<this->MovieName<<endl;
        cout<<"Movie Duration: "<<this->MovieDuration<<endl;
        cout<<"Movie Screen Details: "<<(this->is3D? "3D":"2D")<<endl;
    }
};

class Staff{
    private:
    string Name;
    string Position;
    double salary;

    public:

    void AssignStaffDetails(string n, string pos, double s){
        this->Name=n;
        this->Position=pos;
        this->salary=s;
    }

    void StaffDetailsDisplay(){
      cout<<"Staff Name: "<<this->Name<<endl;
      cout<<"Staff Position: "<<this->Position<<endl;
      cout<<"Staff salary: "<<this->salary<<endl;
    }
};

int main(){
Movie movie1;
Staff Person1;

movie1.AssignMovieDetails("Inception",3,true);
movie1.MovieDetailsDisplay();

cout<<endl;

Person1.AssignStaffDetails("Kelly","Manager",15000);
Person1.StaffDetailsDisplay();

};