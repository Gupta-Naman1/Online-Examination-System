#include<bits/stdc++.h>
#include <Windows.h>
using namespace std; 

void thanks()
{   
    system ("CLS");

    ifstream in("Thanks.txt"); 
   
    if(!in) {
       cout << "Cannot open input file.\n";
    }
    char str[1000];
    while(in) {
       in.getline(str, 1000);  // delim defaults to '\n' cp
       if(in) cout << str << endl;
    }
    in.close();
}

class Question{
private:
int quesNo; 
string quesDesc; 
string choiceA; 
string choiceB; 
string choiceC; 
string choiceD; 
char correctOpt; 
public:
    void addQuestion(string s);
    void editQuestion(string s);
};

void Question::addQuestion(string s)
{
    fstream f;

    string s1 = ".txt";
    s = s + s1;
    f.open(s.c_str(),ios::app | ios::out);

    string str;
    getline (cin, str);
    cout<<"Enter Question : ";
    getline (cin, quesDesc);
    f<<quesDesc<<endl;
    cout<<"Enter Choice A : ";
    getline (cin, choiceA);
    f<<"A. "<<choiceA<<endl;
    cout<<"Enter Choice B : ";
    getline (cin, choiceB);
    f<<"B. "<<choiceB<<endl;
    cout<<"Enter Choice C : ";
    getline (cin, choiceC);
    f<<"C. "<<choiceC<<endl;
    cout<<"Enter Choice D : ";
    getline (cin, choiceD);
    f<<"D. "<<choiceD<<endl;
    cout<<"Enter the correct choice : ";
    cin>>correctOpt;
    f<<"Correct Option : "<<correctOpt<<endl;
    f.close();

    cout<<"\n\n Question added Successfully!! \n";
}

void Question::editQuestion(string s){
    fstream f;
    
    string s1 = ".txt";
    s = s + s1;
    f.open(s.c_str(),ios::in);
    
    int n;
    fstream t;
    t.open("temp.txt",ios::out);
    cout<<"Enter Question number you want to change : ";
    cin>>n;
    
    int ind = (n-1)*6;
    int x = 0;
    string c;
    while (getline(f, c))
    {
        if(ind<=0 && ind>=(-5))
        {   
            if(x==0)
            {
            string str;
            getline (cin, str);
            cout<<"Enter Question : ";
            getline (cin, quesDesc);
            t<<quesDesc<<endl;
            cout<<"Enter Choice A : ";
            getline (cin, choiceA);
            t<<"A. "<<choiceA<<endl;
            cout<<"Enter Choice B : ";
            getline (cin, choiceB);
            t<<"B. "<<choiceB<<endl;
            cout<<"Enter Choice C : ";
            getline (cin, choiceC);
            t<<"C. "<<choiceC<<endl;
            cout<<"Enter Choice D : ";
            getline (cin, choiceD);
            t<<"D. "<<choiceD<<endl;
            cout<<"Enter the correct choice : ";
            cin>>correctOpt;
            t<<"Correct Option : "<<correctOpt<<endl;
            x=1;
            }

        }
        else
        {
            t<<c<<endl;
        }
        ind--;
    }   
    f.close();
    t.close();

    remove(s.c_str());
    rename("temp.txt", s.c_str());

    cout<<"\n\n Question edited Successfully!! \n";

}

void removeQuestion(string s){
    fstream f;
    
    string s1 = ".txt";
    s = s + s1;
    f.open(s.c_str(),ios::in);

    int n;
    fstream t;
    t.open("temp.txt",ios::out);
    cout<<"Enter Question number you want to remove : ";
    cin>>n;
    
    int ind = (n-1)*6;
    string c;
    while (getline(f, c))
    {
        if(ind<=0 && ind>=(-5) )
        {
            cout<<c<<endl;
            // s = s + c;
        }
        else
        {
            t<<c<<endl;
        }
        ind--;
    }   
    f.close();
    t.close();
    
    remove(s.c_str());
    rename("temp.txt", s.c_str());

    cout<<"\n\n Question removed Successfully!! \n";

}

void viewQuestionPaper(string s){
    fstream f;
    
    string s1 = ".txt";
    s = s + s1;
    f.open(s.c_str(),ios::in);

    cout<<endl;
    int x = 1;
    string str;
    while (getline(f, str))
    {   
        if(x%6==1)
        cout<<(x/6)+1<<". "<<str<<endl;
        else
        cout<<str<<endl;

        if(x%6==0)
        cout<<endl;
        x++;
    }

    f.close();
}

class student{
int age;  
int Class;
char sec;
class address{
    public:
    string Hno; 
    string city; 
    string district;
        void inputAddress(){
            cout<<" City Name : ";
            getline (cin,city);
            cout<<" District Name : ";
            getline (cin,district);
            cout<<" House Number : ";
            getline (cin,Hno);
        }
};
address add;
string mothersName;
string fathersName;
protected:
string name;
int rollNo;
public:
    void addStudent(string s);
    void viewAllStudents(string s);
    void searchStudent(string s);
    void removeStudent(string s);
    void updateStudent(string s);
};

void student::addStudent(string st){
    fstream f;
    string s1 = "student.txt";
    st = st+s1;
    f.open(st.c_str(),ios::out | ios::app);
    cout<<"\n Enter Student's Info : \n";
    cout<<"\n Roll Number : ";
    cin>>rollNo;
    f<<"Roll Number : "<<rollNo<<"\n";
    string str;
    getline(cin,str);
    cout<<"\n Name : ";
    getline (cin, name);
    f<<"Name : "<<name<<"\n";
    cout<<"\n Age : ";
    cin>>age;
    f<<"Age : "<<age<<"\n";
    stringstream geek(st);
    geek>>Class;
    cout<<"\n Section : ";
    cin>>sec;
    f<<"Class & Sec : "<<Class<<" "<<sec<<"\n";
    getline(cin,str);
    cout<<"\n Father's Name : ";
    getline (cin, fathersName);
    f<<"Father's Name : "<<fathersName<<"\n";
    cout<<"\n Mother's Name : ";
    getline (cin, mothersName);
    f<<"Mother's Name : "<<mothersName<<"\n";
    cout<<"\n Address : \n";
    add.inputAddress();
    f<<"Address : "<<add.Hno<<", "<<add.district<<", "<<add.city<<"\n";
    f<<"_________________________________________\n";

    cout<<"\n\n Student Info added Successfully!! \n";
}

void student::viewAllStudents(string st){
    fstream f;
    string s1 = "student.txt";
    st = st+s1;
    f.open(st.c_str(),ios::in);
    string str;
    cout<<"\n";
    while (getline(f, str))
    {   
        cout<<str<<endl;
    }
    f.close();
}

void student::searchStudent(string st){
    fstream f;
    string s1 = "student.txt";
    st = st+s1;
    string roll;
    cout<<"\nEnter the Roll Number of the Student you want to Search : ";
    cin>>roll;
    f.open(st.c_str(),ios::in);
    int n=0;
    string str;
    string s;
    s = "Roll Number : " + roll;
    while(getline(f,str))
    {   
        if(str == s || (n>0 && n<=7))
        {
            cout<<str<<endl;
            n++;
        }
    }
    if(f.eof() && n==0)
    {
        cout<<"\n The Entered Roll Number Doesn't match with our records! ";
        cout<<"\n Please try Again! \n\n";
    }
    f.close();
}

void student::removeStudent(string st){
    fstream f,t;
    string s1 = "student.txt";
    st = st+s1;
    f.open(st.c_str(),ios::in);
    t.open("temp.txt",ios::out);
    string roll;
    cout<<"\n Enter the Roll Number of the Student you want to Remove : ";
    cin>>roll;
    cout<<"\n All the information of the student will be removed completely : \n";
    cout<<" Do you want to continue ? (Y/N) : ";
    char ch;
    cin>>ch;
    cout<<"\n\n";
    if(ch=='N' || ch=='n')
    {
        cout<<" Student Information not removed ! \n";
        return;
    }

    int n=0;
    string str;
    string s;
    s = "Roll Number : " + roll;
    while(getline(f,str))
    {   
        if(str == s || (n>0 && n<=7))
        {
            cout<<str<<endl;
            n++;
        }
        else
        {
            t<<str<<endl;
        }
    }
    if(f.eof() && n==0)
    {
        cout<<"\n The Entered Roll Number Doesn't match with our records! ";
        cout<<"\n Please try Again! \n\n";
    }
    f.close();
    t.close();
    remove(st.c_str());
    rename("temp.txt",st.c_str());

    cout<<"\n\n Student Info removed Successfully!! \n";
}

void student::updateStudent(string st){
    fstream f,t;
    string s1 = "student.txt";
    st = st+s1;
    string roll;
    cout<<"\nEnter the Roll Number of the Student you want to Update : ";
    cin>>roll;
    f.open(st.c_str(),ios::in);
    t.open("temp.txt",ios::out);
    int n=0,x=0;
    string str;
    string s;
    s = "Roll Number : " + roll;
    while(getline(f,str))
    {   
        if(str == s || (n>0 && n<=7))
        {   
            if(x==0){
                cout<<"\n Roll Number : ";
                cin>>rollNo;
                t<<"Roll Number : "<<rollNo<<"\n";
                string str;
                getline(cin,str);
                cout<<"\n Name : ";
                getline (cin, name);
                t<<"Name : "<<name<<"\n";
                cout<<"\n Age : ";
                cin>>age;
                t<<"Age : "<<age<<"\n";
                stringstream geek(st);
                geek>>Class;
                cout<<"\n Section : ";
                cin>>sec;
                t<<"Class & Sec : "<<Class<<" "<<sec<<"\n";
                getline(cin,str);
                cout<<"\n Father's Name : ";
                getline (cin, fathersName);
                t<<"Father's Name : "<<fathersName<<"\n";
                cout<<"\n Mother's Name : ";
                getline (cin, mothersName);
                t<<"Mother's Name : "<<mothersName<<"\n";
                cout<<"\n Address : \n";
                add.inputAddress();
                t<<"Address : "<<add.Hno<<", "<<add.district<<", "<<add.city<<"\n";
                t<<"_________________________________________\n";
                x=1;
            }
            n++;
        }
        else
        {
            t<<str<<endl;
        }
    }
    if(f.eof() && n==0)
    {
        cout<<"\n The Entered Roll Number Doesn't match with our records! ";
        cout<<"\n Please try Again! \n\n";
    }
    f.close();
    t.close();
    remove(st.c_str());
    rename("temp.txt",st.c_str());
}

class result: protected student{    //Now name and roll no are also protected members of class result
private:
    map < string, int > m;
    int totalMarks;
    float totalPercentage;
public:
    void addResult(string st);
    void viewResultOfAll(string st);
    void searchResult(string st);         //search result of a student whose roll no is entered by the user
    void updateResult(string st);
};

void result::addResult(string st){
    fstream f;
    string s1;
    s1 = "result.txt";
    st = st + s1;
    f.open(st.c_str(),ios::app | ios::out);
    cout<<"\n Enter the Roll Number of the Student : ";
    cin>>rollNo;
    f<<"Roll Number : "<<rollNo<<"\n";
    string str;
    getline(cin,str);
    cout<<"\n Enter the Name of the Student : ";
    getline(cin,name);
    f<<"Name : "<<name<<"\n";
    
    cout<<"\n Enter total Marks of Each Subject : ";
    cin>>totalMarks;
    if(totalMarks==0)
    {
        cout<<"\n Total Marks cannot be ZERO! Please Try Again : ";
        cin>>totalMarks;
    }

    string sub;
    int marks;
    cout<<"\n Enter Subject Name and Marks one by one : \n";
    for(int i=0; i<5; i++){
        cout<<" ";
        cin>>sub>>marks;
        if(marks>totalMarks)
        {
            cout<<"\n Entered Marks cannot be greater than Total Marks ! Try Again : ";
            cout<<"\n Enter Marks : ";
            cin>>marks;
        }
        m[sub] = marks;
    }
    int sum = 0;
    map < string, int > :: iterator i;
    for(i= m.begin(); i != m.end(); i++){
        f<<i->first<<" : "<<i->second<<"\n";
        sum+=i->second;
    }

    totalMarks*=5;
    f<<"Total Marks : "<<totalMarks<<"\n";
    totalPercentage = float((sum*100) / totalMarks);  
    cout<<" Total Percentage : "<<totalPercentage<<"%"<<endl;
    f<<"Total Percentage : "<<totalPercentage<<"%"<<"\n";
    f<<"_________________________________________\n";
    f.close();
}

void result::viewResultOfAll(string st){
    fstream f;
    string s1;
    s1 = "result.txt";
    st = st + s1;
    f.open(st.c_str(),ios::in);
    string str;
    cout<<"\n";
    while (getline(f, str))
    {   
        cout<<str<<endl;
    }
    f.close();
}

void result::searchResult(string st){
    fstream f;
    string roll;
    cout<<"\nEnter the Roll Number of the Student you want to view Result of : ";
    cin>>roll;
    string s1;
    s1 = "result.txt";
    st = st + s1;
    f.open(st.c_str(),ios::in);
    int n=0;
    string str;
    string s;
    s = "Roll Number : " + roll;
    while(getline(f,str))
    {   
        if(str == s || (n>0 && n<=9))
        {
            cout<<str<<endl;
            n++;
        }
    }
    if(f.eof() && n==0)
    {
        cout<<"\n The Entered Roll Number Doesn't match with our records! ";
        cout<<"\n Please try Again! \n\n";
    }
    f.close();
}

void result::updateResult(string st){
    fstream f,t;
    string s1;
    s1 = "result.txt";
    st = st + s1;
    string roll;
    cout<<"\nEnter the Roll Number of the Student you want to Update : ";
    cin>>roll;
    f.open(st.c_str(),ios::in);
    t.open("temp.txt",ios::out);
    int n=0,x=0;
    string str;
    string s;
    s = "Roll Number : " + roll;
    while(getline(f,str))
    {   
        if(str == s || (n>0 && n<=9))
        {   
            if(x==0){
                cout<<"\n Enter Roll Number : ";
                cin>>rollNo;
                t<<"Roll Number : "<<rollNo<<"\n";
                string str;
                getline(cin,str);
                cout<<"\n Enter Name : ";
                getline(cin,name);
                t<<"Name : "<<name<<"\n";
    
                cout<<"\n Enter total Marks of Each Subject : ";
                cin>>totalMarks;
                if(totalMarks==0)
                {
                    cout<<"\n Total Marks cannot be ZERO! Please Try Again : ";
                    cin>>totalMarks;
                }

                string sub;
                int marks;
                cout<<"\n Enter Subject Name and Marks one by one : \n";
                for(int i=0; i<5; i++){
                    cout<<" ";
                    cin>>sub>>marks;
                    if(marks>totalMarks)
                    {
                        cout<<"\n Entered Marks cannot be greater than Total Marks ! Try Again : ";
                        cout<<"\n Enter Marks : ";
                        cin>>marks;
                    }
                    m[sub] = marks;
                }
                int sum = 0;
                map < string, int > :: iterator i;
                for(i= m.begin(); i != m.end(); i++){
                    t<<i->first<<" : "<<i->second<<"\n";
                    sum+=i->second;
                }
            
                totalMarks*=5;
                t<<"Total Marks : "<<totalMarks<<"\n";
                totalPercentage = float((sum*100) / totalMarks);  
                cout<<" Total Percentage : "<<totalPercentage<<"%"<<endl;
                t<<"Total Percentage : "<<totalPercentage<<"%"<<"\n";
                t<<"_________________________________________\n";
                x=1;
            }
            n++;
        }
        else
        {
            t<<str<<endl;
        }
    }
    if(f.eof() && n==0)
    {
        cout<<"\n The Entered Roll Number Doesn't match with our records! ";
        cout<<"\n Please try Again! \n\n";
    }
    f.close();
    t.close();
    remove(st.c_str());
    rename("temp.txt",st.c_str());
}

class Exam{
string subCode;
string examType;
string examDate;
string examTime;
float duration;
string subName;
public:
void addExam();
void viewAllExams();
void updateExam();
};

void Exam::addExam(){
    fstream f;
    f.open("Exam.txt",ios::app|ios::out);
    cout<<"\n Enter Exam Name : ";
    getline(cin,subName);
    getline(cin,subName);
    transform(subName.begin(), subName.end(), subName.begin(), ::toupper);
    f<<"Exam Name : "<<subName<<"\n";
    cout<<"\n Enter Exam Code : ";
    cin>>subCode;
    f<<"Exam Code : "<<subCode<<"\n";
    cout<<"\n Enter Exam Date : ";
    cin>>examDate;
    f<<"Exam Date : "<<examDate<<"\n";
    string s;
    getline (cin,s);
    cout<<"\n Enter Exam Time : ";
    getline (cin,examTime);
    f<<"Exam Time : "<<examTime<<"\n";
    cout<<"\n Enter Exam Duration (in Hours): ";
    cin>>duration;
    f<<"Exam Duration : "<<duration<<" Hours \n";
    cout<<"\n Enter Exam Type (Subjective/Objective) : ";
    cin>>examType;
    f<<"Exam Type : "<<examType<<"\n";
    f<<"_______________________________\n";
}

void Exam::viewAllExams(){
    fstream f;
    f.open("Exam.txt",ios::in);
    string str;
    cout<<"\n";
    while (getline(f, str))
    {   
        cout<<str<<endl;
    }
    f.close();
}

void Exam::updateExam(){
    fstream f,t;
    f.open("Exam.txt",ios::in);
    t.open("temp.txt",ios::out);
    string s;
    cout<<"\n Enter the Subject Name of the exam you want to edit : ";
    getline(cin,s);
    getline(cin,s);
    transform(s.begin(), s.end(), s.begin(), ::toupper);
    int n=0,x=0;
    string str;
    s = "Exam Name : "+s;
     while(getline(f,str))
    {   
        if(str == s || (n>0 && n<7))
        {   if(x==0)
            {
                cout<<"\n Enter Exam Name : ";
                getline(cin,subName);
                getline(cin,subName);
                t<<"Exam Name : "<<subName<<"\n";
                cout<<"\n Enter Exam Code : ";
                cin>>subCode;
                t<<"Exam Code : "<<subCode<<"\n";
                cout<<"\n Enter Exam Date : ";
                cin>>examDate;
                t<<"Exam Date : "<<examDate<<"\n";
                string s;
                getline (cin,s);
                cout<<"\n Enter Exam Time : ";
                getline (cin,examTime);
                t<<"Exam Time : "<<examTime<<"\n";
                cout<<"\n Enter Exam Duration (in Hours): ";
                cin>>duration;
                t<<"Exam Duration : "<<duration<<" Hours \n";
                cout<<"\n Enter Exam Type (Subjective/Objective) : ";
                cin>>examType;
                t<<"Exam Type : "<<examType<<"\n";
                t<<"_______________________________\n";
                x=1;
            }
            n++;
        }
        else
        {
            t<<str<<endl;
        }
    }
    if(f.eof() && n==0)
    {
        cout<<"\n The Exam doesn't exist in our records! ";
        cout<<"\n Please try Again! \n\n";
    }
    f.close();
    t.close();
    remove("Exam.txt");
    rename("temp.txt","Exam.txt");
}

void quesFunc(string str)
{
    set<string> validSubjects;
    validSubjects.insert("ENGLISH");
    validSubjects.insert("MATHS");
    validSubjects.insert("PHYSICS");
    validSubjects.insert("CHEMISTRY");
    validSubjects.insert("ECONOMICS");
    validSubjects.insert("COMPUTER");
    validSubjects.insert("ACCOUNTS");
    validSubjects.insert("HISTORY");
    validSubjects.insert("PHSYCHOLOGY");
    validSubjects.insert("BST");
    validSubjects.insert("HINDI");

    string s;
    l1 : 
    cout<<"\n\n\t\t Enter name of subject : ";
    cin>>s;
    transform(s.begin(), s.end(), s.begin(), ::toupper); 
    if(validSubjects.find(s) == validSubjects.end()){
        cout<<"\n\t\t Unexpected Input. Try Again! \n";
        goto l1;
    }

    set<string> validClasses;
    validClasses.insert("1");
    validClasses.insert("2");
    validClasses.insert("3");
    validClasses.insert("4");
    validClasses.insert("5");
    validClasses.insert("6");
    validClasses.insert("7");
    validClasses.insert("8");
    validClasses.insert("9");
    validClasses.insert("10");
    validClasses.insert("11");
    validClasses.insert("12");
    
    string cl;
    y : 
    cout<<"\n\n\t\t Enter class : ";
    cin>>cl; 
    if(validClasses.find(cl) == validClasses.end()){
        cout<<"\n\t\t Unexpected Input ";
        goto y;
    }
    Sleep(1200);
    system("CLS");
    Question q;
    if(str=="admin")
    {
    a:
    cout<<"\n\n\t\t 1. DISPLAY ALL QUESTIONS \n\t\t 2. ADD A QUESTION \n\t\t 3. REMOVE A QUESTION \n\t\t 4. EDIT A QUESTION  \n\t\t 5. BACK TO MAIN MENU \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        viewQuestionPaper(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        q.addQuestion(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        removeQuestion(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        q.editQuestion(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 5:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto a;
        break;
        }
    }
    else if(str=="user")
    {
        cout<<"\n\n\t\t 1. DISPLAY ALL QUESTIONS \n\t\t 2. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<"Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        viewQuestionPaper(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        system("CLS");
        break;
        case 2:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        break;
        }
    }
}

void studentFunc(string str)
{   
    set<string> validClasses;
    validClasses.insert("1");
    validClasses.insert("2");
    validClasses.insert("3");
    validClasses.insert("4");
    validClasses.insert("5");
    validClasses.insert("6");
    validClasses.insert("7");
    validClasses.insert("8");
    validClasses.insert("9");
    validClasses.insert("10");
    validClasses.insert("11");
    validClasses.insert("12");
    
    string cl;
    z : 
    cout<<"\n\n\t\t Enter class : ";
    cin>>cl; 
    if(validClasses.find(cl) == validClasses.end()){
        cout<<"\n\t\t Unexpected Input ";
        goto z;
    }
    Sleep(1000);
    system("CLS");
    student s;
    if(str=="admin")
    {
    b:
    cout<<"\n\n\t\t 1. DISPLAY ALL STUDENTS \n\t\t 2. ADD STUDENT INFO \n\t\t 3. REMOVE STUDENT INFO \n\t\t 4. EDIT STUDENT INFO  \n\t\t 5. SEARCH STUDENT INFO \n\t\t 6. BACK TO MAIN MENU \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        s.viewAllStudents(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        s.addStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        s.removeStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        s.updateStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 5:
        system("CLS");
        Sleep(500);
        s.searchStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 6:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto b;
        break;
        }
    }
    else if(str=="user")
    {   
        c:
        cout<<"\n\n\t\t 1. DISPLAY ALL STUDENTS \n\t\t 2. SEARCH STUDENT INFO \n\t\t 3. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<"Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        s.viewAllStudents(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto c;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        s.searchStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto c;
        break;
        case 3:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto c;
        break;
        }
        
    }
}

void resultFunc(string str)
{
    set<string> validClasses;
    validClasses.insert("1");
    validClasses.insert("2");
    validClasses.insert("3");
    validClasses.insert("4");
    validClasses.insert("5");
    validClasses.insert("6");
    validClasses.insert("7");
    validClasses.insert("8");
    validClasses.insert("9");
    validClasses.insert("10");
    validClasses.insert("11");
    validClasses.insert("12");
    
    string cl;
    d : 
    cout<<"\n\n\t\t Enter class : ";
    cin>>cl; 
    if(validClasses.find(cl) == validClasses.end()){
        cout<<"\n\t\t Unexpected Input ";
        goto d;
    }

    result r;

    if(str=="admin")
    {
    e:
    cout<<"\n\n\t\t 1. DISPLAY RESULT OF ALL \n\t\t 2. ADD RESULT \n\t\t 3. UPDATE RESULT  \n\t\t 4. SEARCH RESULT \n\t\t 5. BACK TO MAIN MENU \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        r.viewResultOfAll(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        r.addResult(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        r.updateResult(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        r.searchResult(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 5:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto e;
        break;
        }
    }
    else if(str=="user")
    {
        f:
        cout<<"\n\n\t\t 1. DISPLAY RESULT OF ALL \n\t\t 2. SEARCH RESULT \n\t\t 3. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<"Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        r.viewResultOfAll(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto f;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        r.searchResult(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto f;
        break;
        case 3:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto f;
        break;
        }
    }
}

void examFunc(string str)
{
    Exam e;
    if(str=="admin")
    {
    g:
    cout<<"\n\n\t\t 1. DISPLAY ALL EXAMS \n\t\t 2. ADD AN EXAM \n\t\t 3. UPDATE AN EXAM \n\t\t 4. BACK TO MAIN MENU \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        e.viewAllExams();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto g;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        e.addExam();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto g;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        e.updateExam();
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto g;
        break;
        case 4:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto g;
        break;
        }
    }
    else if(str=="user")
    {
        cout<<"\n\n\t\t 1. DISPLAY ALL EXAMS \n\t\t 2. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<"Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        e.viewAllExams();
        cout<<"\n\n";
        system("PAUSE");
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        system("CLS");
        break;
        case 2:
        Sleep(1000);
        cout<<"\n\n\t\tRETURNING TO MAIN SCREEN....\n";
        Sleep(1500);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        break;
        }
    }
}

void driverFunc(string str)
{   
    int x=0;
    if(str=="admin")
    {   
    x=1;
    string pass;
    cout<<"\t\tPlease Enter the Password! : ";
    cin>>pass;
    if(pass!="admin") 
    {
        cout<<"\n\n\t\tWrong Password, Try Again!\n\n";
        system("PAUSE");
        return;
    }   
    }
    Sleep(1500);
    system("CLS");
    Sleep(1500);
    a:
    cout<<"\n\n\t\t What Do You Want to Perform Operation On ? ";
    cout<<"\n\n\t\t 1. QUESTION PAPERS \n\t\t 2. STUDENT INFO \n\t\t 3. STUDENT RESULT \n\t\t 4. DATESHEET \n\t\t 5. LOG OUT \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        if(x==1)
        quesFunc("admin");
        else
        quesFunc("user");
        system("CLS");
        goto a;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        if(x==1)
        studentFunc("admin");
        else
        studentFunc("user");
        system("CLS");
        goto a;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        if(x==1)
        resultFunc("admin");
        else 
        resultFunc("user");
        cout<<"\n\n";
        system("CLS");
        goto a;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        if(x==1)
        examFunc("admin");
        else
        examFunc("user");
        cout<<"\n\n";
        system("CLS");
        goto a;
        break;
        case 5:
        Sleep(1000);
        cout<<"\n\n\t\tLOGGING OFF.....\n";
        Sleep(1000);
        system("CLS");
        break;
        default:
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto a;
        break;
    }

}

int main()
{   
    l:
    cout<<"\n\n\t\t======= Welcome To Online Examination System =======\n\t\t 1. ENTER AS ADMIN \n\t\t 2. ENTER AS Student \n\t\t 3. EXIT \n\n\t\t";
    int ch;
    cout<<"Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        driverFunc("admin");
        system("CLS");
        goto l;
        break;
        case 2:
        driverFunc("user");
        system("CLS");
        goto l;
        break;
        case 3:
        system("CLS");
        Sleep(1500);
        cout<<"\n\n";
        thanks();
        cout<<"\n\n\n";
        system("PAUSE");
        break;
        default:
        cout<<"\n\t\tWrong Input. Try agin!";
        Sleep(2000);
        system("CLS");
        goto l;
        break;
    }

    return 0;
}
