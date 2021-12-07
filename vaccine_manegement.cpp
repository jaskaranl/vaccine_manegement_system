#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#define SIZE 10000
using namespace std;

class account //pure virtual class no object will be made hence runtime polymorphism
{               //abstract class

protected:
    string username;
    char gender;
    string password;
    string date;

public:
    virtual void newadmin_user() = 0;
};
class admin : public account //inheritance Hierarchical Inheritance
{
public:
    //static int count;
    void newadmin_user()//virtual function override runtime polymorphism
    {
        int chances = 3;
        string key = "1001";
        string key_input;
    start:
        if (chances == 0)
        {
            cout << " you have used all your chances for confimation key "
                 << "\n"
                 << "terminating program" << endl;
            exit(1);
        }
        cout<<"\t\t\t"<<setw(38)<<setfill('#')<<"\n"<<setiosflags(ios::right);
        cout<< "\t\t\tenter the valid key for confirmation" << endl;
        cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t"<<setiosflags(ios::right);
        cin >> key_input;
        if (key_input == key)
        {
            char ch;
             cout<<"\n\t\t\t"<<setw(38)<<setfill('#')<<"\n";
            cout <<"\t\t\t"<< "enter username for new admin :\n";
             cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
            cin >> username;
              cout<<"\n\t\t\t"<<setw(38)<<setfill('#')<<"\n";
            cout << "\t\t\tenter the password :\n";
             cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
            cin >> password;
             cout<<"\n\t\t\t"<<setw(38)<<setfill('#')<<"\n";
            cout << "\t\t\tenter gender using single character:\n";
              cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
            
            cin >> gender;
              cout<<"\n\t\t\t"<<setw(38)<<setfill('#')<<"\n\t\t\t";
            fstream out;                                        // FSTREAM OUT OBJECT
            cout << "date on which account formed:\n";
              cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
            cin >> date;
           
            if(!(int(date[0])>=48&&int(date[0])<=57))
            {
                cout<<"invalid date\n";
                return;
            }
            out.open("admin.txt", ios::app | ios::in | ios::out);
            string aj;
            int k = 0;
            out.seekg(0, ios::beg);
               // cout<<"n";
                fflush(stdin);
                 int flag1=0;
                    int flag2=0;
            while (getline(out, aj))
            {
               //cout<<aj<<endl;
               fflush(stdout);
                if(aj.find(password,0)!=string::npos&& aj.find(username,0)!=string::npos)
                {
                    int fg1=1,fg2=1;
                   //  cout<<"a";
                    int i=0;
                    int j=0;
                    while(aj[i]!=username[0])
                    {
                        i++;
                    }

                  
                    while(username[j]!='\0'||aj[i]!=',')
                    {
                        if(username[j]!=aj[i])
                        {
                            cout<<username[j]<<aj[i]<<" ";
                            fg1=0;
                        }
                        i++,j++;
                    }
                    i++;
                    j=0;
                    while(aj[i]!=','||password[j]!='\0')
                    {
                        if(password[j]!=aj[i])
                        {
                            fg2=0;
                           
                        }
                         i++,j++;
                    }
                     if(fg1==0|| fg2==0)
                    {
                        flag1=fg1;
                        flag2=fg2;
                         /*out.clear();
                         cout<<"1";
                     out << ++k << ")" << username << "," << password << "," << gender << "," << date << "\n";
                     break;*/
                     }
                     if(fg1==1&&fg2==1)
                     {
                         flag1=fg1;
                         flag2=fg2;
                         cout<<"\t\t\tpassword and username both in  use\n\n\n";
                     }
                }
               
                k++;
               
            }
            if(flag1==0||flag2==0)
            {
           out.clear();
            //cout<<"aksd";
            out << ++k << ")" << username << "," << password << "," << gender << "," << date << "\n";
          //  count++;
            // cout << count;
            cout<<endl;
            out.close();
            }
        }
        else
        {
            cout<<"\n\t\t\t"<<setw(38)<<setfill('#')<<"\n";
            cout << "\t\t\twrong key input "
                 << "\n"
                 << " \t\t\tyou have " << --chances << " chances left " << endl;
                 cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\n";
            goto start;
        }
    }
    void search()
    {
        string search;
        cout << "enter the username to search the user:";
        cin >> search;
        fstream file;
        string line_string;

        file.open("user.txt", ios::in);
        string output;
        int line = 1;
        int flag=1;
        while (file.eof() == 0)
        {
            
            getline(file, line_string);

            if (line_string.find(search, 2) != string::npos)
            {   
                int i=0,j=0;
               
                while(line_string[i]!=search[0])
                {
                   // cout<<line_string[i];
                    i++;
                }
            
                while(line_string[i]!=','||search[j]!='\0')
                {
                   //   cout<<line_string[i];
                    if(line_string[i]!=search[j])
                    {
                       flag=0;
                       break;
                    }
                    i++,j++;
                }
               if(flag==1)
               {
                cout << "user found on entry number " << line << "\n";
                cout << line_string << endl; 
                }//else  condition
            }
            line++;
        }
        if(flag==0)
        cout<<"user not found in database"<<endl;
        file.clear();
        file.close();
        //cout<<"user not found in database"<<endl;
    }
    bool search(string name, string passcode)
    {
        fstream file;
        file.open("admin.txt", ios::in);
        string output;
        int flag1=1,flag2=1;
        while ( getline(file, output))
        {
           
            if (output.find(name, 2) != string::npos && output.find(passcode, 2) != string ::npos)
            {
               
                int i=0,j=0;
                while(output[i]!=')')
                {
                    i++;
                }
                i++;
             //   cout<<output[i];
                while(output[i]!=','||name[j]!='\0')
                {
                    if(output[i]!=name[j])
                    {
                        flag1=0;
                    }
                    i++,j++;
                }
                i++;
                j=0;
               // cout<<flag1;
                while(output[i]!=','&&passcode[j]!='\0')
                {
                    if(output[i]!=passcode[j])
                    {
                        flag2=0;
                        break;
                    }
                    i++,j++;
                }
                //cout<<flag2;
                if(flag1&&flag2)
                return true;
            }
        }
        file.clear();
        file.close();
        return false;
    }
    void total_users()
    {
        fstream file;
        file.open("user.txt", ios::in);
        string aj;
        int i = 0;
        while (getline(file, aj))
        {
            i++;
        }
        file.clear();
        file.close();
        cout << " there are total " << i << " users in database" << endl;
    }
     void total_admin()
    {
        fstream file;
        file.open("admin.txt", ios::in);
        string aj;
        int i = 0;
        while (getline(file, aj))
        {
            i++;
        }
        file.clear();
        file.close();
        cout << " there are total " << i << " admins in database" << endl;
    }
    void update_user_vaccine(string name,string date)
    {
        fstream file,newfile;
        string line_string;
        file.open("user.txt",ios::in);
        newfile.open("temp.txt",ios::out|ios::app);
        while(getline(file,line_string))
        {
            if(line_string.find(name,2)!=string::npos&&line_string.find(date,8)!=string::npos)
            {
                int i=0,j=0;
            while(line_string[i]!=name[0])
            i++;
            while(line_string[i]!=','||name[j]!='\0')
            {
                if(line_string[i]!=name[j])
                {
                    break;
                }
                i++,j++;
            }
            i++;
            int count=0;
            while(count<3)
            {
                i++;
                if(line_string[i]==',')
                count++;
            }
            i++;
            int l;
            cout<<"press 1 to update vaccine number 1"<<endl<<"press 2 to update vaccine 2"<<endl;
            cin>>l;
            if(l==1)
            {
                int p=0;
                while(p<i)
                {
                    newfile<<line_string[p];
                    p++;
                }
                newfile<<"1"<<",";
                i=i+2;
                newfile<<"0"<<"\n";
            }
            else if(l==2)
            {
                if(line_string[i]!='1')
                {
                    cout<<"cannot excute action as vaccine 1 is not performed on the person"<<endl;
                     newfile<<line_string<<"\n";
                }
                else{
                 int p=0;
                while(p<=i)
                {
                    newfile<<line_string[p];
                    p++;
                }
                newfile<<",";
                i=i+2;
                newfile<<"1"<<"\n";
                }
            }
            }
            else
            newfile<<line_string<<"\n";

        }
        remove("user.txt");
    rename("temp.txt", "user.txt");
    file.clear();
    newfile.close();
    file.close();
    }
    void delete_admin()
    {
      
        int a = 2;
         int t=a-1;
        fstream file, file_new;
        string line, passcode;
        string line_read;
        string supervisor_pass;
          cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
        cout << "enter supervisor password\n";
          cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
        
        while (a > 0)
        {
            cin >> supervisor_pass;
            if (supervisor_pass == "1001")
            { cout<<"\n\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
                cout << "user name of admin to be removed:\n";
                cout<<"\t\t\t"<<setw(40)<<setfill('#')<<"\n\t\t\t";
                cin >> line;
                string aj;
                file_new.open("temp.txt", ios::in | ios::out | ios::app);
                //  cout<<"password of admin to be removed:";
                //   cin>>passcode;
                file.open("admin.txt");

                file.seekp(0, ios::beg);
                file.seekg(0, ios::beg);
                while (getline(file, line_read))
                { //re do delete funtion ;)
                    if (line_read.find(line, 2) != string::npos)
                    {
                        //cout << line_read.length();
                        line_read.replace(0, line_read.length(), " ");
                        line_read.replace(0,line_read.length(),"\b\b");
                        file_new << line_read << "\n";
                    }
                    else
                        file_new << line_read << "\n";
                }
               
                remove("admin.txt");
                rename("temp.txt", "admin.txt");
                file.clear();
                file.close();
                file_new.close();
                break;
            }
            else
                cout << " wrong password" << endl
                     <<t--<< " chance left" << endl;
            a--;
        }
    }
  void show_all_users(){
      fstream out;
      string file;
      
      out.open("user.txt",ios::in);
      while(getline(out,file))
      {
          int i=0;
         while(file[i]!=')')
         { 
             i++;
         }
         i++;
         while(file[i]!=',')
         {
             cout<<file[i];
             i++;
         }
         cout<<endl;
      }
  }
};
/*int admin::count = 1; */  /*            account
                                    |   |
                                admin   USER    */

class user : public account
{
    static int count;
    bool vaccine1 = false, vaccine2 = false;

public:
    void newadmin_user()
    {

        {
            char ch;
            cout << "\n\t\t\t" << setw(32) << setfill('*') << "\n\t\t\t"
                 << "enter username for  new user :\n"
                 << "\t\t\t" << setw(28) << setfill('*') << "\n"
                 << "\t\t\t"
                 << " ";
          cin>>username;
        
            cout << "\n\t\t\t" << setw(25) << setfill('*') << "\n\t\t\t"
                 << "enter the password :\n"
                 << "\t\t\t" << setw(22) << setfill('*') << "\n"
                 << "\t\t\t"
                 << " ";
            cin>>password;
            cout << "\n\t\t\t" << setw(38) << setfill('*') << "\n\t\t\t"
                 << "enter gender using single character:\n"
                 << "\t\t\t" << setw(35) << setfill('*') << "\n"
                 << "\t\t\t"
                 << " ";
            cin >> gender;
            cout << "\n\t\t\t" << setw(38) << setfill('*') << "\n\t\t\t"
                 << "enter date of account formed:\n"
                 << "\t\t\t" << setw(35) << setfill('*') << "\n"
                 << "\t\t\t"
                 << " ";
            cin >> date;
             if(!(int(date[0])>=48&&int(date[0])<=51))
            {
                cout<<"invalid date\n";
                return;
            }
            cout<<"\n";
            fstream out;

            out.open("user.txt", ios::in | ios::out | ios::app);
            //   int end = out.tellg();
            //cout << end << endl;
            //    count = len = username.size() + password.size() + date.size() + 6;
            string aj;
            int k = 0;
            int flag1=0,flag2=0;
            out.seekg(0, ios::beg);
            while (getline(out, aj))
            {
                
               fflush(stdout);
                if(aj.find(password,0)!=string::npos&& aj.find(username,0)!=string::npos)
                {
                    int fg1=1,fg2=1;
                   //  cout<<"a";
                    int i=0;
                    int j=0;
                    while(aj[i]!=username[0])
                    {
                        i++;
                    }

                  
                    while(username[j]!='\0'||aj[i]!=',')
                    {
                        if(username[j]!=aj[i])
                        {
                            cout<<username[j]<<aj[i]<<" ";
                            fg1=0;
                        }
                        i++,j++;
                    }
                    i++;
                    j=0;
                    while(aj[i]!=','||password[j]!='\0')
                    {
                        if(password[j]!=aj[i])
                        {
                            fg2=0;
                           
                        }
                         i++,j++;
                    }
                     if(fg1==0|| fg2==0)
                    {
                        flag1=fg1;
                        flag2=fg2;
                         /*out.clear();
                         cout<<"1";
                     out << ++k << ")" << username << "," << password << "," << gender << "," << date << "\n";
                     break;*/
                     }
                     if(fg1==1&&fg2==1)
                     {
                         flag1=fg1;
                         flag2=fg2;
                         cout<<"password and username both in  use\n";
                     }
                }
               
                k++;
               
            }
            if(flag1==0||flag2==0)
            {
           out.clear();
            //cout<<"aksd";
            out << ++k << ")" << username << "," << password << "," << gender << "," << date <<","<<vaccine1<<","<<vaccine2<< "\n";
            count++;
            // cout << count;
            out.close();
            }
        }
    }
    void search()
    {
        bool found = false;
        string search;
        string to_search_password;
        cout << "enter the username to search:";
        cin >> search;
        cout << "enter the password of the account:";
        cin >> to_search_password;
        fstream file;
        string line_string;

        file.open("user.txt", ios::in);
        string output;
        while (file.eof() == 0)
        {
            // int line = 1;
            getline(file, line_string);

            //cout<<line_string;

            if (line_string.find(search, 2) != string::npos && line_string.find(to_search_password, 2) != string::npos)
            {

                int p = 3;
                while (line_string[p] != ',')
                {
                    p++;
                }
                p++;
                size_t yo = line_string.find(to_search_password, 2);
                int j = 0;
                while (line_string[p] != ',')
                {

                    //cout<<line_string[p]<<endl;
                    //   cout<<to_search_password[j]<<endl;
                    if (line_string[p] != to_search_password[j])
                    {
                        //   cout<<line_string[p]<<endl;
                        cout << "wrong password\n";
                        return;
                    }
                    j++;
                    p++;
                }
                cout << "user account found "
                     << "\n";
                // cout<<line_string;
                char c;
                int i = 0;
                while (line_string[i] != ')')
                {
                    i++;
                }
                i++;
                string output;
                //int j = 0;
                cout << "account holder name:";
                while (line_string[i] != ',')
                {

                    cout << line_string[i];
                    i++;
                }
                cout << "\n";
                i++;
                while (line_string[i] != ',')
                {

                    // cout<<line_string[i];
                    i++;
                }
                i++;
                cout << "account holder gender:";
                while (line_string[i] != ',')
                {

                    cout << line_string[i] << "\n";
                    i++;
                }
                i++;
                cout << "date on which account is formed:";
                while (line_string[i] != ',')
                {
                    cout << line_string[i];
                    i++;
                }
                cout << "\n";
                i++;
                //cout << " current vaccination status:";
                while (line_string[i] != '\0')
                {
                    //cout << line_string[i];
                    i++;
                }
                cout << "\n";
                found = true;
                // cout <<output<<"\n";
                break; //else  condition
            }
            //line++;
        }
        if (!found)
            cout << "user not found\n";
        file.clear();
        file.close();
    }
    void search(string name, string password)
    {
        fstream file;
        string line;
        file.open("user.txt", ios::in);
        while (getline(file, line))
        {
            if (line.find(name, 1) != string::npos && line.find(password, 1) != string::npos)
            {
               // cout<<line;
                int k = 0;
                while (line[k] != ')')
                {
                    k++;
                }
                k++;

                int d = 0;
                while (line[k] != ',')
                {
                  //  cout << line[k] << " " << name[k] << endl;
                    if (line[k] != name[d])
                    {
                        cout << "wrong name entered" << endl;
                        return;
                    }
                    k++, d++;
                }
                int p = 3;
                while (line[p] != ',')
                {
                    p++;
                }
                p++;
                size_t yo = line.find(password, 2);
                int j = 0;
                while (line[p] != ',')
                {

                    //     cout<<line[p]<<endl;
                    //   cout<<password[j]<<endl;
                    if (line[p] != password[j])
                    {
                        //   cout<<line_string[p]<<endl;
                        cout << "wrong password\n";
                        return;
                    }
                    p++;
                    j++;
                }
                int i = 0, comma_count = 1;
                //cout << line;
                while (line[i] != ',' || comma_count < 4)
                {
                    //cout<<line[i];
                    if (line[i] == ',')
                        comma_count++;
                    i++;
                }
                i++;

                cout << "\n";
                     //<< line[i] << endl;
                if (line[i] == '1')
                {
                    cout << "first dose done\n"
                         << endl;
                }
                else
                    cout << "first dose not done" << endl;
                i = i + 2;
               // cout << line[i] << endl;
                if (line[i] == '1')
                {
                    cout << "second dose done\n"
                         << endl;
                }
                else
                    cout << "second dose not done\n"
                         << endl;
                         return;
            }
           
        }
        file.clear();
        file.close();
         
            
                cout << "wrong input"
                     << "\n";
                return;
            
    }
};

int user::count = 1;
int main()
{
    admin obj;
    user usr;
    admin admin[SIZE];
    user user[SIZE];
    int object_count_user = 0;
    int object_count_admin = 0;
    cout << "\t\t\t" << setfill('*') << setw(50);
    cout << setiosflags(ios::right);
    cout << "welcome to the centre!! " << setw(25) << ""
         << "\n\n";

    cout << "\t\t\t" << setw(45) << "how can we help " << setw(30) << ""
         << "\n\n";

    while (1)
    {
        int variable;

        cout << resetiosflags(ios::right);
        cout << "\t\t\t" << setfill('#') << setw(30) << "\t\t\t\t" << setw(28) << "" << endl; //upper padding
        cout << "\t\t\tpress 1 for new user entry";
        cout << "\t\t\t\tpress 2 for new admin entry"
             << "\n";
        cout << "\t\t\t" << setfill('#') << setw(26) << " "
             << "\t\t\t\t" << setw(30) << "\n\n";                                             //lower padding
        cout << "\t\t\t" << setfill('#') << setw(31) << "\t\t\t\t" << setw(28) << "" << endl; //upper padding
        cout << "\t\t\tpress 3 to delete a admin ";
        cout << "\t\t\t\tpress 4 for admins access"
             << "\n";
        cout << "\t\t\t" << setfill('#') << setw(26) << " "
             << "\t\t\t\t" << setw(30) << "\n\n"; //lower padding
        cout << "\t\t\t" << setfill('#') << setw(29) << "\t\t\t\t" << setw(47) << ""
             << "\n"; //upper padding
        cout << "\t\t\tpress 5 for users access"
             << "\t\t"
             << "                press 6 to know your current vaccination status"
             << "\n";
        cout << "\t\t\t" << setfill('#') << setw(26) << " " //lower padding
             << "\t\t\t\t" << setw(49) << "\n\n";
        cin >> variable;
        if (variable == 1)
        { // FOR NEW USER
            if (object_count_user == SIZE)
            {
                cout << "max data entries reached for the current program\n"
                     << " restart program\n";
                exit(1);
            }
            user[object_count_user].newadmin_user();
            object_count_user = object_count_user + 1;
            //cout << "object count " << object_count_user << "\n";
        }
        if (variable == 2)
        { // FOR NEW ADMIN
            if (object_count_admin == SIZE)
            {
                cout << "max data entries reached for the current program\n"
                     << " restart program\n";
                exit(1);
            }
            admin[object_count_admin].newadmin_user();
            object_count_admin++;
        }
        if (variable == 3)
        { // TO DELETE ADMIN ACCOUNT;
            obj.delete_admin();
        }
        if (variable == 4) // FOR ADMIN ACCESS;
        {
            int chances = 4;
            string username, password;
            int admin_varible;
        begin:
            while (chances > 0)
            {
                cout << "enter your admin's username:";
                cin >> username;
                cout << "enter your password:";
                cin >> password;
                bool ans = obj.search(username, password);
                if (ans)
                {
                    start:
                    cout << "\n\n\n\n\n\n\n\n\n\t\t\t" << setfill('#') << setw(44) << "\t\t\t" << setw(45) << " "
                         << "\n";
                    cout << "\t\t\t press 1 to find the details of any user";
                    cout << "\t\t\t press 2 to find the total numbers of users" << endl;
                    cout << "\t\t\t" << setfill('#') << setw(44) << "\t\t\t" << setw(45) << " "
                         << "\n\n";
                    cout << "\t\t\t" << setfill('#') << setw(48) << "\t\t\t" << setw(45) << " "
                         << "\n";
                    cout << "\t\t\t press 3 to find the total numbers of admins";
                    cout << "\t\t\t press 4 to update a user vaccination state "
                         << "\n";
                    cout << "\t\t\t" << setfill('#') << setw(48) << "\t\t\t" << setw(45) << "\n";
                    cout<<"\n\t\t\t"<<setw(35)<<" \n"<<"\t\t\t press 5 for all users database\n"<<"\t\t\t"<<setw(34)<<"\n";
                    cin >> admin_varible;
                    if (admin_varible == 1)
                    {
                        obj.search();
                        
                    }
                    if (admin_varible == 2)
                    {
                        obj.total_users();
                        
                    }
                    if(admin_varible==3)
                    {
                        obj.total_admin();
                    }
                    if(admin_varible==4)
                    {
                        cout<<"enter the username"<<endl;
                        string name;
                        cin>>name;
                        cout<<"enter the date on whcih accouunt is formed\n";
                        string date;
                        cin>>date;
                        obj.update_user_vaccine(name,date);
                    }
                    if(admin_varible==5)
                    {
                   
                        obj.show_all_users();
                    }
                    cout<<" press Y to contine/ N to return to main screen of admin"<<endl;
                    string ans;
                    cin>>ans;
                    if(ans=="Y")
                    goto start;
                    else if(ans=="N")
                    break;
                }
                else
                {
                    cout << "wrong username or password" << endl;
                    cout << " you have " << --chances << " chances left\n";
                    goto begin;
                }
            }
        }
        if (variable == 5)
        {
            user[object_count_user].search();
        }
        if (variable == 6)
        {
            string username, password;
            cout << "enter the username: " << endl;
            cin >> username;
            cout << "enter the password :" << endl;
            cin >> password;
            usr.search(username, password);
        }
    }
}