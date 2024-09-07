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

class MovieHouse{

private:
string MovieHouseName;
vector <Movie> Movies;
vector <Staff> StaffMembers;

public:

void setMovieHouseName(string name){
  this->MovieHouseName=name;
}

void AddMovies(Movie movie1){
    Movies.push_back(movie1);
}

void AddStaff(Staff person1){
    StaffMembers.push_back(person1);
}

void GetMovieHouseDetails(){
    cout<<"Movie House Name: "<<this->MovieHouseName<<endl;
    cout<<"Movies: "<<endl;
    for(int i=0; i<Movies.size(); i++){

        Movies[i].MovieDetailsDisplay();
    }
  cout<<"Staff Members: "<<endl;
    for(int j=0; j<StaffMembers.size(); j++){

       StaffMembers[j].StaffDetailsDisplay();
    }
}
};

int main(){
MovieHouse MovieHouse1;
string name;
int NumberofMovies;
int NumberofStaff;

cout<<"Enter a MovieHouse name: ";
getline(cin,name);
MovieHouse1.setMovieHouseName(name);

cout<<"Enter Number of Movies: ";
cin>>NumberofMovies;

for(int i=0; i<NumberofMovies; i++){
    string name;
    int time;
    bool screen;
    int num;
    cout<<"Enter details of "<<i+1<<" movie : "<<endl;
    cout<<"Movie Name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Movie Duration: ";
    cin>>time;
    cout<<"Is the movie in 3D? (1 for Yes, 0 for No): ";
    cin>>num;
    screen=(num==1);
    Movie movie1;
    movie1.AssignMovieDetails(name,time,screen);
    MovieHouse1.AddMovies(movie1);
}
cout<<"Enter Number of staff: ";
cin>>NumberofStaff;

for(int i=0; i<NumberofStaff; i++){
    string personName;
    string pos;
    double s;

    cout<<"Enter details of "<<i+1<<" staff members : "<<endl;

    cout<<"Staff name: ";
    cin.ignore();
    getline(cin,personName);

    cout<<"Staff Position: ";
    getline(cin,pos);

    cout<<"Staff Salary: ";
    cin>>s;

    Staff person1;
    person1.AssignStaffDetails(personName,pos,s);
    MovieHouse1.AddStaff(person1);

}
cout<<endl;
MovieHouse1.GetMovieHouseDetails();
return 0;
};