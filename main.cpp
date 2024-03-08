#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

class Process {
  private: 
  static int next_process;
  int process_id = 0;
  
  public:
  vector<int> tickets = vector<int>(0);
  
  // constructors
  Process():tickets({}){
    this->process_id = Process::next_process;
    Process::next_process++;
  }

  Process(const vector<int>& new_tickets):Process(){
    this->tickets = new_tickets;
  }

  // access
  int get_pid(){return this->process_id;}

  // functions
  void run(){
    cout << "Process " << this->process_id << " has ran!" << endl;
  }

  static int get_next_process(){
    return Process::next_process;
  }
};
int Process::next_process = 0;


class Scheduler {
private:
  static int next_ticket;
  
public:
  const static int MAX_PROCESSES = 10;
  vector<Process*> p_list = {};
  
  // Constructor
  Scheduler():p_list({}){}

  ~Scheduler(){
    for (auto p : this->p_list) {
      delete p;
    }
  }

  // functions
  void add_tickets(Process& p){
    for(int i = 0; i < 5; i++){
      p.tickets.push_back(Scheduler::next_ticket);
      Scheduler::next_ticket++;
    }
  }

  void add_process(){
    Process* p = new Process();
    add_tickets(*p);
    this->p_list.push_back(p);
  }

  int draw_ticket(){
    // generate a number between 0 and next_ticket - 1
    int num = (rand() % Scheduler::next_ticket);

    cout << "Scheduler drawing lottery ticket: " << num << endl;

    // check who has the ticket
    for(auto& p : this->p_list){
      for(int tic : p->tickets){
        if (tic == num) {
          p->run();
          return p->get_pid();
        }
      }
    }

    // default
    return 0;
  }
};
int Scheduler::next_ticket = 0;

int main(){
  srand(time(nullptr));
  cout << "Hello world!" << endl;

  cout << "\n\nCreating Scheduler... ";
  Scheduler s = Scheduler();
  cout << "Done!" << endl;

  cout << "\n\nCreating 5 Processes... ";
  s.add_process();
  s.add_process();
  s.add_process();
  s.add_process();
  s.add_process();
  cout << "Done!" << endl;

  cout << "\n\nDrawing 5 Tickets... " << endl;
  s.draw_ticket();
  s.draw_ticket();
  s.draw_ticket();
  s.draw_ticket();
  s.draw_ticket();
  cout << "DONE!" << endl;
  
  return 0;
}
