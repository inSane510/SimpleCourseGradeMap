#include <iostream>
#include <map>

using namespace std;

void addStudentToMap(map<string, string>& courseMap, string studentName){
    map<string, string>::iterator courseIterator = courseMap.find(studentName);

    if(courseIterator == courseMap.end()){
        courseMap[studentName] = "";
        cout << "Added the student to our Course, please make sure to update their grade!" << endl;
    }
    else{
        cout << "Error: This student already exists!" << endl;
    }

}

void removeStudentFromMap(map<string, string>& courseMap, string studentName){
    map<string, string>::iterator courseIterator = courseMap.find(studentName);

    if(courseIterator != courseMap.end()){ // make sure this student exists.
        courseMap.erase(courseIterator);

        cout << "Removed the student from our Course!" << endl;
    }
    else{
        cout << "Error: This student could not be found!" << endl;
    }
}

void modifyStudentGrade(map<string, string>& courseMap, string studentName){
    map<string, string>::iterator courseIterator = courseMap.find(studentName);

    if(courseIterator != courseMap.end()){
        string newGrade;

        cout << "Enter new Grade for " << courseIterator->first << ": ";
        cin >> newGrade;

        courseIterator->second = newGrade;

        cout << "Updated student " << courseIterator->first << "\'s grade to " << newGrade << endl;
    }
    else{
        cout << "Error: This student could not be found!" << endl;
    }

}

void printAllGradesInMap(map<string, string>& courseMap){
    map<string, string>::iterator courseIterator = courseMap.begin();

    cout << "-------------Printing all students....---------------" << endl;
    for(auto i = courseMap.begin(); i != courseMap.end(); i++){
        cout << i->first << ": " << i->second << endl;
    }

    cout << "-----------------------------------------------------" << endl;
}

void initiateInput(map<string, string>& courseMap){
    int userOption;


    do{
        cout << "What did you want to do?" << endl;
        cout << "1: Add a Student." << endl;
        cout << "2: Remove a Student." << endl;
        cout << "3: Modify a Grade." << endl;
        cout << "4: Print all grades." << endl;
        cout << "5: Exit" << endl;
        cout << "Enter Option: ";
        cin >> userOption;

        if(userOption < 1 || userOption > 5){
            cout << "You've went out of option bounds!" << endl;
            cout << "Lets retry..." << endl;
        }
        else
        {
            string studentsName;

            switch(userOption){

            case 1:
                cout << "Enter the Students name to add: ";
                cin >> studentsName;

                addStudentToMap(courseMap, studentsName);
                break;
            case 2:
                cout << "Enter the Student to remove: ";
                cin >> studentsName;

                removeStudentFromMap(courseMap, studentsName);
                break;
            case 3:

                cout << "Enter the Student to modify: ";
                cin >> studentsName;

                modifyStudentGrade(courseMap, studentsName);

                break;
            case 4:
                printAllGradesInMap(courseMap);

                break;
            case 5:
                return;
            }
        }

    }while(userOption != 5);

}



int main()
{
    map<string, string> courseStudents;



    cout << "Welcome to the Course Grade software." << endl;
    initiateInput(courseStudents);


    return 0;
}
