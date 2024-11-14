#include <iostream>
#include <vector>
using namespace std;

class MovieCount {             //Manages Movie count
private:
    static int count;

public:
    static void incrementCount() { count++; }
    static void decrementCount() { count--; }
    static int getCount() { return count; }
};

int MovieCount::count = 0;

class Movie {               //represents a movie with its details
private:
    string MovieName;
    int MovieDuration;
    bool is3D;

public:
    // Constructor
    Movie(string movie = "", int time = 0, bool value = false) {
        MovieName = movie;
        MovieDuration = time;
        is3D = value;
        MovieCount::incrementCount();
        cout << "Movie created: " << MovieName << endl;
    }

    // Destructor
    ~Movie() {
        cout << "Movie destroyed: " << MovieName << endl;
        MovieCount::decrementCount();
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

class IMAXMovie : public Movie {                //Inherited from movie class with additional properties
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

class Staff {                 //represents a staff with details
private:
    string Name;
    string Position;
    double salary;
    static int StaffCount;

public:
    Staff(string n = "", string pos = "", double s = 0.0) : Name(n), Position(pos), salary(s) {
        StaffCount++;
        cout << "Staff created: " << Name << endl;
    }

    virtual ~Staff() {
        cout << "Staff destroyed: " << Name << endl;
        StaffCount--;
    }

    static int getStaffCount() {
        return StaffCount;
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

    virtual void StaffDetailsDisplay() const = 0;  // Pure virtual function
};

int Staff::StaffCount = 0;

class Manager : public Staff {              //inherited from staff class with some additional properties
private:
    string officeLocation;

public:
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    void StaffDetailsDisplay() const override {
        cout << "Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "Office Location: " << officeLocation << endl;
    }
};

class MovieHouse {               //Manages movies and staff within a movie house.
private:
    string MovieHouseName;
    vector<Movie*> Movies;
    vector<Staff*> StaffMembers;
    static int MovieHouseCount;

public:
    MovieHouse(string name = "") : MovieHouseName(name) {
        MovieHouseCount++;
        cout << "MovieHouse created: " << MovieHouseName << endl;
    }

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

int main() {                                     //manages user interactions
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

    return 0;
}
