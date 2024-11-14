#include <iostream>
#include <vector>
using namespace std;

class MovieCount {  // Manages Movie count
private:
    static int count;

public:
    static void incrementCount() { count++; }
    static void decrementCount() { count--; }
    static int getCount() { return count; }
};

int MovieCount::count = 0;

// movie class manages movie data
class Movie {                 //Movie class can be substitued by its sub-class IMAXMovie
private:
    string movieName;
    int movieDuration;
    bool is3D;

public:
    Movie(string movie = "", int time = 0, bool value = false)
        : movieName(movie), movieDuration(time), is3D(value) {
        MovieCount::incrementCount();
        cout << "Movie created: " << movieName << endl;
    }

    virtual ~Movie() {
        cout << "Movie destroyed: " << movieName << endl;
        MovieCount::decrementCount();
    }

    string getMovieName() const {
        return movieName;
    }

    int getMovieDuration() const {
        return movieDuration;
    }

    bool getIs3D() const {
        return is3D;
    }

    virtual void movieDetailsDisplay() const = 0;  // Pure virtual function
};

class IMAXMovie : public Movie {           //a type of movie inherited from movie class
private:
    string soundSystem;

public:
    IMAXMovie(string movie, int time, bool value, string soundSys)
        : Movie(movie, time, value), soundSystem(soundSys) {}

    void movieDetailsDisplay() const override {
        cout << "Movie name: " << getMovieName() << endl;
        cout << "Movie Duration: " << getMovieDuration() << endl;
        cout << "Movie Screen Details: " << (getIs3D() ? "3D" : "2D") << endl;
        cout << "Sound System: " << soundSystem << endl;
    }
};

// Staff class manages the staff data
class Staff {                //Staff class can be substitued by its sub-class manager
private:
    string name;
    string position;
    double salary;

public:
    Staff(string n = "", string pos = "", double s = 0.0)
        : name(n), position(pos), salary(s) {
        cout << "Staff created: " << name << endl;
    }

    virtual ~Staff() {
        cout << "Staff destroyed: " << name << endl;
    }

    string getName() const {
        return name;
    }

    string getPosition() const {
        return position;
    }

    double getSalary() const {
        return salary;
    }

    virtual void staffDetailsDisplay() const = 0;  // Pure virtual function
};

class Manager : public Staff {                  //Inherited from staff class
private:
    string officeLocation;

public:
    Manager(string n, string pos, double s, string location)
        : Staff(n, pos, s), officeLocation(location) {}

    void staffDetailsDisplay() const override {
        cout << "Name: " << getName() << endl;
        cout << "Position: " << getPosition() << endl;
        cout << "Salary: " << getSalary() << endl;
        cout << "Office Location: " << officeLocation << endl;
    }
};

// MovieHouse class manages movies and staff
class MovieHouse {
private:
    string movieHouseName;
    vector<Movie*> movies;
    vector<Staff*> staffMembers;

public:
    MovieHouse(string name = "") : movieHouseName(name) {
        cout << "MovieHouse created: " << movieHouseName << endl;
    }

    ~MovieHouse() {
        cout << "MovieHouse destroyed: " << movieHouseName << endl;
        for (Movie* movie : movies) delete movie;
        for (Staff* staff : staffMembers) delete staff;
    }

    void setMovieHouseName(string name) {
        movieHouseName = name;
    }

    void addMovie(Movie* movie) {
        movies.push_back(movie);
    }

    void addStaff(Staff* staff) {
        staffMembers.push_back(staff);
    }

    void displayDetails() const {
        cout << "Movie House Name: " << movieHouseName << endl;
        cout << "Movies: " << endl;
        for (const Movie* movie : movies) {
            movie->movieDetailsDisplay();
        }
        cout << "Staff Members: " << endl;
        for (const Staff* staff : staffMembers) {
            staff->staffDetailsDisplay();
        }
    }
};

// Main function for interaction
int main() {
    int movieHouseCount;
    cout << "Enter number of movie houses you want to create: ";
    cin >> movieHouseCount;
    cin.ignore();

   
    for (int j = 0; j < movieHouseCount; j++) {
        MovieHouse* movieHouse = new MovieHouse();
        string name;
        int numberOfMovies, numberOfStaff;

        cout << "Enter a MovieHouse name: ";
        getline(cin, name);
        movieHouse->setMovieHouseName(name);

        cout << "Enter number of Movies: ";
        cin >> numberOfMovies;
        cin.ignore();


        for (int i = 0; i < numberOfMovies; i++) {
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
            Movie* movie = new IMAXMovie(name, time, screen, "Dolby Atmos");
            movieHouse->addMovie(movie);
        }

       
        cout << "Enter number of Staff members: ";
        cin >> numberOfStaff;
        cin.ignore();

        for (int i = 0; i < numberOfStaff; i++) {
            string name, position, location;
            double salary;
            cout << "Enter details for Staff member " << i + 1 << ": " << endl;
            cout << "Name: ";
            getline(cin, name);
            cout << "Position: ";
            getline(cin, position);
            cout << "Salary: ";
            cin >> salary;
            cin.ignore();
            cout << "Office Location: ";
            getline(cin, location);
            Staff* staff = new Manager(name, position, salary, location);
            movieHouse->addStaff(staff);
        }

        movieHouse->displayDetails();
        delete movieHouse;  
    }

   
    MovieHouse* myMovieHouse = new MovieHouse("CineMax");
    Movie* imaxMovie = new IMAXMovie("Inception", 148, true, "Dolby Atmos");
    myMovieHouse->addMovie(imaxMovie);
    Staff* manager = new Manager("John Doe", "Manager", 50000, "Downtown Office");
    myMovieHouse->addStaff(manager);
    myMovieHouse->displayDetails();

    delete myMovieHouse;  

    return 0;
}
