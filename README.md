# CallCenterforTripCost

The program serves as a booking system for accommodations and transportation. It simulates the operations of a call center that manages customer requests for reservations.
The program allows users to make and manage reservation requests for accommodations and transportation, providing a simple simulation of a call center's booking system. Users can input details about their stay, choose transportation options, and view the total cost of their booking.



Program Run:
CALL CENTER BOOKING REQUEST \t
0 end/t
1 new reservation request standard
2 new reservation request superior
3 show reservation request
4 show all reservation requests
your choice: 1
location of accomodation: Berlin
arrival on (yyyy-mm-dd): 2023-02-03
how many nights (maximum 4 weeks): 3
how many single bed rooms (80.00 EUR/night): 1
how many double bed rooms (150.00 EUR/night): 1
a all inclusive (50.00 EUR/day)
b breakfast     (10.00 EUR/day)
h half board    (20.00 EUR/day)
n no meals
your choice: b
with parking place (10.00 EUR/day; y(es) or n(o)): n
price: 780.00 EUR
please choose transport outward
0 self travel
1 by flight
2 by train
your choice: 1
code of flight: LH123
airport of departure: Duesseldorf
airport of arrival: Berlin
standard price for one passenger: 99
first class ((y)es or (n)o): y
please choose transport return
0 self travel
1 by flight
2 by train
your choice: 2
code of train: DB456
main train station of departure: Berlin
main train station of arrival: Duisburg
first class ((y)es or (n)o): n
price for one passenger: 50

CALL CENTER BOOKING REQUEST
0 end
1 new reservation request standard
2 new reservation request superior
3 show reservation request
4 show all reservation requests
your choice: 4
********REQUEST NO: 1********
accomodation at:    Berlin
number of guests:   3
number of nights:   3
check-in date:      2023-02-03
check-out date:     2023-02-06
single bed room(s): 1 (80.00 EUR/night)
double bed room(s): 1 (150.00 EUR/night)
board:              breakfast (20.00 EUR/day and person)
parking:            no parking place booked
price accomodation: 780.00 EUR
outward journey:    flight 2023-02-03 LH123 from Duesseldorf to Berlin first class (198.00 EUR/person) transfer included
journey back:       train 2023-02-06 DB456 from Berlin to Duisburg (50.00 EUR/person) no transfer
price total:        1524.00 EUR


CALL CENTER BOOKING REQUEST
0 end
1 new reservation request standard
2 new reservation request superior
3 show reservation request
4 show all reservation requests
your choice: 2
location of accomodation: Hamburg
arrival on (yyyy-mm-dd): 2023-12-31
how many nights (maximum 4 weeks): 1
how many single bed rooms (110.00 EUR/night): 0
how many double bed rooms (210.00 EUR/night): 1
a all inclusive (50.00 EUR/day)
b breakfast     (10.00 EUR/day)
h half board    (20.00 EUR/day)
n no meals
your choice: a
with parking place (10.00 EUR/day; y(es) or n(o)): y
price: 320.00 EUR
please choose transport outward
0 self travel
1 by flight
2 by train
your choice: 0
please choose transport return
0 self travel
1 by flight
2 by train
your choice: 0

CALL CENTER BOOKING REQUEST
0 end
1 new reservation request standard
2 new reservation request superior
3 show reservation request
4 show all reservation requests
your choice: 4
********REQUEST NO: 1********
accomodation at:    Berlin
number of guests:   3
number of nights:   3
check-in date:      2023-02-03
check-out date:     2023-02-06
single bed room(s): 1 (80.00 EUR/night)
double bed room(s): 1 (150.00 EUR/night)
board:              breakfast (20.00 EUR/day and person)
parking:            no parking place booked
price accomodation: 780.00 EUR
outward journey:    flight 2023-02-03 LH123 from Duesseldorf to Berlin first class (198.00 EUR/person) transfer included
journey back:       train 2023-02-06 DB456 from Berlin to Duisburg (50.00 EUR/person) no transfer
price total:        1524.00 EUR

********REQUEST NO: 2********
accomodation at:    Hamburg
number of guests:   2
number of nights:   1
check-in date:      2023-12-31
check-out date:     2024-01-01
single bed room(s): 0 (110.00 EUR/night)
double bed room(s): 1 (210.00 EUR/night)
board:              all inclusive (20.00 EUR/day and person)
parking:            included (10.00 EUR/day)
price accomodation: 320.00 EUR
outward journey:    self travel no transfer
journey back:       self travel no transfer
price total:        320.00 EUR
