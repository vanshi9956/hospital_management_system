#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// we have to store data of patients doctors and appointments so we make different classes for them
int pid;// this is a gloabal patients id as patients id has to be unique everytime
int did;// gloabl doctor id as doctor id has to be unique everytime
unordered_map<int , string> mp;
unordered_map<int , string> md;
class patient{

    public:
    string name;
    string gender;
    int age;
    int ID;
    
    patient(string n,string g,int a){
        ID=pid;
        pid++;
        gender=g;
        age=a;

    }
    

};
class doctor{
    public:
    string name;
    string gender;
    int age;
    int ID;
    
    doctor(string n,string g,int a){
        ID=did;
        did++;
        name=n;
        gender=g;
        age=a;
       
    }
        

};
class appointment{
    public:

    int patient_id;
    int doctor_id;
    string date;
    appointment(int p,int d,string dt){
        patient_id=p;
        doctor_id=d;
        date=dt;
    }


};
vector<patient>allpatient;
vector<doctor>alldoctor;
vector<appointment>allappointment;

void add_patient(){
   
   string n,g;
   int a;
   cout<<"Enter patient name: ";
   cin>>n;
  
   cout<<"Enter patient gender: ";
    cin>>g;
   
    cout<<"Enter patient age: ";
    cin>>a;
    
    patient p(n,g,a);
    allpatient.push_back(p);
    mp[p.ID]=p.name;// we are storing patient id and patient name in hashmap to check whether the patient id is present or not while scheduling appointment
    
}
void add_doctor(){
    string n,g;
   int a;
   cout<<"Enter doctor name: ";
   cin>>n;
  
   cout<<"Enter doctor gender: ";
    cin>>g;
   
    cout<<"Enter doctor age: ";
    cin>>a;
    
    doctor d(n,g,a);
    alldoctor.push_back(d);
    md[d.ID]=d.name;// we are storing doctor id and doctor name in hashmap to check whether the doctor id is present or not while scheduling appointment

}
// bool is_valid_patient(int id){
//     bool ans=false;
//     for(int i=0;i<allpatient.size();i++){
//         if(allpatient[i].ID==id){
//             ans=true;
//             break;

//         }

//     }
//     return ans;
// }
// bool is_valid_doctor(int id){
//     bool ans=false;
//     for(int i=0;i<alldoctor.size();i++){
//         if(alldoctor[i].ID==id){
//             ans=true;
//             break;

//         }

//     }
//     return ans;
// } 
// WE CAN ALSO ADD HASMAP TO MAKE IT OPTIMIZE TO SEE WETHER THE PATIENT ID AND DOCTOR ID IS PRESENT OR NOT S METHOD TO CHECK WHETHER THE PATIENT ID AND DOCTOR ID IS PRESENT OR NOT


void schedule_appointment(){
    int p,d;
    string dt;;

    cout<<"Enter patient id: ";
    cin>>p;
    if(mp.find(p)==mp.end()){
        cout<<"Invalid patient id"<<endl;
        return;
    }
    cout<<"Enter doctor id: ";
    cin>>d;
    
    
    if(md.find(d)==md.end()){
        cout<<"Invalid doctor id"<<endl;
        return;
    }
    cout<<"Enter appointment date in DD-MM-YY FORMAT:  ";
    cin>>dt;
    // if(is_valid_patient(p)==false ){
    //     cout<<"Invalid patient id"<<endl;
    //     return;
    // }
    // if(is_valid_doctor(d)==false){
    //     cout<<"Invalid doctor id"<<endl;
    //     return;
    // }
    appointment a(p,d,dt);
    allappointment.push_back(a);

}
void view_patient(){
    cout<<"---PATIENT DETAILS---"<<endl;
    for(int i=0;i<allpatient.size();i++){
        cout<<"Patient name: "<<allpatient[i].name<<endl;
        cout<<"Patient gender: "<<allpatient[i].gender<<endl;
        cout<<"Patient age: "<<allpatient[i].age<<endl;     
    }


}
void view_doctor(){
     for(int i=0;i<alldoctor.size();i++){
        cout<<"Doctor name: "<<alldoctor[i].name<<endl;
        cout<<"Doctor gender: "<<alldoctor[i].gender<<endl;
        cout<<"Doctor age: "<<alldoctor[i].age<<endl;     
    }


}
void view_appointment(){
     for(int i=0;i<allappointment.size();i++){
        cout<<"Patient id: "<<allappointment[i].patient_id<<" has appointment with doctor id: "<<allappointment[i].doctor_id<<" on date: "<<allappointment[i].date<<endl;
     }


}
// checking whether the patient id and doctor id is present or not before scheduling appointment

int main(){
    pid=1;
    did=1;
    
    // we will provide options to user
    int choice;
    do{
        cout<<"1. Add patient"<<endl;
        cout<<"2. Add doctor"<<endl;
        cout<<"3. Schedule appointment"<<endl;
        cout<<"4. View patient details"<<endl;
        cout<<"5. View doctor details"<<endl;
        cout<<"6. View appointment details"<<endl;
        cout<<"0. Exit"<<endl;
        
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            add_patient();
            break;
            case 2:
            add_doctor();
            break;
            case 3:
            schedule_appointment();
            break;
            case 4:
            view_patient();
            break;
            case 5:
            view_doctor();
            break;
            case 6:
            view_appointment();
            break;
            case 7:
            exit(0);
            default:
            cout<<"Invalid choice"<<endl;

        }
    }while(choice!=0);

    
   
 


}