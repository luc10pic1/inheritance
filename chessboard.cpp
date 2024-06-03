#include "chessboard.h"

void Chessboard::printChessboard()const {
    std::cout<<"  ";
    for(int i=0;i<8;i++){
        std::cout<<" "<<i<<" ";
    }
    std::cout<<"\n";
    for(int i=0;i<8;i++){
        std::cout<<i<<" ";
        for(int j=0;j<8;j++){
            if(buffer[j][i])
                buffer[j][i]->printPiece();
            else
                std::cout<<" * ";
        }
        std::cout<<" "<<i<<" ";
        std::cout<<"\n";
    }
    std::cout<<"  ";
    for(int i=0;i<8;i++){
        std::cout<<" "<<i<<" ";
    }
    std::cout<<"\n";
}

void Chessboard::insertCoordinate() {
    std::cout << "Inserisci le coordinate del pezzo da spostare \nx: ";
    std::cin >> startX;
    std::cout << "y: ";
    std::cin >> startY;
    while (!checkCoordinates(startX, startY)) {
        std::cout << "Inserisci le coordinate del pezzo da spostare \nx: ";
        std::cin >> startX;
        std::cout << "y: ";
        std::cin >> startY;
    }
    std::cout << "Inserisci le coordinate della casella di destinazione\nx: ";
    std::cin >> arrX;
    std::cout << "y: ";
    std::cin >> arrY;
    while(arrY==startY && arrX==startX){
        std::cout<<"Il pezzo deve spostarsi!";
        insertCoordinate();
    }
    while (!checkCoordinates(arrX, arrY ,false)) {
        insertCoordinate();
    }
    while (!buffer[startX][startY]->isLegalMove(*this,arrX,arrY)){
        std::cout<<"Il pezzo selezionato non può compiere la mossa indicata\nRiprovare\n";
        buffer[startX][startY]->setCapture(false);
        insertCoordinate();
    }
    buffer[startX][startY]->setCapture(false);
}

bool Chessboard::checkCoordinates(int x, int y,bool start) {
    bool result=true;
    if(x>7 || x<0 || y>7 || y<0){
        std::cout<<"Le coordinate inserite non sono valide. Riprovare\n";
        result=false;
    }
    if(result && start && !buffer[x][y]){
        std::cout<<"Non ci sono pezzi da spostare alle coordinate inserite. Riprovare\n";
        result=false;
    }
    if(result && start && buffer[x][y]->getColor()!=turn){
        std::cout<<"Non è il tuo turno\n";
        result=false;
    }
    return result;
}

void Chessboard::doMove() {
    Re* king=dynamic_cast<Re*>(buffer[startX][startY]);
    if(king){
        if(buffer[startX][startY]->getColor()==ColorPed::white){
            xW=arrX;
            yW=arrY;
        }
        else{
            xB=arrX;
            yB=arrY;
        }
    }
    if(buffer[arrX][arrY]){
        if(buffer[arrX][arrY]->getColor()==ColorPed::white)
            captureW.push_front(buffer[arrX][arrY]);
        else
            captureB.push_front(buffer[arrX][arrY]);
        buffer[startX][startY]->setCapture(true);
    }

    buffer[arrX][arrY]=buffer[startX][startY];
    buffer[arrX][arrY]->setMove(arrX,arrY);
    buffer[startX][startY]= nullptr;
}
void Chessboard::cancelMove() {
    Re* king=dynamic_cast<Re*>(buffer[arrX][arrY]);
    if(king){
        if(buffer[arrX][arrY]->getColor()==ColorPed::white){
            xW=startX;
            yW=startY;
        }
        else{
            xB=startX;
            yB=startY;
        }
    }
    buffer[arrX][arrY]->setMove(startX,startY);
    buffer[startX][startY]=buffer[arrX][arrY];
    if(buffer[startX][startY]->isCapture()){
        buffer[startX][startY]->setCapture(false);
        if(buffer[startX][startY]->getColor()==ColorPed::white)
            buffer[arrX][arrY]=takeCaptureB();
        else
            buffer[arrX][arrY]=takeCaptureW();
    }
    else
        buffer[arrX][arrY]=nullptr;
}

void Chessboard::doMove(int startX, int startY, int arrX, int arrY) {
    Re* king=dynamic_cast<Re*>(buffer[startX][startY]);
    if(king){
        if(buffer[startX][startY]->getColor()==ColorPed::white){
            xW=arrX;
            yW=arrY;
        }
        else{
            xB=arrX;
            yB=arrY;
        }
    }
    if(buffer[arrX][arrY]){
        if(buffer[arrX][arrY]->getColor()==ColorPed::white)
            captureW.push_front(buffer[arrX][arrY]);
        else
            captureB.push_front(buffer[arrX][arrY]);
        buffer[startX][startY]->setCapture(true);
    }

    buffer[arrX][arrY]=buffer[startX][startY];
    buffer[arrX][arrY]->setMove(arrX,arrY);
    buffer[startX][startY]= nullptr;
}
void Chessboard::cancelMove(int startX, int startY, int arrX, int arrY) {
    Re* king=dynamic_cast<Re*>(buffer[arrX][arrY]);
    if(king){
        if(buffer[arrX][arrY]->getColor()==ColorPed::white){
            xW=startX;
            yW=startY;
        }
        else{
            xB=startX;
            yB=startY;
        }
    }
    buffer[arrX][arrY]->setMove(startX,startY);
    buffer[startX][startY]=buffer[arrX][arrY];
    if(buffer[startX][startY]->isCapture()){
        buffer[startX][startY]->setCapture(false);
        if(buffer[startX][startY]->getColor()==ColorPed::white)
            buffer[arrX][arrY]=takeCaptureB();
        else
            buffer[arrX][arrY]=takeCaptureW();
    }
    else
        buffer[arrX][arrY]=nullptr;
}

bool Chessboard::isAutoScacco() {
    bool result=false;
    for(int i=0;i<8 && !result;i++){
        for(int j=0;j<8 && !result;j++){
            if(buffer[i][j] && buffer[i][j]->getColor()!=turn){
                if(buffer[i][j]->getColor()==ColorPed::white && buffer[i][j]->isLegalMove(*this,xB,yB) && turn==ColorPed::black) {
                    result = true;
                }
                else if(buffer[i][j]->getColor()==ColorPed::black && buffer[i][j]->isLegalMove(*this,xW,yW) && turn==ColorPed::white){
                    result=true;
                }
            }
        }
    }
    return result;
}

void Chessboard::printCapture(std::list<Pieces *> color) {
    auto it=color.begin();
    for(int i=1;i<=color.size();i++,it++){
        std::cout<<i<<". ";
        Pieces * element=*it;
        element->printPieceString();
    }
}

bool Chessboard::checkScacco() {
    bool result=false;
    int x,y;
    for(int i=0;i<8 && !result;i++){
        for(int j=0;j<8 && !result;j++){
            if(buffer[i][j]){
                if(buffer[i][j]->getColor()==ColorPed::white && buffer[i][j]->isLegalMove(*this,xB,yB)){
                    result=true;
                    x=i;
                    y=j;
                }
                else if(buffer[i][j]->getColor()==ColorPed::black && buffer[i][j]->isLegalMove(*this,xW,yW)){
                    result=true;
                    x=i;
                    y=j;
                }
            }
        }
    }
    if(result){
        if(buffer[x][y]->getColor()==ColorPed::white) {
            scaccoReW = true;
            scaccoReB = false;
            std::cout<<"Il Bianco ha fatto scacco al re!\n";
        }
        else {
            scaccoReB = true;
            scaccoReW = false;
            std::cout<<"Il Nero ha fatto scacco al re!\n";
        }
        if(scaccoReB)
            result=checkScaccoMatto(ColorPed::white);
        else if(scaccoReW)
            result=checkScaccoMatto(ColorPed::black);
    }
    return result;
}

bool Chessboard::checkScacco(ColorPed whoCheck) {
    bool result=false;
    for(int i=0;i<8 && !result;i++){
        for(int j=0;j<8 && !result;j++){
            if(buffer[i][j] && buffer[i][j]->getColor()!=whoCheck){
                if(buffer[i][j]->getColor()==ColorPed::white && buffer[i][j]->isLegalMove(*this,xB,yB)){
                    result=true;
                }
                else if(buffer[i][j]->getColor()==ColorPed::black && buffer[i][j]->isLegalMove(*this,xW,yW)){
                    result=true;
                }
            }
        }
    }
    return !result;
}

bool Chessboard::checkScaccoMatto(ColorPed whoCheck) {
    bool scacco=false;
    int xK,yK;
    if(whoCheck==ColorPed::white){
        xK=xW;
        yK=yW;
    }
    else{
        xK=xB;
        yK=yB;
    }
    scacco= canMoveK(xK+1,yK,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK-1,yK,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK,yK+1,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK,yK-1,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK+1,yK+1,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK+1,yK-1,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK-1,yK-1,whoCheck);
    if (!scacco)
        scacco= canMoveK(xK-1,yK+1,whoCheck);
    bool result=false;
    if(scacco) {
        for (int i = 0; !result && i < 8; i++) {
            for (int j = 0; !result &&j < 8; j++) {
                if (buffer[i][j] && buffer[i][j]->getColor()==whoCheck) {
                    for (int k=0;!result && k<8;k++){
                        for(int l=0;!result && l<8;l++){
                            if(i!=k && j!=l && buffer[i][j]->isLegalMove(*this,k,l)) {
                                Pieces *repo = nullptr;
                                doMove(i, j, k, l);
                                result= checkScacco(whoCheck);
                                cancelMove(i,j,k,l);
                            }

                        }
                    }
                }
            }
        }
    }
    if(result)
        scacco=false;
    if(scacco && whoCheck==ColorPed::white) {
        scaccoMattoB = true;
        std::cout<<"Il Nero ha fatto scacco matto\n"
                   "Il Nero ha vinto!!";
    }
    else if(scacco && whoCheck==ColorPed::black) {
        scaccoMattoW = true;
        std::cout << "Il Bianco ha fatto scacco matto\n"
                     "Il Bianco ha vinto!!";
    }
    return scacco;
}

bool Chessboard::canMoveK(int x, int y, ColorPed whoCheck) {
    int xK,yK;
    if(whoCheck==ColorPed::white){
        xK=xW;
        yK=yW;
    }
    else{
        xK=xB;
        yK=yB;
    }
    bool result=true;
    if(buffer[xK][yK]->isLegalMove(*this,x,y)){
        for(int i=0;i<8 && result;i++){
            for(int j=0;j<8 && result;j++){
                if(buffer[i][j] && buffer[i][j]->getColor()!=whoCheck && !buffer[i][j]->isLegalMove(*this,xK,yK))
                    result=false;
            }
        }
    }
    return result;
}

void Chessboard::checkSubstionPedone() {
    Pedone* pedone=dynamic_cast<Pedone*>(buffer[arrX][arrY]);
    if(pedone) {
        if (arrY == 0 && buffer[arrX][arrY]->getColor() == ColorPed::white)
            substitionPedone(captureW);

        if(arrY==7 && buffer[arrX][arrY]->getColor()==ColorPed::black)
            substitionPedone(captureB);

    }
}

void Chessboard::substitionPedone(std::list<Pieces *> color) {
    bool result=false;
    for(auto it= color.begin(); !result && it != color.end(); it++){
        Pedone*element=dynamic_cast<Pedone*>(*it);
        if(!element)
            result=true;
    }
    if(result) {
        std::cout << "Digitare il numero vicino al pezzo con cui sostituire il pedone\n";
        printCapture(color);
        int i;
        std::cin >> i;
        while (i > color.size() || i < 1) {
            std::cout << "Valore non valido. Riprovare:\n";
            std::cin >> i;
        }
        auto it = color.begin();
        for (int j = 1; j < i; j++) {
            it++;
        }
        while (Pedone *element = dynamic_cast<Pedone *>(*it)) {
            std::cout << "Non puoi sostituire un pedone con un altro pedone\n";
            std::cin >> i;
            it = color.begin();
            for (int j = 1; j < i; j++) {
                it++;
            }
        }
        buffer[arrX][arrY] = *it;
        color.erase(it);
        std::cout << "Pedone sostituito\n";
    }
    else {
        buffer[arrX][arrY] = nullptr;
        std::cout << "Nessun pezzo con cui sostituire il pedone\n";
    }
}