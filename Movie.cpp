#include <iostream>
#include <vector>
using namespace std;

class Movie{
    private :
    string MovieName;
    int MovieDuration;
    bool is3D;

    public:

    void MovieDisplay(){
        cout<<"This a movie class"<<endl;
    }
};

class Staff{
    private:
    string Name;
    string Position;
    double salary;

    public:

    void StaffDisplay(){
      cout<<"I am a staff person in movie house."<<endl;
    }
};

int main(){
Movie movie1;
Staff Person1;

movie1.MovieDisplay();
Person1.StaffDisplay();

};