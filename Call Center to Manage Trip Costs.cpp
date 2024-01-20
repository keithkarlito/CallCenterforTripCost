/***********************************************************************
Matr.-Nr:                     3144738
Nachname/Surname:             Desouza
Vorname/Given name:           Keith
Uni-Email:                    keith.de-souza@stud.uni-due.de / keithkarlito@gmail.com
Studiengang/Course of studis: Bsc. Computer Engineering (Software) ISE
***********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date{
    private:
        unsigned short day;
        unsigned short month;
        unsigned short year;
    public:
        int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        Date(unsigned short day, unsigned short month, unsigned short year):day(day),month(month),year(year){}
        Date() : day(11), month(01), year(2023) { }
        Date operator+(int);
        friend istream& operator>>(istream&, Date&);
        friend ostream& operator<<(ostream&, const Date&);

};


Date Date::operator+(int no_of_dates){
    Date new_date(day, month, year);
    new_date.day=new_date.day+no_of_dates;
    if(new_date.day>daysInMonth[new_date.month-1]){
        new_date.day=new_date.day-daysInMonth[new_date.month-1];
        new_date.month++;
        if (new_date.month>12){
            new_date.year++;
            new_date.month=1;}
    }
    return new_date;
}

istream& operator>>(istream& in, Date& date){
    char c;
    return (in >> date.year >> c >> date.month >> c >> date.day);
}

ostream& operator<<(ostream& out, const Date& date){
   return out<< setw(4) << setfill('0') << date.year
            << '-' << setw(2) << setfill('0') << date.month
            << '-' << setw(2) << setfill('0') << date.day;
}

enum struct Board:short int {
  no_meals=0,
  breakfast,
  half_board,
  all_inclusive
};

ostream& operator<<(ostream&,const Board&);

ostream& operator<<(ostream& out,const Board& board){
    switch(board) {
        case Board::no_meals:
            out << "no meals";
            break;
        case Board::breakfast:
            out << "breakfast";
            break;
        case Board::half_board:
            out << "half board";
            break;
        case Board::all_inclusive:
            out << "all inclusive";
            break;
    }
    return out;
}

float get_prices(Board board_val){
    float price;
    if (board_val==Board::no_meals){
       price=0.00;
    }else if (board_val==Board::breakfast){
       price=10.00;
    }else if (board_val==Board::half_board){
        price=20.00;
    }else if (board_val==Board::all_inclusive){
        price=50.00;
    }else{cout<<"ERROR";}////////
    return price;
}

class Accomodation{
    private:
        float priceNightSingle;
        float priceNightDouble;
        float priceOneDayParking;
        string location;
        Date arrival;
        int nights;
        int singles;
        int doubles;
        Board desiredBoard;
        bool parking;
    public:
        Accomodation(float,float,float);
        ~Accomodation();
        Date get_arrival(void);
        Date get_checkout(void);
        int get_guests(void);
        float get_price(void);
        void ask_data(void);
        void print(void);

};

Accomodation::Accomodation(float price_single_room,float price_double_room,float price_parking):priceNightSingle(price_single_room),priceNightDouble(price_double_room), priceOneDayParking(price_parking){
    ask_data();
}

Accomodation::~Accomodation(){
    cout<<"destructor Accomodation "<<location<<" at "<<arrival<<" for "<<get_guests()<<" guests done"<<endl;
}

Date Accomodation::get_arrival(void){
    return arrival;
}

Date Accomodation::get_checkout(void){
    return arrival+nights;
}

int Accomodation::get_guests(void){
    return (singles+(2*doubles));
}

float Accomodation::get_price(void){
    float price;
    price=((singles*priceNightSingle)+(doubles*priceNightDouble))*nights;
    if (parking==true){
        price=price+(priceOneDayParking*nights);
    }
    price=price+(get_guests()*(get_prices(desiredBoard)*nights));
    return price;
}

void Accomodation::ask_data(void){
    char board,parking_yn;
    cout<<"location of accomodation: ";cin>>location;
    cout<<"arrival on (yyyy-mm-dd): ";cin>>arrival;
    cout<<"how many nights (maximum 4 weeks): ";cin>>nights;
    cout<<"how many single bed rooms ("<< priceNightSingle<<" EUR/night): ";cin>>singles;
    cout<<"how many double bed rooms ("<< priceNightDouble<<" EUR/night): ";cin>>doubles;

    cout<<"a all inclusive\t (50.00 EUR/day)"<<endl<<"b breakfast\t (10.00 EUR/day)"<<endl<<"h half board\t (20.00 EUR/day)"<<endl<<"n no meals"<<endl<<"your choice: ";
    cin>>board;
    if (board=='a'){
        desiredBoard=Board::all_inclusive;
    }else if (board=='b'){
        desiredBoard=Board::breakfast;
    }else if (board=='h'){
        desiredBoard=Board::half_board;
    }else if (board=='n'){
        desiredBoard=Board::no_meals;
    }

    cout<<"with parking place ("<< priceOneDayParking<<" EUR/night; y(es) or n(o)): ";cin>>parking_yn;
    if (parking_yn=='y'){
        parking=true;
    }else{
        parking=false;
    }
    cout<<"price: "<<fixed << setprecision(2) <<get_price()<<endl;
}

void Accomodation::print(void){
    cout<<"accomodation at:\t"<<location<<endl<<"number of guests:\t"<<get_guests()<<endl<<"number of nights:\t"<<nights<<endl<<"check-in date:\t\t"<<arrival<<endl<<"check-out date:\t\t"<<get_checkout()<<endl<<"single bed room(s):\t"<<singles<<" ("<<fixed << setprecision(2) <<priceNightSingle<<" EUR/night)"<<endl<<"double bed room(s):\t"<<fixed << setprecision(2) <<doubles<<" ("<<priceNightDouble<<" EUR/night)"<<endl<<"board:\t\t\t"<<desiredBoard<<" ("<<fixed << setprecision(2) <<get_prices(desiredBoard)<<" EUR/day and person)"<<endl<<"parking:\t\t"<<(parking==true?"included (":"not included (")<<fixed << setprecision(2) <<priceOneDayParking<<" EUR/day)"<<endl<<"price accomodation:\t"<<fixed << setprecision(2) <<get_price()<<" EUR"<<endl;
}

class Transport{
    public:
        virtual ~Transport();
        virtual bool includedTransfer(){
            return false;
        };
        virtual float get_price()=0;
        virtual void print()=0;
};

Transport::~Transport(){
    cout<<"destructor Transport done"<<endl;
}

class Request{
    private:
        const unsigned int no;
        static unsigned int lastNo;
        Accomodation* accomodation;
        Request* next;
        Transport* transportOutward;
        Transport* transportReturn;
    public:
        Request(Accomodation*, Request*,Transport*,Transport*);
        ~Request();
        unsigned int get_no(void);
        Request* get_next(void);
        void set_next(Request*);
        float get_price(void);
        void print(void);
};
unsigned int Request::lastNo=1;

Request::Request(Accomodation* accomodation, Request* next,Transport* outwards=nullptr,Transport* returns=nullptr):no(lastNo++),accomodation(accomodation), next(nullptr),transportOutward(outwards),transportReturn(returns){
}


Request::~Request(){
    delete accomodation;
    delete transportOutward;
    delete transportReturn;
    cout<<"destructor Request "<<no<<" done"<<endl;
}


unsigned int Request::get_no(void){
    return no;
}

Request* Request::get_next(void){
    return next;
}

void Request::set_next(Request* new_request){
    next=new_request;
}

float Request::get_price(void){
    return accomodation->get_price()+(transportOutward->get_price()*accomodation->get_guests())+(transportReturn->get_price()*accomodation->get_guests());
}

void Request::print(void){
    cout<<"*********REQUEST NO: "<<no<<"*********"<<endl;
    accomodation->print();
    cout<<"outward journey:\t";
    transportOutward->print();
    cout<<"journey back:\t\t";
    transportReturn->print();
    cout<<"price total:\t\t"<<fixed << setprecision(2)<<get_price()<<" EUR"<<endl;
}

class Callcenter{
    private:
        Request* requests;
    public:
        Callcenter():requests(nullptr){}
        void append(Request*);
        void cancel(Request*);
        Request* get_request(unsigned int);
        void print_All(void);
};

void Callcenter::append(Request* new_request){
    bool done=false;
    Request *temp;
    temp=requests;
    if(requests==nullptr){
        requests=new_request;
    }else{
        while (temp->get_next()!=nullptr){
            temp=temp->get_next();
        }
        temp->set_next(new_request);
    }
}

void Callcenter::cancel(Request* request_deletion){
    Request* prev;
    Request* next;
    if (request_deletion==requests){
        requests=request_deletion->get_next();
    }else{
        prev=requests;
        while (prev->get_next()!=request_deletion){
            prev=prev->get_next();
        }
        next=request_deletion->get_next();

        prev->set_next(next);
    }
    delete request_deletion;
}

Request* Callcenter::get_request(unsigned int request_number){
    Request* temp;
    temp=requests;
    while (temp!=nullptr){
        if(temp->get_no()==request_number){
            break;
        }
        temp=temp->get_next();
    }
    return temp;
}

void Callcenter::print_All(void){
    Request* temp;
    temp=requests;
    while (temp!=nullptr){
        temp->print();
        temp=temp->get_next();
    }
}

class SelfTravel:public Transport{
    public:
        SelfTravel(){};
        virtual ~SelfTravel();
        float get_price(){
            return 0.00;
        }
        void print(){
            cout<<"self travel no transfer"<<endl;
        }
};

SelfTravel::~SelfTravel(){
    cout<<"destructor SelfTravel done"<<endl;
}

class PublicTransport:public Transport{
    protected:
        Date depature;
        string code;
        string from;
        string to;
        float priceOneSeat;
        bool firstClass;
    public:
        PublicTransport(Date date,string code,string depature,string arrival,float priceOneTicket,bool fc=false):depature(date),code(code),from(depature),to(arrival),priceOneSeat(priceOneTicket),firstClass(fc){};
        virtual ~PublicTransport();
        void print();
};

PublicTransport::~PublicTransport(){
    cout<<"destructor PublicTransport "<<code<<" at "<<depature<<" from "<<from<<" to "<<to<<" done"<<endl;

}

void PublicTransport::print(){
    cout<<depature<<" "<<code<<" from "<<from<<" to "<<to<<(firstClass?" first class ":" ")<<" ("<<fixed << setprecision(2)<<get_price()<<" EUR/person)"<<endl;
}

class Flight:public PublicTransport{
    protected:
        bool transfer;
    public:
        Flight(Date date,string code,string depature,string arrival,float priceOneTicket,bool fc,bool transfer=true): PublicTransport(date,code,depature,arrival,priceOneTicket,fc), transfer(transfer){}
        ~Flight();
        bool includedTransfer(void){ return transfer;}
        float get_price(void){
            if (firstClass==true){
                return (priceOneSeat*2);
            }
            else{
                return priceOneSeat;
            }
        }
        void print(void);
};

Flight::~Flight(){
    cout<<"destructor Flight done"<<endl;;
}

void Flight::print(void){
    cout<<"flight ";
    PublicTransport::print();
}

class Train:public PublicTransport{
    public:
        Train(Date date,string code,string depature,string arrival,float priceOneTicket,bool fc): PublicTransport(date,code,depature,arrival,priceOneTicket,fc){}
        ~Train();
        float get_price(void){
            if (firstClass==true){
                return (priceOneSeat*1.5);
            }
            else{
                return priceOneSeat;
            }
        }
        void print(void);
};

Train::~Train(){
    cout<<"destructor Train done"<<endl;
}

void Train::print(void){
    cout<<"train ";
    PublicTransport::print();
}

Transport* inputTransport(Date date, string direction){
    string code,departure,arrival;
    char fC,choice;
    bool firstClass;
    float price;
    Transport* transport;
    cout<<"please choose transport "<<direction<<endl<<"0 self travel\n1 by flight\n2 by train\nyour choice: ";
    cin>>choice;
    if (choice=='0'){
        transport=new SelfTravel();
    }else if (choice=='1'){
        cout<<"code of flight: ";cin>>code;
        cout<<"airport of departure: ";cin>>departure;
        cout<<"airport of arrival: ";cin>>arrival;
        cout<<"standard price for one passenger: ";cin>>price;
        cout<<"first class ((y)es or (n)o): ";cin>>fC;firstClass=(fC=='y'?true:false);
        transport=new Flight(date,code,departure,arrival,price,firstClass);
    }else if (choice=='2'){
        cout<<"code of train: ";cin>>code;
        cout<<"main train station of departure: ";cin>>departure;
        cout<<"main train station of arrival: ";cin>>arrival;
        cout<<"first class y(es) or n(o): ";cin>>fC;firstClass=(fC=='y'?true:false);
        cout<<"price for one passenger: ";cin>>price;
        transport=new Train(date,code,departure,arrival,price,firstClass);
    }
    return transport;
}

int main(){
    Callcenter call_center= Callcenter();
    int choice;
    do{
        cout<<endl<<"CALL CENTER BOOKING REQUEST\n0 end\n1 new reservation request standard\n2 new reservation request superior\n3 show reservation request\n4 show all reservation requests\nyour choice: ";
        cin>>choice;
        if (choice==0){cout<<"END";}

        else if (choice==1){
            Request* tail;
            Accomodation* accomodation=new Accomodation(80.00f,150.00f,10.00f);
            Transport* outwards=inputTransport(accomodation->get_arrival(),"Outward");
            Transport* returns=inputTransport(accomodation->get_checkout(),"Return");

            Request* new_request=new Request(accomodation,tail,outwards,returns);
            call_center.append(new_request);

        }else if (choice==2){
            Request* tail;
            Accomodation* accomodation=new Accomodation(110.00f,210.00f,10.00f);
            Transport* outwards=inputTransport(accomodation->get_arrival(),"Outward");
            Transport* returns=inputTransport(accomodation->get_checkout(),"Return");

            Request* new_request=new Request(accomodation,tail,outwards,returns);
            call_center.append(new_request);

        }else if (choice==3){
            Request* reservation;
            unsigned int reservation_no;
            cout<<"Enter reservation no: ";
            cin>>reservation_no;
            reservation=call_center.get_request(reservation_no);
            if (reservation!=nullptr){
                reservation->print();
                char cancel;
                cout<<"(c)ancel this request or (n)ot: ";
                cin>>cancel;
                if (cancel=='c'){
                    call_center.cancel(reservation);
                }
            }else{
                cout<<"reservation request not found"<<endl;
            }

        }else if (choice==4){
            call_center.print_All();
        }
    }while (choice!=0);
}
