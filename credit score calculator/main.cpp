#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
using namespace::std;
//class definition
class applicant{
    string name;
    int age;
    string address;
    int m_sal;
    int h_loan;
    int p_loan;
    int chq_bounce;
    char own_house;
    char spouse_working;
    char dependent_parents;
    char company_tier;
public:
    //function declarations
    void get_data();
    int calc_credit_score();
    void display_score();
    
};
//function for recieving and storing loan applicant details
void applicant::get_data(){
   // system("cls");
    cout<<"Name of applicant: ";
    cin>>name;
    cout<<"Age: ";
    cin>>age;
    
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Address: ";
    cin>>address;
    cin.clear();
    cin.ignore(1000,'\n');
    cout<<"Monthly salary: ";
    cin>>m_sal;
    cout<<"Total monthly home loan EMI: ";
    cin>>h_loan;
    cout<<"Total monthly personal loan EMI: ";
    cin>>p_loan;
    cout<<"Number of cheque bounces in last six months: ";
    cin>>chq_bounce;
    cout<<"Own house? (y/n): ";
    cin>>own_house;
    cout<<"Spouse working? (y/n): ";
    cin>>spouse_working;
    cout<<"Dependent parents? (y/n): ";
    cin>>dependent_parents;
    cout<<"Company tier? (1/2/3): ";
    cin>>company_tier;
}
//end of get_data()
//start of calc_credit_score()
int applicant::calc_credit_score(){
    int credit_score=0;
    if (age>22&&age<=30) {
        credit_score=credit_score+2;
    }
    else if (age>30&&age<=35){
        credit_score=credit_score+1;
    }
    else if (age>35){
        credit_score=credit_score-1;
    }
    int liability;
    liability=h_loan+p_loan;
    if (liability<=m_sal/4) {
        credit_score=credit_score+5;
    }
    if (liability>m_sal/4 && liability<=m_sal/3) {
        credit_score=credit_score+3;
    }
    if (liability>m_sal/3 && liability<=m_sal/2) {
        credit_score=credit_score+1;
    }
    if (liability>m_sal/2) {
        credit_score=credit_score-1;
    }
    if (chq_bounce>1) {
        credit_score=credit_score-2;
    }
    if (chq_bounce==1) {
        credit_score=credit_score-1;
    }
    if (chq_bounce==0) {
        credit_score=credit_score+1;
    }
    if (p_loan>h_loan) {
        credit_score=credit_score-1;
    }
    else if (p_loan<h_loan){
        credit_score=credit_score+1;
    }
    if (own_house=='y') {
        credit_score=credit_score+1;
    }
    else{
        credit_score=credit_score-1;
    }
    if (spouse_working=='y') {
        credit_score=credit_score+1;
    }
    else{
        credit_score=credit_score-1;
    }
    if (dependent_parents=='y') {
        credit_score=credit_score+1;
    }
    else{
        credit_score=credit_score-1;
    }
    if (company_tier==1) {
        credit_score=credit_score+3;
    }
    else if (company_tier==2){
        credit_score=credit_score+2;
    }
    else if (company_tier==3){
        credit_score=credit_score+1;
    }
    return credit_score;
}
//end of calc_credit_score()
//start of display_score()
void applicant::display_score(){
    int score=calc_credit_score();
    //system("cls");
    //displaying the results
    if (score>9) {
        cout<<"The applicant "<<name<<" is at low risk."<<"\n"<<"Credit score is: "<<score<<".\nCredit can be given."<<endl;
    }
    else if (score<9&&score>=5){
        cout<<"The applicant "<<name<<" is at average risk."<<"\n"<<"Credit score is: "<<score<<".\nCredit can be given with due precaution."<<endl;
    }
    else if (score<5){
        cout<<"The applicant "<<name<<" is at high risk."<<"\n"<<"Credit score is: "<<score<<".\nCredit can not be given"<<endl;
    }
}
//end of display score
int main(){
    applicant a;
    char ch;
    while (1) {
      //  system("cls");
        cout<<setw(40)<<"Credit calculator\n";
        cout<<setw(40)<<"_________________\n";
        cout<<setw(40)<<"1- Enter loan applicant details\n";
        cout<<setw(32)<<"2- Display credit score\n";
        cout<<setw(16)<<"3- Exit\n";
        cout<<setw(53)<<"Select an option by typing the numeric code: ";
        cin>>ch;
        switch (ch) {
            case ('1'):
                a.get_data();
                break;
            case ('2'):
                a.display_score();
                break;
            case ('3'):
                exit(1);
            default:
                cout<<"Invalid choice press enter to continue\n";
                break;
        }//end of switch block
    }//end of while loop
    return 0;
}//end of main function
