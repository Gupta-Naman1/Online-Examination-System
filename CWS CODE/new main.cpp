#include<bits/stdc++.h>
#include <Windows.h>
using namespace std; 

set<string> validSubjects;

set<string> validClasses;


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
protected:
    int quesNo; 
    string quesDesc; 
    string choiceA; 
    string choiceB; 
    string choiceC; 
    string choiceD; 
    char correctOpt; 
public:
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

};

class student{
protected:
    string name;
    int rollNo;
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

public:
    void viewAllStudents(string st){
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
    void searchStudent(string st){
    fstream f;
    string s1 = "student.txt";
    st = st+s1;
    string roll;
    cout<<"\nEnter the Roll Number of the Student you want to Search : ";
    cin>>roll;
    f.open(st.c_str(),ios::in);
    int n=0;
    string str;
    string rol;
    rol = "Roll Number : " + roll;
    while(getline(f,str))
    {   
        if(str == rol || (n>0 && n<=7))
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

};

class result {   
protected:
    map < string, int > m;
    int totalMarks;
    float totalPercentage;
public:
    void viewResultOfAll(string st){
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
    void searchResult(string st){
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
    
};

class Exam{
protected:
    string subCode;
    string subName;
    string examType;
    string examDate;
    string examTime;
    float duration;
public:
    void viewAllExams(string st){
    string s1;
    s1 = "Exam.txt";
    st = st + s1;
    fstream f;
    f.open(st.c_str(),ios::in);
    string str;
    cout<<"\n";
    while (getline(f, str))
    {   
        cout<<str<<endl;
    }
    f.close();
    }

};


class user : public Question , public student , public result , public Exam {};


class admin : public Question , public student , public result , public Exam {

    public:
    void addQuestion(string s);
    void updateQuestion(string s);
    void removeQuestion(string s);
    void addStudent(string s);
    void removeStudent(string s);
    void updateStudent(string s);
    void addResult(string st);
    void updateResult(string st);
    void addExam(string st);
    void updateExam(string st);

};

void admin::addQuestion(string s)
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

void admin::updateQuestion(string s){
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

    if(x==0)
    {
        cout<<"\n\n No Question was Changed!! \n";
        return;
    }

    cout<<"\n\n Question updated Successfully!! \n";

}

void admin::removeQuestion(string s){
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

void admin::addStudent(string st){
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

void admin::removeStudent(string st){
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
        return;
    }
    f.close();
    t.close();
    remove(st.c_str());
    rename("temp.txt",st.c_str());

    cout<<"\n\n Student Info removed Successfully!! \n";
}

void admin::updateStudent(string st){
    fstream f,t;
    string a = st;
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
                stringstream geek(a);
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

void admin::addResult(string st){
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

void admin::updateResult(string st){
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

void admin::addExam(string st){
    string s1;
    s1 = "Exam.txt";
    st = st + s1;
    fstream f;
    f.open(st.c_str(),ios::app|ios::out);
    cout<<"\n Enter Exam Name : ";
    cin>>subName;
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
    f.close();
}

void admin::updateExam(string st){
    string s1;
    s1 = "Exam.txt";
    st = st + s1;
    fstream f,t;
    f.open(st.c_str(),ios::in);
    t.open("temp.txt",ios::out);
    string s;
    cout<<"\n Enter the Subject Name of the exam you want to update : ";
    cin>>s;
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
                cin>>subName;
                transform(subName.begin(), subName.end(), subName.begin(), ::toupper);
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
    remove(st.c_str());
    rename("temp.txt",st.c_str());
}


void driverFunc()                         //user
{
    Sleep(1500);
    system("CLS");
    Sleep(1500);
    
    user u;
    string cl;
    l2 : 
    cout<<"\n\n\t\t Please Enter Your class : ";
    cin>>cl; 
    if(validClasses.find(cl) == validClasses.end()){
        cout<<"\n\t\t Unexpected Input. Try Again! \n ";
        goto l2;
    }

    z:
    cout<<"\n\n\t\t What Do You Want to Perform Operation On ? ";
    cout<<"\n\n\t\t 1. QUESTION PAPERS \n\t\t 2. STUDENT INFO \n\t\t 3. STUDENT RESULT \n\t\t 4. DATESHEET \n\t\t 5. LOG OUT \n\n\t\t";
    int c;
    cout<<" Enter Your Choice : ";
    cin>>c;
    if(c==1)
    {   
        system("CLS");
        Sleep(1000);
        string s;
        l1 : 
        cout<<"\n\n\t\t Enter name of subject : ";
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::toupper); 
        if(validSubjects.find(s) == validSubjects.end()){
            cout<<"\n\t\t Unexpected Input. Try Again! \n";
            goto l1;
        }

        cout<<"\n\n\t\t 1. DISPLAY ALL QUESTIONS \n\t\t 2. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<" Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        u.viewQuestionPaper(cl+s);
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

        system("CLS");
        goto z;
    }

    else if(c==2)
    {
        system("CLS");
        Sleep(1000);

        c:
        cout<<"\n\n\t\t 1. DISPLAY ALL STUDENTS \n\t\t 2. SEARCH STUDENT INFO \n\t\t 3. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<" Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        u.viewAllStudents(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto c;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        u.searchStudent(cl);
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

        system("CLS");
        goto z;
    }

    else if(c==3)
    {
        system("CLS");
        Sleep(1000);

        f:
        cout<<"\n\n\t\t 1. DISPLAY RESULT OF ALL \n\t\t 2. SEARCH RESULT \n\t\t 3. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<" Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        u.viewResultOfAll(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto f;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        u.searchResult(cl);
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
        system("CLS");
        goto z;
    }

    else if(c==4)
    {
        system("CLS");
        Sleep(1000);

        cout<<"\n\n\t\t 1. DISPLAY ALL EXAMS \n\t\t 2. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<" Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        u.viewAllExams(cl);
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
        system("CLS");
        goto z;
    }
    else if(c==5)
    {
        Sleep(1000);
        cout<<"\n\n\t\tLOGGING OFF.....\n";
        Sleep(1000);
        system("CLS");
    }
    else
    {
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto z;
    }

}

void driverFunc(string s)                 //admin
{
    string pass="";
    char ch;
    cout<<"\n\t\t Please Enter the Password! : ";
    ch = _getch();
    while(ch != 13){//character 13 is enter
        pass.push_back(ch);
        cout << '*';
        ch = _getch();
    }
    if(pass!="admin")
    {
        cout<<"\n\n\t\tWrong Password, Try Again!\n\n";

        system("PAUSE");
        return;
    }

    Sleep(1500);
    system("CLS");
    Sleep(1500);
    
    admin ad;

    z:
    cout<<"\n\n\t\t What Do You Want to Perform Operation On ? ";
    cout<<"\n\n\t\t 1. QUESTION PAPERS \n\t\t 2. STUDENT INFO \n\t\t 3. STUDENT RESULT \n\t\t 4. DATESHEET \n\t\t 5. LOG OUT \n\n\t\t";
    int c;
    cout<<" Enter Your Choice : ";
    cin>>c;

    if(c==1)
    {   system("CLS");
        Sleep(500);

        string s;
        l1 : 
        cout<<"\n\n\t\t Enter name of subject : ";
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::toupper); 
        if(validSubjects.find(s) == validSubjects.end()){
            cout<<"\n\t\t Unexpected Input. Try Again! \n";
            goto l1;
        }
        string cl;
        l2 : 
        cout<<"\n\n\t\t Enter class : ";
        cin>>cl; 
        if(validClasses.find(cl) == validClasses.end()){
            cout<<"\n\t\t Unexpected Input ";
            goto l2;
        }

    Sleep(1200);
    system("CLS");
    a:
    cout<<"\n\n\t\t 1. DISPLAY ALL QUESTIONS \n\t\t 2. ADD A QUESTION \n\t\t 3. REMOVE A QUESTION \n\t\t 4. update A QUESTION  \n\t\t 5. BACK TO MAIN MENU \n\n\t\t";
    int ch;
    cout<<" Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        ad.viewQuestionPaper(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        ad.addQuestion(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        ad.removeQuestion(cl+s);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto a;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        ad.updateQuestion(cl+s);
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

        system("CLS");
        goto z;
    
    }
    else if (c == 2)
    {
        string cl;
        l3 : 
        cout<<"\n\n\t\t Enter class : ";
        cin>>cl; 
        if(validClasses.find(cl) == validClasses.end()){
        cout<<"\n\t\t Unexpected Input ";
        goto l3;
        }
        Sleep(1000);
        system("CLS");
    b:
    cout<<"\n\n\t\t 1. DISPLAY ALL STUDENTS \n\t\t 2. ADD STUDENT INFO \n\t\t 3. REMOVE STUDENT INFO \n\t\t 4. update STUDENT INFO  \n\t\t 5. SEARCH STUDENT INFO \n\t\t 6. BACK TO MAIN MENU \n\n\t\t";
    int ch;
    cout<<" Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        system("CLS");
        Sleep(500);
        ad.viewAllStudents(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        ad.addStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        ad.removeStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        ad.updateStudent(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto b;
        break;
        case 5:
        system("CLS");
        Sleep(500);
        ad.searchStudent(cl);
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
        system("CLS");
        goto z;
    }
    else if(c==3)
    {
        system("CLS");
        Sleep(500);
        string cl;
        l4 : 
        cout<<"\n\n\t\t Enter class : ";
        cin>>cl; 
        if(validClasses.find(cl) == validClasses.end()){
            cout<<"\n\t\t Unexpected Input ";
            goto l4;
        }
        e:
        cout<<"\n\n\t\t 1. DISPLAY RESULT OF ALL \n\t\t 2. ADD RESULT \n\t\t 3. UPDATE RESULT  \n\t\t 4. SEARCH RESULT \n\t\t 5. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<" Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        ad.viewResultOfAll(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        ad.addResult(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        ad.updateResult(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto e;
        break;
        case 4:
        system("CLS");
        Sleep(500);
        ad.searchResult(cl);
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
        system("CLS");
        goto z;
    }
    else if (c==4)
    {   string cl;
        l5 : 
        cout<<"\n\n\t\t Enter class : ";
        cin>>cl; 
        if(validClasses.find(cl) == validClasses.end()){
            cout<<"\n\t\t Unexpected Input ";
            goto l5;
            }
        Sleep(1000);
        system("CLS");
        system("CLS");
        Sleep(500);
        g:
        cout<<"\n\n\t\t 1. DISPLAY ALL EXAMS \n\t\t 2. ADD AN EXAM \n\t\t 3. UPDATE AN EXAM \n\t\t 4. BACK TO MAIN MENU \n\n\t\t";
        int ch;
        cout<<" Enter Your Choice : ";
        cin>>ch;
        switch(ch)
        {
        case 1:
        system("CLS");
        Sleep(500);
        ad.viewAllExams(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto g;
        break;
        case 2:
        system("CLS");
        Sleep(500);
        ad.addExam(cl);
        cout<<"\n\n";
        system("PAUSE");
        system("CLS");
        goto g;
        break;
        case 3:
        system("CLS");
        Sleep(500);
        ad.updateExam(cl);
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
        system("CLS");
        goto z;
    }

    else if(c==5)
    {
        Sleep(1000);
        cout<<"\n\n\t\tLOGGING OFF.....\n";
        Sleep(1000);
        system("CLS");
    }
    else
    {
        cout<<"\n\n\t\tWrong Input. Try agin!\n";
        Sleep(2000);
        system("CLS");
        goto z;
    }
    
}

int main()
{   

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
    validSubjects.insert("SST");
    validSubjects.insert("BIOLOGY");
    validSubjects.insert("FRENCH");

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
    l:
    cout<<"\n\n\t\t======= Welcome To Online Examination System =======\n\t\t 1. ENTER AS ADMIN \n\t\t 2. ENTER AS Student \n\t\t 3. EXIT \n\n\t\t";
    int ch;
    cout<<" Enter Your Choice : ";
    cin>>ch;
    switch(ch)
    {
        case 1:
        driverFunc("admin");
        system("CLS");
        goto l;
        break;
        case 2:
        driverFunc();
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
