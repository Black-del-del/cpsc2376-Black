class Game {
public:
    std::string title;
    int totalCopies;
    int availableCopies;

    Game(std::string title, int totalCopies);
    void checkOut();
    void returnCopy();
};

class Customer {
public:
    std::string name;

    Customer(std::string name);
};

class LendingRecord {
public:
    Game* game;
    Customer* customer;
    std::string dueDate;

    LendingRecord(Game* game, Customer* customer, std::string dueDate);
};

class LendingSystem {
public:
    void addGame(std::string title, int totalCopies);
    void listGames() const;
    void checkOutGame(std::string title, std::string customerName, std::string dueDate);
    void returnGame(std::string title, std::string customerName);

private:
    std::vector<Game> games;
    std::vector<LendingRecord> activeLoans;
};

classDiagram
    class Game {
        +string title
        +int totalCopies
        +int availableCopies
        +Game(string title, int totalCopies)
        +void checkOut()
        +void returnCopy()
    }

    class Customer {
        +string name
        +Customer(string name)
    }

    class LendingRecord {
        +Game* game
        +Customer* customer
        +string dueDate
        +LendingRecord(Game* game, Customer* customer, string dueDate)
    }

    class LendingSystem {
        +void addGame(string title, int totalCopies)
        +void listGames()
        +void checkOutGame(string title, string customerName, string dueDate)
        +void returnGame(string title, string customerName)
        -vector~Game~ games
        -vector~LendingRecord~ activeLoans
    }

    LendingSystem --> Game : manages
    LendingSystem --> LendingRecord : tracks
    LendingRecord --> Game : references
    LendingRecord --> Customer : references
