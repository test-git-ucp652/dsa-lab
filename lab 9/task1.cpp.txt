//#include <iostream>
//using namespace std;
//
//class Song
//{
//public:
//    int songID;
//    string songName;
//    float duration;
//    Song* next;
//    Song* prev;
//
//    Song(int id, string name, float dur)
//    {
//        songID = id;
//        songName = name;
//        duration = dur;
//        next = prev = NULL;
//    }
//};
//class Playlist 
//{
//private:
//    Song* head;
//    Song* tail;
//    Song* current;
//
//public:
//    Playlist()
//    {
//        head = tail = current = NULL;
//    }
//
//    //  Add song at end
//    void addSong(int id, string name, float duration)
//    {
//        Song* n = new Song(id, name, duration);
//
//        if (head == NULL)
//        {
//            head = tail = current = n;
//        }
//        else {
//            tail->next = n;
//            n->prev = tail;
//            tail = n;
//        }
//        cout << "Song added: " << name << endl;
//    }
//
//    //  Delete song by name
//    void deleteSong(string name)
//    {
//        Song* temp = head;
//
//        while (temp != NULL) {
//            if (temp->songName == name)
//            {
//                if (temp == head) 
//                {
//                    head = head->next;
//                    if (head)
//                    {
//                        head->prev = NULL;
//                    }
//                }
//                // If deleting tail
//                else if (temp == tail)
//                {
//                    tail = tail->prev;
//                    if (tail)
//                        tail->next = NULL;
//                }
//                // Middle node
//                else
//                {
//                    temp->prev->next = temp->next;
//                    temp->next->prev = temp->prev;
//                }
//
//                // Adjust current pointer
//                if (current == temp)
//                    current = temp->next ;
//
//                delete temp;
//                cout << "Song deleted: " << name << endl;
//                return;
//            }
//            temp = temp->next;
//        }
//
//        cout << "Song not found!\n";
//    }
//
//    // 3. Play next
//    void playNext() {
//        if (current == NULL)
//        {
//            cout << "Playlist is empty!\n";
//            return;
//        }
//
//        if (current->next != NULL) {
//            current = current->next;
//            cout << "Now playing: " << current->songName << endl;
//        }
//        else {
//            cout << "Already at last song.\n";
//        }
//    }
//
//    // Play previous
//    void playPrevious() {
//        if (current == NULL) {
//            cout << "Playlist is empty!\n";
//            return;
//        }
//
//        if (current->prev != NULL) {
//            current = current->prev;
//            cout << "Now playing: " << current->songName << endl;
//        }
//        else {
//            cout << "Already at first song.\n";
//        }
//    }
//
//    // 4. Reverse playlist
//    void reversePlaylist() {
//        Song* temp = NULL;
//        Song* curr = head;
//
//        while (curr != NULL) {
//            temp = curr->prev;
//            curr->prev = curr->next;
//            curr->next = temp;
//            curr = curr->prev;
//        }
//
//        // Swap head and tail
//        if (temp != NULL) {
//            head = temp->prev;
//        }
//
//        cout << "Playlist reversed!\n";
//    }
//
//    // 5. Display playlist
//    void display() {
//        Song* temp = head;
//
//        if (temp == NULL) {
//            cout << "Playlist is empty.\n";
//            return;
//        }
//
//        cout << "\n--- Playlist ---\n";
//        while (temp != NULL) {
//            cout << "ID: " << temp->songID
//                << ", Name: " << temp->songName
//                << ", Duration: " << temp->duration << " mins\n";
//            temp = temp->next;
//        }
//    }
//};
//
//// Example usage
//int main() {
//    Playlist p;
//
//    p.addSong(1, "Song A", 3.5);
//    p.addSong(2, "Song B", 4.0);
//    p.addSong(3, "Song C", 2.8);
//
//    p.display();
//
//    p.playNext();
//    p.playNext();
//    p.playPrevious();
//
//    p.deleteSong("Song B");
//    p.display();
//
//    p.reversePlaylist();
//    p.display();
//
//    return 0;
//}