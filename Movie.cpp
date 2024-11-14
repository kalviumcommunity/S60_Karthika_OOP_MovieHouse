#include <iostream>
#include <vector>
using namespace std;

class Movie {
private:
    string MovieName;
    int MovieDuration;
    bool is3D;
    static int MovieCount;

public:
    // Constructor
    Movie(string movie = "", int time = 0, bool value = false) {
        MovieName = movie;
        MovieDuration = time;
        is3D = value;
        MovieCount++;
        cout << "Movie created: " << MovieName << endl;
    }

    // Destructor
    ~Movie() {
        cout << "Movie destroyed: " << MovieName << endl;
        MovieCount--;
    }

    static int getMovieCount() {
        return MovieCount;
    }

    void AssignMovieDetails(string title = "", int timetaken = 0, bool screen = false) {
        MovieName = title;
        MovieDuration = timetaken;
        is3D = screen;
    }

    string getMovieName() {
        return MovieName;
    }
    
    int getMovieDuration() {
        return MovieDuration;
    }
    
    bool getis3D() {
        return is3D;
    }

    void MovieDetailsDisplay() {
        cout << "Movie name: " << getMovieName() << endl;
        cout << "Movie Duration: " << getMovieDuration() << endl;
        cout << "Movie Screen Details: " << (getis3D() ? "3D" : "2D") << endl;
    }
};

int Movie::MovieCount = 0;

class Staff {
private:
    string Name;
    string Position;
    double salary;
    static int StaffCount;

public:
    // Constructor
    Staff(string n = "", string pos = "", double s = 0.0) : Name(n), Position(pos), salary(s) {
        StaffCount++;
        cout << "Staff created: " << Name << endl;
    }

    // Destructor
    ~Staff() {
        cout << "Staff destroyed: " << Name << endl;
        StaffCount--;
    }

    static int getStaffCount() {
        return StaffCount;
    }

    void AssignStaffDetails(string n, string pos, double s) {
        this->Name = n;
        this->Position = pos;
        this->salary = s;
    }

    string getName() {
        return Name;
    }
    
    string getPosition() {
        return Position;
    }
    
    double getSalary() {
        return salary;
    }

    void StaffDetailsDisplay() {
        cout << "Staff Name: " << getName() << endl;
        cout << "Staff Position: " << getPosition() << endl;
        cout << "Staff salary: " << getSalary() << endl;
    }
};

int Staff::StaffCount = 0;

class MovieHouse {
private:
    string MovieHouseName;
    vector<Movie*> Movies;
    vector<Staff*> StaffMembers;
    static int MovieHouseCount;

public:
    // Constructor
    MovieHouse(string name = "") : MovieHouseName(name) {
        MovieHouseCount++;
        cout << "MovieHouse created: " << MovieHouseName << endl;
    }

    // Destructor
    ~MovieHouse() {
        cout << "MovieHouse destroyed: " << MovieHouseName << endl;
        for (Movie* movie : Movies) delete movie;
        for (Staff* staff : StaffMembers) delete staff;
        MovieHouseCount--;
    }

    static int getMovieHouse() {
        return MovieHouseCount;
    }

    void setMovieHouseName(string name) {
        this->MovieHouseName = name;
    }

    void AddMovies(Movie* movie1) {
        Movies.push_back(movie1);
    }

    void AddStaff(Staff* person1) {
        StaffMembers.push_back(person1);
    }

    void GetMovieHouseDetails() {
        cout << "Movie House Name: " << this->MovieHouseName << endl;
        cout << "Movies: " << endl;
        for (int i = 0; i < Movies.size(); i++) {
            Movies[i]->MovieDetailsDisplay();
        }
        cout << "Staff Members: " << endl;
        for (int j = 0; j < StaffMembers.size(); j++) {
            StaffMembers[j]->StaffDetailsDisplay();
        }
    }
};

int MovieHouse::MovieHouseCount = 0;

int main() {
    int MovieHouseCount;
    cout << "Enter number of movie houses you want to create: ";
    cin >> MovieHouseCount;
    cin.ignore();

    for (int j =0; j < MovieHouseCount; j++) {
        MovieHouse* MovieHouse1 = new MovieHouse();
        string name;
        int NumberofMovies;
        int NumberofStaff;

        cout << "Enter a MovieHouse name: ";
        getline(cin, name);
        MovieHouse1->setMovieHouseName(name);

        cout << "Enter Number of Movies: ";
        cin >> NumberofMovies;
        cin.ignore();

        for (int i = 0; i < NumberofMovies; i++) {
            string name;
            int time;
            bool screen;
            int num;
            cout << "Enter details of " << i + 1 << " movie : " << endl;
            cout << "Movie Name: ";
            // cin.ignore();
            getline(cin, name);
            cout << "Movie Duration: ";
            cin >> time;
            cout << "Is the movie in 3D? (1 for Yes, 0 for No): ";
            cin >> num;
            screen = (num == 1);
            cin.ignore();
            Movie* movie1 = new Movie;
            movie1->AssignMovieDetails(name, time, screen);
            MovieHouse1->AddMovies(movie1);
        }

        cout << "Enter Number of staff: ";
        cin >> NumberofStaff;
        cin.ignore();

        for (int i = 0; i < NumberofStaff; i++) {
            string personName;
            string pos;
            double s;

            cout << "Enter details of " << i + 1 << " staff members : " << endl;

            cout << "Staff name: ";
            // cin.ignore();
            getline(cin, personName);

            cout << "Staff Position: ";
            getline(cin, pos);

            cout << "Staff Salary: ";
            cin >> s;
            cin.ignore();

            Staff* person1 = new Staff;
            person1->AssignStaffDetails(personName, pos, s);
            MovieHouse1->AddStaff(person1);
        }

        cout << endl;
        MovieHouse1->GetMovieHouseDetails();
        delete MovieHouse1;
    }

    cout << "Total number of movies added: " << Movie::getMovieCount() << endl;
    cout << "Total number of staff members: " << Staff::getStaffCount() << endl;
    cout << "Total number of Movie Houses: " << MovieHouse::getMovieHouse() << endl;

    return 0;
}
