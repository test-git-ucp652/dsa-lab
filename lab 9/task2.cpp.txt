//#include <iostream>
//using namespace std;
//
//struct Player
//{
//    int playerID;
//    int score;
//    Player* next;
//};
//
//class Game {
//private:
//    Player* head;
//    Player* current;
//
//public:
//    Game() 
//    {
//        head = NULL;
//        current = NULL;
//    }
//
//    // Add player
//    void addPlayer(int id) {
//        Player* newPlayer = new Player();
//        newPlayer->playerID = id;
//        newPlayer->score = 0;
//
//        if (head == NULL) {
//            head = newPlayer;
//            head->next = head;
//            current = head;
//        }
//        else {
//            Player* temp = head;
//            while (temp->next != head)
//                temp = temp->next;
//
//            temp->next = newPlayer;
//            newPlayer->next = head;
//        }
//    }
//
//    // Remove player
//    void removePlayer(int id) {
//        if (head == NULL) return;
//
//        Player* temp = head;
//        Player* prev = NULL;
//
//        do {
//            if (temp->playerID == id)
//                break;
//            prev = temp;
//            temp = temp->next;
//        } 
//        while (temp != head);
//
//        // If not found
//        if (temp->playerID != id) return;
//
//        // Only one player
//        if (temp == head && temp->next == head)
//        {
//            delete temp;
//            head = NULL;
//           //// current = NULL;
//            return;
//        }
//
//        // If removing head
//        if (temp == head) {
//            Player* last = head;
//            while (last->next != head)
//                last = last->next;
//
//            head = head->next;
//            last->next = head;
//        }
//        else {
//            prev->next = temp->next;
//        }
//
//        // Fix current
//        if (current == temp)
//            current = temp->next;
//
//        delete temp;
//    }
//
//    // Next turn
//    void nextTurn() {
//        if (current != NULL)
//            current = current->next;
//    }
//
//    // Skip turn
//    void skipTurn() {
//        if (current != NULL)
//            current = current->next->next;
//    }
//
//    // Check game over
//    bool isGameOver() {
//        return (head != NULL && head->next == head);
//    }
//
//    // Show current player
//    void showCurrent() {
//        if (current != NULL)
//            cout << "Current Player: " << current->playerID << endl;
//    }
//
//    // Declare winner
//    void declareWinner() {
//        if (isGameOver())
//            cout << "Winner is Player " << head->playerID << endl;
//    }
//};
//
//int main() {
//    Game g;
//
//    // Adding players
//    g.addPlayer(1);
//    g.addPlayer(2);
//    g.addPlayer(3);
//    g.addPlayer(4);
//
//    g.showCurrent();
//
//    // Game simulation
//    g.nextTurn();
//    g.showCurrent();
//
//    g.skipTurn();
//    g.showCurrent();
//
//    // Remove players
//    g.removePlayer(2);
//    g.removePlayer(3);
//    g.removePlayer(4);
//
//    // Check winner
//    if (g.isGameOver())
//        g.declareWinner();
//
//    return 0;
//}