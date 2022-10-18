#include<iostream>
using namespace std;

class Vehicle{
    protected: 
    string category,reg_no;
    };

class Four_wheeler : public Vehicle{

    string model_no,color,company_name;
    public:

    void setter_Four_wheeler(){
        category="Four Wheeler";
        reg_no="KA03JJJ9324";
        model_no="NEXON XZA Plus P";
        color="Blue";
        company_name="TATA MOTORS";
        }

    void getter_four_wheeler(){
        cout<<"Category : "<<category<<endl;
        cout<<"Registration No. : "<<reg_no<<endl;
        cout<<"Model : "<<model_no<<endl;
        cout<<"Color : "<<color<<endl;
        cout<<"Company Name : "<<company_name<<endl;
    }
};

class Two_wheeler : public Vehicle{
    string model_no,color,company_name;
    public:

    void setter_Two_wheeler(){
        category="Two Wheeler";
        reg_no="HKL2345IJK";
        model_no="Hunter 350";
        color="Red";
        company_name="Royal Enfield";
        }

    void getter_Two_wheeler(){
        cout<<"Category : "<<category<<endl;
        cout<<"Registration No. : "<<reg_no<<endl;
        cout<<"Model : "<<model_no<<endl;
        cout<<"Color : "<<color<<endl;
        cout<<"Company Name : "<<company_name<<endl;
    }
};

int main(){
    cout<<endl<<"*********Object 1 details******** "<<endl;
    cout<<"----------------------------------"<<endl;
    Two_wheeler bike;
    bike.setter_Two_wheeler();
    bike.getter_Two_wheeler(); 
    cout<<endl<<"*********Object 2 details******** "<<endl;
    cout<<"----------------------------------"<<endl;
    Four_wheeler car;
    car.setter_Four_wheeler();
    car.getter_four_wheeler();

    return 0;
}
