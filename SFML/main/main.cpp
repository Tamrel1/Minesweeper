#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <time.h>


int HowManyBombsAround(std::vector<int> BombQOBS1, std::vector<int>BombQOBS2, std::vector<std::vector <sf::RectangleShape>>& Plansza, int IndexWidth, int IndexHeight, std::vector<sf::Texture>& arr_t, std::vector<int>& Empty_B, std::vector<int>& Empty_B_2, bool f_1, bool OnlyEmpty, bool Recursion_flag, std::vector<int>& Empty_1_TODO, std::vector<int>& Empty_2_TODO);

void CheckIfWon(std::vector<std::vector <sf::RectangleShape>>& Plansza, std::vector<int> BombQOBS1, std::vector<int>BombQOBS2, int QuantityWidth, int QuantityHeight) {
    int WinCount=0; //Sprawdza jak du¿o bomb zosta³o rozbrojonych poprzez przyrównanie miejsca bomby (Przechowywanego kolejno w wketorach BomQOBS1 i BombQOBS2) 
   
           for (size_t o_2 = 0; o_2 <= BombQOBS1.size()-1; o_2++) {
                if (Plansza[BombQOBS1[o_2]][BombQOBS2[o_2]].getFillColor() == sf::Color::Cyan) {
                    std::cout << "Defused " << std::endl;
                    WinCount++;

                }
                
            }
      
  
    if (WinCount == BombQOBS1.size()) { //sprawdza czy zmienna WinCount jest równa przyporz¹dkowanym koordynatom X dla danej Bomby (jeden koordynat X = jenda Bomba)
        std::cout << "Rozbrojono wszystkie bomby" << std::endl;
    }

}

bool  DefuseBomb(std::vector<int> BombQOBS1, std::vector<int>BombQOBS2, std::vector<std::vector <sf::RectangleShape>>& Plansza, int IndexWidth, int IndexHeight, sf::Texture &t1, sf::Texture &t2, sf::Texture &t3){
    //zmienia kolor pola na Cyan na podstawie obecnej tekstury (w trakcie klikniêcia)
    //
    
    if (Plansza[IndexWidth][IndexHeight].getTexture() != &t1 && Plansza[IndexWidth][IndexHeight].getTexture() != &t3) {
        Plansza[IndexWidth][IndexHeight].setFillColor(sf::Color::Cyan);
        Plansza[IndexWidth][IndexHeight].setTexture(&t1);
        
    }
    
    else if (Plansza[IndexWidth][IndexHeight].getTexture() == &t1) { //odpowiada za odklikniêcie (nadaje teksturê bloku)
        Plansza[IndexWidth][IndexHeight].setFillColor(sf::Color::White);
        Plansza[IndexWidth][IndexHeight].setTexture(&t2);
     
    }
    int DefuseCouter=0;
    for (int i = 0; i < BombQOBS1.size(); i++) {
    
        if (Plansza[BombQOBS1[i]][BombQOBS2[i]].getFillColor() == sf::Color::Cyan) {
          
            DefuseCouter++;
            if (DefuseCouter == BombQOBS1.size()-1 ) { //Liczi dopóki DefuseCounte nie bêdzie równy iloœci Bomb
              
                return true;
            }
            
        
        }
    }
    
    return false;
    

}

void GiantClick(std::vector<int> BombQOBS1, std::vector<int>BombQOBS2, int PlayerPosX, int PlayerPosY, std::vector<std::vector<sf::RectangleShape>>& Playground, std::vector<sf::Texture >& arr_t) {
    std::vector<int> a[1];
    std::vector<sf::Thread> b;
        //wykonuje funkcjê HowManyBobmsAround(która zwróci liczbê bomb, aby przyporz¹dkowaæ dan¹ liczbe.png) dla wszystkich pól w okó³ klikniêtego pola
        //niektóre instrukcje warunkowe bior¹ poprawkê na wielkoœæ planszy 
        //jeœli pole jest rónwe 0 (pusty naciœniêty kafelek) zostanie wywoa³ana funkcja HowManyBombaAround() dla kolejnego kafelka i tak do momentu gdzie nie bêdzie równe 0;
        if (PlayerPosX -1 >= 0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX - 1, PlayerPosY, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {
 
            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX - 1, PlayerPosY, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }
        if (PlayerPosX + 1 <= 27 && HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX + 1, PlayerPosY, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {
  
            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX + 1, PlayerPosY, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }

        if (PlayerPosX - 1 >= 0  && PlayerPosY - 1 >= 0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX - 1, PlayerPosY - 1, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {

            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX - 1, PlayerPosY - 1, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }

        if (PlayerPosX + 1 <= 27 && PlayerPosY+ 1 <= 26 &&  HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX + 1, PlayerPosY + 1, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {

            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX + 1, PlayerPosY + 1, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }

        if (PlayerPosX - 1 >= 0 && PlayerPosY + 1 <= 26 && HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX - 1, PlayerPosY + 1, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {
       
            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX - 1, PlayerPosY + 1, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }
        if (PlayerPosX + 1 <= 27 && PlayerPosY - 1 >= 0 &&HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX + 1, PlayerPosY - 1, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {
   
            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX + 1, PlayerPosY - 1, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }

        if  (PlayerPosY - 1 >= 0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX, PlayerPosY - 1, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {

            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX, PlayerPosY - 1, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }

        if (PlayerPosY + 1 <= 26 && HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX, PlayerPosY + 1, arr_t, a[0], a[0], false, true, false, a[0], a[0]) != 0)
        {
    
            HowManyBombsAround(BombQOBS1, BombQOBS2, Playground, PlayerPosX, PlayerPosY + 1, arr_t, a[0], a[0], true, true, false, a[0], a[0]);
        }


    
    






}


int HowManyBombsAround(std::vector<int> BombQOBS1, std::vector<int>BombQOBS2, std::vector<std::vector <sf::RectangleShape>> &Plansza, int IndexWidth, int IndexHeight, std::vector<sf::Texture>& arr_t, std::vector<int>&Empty_B, std::vector<int>&Empty_B_2, bool f_1, bool OnlyEmpty, bool Recursion_flag, std::vector<int>& Empty_1_TODO, std::vector<int>& Empty_2_TODO) {
    int BombCounted=0;
    if (Empty_1_TODO.size() >= 10000) { //Zwalnia miejsce aby zapobiec przeci¹¿niu stosu 
        while (!Empty_1_TODO.empty()) {
            Empty_1_TODO.pop_back();
            while (!Empty_2_TODO.empty()) {
                Empty_2_TODO.pop_back();
            }
        }
    }

    
    for (int j = 0; j < BombQOBS1.size(); j++) { //okreœla teksture dobieran¹ dla pola poprzez zwiêkszanie BombCount np. 8.png dla BombCount = 8
            if (IndexHeight - 1 == BombQOBS1[j] && IndexWidth == BombQOBS2[j]) {
              
                BombCounted++;
            }
            if ( IndexHeight + 1 == BombQOBS1[j] && IndexWidth == BombQOBS2[j]) {
              
                BombCounted++;
            }
            if ( IndexHeight  == BombQOBS1[j] && IndexWidth+1 == BombQOBS2[j]) {
              
                BombCounted++;
            }
            if ( IndexHeight  == BombQOBS1[j] && IndexWidth-1 == BombQOBS2[j]) {
             
                BombCounted++;
            }
            if (  IndexHeight-1 == BombQOBS1[j] && IndexWidth - 1 == BombQOBS2[j]) {
              
                BombCounted++;
            }
            if (  IndexHeight + 1 == BombQOBS1[j] && IndexWidth + 1 == BombQOBS2[j]) {
         
                BombCounted++;
            }
            if (IndexHeight - 1 == BombQOBS1[j] && IndexWidth + 1 == BombQOBS2[j]) {
           
                BombCounted++;
            }
            if (IndexHeight + 1 == BombQOBS1[j] && IndexWidth - 1 == BombQOBS2[j]) {
            
                BombCounted++;
            }
            
         } 
    if (BombCounted > 0 && f_1 == true ) {

  
        Plansza[IndexWidth][IndexHeight].setTexture(&arr_t[BombCounted]);
    }
    if (BombCounted == 0 && f_1 == true) { //funkcja rekurencyjna wowo³uj¹ca sam¹ siêbie dla pustych pól (tych z BombCount = 0) tak aby mog³a ona sprawdziæ pola we wszysztkich wolnych kierunkach do czasu a¿ nie trafi na kafelek z faktycz¹ wartoœci¹ lub na œcianê 
        
        sf::Color color(102, 102, 51);
        Plansza[IndexWidth][IndexHeight].setFillColor(color);
        
        Plansza[IndexWidth][IndexHeight].setTexture(&arr_t[BombCounted]);
        
        Empty_1_TODO.push_back(IndexWidth); //Pocz¹tkowe koordynaty s¹ wpisywane do listy na której bêdziemy dzia³aæ 
        Empty_2_TODO.push_back(IndexHeight);
        
            //jeœli kafelek z bloku obok zostanie uznany za posiadaj¹cy 0, zostanie zabadny nastêpny kafelek 
            if (IndexWidth - 1 >= 0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth - 1, IndexHeight, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth - 1][IndexHeight].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth - 1);
                Empty_2_TODO.push_back(IndexHeight);
            }
         
            if (IndexWidth + 1 <=27 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth + 1, IndexHeight, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth + 1][IndexHeight].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth + 1);
                Empty_2_TODO.push_back(IndexHeight);
            }
            if (IndexHeight + 1 <= 26 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth, IndexHeight + 1, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth][IndexHeight + 1].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth);
                Empty_2_TODO.push_back(IndexHeight + 1);
            }
            if (IndexHeight - 1 >=0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth, IndexHeight - 1, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth][IndexHeight - 1].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth);
                Empty_2_TODO.push_back(IndexHeight - 1);
            }
            if (IndexWidth + 1 <= 27 && IndexHeight + 1 <= 26 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth + 1, IndexHeight + 1, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth + 1][IndexHeight + 1].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth + 1);
                Empty_2_TODO.push_back(IndexHeight + 1);
            }
            if (IndexHeight - 1 >= 0 && IndexWidth - 1 >= 0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth - 1, IndexHeight - 1, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth - 1][IndexHeight - 1].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth - 1);
                Empty_2_TODO.push_back(IndexHeight - 1);
            }
            if (IndexWidth + 1 <= 27  && IndexHeight - 1 >= 0 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth + 1, IndexHeight - 1, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth + 1][IndexHeight - 1].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth + 1);
                Empty_2_TODO.push_back(IndexHeight - 1);
            }
            if (IndexWidth - 1 >= 0 && IndexHeight + 1 <= 26 && HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, IndexWidth - 1, IndexHeight + 1, arr_t, Empty_B, Empty_B_2, false, true, false, Empty_1_TODO, Empty_2_TODO) == 0 && Plansza[IndexWidth - 1][IndexHeight + 1].getTexture() != &arr_t[0])
            {
                Empty_1_TODO.push_back(IndexWidth - 1);
                Empty_2_TODO.push_back(IndexHeight + 1);

            }
            
            GiantClick(BombQOBS1, BombQOBS2, IndexWidth, IndexHeight, Plansza, arr_t); //giant click odpowiada za sprawdzenie ka¿dego pola na oko³o klikniêtego pola i ustalenie dla nich numeru 
            for (int i = 0; i < Empty_1_TODO.size(); i++) {
                if (Plansza[Empty_1_TODO[i]][Empty_2_TODO[i]].getTexture() != &arr_t[0]) { //kiedy kafelek ma jak¹œ liczbê (tekstura  != 0)(arr_t odpowiada za tekstury)
                   
                   Empty_1_TODO.resize(Empty_1_TODO.size()); //poprawka z próbuj¹ca zapobiec b³êdowi stack overflow
                    Empty_2_TODO.resize(Empty_1_TODO.size());
                   Plansza[IndexWidth][IndexHeight].setTexture(&arr_t[BombCounted]);                    
                    Plansza[Empty_1_TODO[i]][Empty_2_TODO[i]].setFillColor(color);
                    GiantClick(BombQOBS1, BombQOBS2, Empty_1_TODO[i], Empty_2_TODO[i], Plansza, arr_t);
                    HowManyBombsAround(BombQOBS1, BombQOBS2, Plansza, Empty_1_TODO[i], Empty_2_TODO[i], arr_t, Empty_B, Empty_B_2, true, true, false, Empty_1_TODO, Empty_2_TODO);
                }
             
            }
           
    
             
    };
   
    return BombCounted;
    
   
}
//Funkcja pokazuje wszystkie bomby i koñczy grê 
bool GameOver(std::vector<int> QOBS_Array, std::vector<int> QOBS_Array_2, int QuantityWidth, int QuantityHeight, std::vector<sf::Texture>& text2, std::vector<std::vector <sf::RectangleShape>>& rect1, int i, int j) {
    
    bool flaga_1= false;
    for (int o_1 = 0; o_1 < QOBS_Array.size(); o_1++) {

        if (i == QOBS_Array[o_1] && j == QOBS_Array_2[o_1] && rect1[j][i].getFillColor() != sf::Color::Cyan) { //Jeœli "i " a tak¿e "j" s¹ równe koordynatom w listach QOBS_Array_2 i QOBS_Array_1 a ich pole nie jest koloru Cyan 
            //(Cyan oznacza pole poddane rozbrojeniu )
            rect1[j][i].setTexture(&text2[0]);//Textura PNG
         

            rect1[j][i].setFillColor(sf::Color::Red); //Zmiana koloru 
        
            for (int j = 0; j < QuantityWidth; j++) { //Pêtle dzia³aj¹ce na iloœci paneli w grze
                for (int i = 0; i < QuantityHeight; i++) {

                    for (int o_2 = 0; o_2 < QOBS_Array.size(); o_2++) {

                        if (i == QOBS_Array[o_2] && j == QOBS_Array_2[o_2] && rect1[j][i].getFillColor() != sf::Color::Cyan) { //pokazywanie miejsc bomb i kolorowanie pól na czerwono
                            rect1[j][i].setTexture(&text2[0]);
                            rect1[j][i].setFillColor(sf::Color::Red);
                            flaga_1 = true;
                      
                            
                        }
                    }
                }
            }
            break;
        }
    }
    if (flaga_1 == false) {
        return false;
    }
    else if (flaga_1 == true) {
        return true;
    }
    
}
//Zwraca ile jest pól rozbrojonych 
int GetDefuseCount(std::vector<std::vector <sf::RectangleShape>>& rect1, int QuantityWidth, int QuantityHeight) {
    int Counter=0;
    for (int j = 0; j < QuantityWidth; j++) { //Dzia³anie na wszystkich kafelkach gry (ich iloœci)
        for (int i = 0; i < QuantityHeight; i++) {
            if (rect1[j][i].getFillColor() == sf::Color::Cyan) { //jeœli pole jest koloru rozbrojonej bomby to zwiêksze Counter o 1
                Counter++;
            }
        }
    }
    std::cout << Counter << std::endl;
    return Counter;
}



int main()
{


    
    srand(time(NULL));
 
    int QuantityOfBombs = 110;//110
    sf::Clock cl1;
    int Blok_height = 10, Block_width = 10;
    std::vector<int > QOBS_Array ; //dynamiczne alokowanie pamieci
    std::vector<int > QOBS_Array_2 ;
    std::vector<int> Empty_Blocks;
    std::vector <int> Empty_Blocks_2;
    std::vector<int> TODO_1;
    std::vector <int> TODO_2;
    sf::Texture t1;
    //t1.loadFromFile("Flaga.png");
    int I_W;
    int I_H;

    float OriginX = 0, OriginY = -100;
    float width = 311, height = 400, Height_min_Origini = height + OriginY;
    int QuantityWidth = std::floor(width / (Block_width + 1)), QuantityHeight = std::floor((Height_min_Origini) / (Blok_height + 1)); //ile blokwo na szerokosci i wysokosci
    int QuantityOfBlocks = QuantityWidth * QuantityHeight; //ile kafelkow w ogóle
    int DefuseCounter = 0;
    std::cout << QuantityWidth << " <- Quanitity Width / Quntity Height ->" << QuantityHeight << std::endl;

    sf::RenderWindow window(sf::VideoMode(width, height), "Saper", !sf::Style::Resize + sf::Style::Titlebar + sf::Style::Close);
    
    int c = 0, j = 0;
    
    sf::Image img1;
    sf::Texture texture;
    std::vector<sf::Texture> text2(1);
    std::vector<sf::Texture> text3(9);

    for (int i = 0; i < 9; i++) {
        text3[i].loadFromFile(std::to_string(i) + ".png");
    }


    if (!texture.loadFromFile("Blok.PNG")) {
        std::cout << "Blok sie nie wczytal " << std::endl;
    }
    else {

        std::cout << "Blok sie wczytal " << std::endl;
    }

    if (!text2[0].loadFromFile("Bomba.PNG"))
    {
        std::cout << "Bomba sie nie wczytana " << std::endl;
    }
    else {

        std::cout << "Bobmba wczytana " << std::endl;
    }

    sf::Clock clock;
    std::cout << QuantityOfBlocks << std::endl;
    std::vector<std::vector<sf::RectangleShape>> rect1(QuantityWidth, std::vector<sf::RectangleShape>(QuantityHeight));

    //ustawianie kafelkow za pomoca pêtli (nadawanie im w³aœciwoœci)
    for (j = 0; j < QuantityWidth; j++) {
        for (int i = 0; i < QuantityHeight; i++) {
            rect1[j][i] = (sf::RectangleShape(sf::Vector2f(10, 10))); 
            rect1[j][i].setFillColor(sf::Color::White);
            rect1[j][i].setTexture(&texture);  
            rect1[j][i].setTextureRect(sf::IntRect(rect1[j][i].getPosition().x, rect1[j][i].getPosition().y, 36, 35)); 
            rect1[j][i].setPosition(sf::Vector2f(((1 + Block_width) * j) + 1, ((Blok_height + 1) * i) + 99));

        }
    }
    int rand_1, rand_2;
    bool Flaga_1 = true;
    //Ustawianie Bomb w losowych miejscach 
    for (int i = 0; i < QuantityOfBombs; i++) {
        rand_1 = rand() % QuantityWidth;
        rand_2 = rand() % QuantityHeight;


        for (int i = 0; i < QOBS_Array.size(); i++) {
            if (rand_1 == QOBS_Array[i] && rand_2 == QOBS_Array_2[i]) { //jeœli wylosowane koordynaty (rand1/rand2)ju¿ znajduj¹ siê w jednej ze tabel, nie mo¿emy pozwoliæ na to aby znowu zosta³a dodana 
                Flaga_1 = false;
                break;
            }
            else if (rand_1 != QOBS_Array[i] && rand_2 != QOBS_Array_2[i]) { //Jeœli wylosowane koordynaty nie s¹ w tabeli, mo¿na je dodaæ 
                Flaga_1 = true;
            }
        }

        if (Flaga_1 == true) { //dodawanie koordynatów do tabel

            QOBS_Array.push_back(rand_1);
            QOBS_Array_2.push_back(rand_2);
        }
       


    }
    //Pokazuj bomby
    for (int j = 0; j < QuantityWidth; j++) {
        for (int i = 0; i < QuantityHeight; i++) {

            for (int o_2 = 0; o_2 < QOBS_Array.size(); o_2++) {

                if (i == QOBS_Array[o_2] && j == QOBS_Array_2[o_2] && rect1[j][i].getFillColor() != sf::Color::Cyan) {
           
                  //  rect1[j][i].setFillColor(sf::Color::Red);
                   

                }
            }
        }
    }
  
    //Jesli HowManyBombsAround() zwróci 0 znaczy ¿e pole jest ca³kowicie puste, i nie wyœwietli siê na nim ¿adna liczba, jest to potzebne w jako argument w funkcji HowManyBombsAround()
    for (j = 0; j < QuantityWidth; j++) {
        for (int i = 0; i < QuantityHeight; i++) {
            if (HowManyBombsAround(QOBS_Array, QOBS_Array_2, rect1, j, i, text3, Empty_Blocks, Empty_Blocks_2, false, true, false, TODO_1, TODO_2) == 0) {//przypisywanie pustych pól do tabel
                Empty_Blocks.push_back(j);
                Empty_Blocks_2.push_back(i);
            }
        }
    }



    sf::Font font;
    if (!font.loadFromFile("joystix_monospace.otf")) {

        std::cout << " Czcionka nie dziala " <<std::endl;
    }


    



        //inicjalizacja uœmiechu (do restartu), czasomierza i licznika rozbrojeñ
     sf::Texture UI,UI1,UI2;
     UI.loadFromFile("smile.PNG");
    std::vector<sf::RectangleShape> rect2;
    rect2.push_back(sf::RectangleShape(sf::Vector2f(80, 30)));
    rect2[0].setPosition(sf::Vector2f(10,30));
    rect2[0].setFillColor(sf::Color::Black);
    rect2.push_back(sf::RectangleShape(sf::Vector2f(80, 30)));
    rect2[1].setPosition(sf::Vector2f(width-110,30));
    rect2[1].setFillColor(sf::Color::Black);
    rect2.push_back(sf::RectangleShape(sf::Vector2f(30, 30)));
    rect2[2].setPosition(sf::Vector2f((width/2)-15, 50));
    rect2[2].setFillColor(sf::Color::White);
    rect2[2].setTexture(&UI);
    bool flaga_1 = true;
    
    sf::Text textee(std::to_string(QuantityOfBombs), font);
    sf::Text textee2("Cos", font);
    textee2.setCharacterSize(rect2[1].getSize().y); //czasomierz 
    textee2.setPosition(rect2[1].getPosition().x + 20, rect2[1].getPosition().y - 3);
    textee2.setFillColor(sf::Color::Red);
    textee2.setStyle(sf::Text::Bold);
    textee.setCharacterSize(rect2[0].getSize().y); //licznik 
    textee.setPosition(rect2[0].getPosition().x+20, rect2[0].getPosition().y-3);
    textee.setStyle(sf::Text::Bold);
    textee.setFillColor(sf::Color::Red);

    while (window.isOpen())
    {
      //pomiar czasu dla czasomierza (sekundy)
        sf::Time elapsed1 = cl1.getElapsedTime();
        sf::Int64 elapsed1_int = elapsed1.asSeconds();
       
        sf::Event event;
        while (window.pollEvent(event) )
        {
            sf::Vector2i globalPosition = sf::Mouse::getPosition(window);
           

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                if (globalPosition.y < rect1[0][0].getPosition().y && globalPosition.y > 0) {
                   if (globalPosition.x > rect2[2].getPosition().x && globalPosition.x < rect2[2].getPosition().x + rect2[2].getSize().x
                        && globalPosition.y >= rect2[2].getPosition().y && globalPosition.y <= (rect2[2].getPosition().y + rect2[2].getSize().y)) //okreœlanie klikniêcia i na jakim polu dzia³a
                     {
                        rect2[2].setFillColor(sf::Color::Yellow);
                        window.close();
                        main();
                    }
                    
                }
                if(globalPosition.y < height && globalPosition.y > rect1[0][0].getPosition().y && flaga_1 == true) {

                    globalPosition.y = globalPosition.y - Blok_height;

                    for (int j = 0; j < QuantityWidth; j++) {
                        for (int i = 0; i < QuantityHeight; i++) {
                            
                            if (globalPosition.x > rect1[j][i].getPosition().x && globalPosition.x < rect1[j][i].getPosition().x + Block_width
                                && globalPosition.y >= (rect1[j][i].getPosition().y - Blok_height) && globalPosition.y <= rect1[j][i].getPosition().y)
                            {                                                 
                                HowManyBombsAround(QOBS_Array, QOBS_Array_2, rect1, j, i, text3, Empty_Blocks, Empty_Blocks_2, true, false, false, TODO_1, TODO_2);
                                if (GameOver(QOBS_Array, QOBS_Array_2, QuantityWidth, QuantityHeight, text2, rect1, i, j) == true) { //zakoñczenie gry
                                    flaga_1 = false;
                                } 
                               

                                
                                
                                break;

                            }
                        }
                    }
                    
                }
               
               
                
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
            {
               
                if (globalPosition.y < height && globalPosition.y > 97) {

                    globalPosition.y = globalPosition.y - Blok_height;

                    for (int j = 0; j < QuantityWidth; j++) {
                        for (int i = 0; i < QuantityHeight; i++) {
                            
                            if (globalPosition.x > rect1[j][i].getPosition().x && globalPosition.x < rect1[j][i].getPosition().x + Block_width && globalPosition.y >= (rect1[j][i].getPosition().y - Blok_height) && globalPosition.y <= rect1[j][i].getPosition().y)
                            {
                              
                               if(DefuseBomb(QOBS_Array, QOBS_Array_2, rect1, j, i, t1, texture, text3[0])==true){ 

                                   flaga_1 = false;
                                }
                               
                                textee.setString(std::to_string(QuantityOfBombs - GetDefuseCount(rect1, QuantityWidth, QuantityHeight)));
                                
                            }
                            

                        }
                    }
                    CheckIfWon(rect1, QOBS_Array, QOBS_Array_2, QuantityWidth, QuantityHeight); 
                }
                
                
            }
            
            if (event.type == sf::Event::Closed )
                window.close();
        }
        //rysowanie obietków i tekstu a tak¿e wyœietlenie ca³ego okna
        textee2.setString(std::to_string(elapsed1_int));
        window.clear(sf::Color::Black);
        for (int j = 0;j<QuantityWidth;j++) {
            for (int i = 0; i < QuantityHeight; i++) {
                window.draw(rect1[j][i]);
            }
        }
        for (int i = 0; i < 3; i++) {
            window.draw(rect2[i]);
        }
        window.draw(textee2);
        window.draw(textee);
        window.display();
        
    }

    return 0;
}
