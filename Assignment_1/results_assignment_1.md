## Κώδικας επίλυσης 
    |     ΚΩΔΙΚΑΣ                                                                                         |
    |-----------------------------------------------------------------------------------------------------|
    | [horse.hpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/horse.hpp)  |
    | [horse.cpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/horse.cpp)  |
    | [racing.hpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/racing.hpp)|
    | [racing.cpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/racing.cpp)|
    | [bet.hpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/bet.hpp)      |
    | [bet.cpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/bet.cpp)      |
    | [main_b.cpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/horse_race_b.cpp)|
    | [main_a.cpp])(https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/horse_race.cpp)|
    | [main_tests.cpp](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/tests.cpp)|
    | [results.txt](https://github.com/vasnastos/OOP/blob/main/Assignment_1/Assignment_Solution/results.txt)|
## Εντολές μεταγλώττισης
  **Μεταγλώττιση main κώδικα**
   * g++ horse.cpp racing.cpp horse_race.cpp -o race
   * race
 
  **Μεταγλώττιση Κώδικα πονταρίσματος χρήστη**
   * g++ horse.cpp racing.cpp bet.cpp  horse_race_b.cpp -o race
   * race
  
  **Μεταγλώττιση Unit tests**
   * g++ horse.cpp tests.cpp -o test_main
   * test_main 


## Αποτελέσματα εκτέλεσης

==== Bet User Insertion ====
Insert money amount:200


==== Place Bet ====
Place your bet:100

===== Select Horse =====
1.[Name:Rogue Startup Speed:86 Power:57 Stamina:100]
2.[Name:Goliath Startup Speed:80 Power:53 Stamina:94]
3.[Name:Nitro Startup Speed:65 Power:53 Stamina:97]
4.[Name:Storm Startup Speed:87 Power:55 Stamina:71]
5.[Name:Danger Startup Speed:99 Power:82 Stamina:96]
6.[Name:Raider Startup Speed:62 Power:96 Stamina:50]
7.[Name:Bolt Startup Speed:82 Power:92 Stamina:75]
8.[Name:Hercules Startup Speed:90 Power:83 Stamina:83]
Select horse:7

|0.........|
|1.........|
|2.........|
|3.........|
|4.........|
|5.........|
|6.........|
|7.........|

|0.........|
|.1........|
|2.........|
|.3........|
|.4........|
|5.........|
|6.........|
|.7........|

|0.........|
|.1........|
|.2........|
|..3.......|
|..4.......|
|5.........|
|.6........|
|..7.......|

|.0........|
|..1.......|
|..2.......|
|...3......|
|...4......|
|.5........|
|.6........|
|...7......|

|..0.......|
|..1.......|
|..2.......|
|....3.....|
|....4.....|
|.5........|
|.6........|
|....7.....|

|...0......|
|...1......|
|...2......|
|....3.....|
|.....4....|
|..5.......|
|..6.......|
|....7.....|

|...0......|
|...1......|
|...2......|
|....3.....|
|.....4....|
|..5.......|
|...6......|
|.....7....|

|...0......|
|....1.....|
|...2......|
|.....3....|
|......4...|
|...5......|
|....6.....|
|......7...|

|....0.....|
|....1.....|
|....2.....|
|......3...|
|.......4..|
|....5.....|
|.....6....|
|.......7..|

|....0.....|
|....1.....|
|....2.....|
|.......3..|
|........4.|
|....5.....|
|......6...|
|.......7..|

|.....0....|
|....1.....|
|.....2....|
|.......3..|
|.........4|
|.....5....|
|.......6..|
|........7.|

|......0...|
|....1.....|
|......2...|
|.......3..|
|.........4|
|......5...|
|........6.|
|.........7|

|.......0..|
|.....1....|
|.......2..|
|.......3..|
|.........4|
|.......5..|
|.........6|
|.........7|

|.......0..|
|.....1....|
|.......2..|
|........3.|
|.........4|
|........5.|
|.........6|
|.........7|

|........0.|
|......1...|
|........2.|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

|........0.|
|.......1..|
|.........2|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|.......1..|
|.........2|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|........1.|
|.........2|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|.........1|
|.........2|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

======= Standings ========
1.[Danger, Startup Speed:99, Power:82, Stamina:96]
2.[Hercules, Startup Speed:90, Power:83, Stamina:83]
3.[Bolt, Startup Speed:82, Power:92, Stamina:75]
4.[Storm, Startup Speed:87, Power:55, Stamina:71]
5.[Raider, Startup Speed:62, Power:96, Stamina:50]
6.[Nitro, Startup Speed:65, Power:53, Stamina:97]
7.[Rogue, Startup Speed:86, Power:57, Stamina:100]
8.[Goliath, Startup Speed:80, Power:53, Stamina:94]



====== User Round Summary ======
* User's amount:200
* User's winning bets:0
* User's no money loss bets:1
* User's money loss bets:0

===== User's Next Choice =====
Do you want to continue to the next race(yes/no):yes
==== Place Bet ====
Place your bet:50

===== Select Horse =====
1.[Name:Goliath Startup Speed:97 Power:68 Stamina:61]
2.[Name:Storm Startup Speed:73 Power:90 Stamina:75]
3.[Name:Rogue Startup Speed:69 Power:53 Stamina:67]
4.[Name:Nitro Startup Speed:67 Power:97 Stamina:62]
5.[Name:Hercules Startup Speed:60 Power:73 Stamina:59]
6.[Name:Raider Startup Speed:72 Power:95 Stamina:66]
7.[Name:Bolt Startup Speed:84 Power:60 Stamina:75]
8.[Name:Hulk Startup Speed:51 Power:100 Stamina:79]
Select horse:4

|0.........|
|1.........|
|2.........|
|3.........|
|4.........|
|5.........|
|6.........|
|7.........|

|.0........|
|1.........|
|.2........|
|.3........|
|.4........|
|.5........|
|6.........|
|.7........|

|..0.......|
|.1........|
|.2........|
|.3........|
|..4.......|
|.5........|
|.6........|
|..7.......|

|...0......|
|..1.......|
|.2........|
|..3.......|
|...4......|
|..5.......|
|..6.......|
|...7......|

|...0......|
|...1......|
|.2........|
|...3......|
|...4......|
|...5......|
|...6......|
|....7.....|

|....0.....|
|...1......|
|..2.......|
|....3.....|
|...4......|
|....5.....|
|....6.....|
|.....7....|

|....0.....|
|....1.....|
|..2.......|
|.....3....|
|....4.....|
|.....5....|
|.....6....|
|......7...|

|....0.....|
|.....1....|
|..2.......|
|......3...|
|.....4....|
|.....5....|
|......6...|
|.......7..|

|....0.....|
|.....1....|
|..2.......|
|.......3..|
|.....4....|
|......5...|
|......6...|
|........7.|

|....0.....|
|......1...|
|..2.......|
|........3.|
|......4...|
|.......5..|
|......6...|
|.........7|

|.....0....|
|.......1..|
|..2.......|
|.........3|
|.......4..|
|........5.|
|......6...|
|.........7|

|......0...|
|........1.|
|...2......|
|.........3|
|........4.|
|.........5|
|......6...|
|.........7|

|.......0..|
|.........1|
|...2......|
|.........3|
|.........4|
|.........5|
|......6...|
|.........7|

|.......0..|
|.........1|
|....2.....|
|.........3|
|.........4|
|.........5|
|......6...|
|.........7|

|........0.|
|.........1|
|.....2....|
|.........3|
|.........4|
|.........5|
|.......6..|
|.........7|

|.........0|
|.........1|
|......2...|
|.........3|
|.........4|
|.........5|
|.......6..|
|.........7|

|.........0|
|.........1|
|......2...|
|.........3|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|.........1|
|.......2..|
|.........3|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|.........1|
|.......2..|
|.........3|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|.........1|
|........2.|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|.........1|
|........2.|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

======= Standings ========
1.[Hulk, Startup Speed:51, Power:100, Stamina:79]
2.[Nitro, Startup Speed:67, Power:97, Stamina:62]
3.[Raider, Startup Speed:72, Power:95, Stamina:66]
4.[Storm, Startup Speed:73, Power:90, Stamina:75]
5.[Hercules, Startup Speed:60, Power:73, Stamina:59]
6.[Goliath, Startup Speed:97, Power:68, Stamina:61]
7.[Bolt, Startup Speed:84, Power:60, Stamina:75]
DNF.[Rogue, Startup Speed:69, Power:53, Stamina:67]



====== User Round Summary ======
* User's amount:200
* User's winning bets:0
* User's no money loss bets:2
* User's money loss bets:0

===== User's Next Choice =====
Do you want to continue to the next race(yes/no):yes

==== Place Bet ====
Place your bet:10

===== Select Horse =====
1.[Name:Blitz Startup Speed:73 Power:69 Stamina:92]
2.[Name:Hulk Startup Speed:75 Power:61 Stamina:65]
3.[Name:Goliath Startup Speed:61 Power:98 Stamina:99]
4.[Name:Danger Startup Speed:84 Power:61 Stamina:75]
5.[Name:Storm Startup Speed:87 Power:93 Stamina:84]
6.[Name:Hercules Startup Speed:58 Power:98 Stamina:97]
7.[Name:Raider Startup Speed:63 Power:58 Stamina:83]
8.[Name:Nitro Startup Speed:62 Power:81 Stamina:82]
Select horse:2

|0.........|
|1.........|
|2.........|
|3.........|
|4.........|
|5.........|
|6.........|
|7.........|

|0.........|
|.1........|
|.2........|
|.3........|
|.4........|
|.5........|
|.6........|
|.7........|

|.0........|
|..1.......|
|.2........|
|..3.......|
|..4.......|
|..5.......|
|.6........|
|..7.......|

|..0.......|
|..1.......|
|.2........|
|..3.......|
|...4......|
|...5......|
|..6.......|
|...7......|

|...0......|
|...1......|
|.2........|
|...3......|
|....4.....|
|....5.....|
|..6.......|
|....7.....|

|....0.....|
|....1.....|
|.2........|
|....3.....|
|.....4....|
|.....5....|
|...6......|
|....7.....|

|....0.....|
|.....1....|
|..2.......|
|.....3....|
|......4...|
|......5...|
|...6......|
|.....7....|

|.....0....|
|......1...|
|...2......|
|.....3....|
|.......4..|
|.......5..|
|...6......|
|......7...|

|......0...|
|......1...|
|....2.....|
|.....3....|
|........4.|
|........5.|
|....6.....|
|.......7..|

|.......0..|
|......1...|
|.....2....|
|......3...|
|.........4|
|.........5|
|.....6....|
|........7.|

|.......0..|
|......1...|
|......2...|
|......3...|
|.........4|
|.........5|
|......6...|
|.........7|

|........0.|
|.......1..|
|.......2..|
|......3...|
|.........4|
|.........5|
|.......6..|
|.........7|

|........0.|
|........1.|
|........2.|
|.......3..|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|........1.|
|.........2|
|........3.|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|.........1|
|.........2|
|........3.|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|.........1|
|.........2|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

======= Standings ========
1.[Storm, Startup Speed:87, Power:93, Stamina:84]
2.[Hercules, Startup Speed:58, Power:98, Stamina:97]
3.[Nitro, Startup Speed:62, Power:81, Stamina:82]
4.[Blitz, Startup Speed:73, Power:69, Stamina:92]
5.[Goliath, Startup Speed:61, Power:98, Stamina:99]
6.[Hulk, Startup Speed:75, Power:61, Stamina:65]
7.[Danger, Startup Speed:84, Power:61, Stamina:75]
8.[Raider, Startup Speed:63, Power:58, Stamina:83]



====== User Round Summary ======
* User's amount:190
* User's winning bets:0
* User's no money loss bets:2
* User's money loss bets:1

===== User's Next Choice =====
Do you want to continue to the next race(yes/no):yes

==== Place Bet ====
Place your bet:100

===== Select Horse =====
1.[Name:Hulk Startup Speed:76 Power:90 Stamina:56]
2.[Name:Hercules Startup Speed:90 Power:66 Stamina:62]
3.[Name:Danger Startup Speed:94 Power:50 Stamina:63]
4.[Name:Bolt Startup Speed:80 Power:52 Stamina:71]
5.[Name:Goliath Startup Speed:71 Power:77 Stamina:72]
6.[Name:Raider Startup Speed:86 Power:91 Stamina:72]
7.[Name:Nitro Startup Speed:73 Power:72 Stamina:77]
8.[Name:Storm Startup Speed:92 Power:67 Stamina:71]
Select horse:1

|0.........|
|1.........|
|2.........|
|3.........|
|4.........|
|5.........|
|6.........|
|7.........|

|.0........|
|1.........|
|2.........|
|.3........|
|.4........|
|5.........|
|.6........|
|.7........|

|..0.......|
|1.........|
|.2........|
|.3........|
|..4.......|
|.5........|
|..6.......|
|..7.......|

|...0......|
|.1........|
|..2.......|
|..3.......|
|...4......|
|..5.......|
|...6......|
|...7......|

|....0.....|
|..1.......|
|..2.......|
|..3.......|
|....4.....|
|...5......|
|....6.....|
|....7.....|

|.....0....|
|..1.......|
|..2.......|
|...3......|
|.....4....|
|....5.....|
|.....6....|
|.....7....|

|......0...|
|...1......|
|..2.......|
|...3......|
|......4...|
|.....5....|
|......6...|
|......7...|

|.......0..|
|...1......|
|...2......|
|...3......|
|.......4..|
|......5...|
|......6...|
|.......7..|

|........0.|
|....1.....|
|....2.....|
|....3.....|
|........4.|
|......5...|
|......6...|
|........7.|

|.........0|
|....1.....|
|....2.....|
|....3.....|
|.........4|
|.......5..|
|......6...|
|.........7|

|.........0|
|.....1....|
|....2.....|
|....3.....|
|.........4|
|........5.|
|......6...|
|.........7|

|.........0|
|.....1....|
|.....2....|
|.....3....|
|.........4|
|........5.|
|.......6..|
|.........7|

|.........0|
|......1...|
|......2...|
|......3...|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|......1...|
|.......2..|
|.......3..|
|.........4|
|.........5|
|........6.|
|.........7|

|.........0|
|.......1..|
|........2.|
|.......3..|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|.......1..|
|.........2|
|.......3..|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|........1.|
|.........2|
|........3.|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|........1.|
|.........2|
|........3.|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|.........1|
|.........2|
|........3.|
|.........4|
|.........5|
|.........6|
|.........7|

|.........0|
|.........1|
|.........2|
|.........3|
|.........4|
|.........5|
|.........6|
|.........7|

======= Standings ========
1.[Hulk, Startup Speed:76, Power:90, Stamina:56]
2.[Goliath, Startup Speed:71, Power:77, Stamina:72]
3.[Storm, Startup Speed:92, Power:67, Stamina:71]
4.[Raider, Startup Speed:86, Power:91, Stamina:72]
5.[Nitro, Startup Speed:73, Power:72, Stamina:77]
6.[Danger, Startup Speed:94, Power:50, Stamina:63]
7.[Hercules, Startup Speed:90, Power:66, Stamina:62]
8.[Bolt, Startup Speed:80, Power:52, Stamina:71]



====== User Round Summary ======
*User's amount:390
*User's winning bets:1
*User's no money loss bets:2
*User's money loss bets:1

===== User's Next Choice =====
Do you want to continue to the next race(yes/no):no


===== User's Summary =====
Money Amount:390
-------
Horse:Bolt Bet Amount:100.000000 Bet_Status:Money Back
Horse:Nitro Bet Amount:50.000000 Bet_Status:Money Back
Horse:Hulk Bet Amount:10.000000 Bet_Status:Losing
Horse:Hulk Bet Amount:100.000000 Bet_Status:Winning