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
    unsigned long long int Quotient = 0;
    unsigned long long int SUM = 0;
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
    printf("자릿수의 합 : %lld\n\n", SUM);
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
        printf("배팅할 금액 입력 :");
        cin >> bet;
        while (1)
        {
            if (bet > 100 && bet <= Startmoney)
            {
                break;
            }
            else
            {
                printf("최소 100이상, 현재소지금 내에 배팅해야합니다.\n");
                printf("배팅할 금액 입력 :");
                cin >> bet;
			}
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
        else
        {
            printf("배팅 실패.\n");
			Startmoney = Startmoney - bet;
        }
        printf("=========================\n");
    }

	printf("소지금이 100원 이하입니다. 게임 종료.\n");



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

void FisherYatesShuffle(int* Array, int Lenght)
{

    for (int i = Lenght - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        int Temp = Array[i];
        Array[i] = Array[j];
        Array[j] = Temp;
    }
}

void Homework04_Run()
{
    unsigned long long int Startmoney = 10000;
    unsigned long long int bet = 100;
    int Card1 = 0;
    int Card2 = 0;
	int Card3 = 0;

    srand(time(0));
    while (Startmoney >= 100)
    {
        printf("현재 소지금 : %lld원\n", Startmoney);
        printf("배팅할 금액 입력 :");
        cin >> bet;
        while (1)
        {
            if (bet > 100 && bet <= Startmoney)
            {
                break;
            }
            else
            {
                printf("최소 100이상, 현재소지금 내에 배팅해야합니다.\n");
                printf("배팅할 금액 입력 :");
                cin >> bet;
            }
        }

        printf("\n현재 배팅금 : %lld원\n", bet);


        Card1 = rand() % 14;
        Card2 = rand() % 14;
        Card3 = 14;

        while(Card1 == Card2)
        {
            Card2 = rand() % 14;
		}
        int CardArray[3] = { Card1, Card2, Card3 };
        char CardNameArray[2] = {' ',' '};
        for (int i = 0; i < 2; i++)
        {
            switch (CardArray[i])
            {
            case 0:
				CardNameArray[i] = 'A';
                break;
            case 10:
                CardNameArray[i] = '10';
                break;
            case 11:
				CardNameArray[i] = 'J';
                break;
            case 12:
				CardNameArray[i] = 'Q';
                break;
            case 13:
				CardNameArray[i] = 'K';
                break;
            default:
                CardNameArray[i] = '0' + CardArray[i];
				break;
            }
        }
        printf("딜러 카드 선택 완료\n");
        printf("현재 딜러가 들고 있는 카드(순서 상관 X) : %c, %c, 조커\n", CardNameArray[0], CardNameArray[1]);

        FisherYatesShuffle(CardArray, 3);

        printf("플레이어 카드 선택 : 1, 2, 3 중 하나 선택 : ");
		int PlayerCard = 0;
		cin >> PlayerCard;

        if (CardArray[PlayerCard-1] == 14)
        {
            printf("조커를 뽑았습니다. 플레이어 승리!\n");
            printf("배팅한 금액 %lld의 2배인 %lld를 받습니다.\n", bet, 2 * bet);
            Startmoney = Startmoney + bet;
        }
        else
        {
            printf("조커를 뽑지 못했습니다.\n");
            printf("다음 게임을 시작하거나 배팅 금액의 2배인 %lld를 추가로 지불하고 한번 더 선택할 수 있습니다.\n", 2 * bet);
            printf("1. 다음 게임 시작\n");
            printf("2. 한번 더 선택\n");
            printf("선택 : ");
			int PlayerChoice = 0;

			cin >> PlayerChoice;
            if(PlayerChoice == 1)
            {
				Startmoney -= bet;
                continue;
            }
            else if (PlayerChoice == 2)
            {
                if (Startmoney >= bet * 3)
                {
                    printf("플레이어 카드 선택 : 1, 2, 3 중 하나 선택 : ");
                    cin >> PlayerCard;
                    if (CardArray[PlayerCard-1] == 14)
                    {
                        
                        printf("조커를 뽑았습니다. 플레이어 승리!\n");
                        printf("배팅한 금액 %lld + %lld의 2배인 %lld를 받습니다.\n", bet, bet*3, 6 * bet);
                        Startmoney = Startmoney + 6 * bet;
                    }
                    else
                    {
                        printf("조커를 뽑지 못했습니다. 플레이어 패배.\n");
                    }

                }
            }

        }
    }

    printf("소지금이 100원 이하입니다. 게임 종료.\n");



}



/*
4. 미로 탈출 게임에 랜덤 인카운터를 추가하여 적과의 턴제 전투 만들기
    Homework05_Run(); 함수로 실행 가능해야 함.
    HP는 100으로 시작
    공격을 할 때 상대방에게 5~15의 데미지를 준다.
    10 % 의 확률로 크리티컬이 발생해 2배의 데미지를 준다.
    상대방의 HP가 0 이하가 되면 승리한다.
*/

const int MazeRows = 10;
const int MazeCols = 20;

// 미로 배열
int Maze[MazeRows][MazeCols] =
{
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,2,0,0,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,1},
    {1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1},
    {1,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,3,1},
    {1,0,1,1,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void Homework05_Run() {
    char Selectkey;

	int PlayerX = 1;
	int PlayerY = 1;
	int PlayerLocatition = Maze[PlayerY][PlayerX];


    while (true)
    {

        system("cls");
        int h = 0, w = 0;		//세로,가로

        //탈출 로직
        if (PlayerLocatition == 3)
        {
            system("cls");
            printf("미로 탈출 성공!\n");
            break;
        }

        // 미로 출력
		for (h = 0; h < MazeRows; h++)
        {
            for (w = 0; w < MazeCols; w++)
            {
                int temp = Maze[h][w];
                if (h == PlayerY && w == PlayerX)
                {
                    printf("P");
                }
                else if (Maze[h][w] == 0)
                {
                    printf(".");
                }
                else if (Maze[h][w] == 1)
                {
                    printf("#");
                }
                else if (Maze[h][w] == 2)
                {
                    printf("S");
                }
                else if (Maze[h][w] == 3)
                {
                    printf("E");
                }
            }
            printf("\n");
        }

		printf("이동할 방향을 입력해주세요. (w: 위, s: 아래, a: 왼쪽, d: 오른쪽)\n");


        //플레이어 이동
        Selectkey = _getch();
        while (true)
        {


            if (Selectkey == 'w' || Selectkey == 'W')
            {
                if (PlayerY > 0 && PlayerY < 9)
                {
                    PlayerY--;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                if (PlayerLocatition == 1)
                {
                    PlayerY++;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                break;

            }
            else if (Selectkey == 's' || Selectkey == 'S')
            {
                if (PlayerY > 0 && PlayerY < 9)
                {
                    PlayerY++;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                if (PlayerLocatition == 1)
                {
                    PlayerY--;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                break;
            }
            else if (Selectkey == 'a' || Selectkey == 'A')
            {
                if (PlayerX > 0 && PlayerX < 19)
                {
                    PlayerX--;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                if (PlayerLocatition == 1)
                {
                    PlayerX++;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                break;
            }
            else if (Selectkey == 'd' || Selectkey == 'D')
            {
                if (PlayerX > 0 && PlayerX < 19)
                {
                    PlayerX++;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                if (PlayerLocatition == 1)
                {
                    PlayerX--;
                }
                PlayerLocatition = Maze[PlayerY][PlayerX];
                break;
            }
            else
            {
				Selectkey = _getch();
            }
        }
    }
}