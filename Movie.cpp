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

    string getMovieName() const {
        return MovieName;
    }
    
    int getMovieDuration() const {
        return MovieDuration;
    }
    
    bool getis3D() const {
        return is3D;
    }

    virtual void MovieDetailsDisplay() const {
        cout << "Movie name: " << getMovieName() << endl;
        cout << "Movie Duration: " << getMovieDuration() << endl;
        cout << "Movie Screen Details: " << (getis3D() ? "3D" : "2D") << endl;
    }
};

int Movie::MovieCount = 0;

class IMAXMovie : public Movie {
private:
    string soundSystem;

public:
    IMAXMovie(string movie, int time, bool value, string soundSys)
        : Movie(movie, time, value), soundSystem(soundSys) {}

    void MovieDetailsDisplay() const override {
        Movie::MovieDetailsDisplay();
        cout << "Sound System: " << soundSystem << endl;
    }
};

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

    string getName() const {
        return Name;
    }
    
    string getPosition() const {
        return Position;
    }
    
    double getSalary() const {
        return salary;
    }

    virtual void StaffDetailsDisplay() const {
        cout << "Staff Name: " << getName() << endl;
        cout << "Staff Position: " << getPosition() << endl;
        cout << "Staff Salary: " << getSalary() << endl;
    }
};

int Staff::StaffCount = 0;

class Manager : public Staff {
private:
    string officeLocation;

public:
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    void StaffDetailsDisplay() const override {
        Staff::StaffDetailsDisplay();
        cout << "Office Location: " << officeLocation << endl;
    }
};

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

    void GetMovieHouseDetails() const {
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

    for (int j = 0; j < MovieHouseCount; j++) {
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
            getline(cin, name);
            cout << "Movie Duration: ";
            cin >> time;
            cout << "Is the movie in 3D? (1 for Yes, 0 for No): ";
            cin >> num;
            screen = (num == 1);
            cin.ignore();
            Movie* movie1 = new Movie(name, time, screen);
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
            getline(cin, personName);
            cout << "Staff Position: ";
            getline(cin, pos);
            cout << "Staff Salary: ";
            cin >> s;
            cin.ignore();

            Staff* person1 = new Staff(personName, pos, s);
            MovieHouse1->AddStaff(person1);
        }

        cout << endl;
        MovieHouse1->GetMovieHouseDetails();
        delete MovieHouse1;
    }

    MovieHouse* myMovieHouse = new MovieHouse("CineMax");

    Movie* imaxMovie = new IMAXMovie("Inception", 148, true, "Dolby Atmos");
    myMovieHouse->AddMovies(imaxMovie);

    Staff* manager = new Manager("John Doe", "Manager", 50000, "Downtown Office");
    myMovieHouse->AddStaff(manager);

    myMovieHouse->GetMovieHouseDetails();

    delete myMovieHouse;

    cout << "Total number of movies added: " << Movie::getMovieCount() << endl;
    cout << "Total number of staff members: " << Staff::getStaffCount() << endl;
    cout << "Total number of Movie Houses: " << MovieHouse::getMovieHouse() << endl;

    return 0;
}
