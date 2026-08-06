#include <iostream>
#include <vector>
#include <string>

#include <algorithm>
#include <random> 

#include <fstream>




using namespace std;

enum Priority{
 Low = 1,

 Medium,

 High,
};

class Task{  //v3
private: 
  string title;

  string deadline;

  string description;
 
  Priority taskPriority;
  
  bool complete;

public: 

Task(){

}

Task(string t, string d, string e, bool c, Priority p){
    title = t;

    deadline = d;

    description = e;

    complete = c;

    taskPriority = p ;

}

string getTitle() const
{
    return title;
}

string getDeadline() const
{
    return deadline;
}

string getDescription() const
{
    return description; 
}

bool isCompleted() const
{
    return complete;

}

enum Priority getPriority() const
{
  return taskPriority;
}

int priorityChoice;

void inputData()
{
    cout<<"Enter Title: "<<endl;
    getline(cin, title);

  cout<<"======================="<<endl; 

    cout<<"Enter Description: "<<endl;
    getline(cin, description);

  cout<<"======================="<<endl;   
    
    cout<<"Enter Deadline: "<<endl;
    getline(cin, deadline);

  cout<<"======================="<<endl; 

  cout<<"Enter Priority: "<<endl;

 cout<<"|1. Low" <<endl;

cout<<"======================="<<endl; 

 cout<<"|2. Medium" <<endl; 
 
cout<<"======================="<<endl;

 cout<<"|3. High" <<endl;

cout<<"======================="<<endl;

 cin>> priorityChoice;
  cin.ignore();

  switch(priorityChoice)
  {
    case 1: 
    {
       taskPriority = Low;
       break;
    }
    case 2:
    {
        taskPriority = Medium;
        break;
    }
    case 3:
    {
        taskPriority = High;
        break;
    }
    default:
    {
        cout<<"Wrong Input, Choose a Valid Input."<<endl;
    }
  }

cout<<"======================="<<endl;
  
  complete = false;

  cout<<"======================="<<endl; 
}

void markComplete()
{
    complete = true;
}

void showInfo() const
{
    cout<<"|Title: "<< title <<endl;

   cout<<"======================="<<endl; 

   cout<<"|Deadline: "<< deadline <<endl;
   
   cout<<"======================="<<endl; 

   cout<<"|Description: "<< description <<endl;
   
   cout<<"======================="<<endl; 

   cout<<"|Priority: ";
   switch (taskPriority)
   {
   case Low:
   
    cout<<"Low"<<endl;
    break;
   
   case Medium:
   
    cout<<"Medium"<<endl;
    break;
   
   case High:
   
    cout<<"High"<<endl;
    break;
   
   default:
    break;
   }

   cout<<"======================="<<endl; 

   cout<<"|Status: ";
   if(complete)
   {
    cout<<"Finished"<<endl;
   }
   else
   {
    cout<<"Unfinished"<<endl;
   }
}

}; 

void saveTasks(vector<Task> &tasks)
{
    ofstream outfile("Tasks.txt");
    for(const Task &t : tasks)
    {
        outfile << t.getTitle() <<endl;

        outfile << t.getDescription() <<endl;

        outfile << t.getDeadline() <<endl;

        outfile << t.getPriority() <<endl;
        
        outfile << t.isCompleted() <<endl;
    }
    outfile.close();
}

void loadTasks(vector<Task> &tasks)
{


    tasks.clear();


    ifstream infile("Tasks.txt");
     

    if(infile.is_open())
    {
        string title;
        string description;
        string deadline;
        Priority taskPriority;
        bool complete;

        while(getline(infile, title))
        {
            getline(infile, description);
            getline(infile, deadline);
            
            int priorityValue;
            infile>> priorityValue;
            infile.ignore();

            taskPriority = static_cast<Priority>(priorityValue);
             
            infile >> complete;
            infile.ignore();

            

            Task temp(title, deadline, description, complete, taskPriority);

                tasks.push_back(temp);

        }
    }
    else
    {
        cout<<"No tasks to load."<<endl;
        return;
    }
    infile.close();
}



void saveCompleteTasks( const Task &t)
{
    ofstream outfile("Complete_Tasks.txt", ios::app);
 
   
     outfile << t.getTitle()<<endl;
     outfile << t.getDescription()<<endl;
     outfile << t.getDeadline()<<endl;
     outfile<< t.getPriority()<<endl;
    outfile << t.isCompleted() <<endl;

 outfile.close();
}

void loadCompleteTasks(vector<Task> &completedTasks)
{

    completedTasks.clear();

    ifstream infile("Complete_Tasks.txt");
    if(infile.is_open())
    {   
        string title;

        string description;

        string deadline;

        Priority taskPriority;

       bool complete;

       while(getline(infile, title))
       {
        getline(infile, description);

        getline(infile,deadline);

         int priorityValue;
            infile>> priorityValue;
            infile.ignore();

            taskPriority = static_cast<Priority>(priorityValue);
             
          infile>> complete;
          infile.ignore();

           Task temp(title, deadline, description, complete, taskPriority);
           
           completedTasks.push_back(temp);

       }
    }
    else
    {
        cout<<"No Complete Tasks."<<endl;

    }
    infile.close();
}


struct Statistics{
 int total;

 int completed;

 int unfinished;

 double getFinishedPercentage() const
 {

  if(total == 0){
    return 0.0;
  }

  {

  
    double percentFinished = (completed * 100.0) / total;
        return percentFinished;
  }

 }


 double getUnfinishedPercentage() const
 {
    if(total == 0){
        return 0.0;

    }

    {
    double percentUnfinished = (unfinished * 100.0) / total;

     return percentUnfinished;
    }

 }


 void display()const {
         cout<<"\n--Info--\n";

    cout<<"|Total           : "<< total <<endl;

    cout<<"|Completed       : "<< completed <<endl;

    cout<<"|Completion Rate :  "<< getFinishedPercentage() << "%" <<endl;

    cout<<"==========================="<<endl;

    cout<<"|Unfinished      : "<< unfinished <<endl;

    cout<<"|Remaining Rate  :  "<< getUnfinishedPercentage() << "%" << endl;

 }
};


int main(){


vector<Task> tasks;
vector<Task> completedTasks;

int choice;

bool Running = true;

int numofTasks;

int count = 0;

string Target;

bool Found = false;



loadTasks(tasks);

loadCompleteTasks(completedTasks);

while(Running)
{
   cout<<"\n=========================\n"<<endl;
   cout<<"\n|--STUDENT LIFE MANAGER V3!--|\n"<<endl;
   cout<<"\n=========================\n"<<endl;

   cout<<"Hello user how can i help you today?"<<endl;

   cout<<"1. Add Task"<<endl;
   cout<<"===================="<<endl;

   cout<<"2. Display Tasks"<<endl;
   cout<<"===================="<<endl;

   cout<<"3. Search Tasks"<<endl;
   cout<<"===================="<<endl;

   cout<<"4. Mark Task Complete"<<endl;
   cout<<"===================="<<endl;

   cout<<"5.Remove Task"<<endl;
   cout<<"===================="<<endl;

   cout<<"6.Show Statistics"<<endl;
   cout<<"===================="<<endl;

   cout<<"7.Show Completed Tasks"<<endl;
   cout<<"===================="<<endl;

    cout<<"8.Exit"<<endl;

   cin>> choice;
   cin.ignore();

   switch (choice)
   {
   case 1:
   {
    cout<<"How Many Tasks You Want to add?"<<endl;
    cin>> numofTasks;
    cin.ignore();

    for(int i = 0; i < numofTasks; i++)
    {
        Task t;
        t.inputData();

        tasks.push_back(t);

    }
    saveTasks(tasks);
         break;
   }

   case 2:
   {
    if(tasks.empty())
    {
        cout<<"No Tasks To Show"<<endl;
    }
    else
    {
        cout<<"\n--Tasks--\n"<<endl;
        count = 0;
        
        for(const Task &t : tasks)
        {
            cout<<"\n---Task "<< count + 1 << "---\n";

            t.showInfo();

            count++;
           
        }
    }
    break;
   }
   case 3:
   {
    if(tasks.empty())
    {
        cout<<"No Tasks To Search For."<<endl;
       
    }
    else
    {
        cout<<"\nEnter Task's Title: \n"<<endl;

        getline(cin, Target);

        Found = false;

        for(const Task &t : tasks)
        {
            if(Target == t.getTitle())
            {
                Found = true;

                cout<<"Task Is Found!"<<endl;

                t.showInfo();
                 
                break;
            }
            
        }
        if(!Found)
        {
            cout<<"Task Is Not Found."<<endl;
        }
    }
       break;
   }
   case 4:
   {
     if(tasks.empty())
     {

        cout<<"No Tasks Available To Mark Complete."<<endl;

     }
     else
     {
        count = 0;
        for(const Task &t : tasks)
        {
            cout<<"\n--Task "<< count + 1 <<"---\n"<<endl;
            t.showInfo();
            count++;
        }

        cout<<"\nEnter Task's Title: \n"<<endl;
        getline(cin, Target);

        Found = false;
        for( Task &t : tasks)
        {
            if(Target == t.getTitle())
            {
                Found = true;

                if(t.isCompleted())
                {
                    cout<<"Task Is Already Completed."<<endl;
                }
                else
                {
                    t.markComplete();

                    cout<<"Task Is Marked Complete!"<<endl;

                     completedTasks.push_back(t);
                     
                    saveCompleteTasks(t);

                    saveTasks(tasks);

                    t.showInfo();
                    
                }
                   break;
                }
            }

            if(!Found)
            {
                cout<<"Task Is Not Found."<<endl;
            }
            break;
        }
        
     }
     case 5:
     {
        if(tasks.empty())
        {
            cout<<"No Tasks Available To Remove."<<endl;
        }
        else
        {      count = 0;
            for(const Task &t : tasks)
            {
                cout<<"\n--Task "<< count + 1 <<"---\n"<<endl;

                t.showInfo();

                count++;
            }

            cout<<"\nEnter Task's Title To Remove: \n"<<endl;

            getline(cin, Target);
            Found = false;

            for(int i = 0; i < tasks.size(); i++)
            {
                if(Target == tasks[i].getTitle())
                {
                    Found = true;

                    tasks.erase(tasks.begin() + i);

                    cout<<"Task Is Removed!"<<endl;
                    

                    saveTasks(tasks);
                    break;


                }
            } 
             if(!Found)
            {
                cout<<"Task Is Not Found."<<endl;

            }
        }
            break;
        }
        case 6:
        {
            if(tasks.empty())
            {
                cout<<"No Tasks Available To Show Statistics."<<endl;
            }
            else
            {
                int completed = 0;
                
                for(const Task &t : tasks)
                {
                    if(t.isCompleted())
                    {
                        completed++;
                    }
                }

                Statistics stats;

               stats.total = tasks.size();

               stats.completed = completed;

               stats.unfinished = stats.total - stats.completed;

               stats.display();
            }

               break;
        }
        case 7:
        {
            if(completedTasks.empty())
            {
                cout << "No Completed Tasks To Show." << endl;
            }
    else
    {
        count = 0;

        for(const Task &t : completedTasks)
        {
            cout << "\n--Completed Task "
                 << count + 1
                 << "---\n" << endl;

            t.showInfo();

            count++;
        }
    }

    break;
}
        
case 8:
    {
            Running = false;
            cout<<"Exiting Student Life Manager V3"<<endl;
            break;
    }
    
   
   default:
   cout<<"This Option Doesn't Exist"<<endl;

    break;
   }





















    return 0;


}
}








