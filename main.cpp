#include <iostream>
void CrossZero(std::string text, int* answerVictoryCross, int* answerVictoryZero, int* answerCross, int* answerZero, int* answerPoint, bool* answerGood) {
    bool good = true;
    int cross = 0, zero = 0, point = 0, RowCross = 0, RoWZero = 0, VictoryCross = 0, VictoryZero = 0;

    for (int i = 0; i < text.length(); i++) {
        if (text.length() == 3) {
            if (text[i] == 'X') {
                cross++;
                RowCross++;
            }
            else if (text[i] == 'O') {
                zero++;
                RoWZero++;
            }
            else if (text[i] == '.') {
                point++;
            }
            else {
                good = false;
                break;
            }
        }
        else {
            good = false;
            break;
        }
    }
    if (RowCross == 3) {
        VictoryCross++;
    }
    else if (RoWZero == 3) {
        VictoryZero++;
    }
    (*answerVictoryCross) = VictoryCross;
    (*answerVictoryZero) = VictoryZero;
    (*answerCross) = cross;
    (*answerZero) = zero;
    (*answerPoint) = point;
    (*answerGood) = good;
}
int main() {
    std::string TopRow, MiddleRow, LowerRow, answer;
    std::cout << "Enter cross and zero\n";
    std::cin >> TopRow >> MiddleRow >> LowerRow;
    bool TopRowGood = true, MiddleRowGood = true, LowerRowGood = true;
    int cross = 0, zero = 0, point = 0, TopRowCross = 0, TopRowZero = 0, MiddleRoWCross = 0, MiddleRowZero = 0, LowerRowCross = 0, LowerRowZero = 0, VictoryCross = 0, VictoryZero = 0, TopRowVictoryCross = 0, TopRowVictoryZero = 0, MiddleRoWVictoryCross = 0, MiddleRowVictoryZero = 0, LowerRowVictoryCross = 0, LowerRowVictoryZero = 0, TopRowPoint = 0, MiddleRowPoint = 0, LowerRowPoint = 0;

    CrossZero(TopRow, &TopRowVictoryCross, &TopRowVictoryZero, &TopRowCross, &TopRowZero, &TopRowPoint, &TopRowGood);
    CrossZero(MiddleRow, &MiddleRoWVictoryCross, &MiddleRowVictoryZero, &MiddleRoWCross, &MiddleRowZero, &MiddleRowPoint, &MiddleRowGood);
    CrossZero(LowerRow, &LowerRowVictoryCross, &LowerRowVictoryZero, &LowerRowCross, &LowerRowZero, &LowerRowPoint, &LowerRowGood);

    VictoryCross = TopRowVictoryCross + MiddleRoWVictoryCross + LowerRowVictoryCross;
    VictoryZero = TopRowVictoryZero + MiddleRowVictoryZero + LowerRowVictoryZero;
    cross = TopRowCross + MiddleRoWCross + LowerRowCross;
    zero = TopRowZero + MiddleRowZero + LowerRowZero;
    point = TopRowPoint + MiddleRowPoint + LowerRowPoint;

    if (TopRowGood && MiddleRowGood && LowerRowGood) {
        for (int i = 0, j = 1, k = 2; (i < 3), (j >= 0), (k>=0); i++, j--, k-=2)
        {
            if ((TopRow[i] == 'X' && MiddleRow[i] == 'X' && LowerRow[i] == 'X')
                || (TopRow[i] == 'X' && MiddleRow[j] == 'X' && LowerRow[k] == 'X')
                || (TopRow[k] == 'X' && MiddleRow[j] == 'X' && LowerRow[i] == 'X')) {
                VictoryCross++;
            }
        }
        for (int i = 0, j = 1, k = 2; (i < 3), (j >= 0), (k >= 0); i++, j--, k -= 2)
        {
            if ((TopRow[i] == 'O' && MiddleRow[i] == 'O' && LowerRow[i] == 'O')
                || (TopRow[i] == 'O' && MiddleRow[j] == 'O' && LowerRow[k] == 'O')
                || (TopRow[k] == 'O' && MiddleRow[j] == 'O' && LowerRow[i] == 'O')) {
                VictoryZero++;
            }
        }
        
        if (VictoryCross > 1 || VictoryZero > 1 || (VictoryCross >= 1 && VictoryZero >= 1) || (VictoryCross == 1 && zero >= cross)
            || (VictoryZero == 1 && cross > zero) || (VictoryZero == 1 && cross < zero) || (VictoryCross == 1 && zero != (cross - 1)) || (VictoryZero == 0 && cross < zero)) {
            answer = "Incorrect";
        }
        else if (VictoryCross == 0 && VictoryZero == 0 && point >= 0) {
            answer = "Nobody";
        }
        else if (VictoryCross == 1 && VictoryZero == 0) {
            answer = "Petya won";
        }
        else if (VictoryCross == 0 && VictoryZero == 1) {
            answer = "Vanya won";
        }
    }
    else {
        answer = "Incorrect";
    }
    std::cout << answer;
}