#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>

using namespace std;

struct Page {
    int id;
    string path;
    int counter;
    Page(int id, string path) {
        this->id = id;
        this->path = path;
        counter = 0;
    };
};

// This function can facilitate sorting
bool operator<(const Page & a, const Page & b) {
  return (a.id < b.id);
}

vector<Page> pages;

struct User {
    int id;
    vector<string> visits; //record the website the users has been

    User(int id) {
        this->id = id;
    };

    void add_visit(int page_id) {
    //find the page name by using the page id
    vector<Page>::iterator iter;
    for(iter=pages.begin();iter != pages.end();iter++){
      if ((*iter).id == page_id) visits.push_back((*iter).path);
    }
    };

    int size() const {
        return visits.size();
    };

    void print_visits() {
      vector<string>::iterator iter;
      //sort the pages
      sort(visits.begin(), visits.end());
      // finally, print out the pages
      for(iter = visits.begin();iter != visits.end();iter++){
        cout<<"- "<<*iter<<endl;
      }
    }
};

vector<User> users;

// Please implement the following function to facilitate the sorting of users
bool operator<(const User & a, const User & b) {
  if (a.size() == b.size()) return a.id < b.id;
  return (a.size() > b.size());
}

// Please implement the following function
void add_page(const Page& p) {
  pages.push_back(p);

}

// Please implement the following function
bool cmp_page_count(const Page & a, const Page & b) {
  if (a.counter == b.counter) return a.path < b.path;
  return (a.counter > b.counter);
}

// Please implement the following function
void print_pages(int number) {
  for(int i=0;i<number;++i){
    cout<<pages[i].counter<<":"<<pages[i].path<<endl;
  }
}

// Please implement the following function
void add_user(User u) {
  users.push_back(u);
}

// Please implement the following function
// This is to record the pages that a certain user has been
void add_visit(int page_id) {
  users.back().add_visit(page_id);
}

// Please implement the following function
void print_users(int number) {
  for(int i = 0; i< number;++i){
    cout<<users[i].size()<<":"<<users[i].id<<endl;
    users[i].print_visits();
  }
}

int main() {

    string type;
    while(cin >> type){

        if(type == "USER") {
          int user_id;
          cin >> user_id;
          User u(user_id);
          add_user(u);
        }

        else if(type == "PAGE") {
          int page_id;
          string page_path;
          cin >> page_id;
          cin >> page_path;
          Page p(page_id, page_path);
          add_page(p);
        }

        else if(type == "VISIT") {
          int page_id;
          cin >> page_id;
          Page p(page_id, "");
          //add number to the counter of the webpage
          vector<Page>::iterator iter;
          for(iter = pages.begin(); iter != pages.end();iter++){
            if(iter->id == p.id) {
              iter->counter++;
              break;
            }
          }
          //this is for users, it counts how many webpage he has visited
          add_visit(p.id);
        }
    }


    sort(pages.begin(), pages.end(), cmp_page_count);
    cout << "*** 5 most popular pages ***" << endl;
    print_pages(5);
    sort(pages.begin(), pages.end());

    sort(users.begin(), users.end());
    cout << "*** 5 most active users ***" << endl;
    print_users(5);

    return 0;

}
