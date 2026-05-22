#include <iostream>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include "HW.h"
//#include <random>
using namespace std;

/*
1. 자리수 분리해서 합치기(입력은 자리 수 제한 없음)
    Homework02_Run(); 함수로 실행 가능해야 함.
*/
void Homework02_Run()
{
    unsigned long long int Input = 0;
    printf("자릿수 입력 : ");
    cin >> Input;
    int EST = 1;
    int Quotient = 0;
    int SUM = 0;
    while (EST)
    {
        SUM = SUM + Input % 10;
        Quotient = Input / 10;
        if (Quotient != 0)
        {
            Input = Quotient;
        }
        else
        {
            EST = 0;
        }

    }
    printf("자릿수의 합 : %d\n\n", SUM);
}





/*
2. 슬롯 머신 게임 만들기
    Homework03_Run(); 함수로 실행 가능해야 함.
    시작 금액 10000
    한판에 무조건  최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
    같은 숫자 3개가 나오면 50배로 돌려 받는다.
    만약 777이면 10000배 받음
*/

void Homework03_Run()
{
    unsigned long long int Startmoney = 10000;
    unsigned long long int bet = 100;
    int slut1 = 0;
    int slut2 = 0;
    int slut3 = 0;

    srand(time(0));
    while (Startmoney>=100)
    {
        printf("현재 소지금 : %lld원\n", Startmoney);
        printf("배팅할 금액 입력 :\n");
        cin >> bet;
        if (bet < 100)
        {
            printf("최소 100이상 배팅해야합니다.\n");
            printf("배팅할 금액 입력 :\n");
            cin >> bet;
        }
        printf("\n현재 배팅금 : %lld원\n", bet);
        

        slut1 = rand() % 10;
        slut2 = rand() % 10;
        slut3 = rand() % 10;

        if (slut1 == slut2 && slut2 == slut3)
        {
            if (slut1 != 7)
            {
                printf("같은 숫자가 3개입니다.\n");
                printf("배팅한 금액 %lld의 50배인 %lld를 받습니다.\n", bet, 50 * bet);
                Startmoney = Startmoney + 49 * bet;
            }
            else if (slut1 == 7)
            {
                printf("7이 3개입니다.\n");
                printf("배팅한 금액 %lld의 10000배인 %lld를 받습니다.\n", bet, 10000 * bet);
                Startmoney = Startmoney + 9999 * bet;
            }

        }

    }



}




/*
3. 도둑 잡기 만들기
    Homework04_Run(); 함수로 실행 가능해야 함.
    시작 금액 10000
    한판에 무조건 최소 100 배팅해야 함. 만약 소지금액이 100 이하일 경우 게임 종료.
    딜러는 A~K까지의 트럼프 카드 중 2장을 중복없이 선택하고 조커 카드가 추가된다.
    플레이어는 딜러의 카드 중 한장을 선택한다.
    만약 플레이어가 조커를 뽑있다면 플레이어의 승리. 배팅 금액의 2배를 받는다.
    플레이어가 조커를 뽑지 못했다면 다음 게임을 시작하거나 배팅 금액의 2배를 추가로 지불하고 한번 더 선택할 수 있다.
*/




/*
4. 미로 탈출 게임에 랜덤 인카운터를 추가하여 적과의 턴제 전투 만들기
    Homework05_Run(); 함수로 실행 가능해야 함.
    HP는 100으로 시작
    공격을 할 때 상대방에게 5~15의 데미지를 준다.
    10 % 의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
    상대방의 HP가 0 이하가 되면 승리한다.
*/
