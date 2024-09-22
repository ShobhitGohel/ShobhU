#include<iostream>
#include<fstream>
#include<unistd.h>
#include<string.h>

using namespace std;

//declaring variables to be used globally
short unsigned int correctusrpswdcounter = 0;
short unsigned int incorrectusrpswdcounter = 0;
string username1;
int password1;
string username2;
int password2;
string donor_name;
string donor_id;
string blood_group;
short unsigned int blood_packets;
short unsigned int donor_weight;
string donor_condition;
string donor_list;
string contexit;
string c;//unique donor id
char d;//serial number
int serial_no1;
int serial_no2;
int sr_input;//take serial number from user to search data
int sr_present;//no of lines already present
int z;//for loop counter
string current_line;//Storing current line while searching data
string sr_current_line;//storing current line for serial number deletion
char last_error;//number of elements
char a;//for copy data from temp
//char q;

//function prototype
int main();
int home();
int newdata();
int seelist();
int exit();
int search_data();
int numberofelements();
int delete_data();

//main function to check the username and password
int main(){

    system("cls");

    string username1 = "shobhit";
    int password1 = 123;
    string username2;
    int password2;


    if(correctusrpswdcounter == 0){
        cout << "Enter username : ";
        cin >> username2;
        cout << "Enter password : ";
        cin >> password2;
        if(username2 == username1 && password2 == password1){
            correctusrpswdcounter++;
            home();
        }
        else{
            username2.clear();
            password2 = NULL;
            ++incorrectusrpswdcounter;
            if(incorrectusrpswdcounter < 5){
                cout << "\a\aWrong username or password!!!\a\a";
                sleep(3);
                for (int i = 5; i >= 1; i--){
                    system("cls");
                    cout << "Please re-enter the correct password in : " << i;
                    sleep(1);
                }
                system("cls");
                main();
            }
            else{
                cout << "You are blocked for 1 hour";
                sleep(3600);
                main();
            }
            
        }
    }
    else{
        home();
    }
    return 0;
}


//home function to ask the user to enter his/her choice
int home(){

    int n;
    cout<<"\n\t\t===========================================";
    cout<<"\n\t\t|   Simple Blood Bank Management System   |"<<endl;
    cout<<"\t\t===========================================";
    cout<<"\n\t \t \t ::Enter Your Choice::"<<endl;
    cout<<"\n\t\t\tTo Add New Data \t(1)\n\t\t\tTo View List Of Donar   (2)\n\t\t\tTo Search Donar \t(3)\n\t\t\tTo Delete Specific Data (4)\n\t\t\tTo Exit \t\t(5)"<<endl;
    cout<<"\t\t\t: ";
    cin>>n;

    switch (n){
    case 1:
        newdata();
        break;
    
    case 2:
        seelist();
        break;

    case 3:
        search_data();
        break;

    case 4:
        delete_data();
        break;

    case 5:
        exit();
        break;

    default:
        system("cls");
        cout << "\a\aWrong choice enterd!!\a\a\n" << endl << "\a\aPlease recheck your choice!!\a\a";
        sleep(2);
        for (int i = 3; i >= 1; i--){
            system("cls");
            cout << "Re-enter the correct choice in : " << i;
            sleep(1);
        }
        system("cls");
        main();
    }
    return 0;
}


//Function to add new donor data
int newdata(){
    cout << "Please enter your weight : ";
    cin >> donor_weight;
    cout << "Enter donor health status : ";
    cin >> donor_condition;

    if(donor_weight >= 45 && (donor_condition == "Good" || donor_condition == "good" || donor_condition == "Nice" || donor_condition == "nice" || donor_condition == "Fine" || donor_condition == "fine")){
        ofstream out("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt" , ios::app);
        ofstream out1("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\donorid.txt" , ios::app);
        ifstream in1;
        in1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\donorid.txt");
        ifstream srnoin;
        srnoin.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\serialnumber.txt");
        ofstream srnoout;
        srnoout.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\serialnumber.txt" , ios::app);

        cout << "Enter your name : ";
        cin >> donor_name;
        //getline(cin , donor_name);

        cout << "Enter donor id : ";
        cin >> donor_id;

        cout << "Enter your blood group : ";
        cin >> blood_group;
        
        cout << "How many blood packets you want to donate?(1 packet = 350 mL Blood) : ";
        cin >> blood_packets;

        if(blood_group == "A+" || blood_group == "A-" || blood_group == "AB+" || blood_group == "AB-" || blood_group == "B+" || blood_group == "B-" || blood_group == "O+" || blood_group == "O-"){
            while (in1.eof() == 0){
                getline(in1 , c);
                if(donor_id == c){
                    //cout << c;
                    cout << "Wrong donor id entered!! Please re enter the details.";
                    sleep(5);
                    donor_name.clear();
                    donor_id.clear();
                    blood_group.clear();
                    blood_packets = NULL;
                    donor_weight = NULL;
                    donor_condition.clear();
                    out.close();
                    out1.close();
                    in1.close();
                    system("cls");
                    goto wrongid;
                    break;
                }
                else{
                    //cout << c;
                    //cout << "@";
                    continue;
               }
            }

        serial_no1 = numberofelements();
        //serial_no2 = serial_no1;
        //serial_no = serial_no - 1;
        srnoout << serial_no1 << endl;
        //serial_no = 0;

        out1 << donor_id << endl;
        out << "Name:" << donor_name << ' ';
        out << "DonorId:" << donor_id << ' ';
        out << "BloodGroup:" << blood_group << ' ';
        out << "BloodPackets:" << blood_packets << ' ' << endl;

        


        donor_name.clear();
        donor_id.clear();
        blood_group.clear();
        blood_packets = NULL;
        donor_weight = NULL;
        donor_condition.clear();

        cout << "Data Saved Successfully!!";
        sleep(3);
        out.close();
        out1.close();
        in1.close();
        srnoin.close();
        srnoout.close();
        system("cls");
        home();
        }
        else{
            cout << "Please enter the correct blood group!!" << endl;
            cout << "Please re enter the details!!\n\n";
            sleep(3);
            newdata();
        }
        

    }
    else if(donor_weight < 45 || donor_condition == "Bad" || donor_condition == "bad"){
        cout << "The health requirements not met for blood donation!" << endl;
        donor_weight = NULL;
        donor_condition.clear();
        sleep(3);
        system("cls");
        home();
    }
    else{
        cout << "Please enter correct condition!!" << endl;
        sleep(3);
        system("cls");
        wrongid:
        newdata();
    }

    return 0;
}

//Function to see the list of donors
int seelist(){
    ifstream in("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt");
    while(in.eof() == 0){
        getline(in , donor_list);
        cout << donor_list << endl;
    }
    in.close();
    seedata:
    cout << "Do you want to continue or exit(y/n) : ";
    cin >> contexit;
    if(contexit == "y" || contexit == "Y" || contexit == "Yes" || contexit == "yes"){
        home();
    }
    else if(contexit == "n" || contexit == "N" || contexit == "No" || contexit == "no"){
        exit();
    }
    else{
        cout << "\n\nPlease choose from the bracket!!\n\n";
        sleep(2);
        goto seedata;
    }
    return 0;
}

//Function to exit
int exit(){
    system("cls");
    cout << "Thanks for using our app!";
    sleep(2);
    return 0;
}

//function to calculate the number of lines in which the data is present
int numberofelements(){
    int y = 0;
    ifstream noe;
    noe.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt");
    while(noe.eof() == 0){
        noe.get(last_error);
        if(last_error == '\n'){
            ++y;
        }
        else{
            continue;
        }
    }
    noe.close();
    return y;
}

//function to search a particular data
int search_data(){
    ifstream sr_read;
    sr_read.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt");
    cout << "Enter the serial number to be searched : ";
    cin >> sr_input;
    cout << endl;
    sr_present = numberofelements();
    sr_present = sr_present - 1;
    if(sr_input <= sr_present){
        for(z = 1; z <= sr_present ; z++){
            if(z == sr_input){
                getline(sr_read , current_line);
                cout << current_line;
                cout << endl;
                home();
                break;
            }
            else{
                getline(sr_read , current_line);
                continue;
            }
        }
    }
    else{
        cout << "Serial number not present!!\n\n";
        sleep(4);
        sr_input = NULL;
        search_data();
    }
    sr_read.close();
    return 0;
}

//function to delete particular data from the database
//it deletes the serial number from the file and also the donor id for the selected derial number of data
int delete_data(){
    ifstream sr_read1;//reads data from blooddonordatabase.txt
    sr_read1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt");
    ofstream temp_write;//writes in temp.txt
    temp_write.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");
    
    ifstream temp_read;//reads data from temp.txt
    temp_read.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");
    cout << "Enter the serial number whose data needs to be deleted : ";
    cin >> sr_input;
    cout << endl;
    sr_present = numberofelements();
    sr_present = sr_present - 1;
    cout << sr_present;
    if(sr_input <= sr_present){
        for(z = 1; z <= sr_present ; z++){
            if(z == sr_input){
                getline(sr_read1 , current_line);
                continue;
            }
            else{
                getline(sr_read1 , current_line);
                temp_write << current_line << endl;
            }
        }
    }
    else{
        cout << "Serial number not present!!\n" << endl;
        sleep(4);
        sr_input = NULL;
        delete_data();
    }
    ofstream sr_write;//writes data in blooddonordatabase.txt
    sr_write.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt");
    while(temp_read.get(a)){
        sr_write.put(a);
    }

    sr_read1.close();
    temp_write.close();
    temp_read.close();
    sr_write.close();



    ifstream donorid_read;//reads data from donorid.txt
    donorid_read.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\donorid.txt");
    ofstream temp_write2;//writes in temp.txt
    temp_write2.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");

    if(sr_input <= sr_present){
        for(z = 1; z <= sr_present ; z++){
            if(z == sr_input){
                getline(donorid_read , current_line);
                continue;
            }
            else{
                getline(donorid_read , current_line);
                temp_write2 << current_line << endl;
            }
        }
    }

    donorid_read.close();
    temp_write2.close();

    ofstream donorid_write;//writes data in donorid.txt
    donorid_write.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\donorid.txt");
    ifstream temp_read1;//reads data from temp.txt
    temp_read1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");
    while(temp_read1.get(a)){
        donorid_write.put(a);
    }

    donorid_write.close();
    temp_read1.close();


    cout << "\nData deleted successfully!!!\n\n";
    //temp_write.close();
    //temp_read.close();
    //sr_write.close();
    //sr_read1.close();
    //donorid_read.close();
    

    ifstream srno_read;//reads data from serialnumber.txt
    srno_read.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\serialnumber.txt");
    ofstream temp_write1;//writes data into temp.txt
    temp_write1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");
    sr_present = numberofelements();
    cout << sr_present << endl;
    //sr_present = sr_present - 1;
    for(int z = 1; z <= sr_present; z++){
        if(z == sr_present){
            getline(srno_read , sr_current_line);
            break;
        }
        else{
            getline(srno_read , sr_current_line);
            //temp_write1.put(a);
            temp_write1 << sr_current_line << endl;
        }
    }
    srno_read.close();
    temp_write1.close();
    
    ifstream temp_read2;//reads data from temp.txt
    temp_read2.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");
    ofstream srno_write;//writes data into serialnumber.txt
    srno_write.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\serialnumber.txt");
    while(temp_read2.get(a)){
        srno_write.put(a);
    }
    temp_read2.close();
    srno_write.close();

    /*int y = 0;
    ifstream noe1;//reads data from blooddonordatabase.txt
    noe1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\blooddonordatabase.txt");
    ofstream noe2;//writes data into serialnumber.txt
    noe2.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\serialnumber.txt");
    //while(noe1.eof() == 0){
    serial_no2 = numberofelements();
    serial_no2 = serial_no2 - 1;
    cout << serial_no2;
    while(noe1.eof() == 0){
        noe1.get(last_error);
        if(last_error == '\n'){
            y++;
            noe2 << y << endl;
        }
        else{
            cout << "1";
            continue;
        }
    }*/
    /*for(int z = 1; z <= serial_no2 - 1; z++){
        while(noe1.eof() == 0){
        noe1.get(last_error);
        if(last_error == '\n'){
            y++;
            noe2 << y << endl;
        }
        else{
            cout << "1";
            continue;
        }
        }
        
    }
    serial_no2 = NULL;
    noe1.close();
    noe2.close();*/

    /*ifstream donorid_read1;//reads data from donorid.txt
    donorid_read1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\donorid.txt");
    ofstream temp_write2;//writes data into temp.txt
    temp_write2.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");

    ifstream temp_read3;//reads data from temp.txt
    temp_read3.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\temp.txt");

    if(sr_input <= sr_present){
        for(z = 1; z <= sr_present ; z++){
            if(z == sr_input){
                getline(donorid_read1 , current_line);
                continue;
            }
            else{
                getline(donorid_read1 , current_line);
                temp_write2 << current_line << endl;
            }
        }
    }
    donorid_read1.close();
    temp_write2.close();

    
    ofstream donorid_write1;//writes data into donorid.txt
    donorid_write1.open("C:\\VS Code\\Simple Bloodbank C++\\Blud Bank\\donorid.txt");

    while(temp_read3.get(a)){
        donorid_write1.put(a);
    }
    temp_read3.close();
    donorid_write1.close();*/

    sleep(2);
    home();
    return 0;
}