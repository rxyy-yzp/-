#include"txz.h"

IMAGE imgbk, img01, img02, img03, img04, img05, img06;
IMAGE img0, img1, img2, img3, img4, img5;
IMAGE img15, img16, img40, img50;
IMAGE img20, img21, img22, img23, img24;
IMAGE imgmes1,imgmes2;

//ǽΪ1 �յ�Ϊ0 ��Ϊ5 ����Ϊ4 Ŀ�ĵ�Ϊ3  �ʵ�Ϊ10  �հ�50
int map00[7][10] =
{ {50,50,50,1,1,1,1,1,10,50},
{50,1,1,1,0,0,0,0,10,50},
{1,1,3,0,4,1,1,0,10,1},
{1,3,3,4,0,4,0,0,5,10},
{1,3,3,0,4,0,4,0,10,1},
{1,1,1,1,1,1,0,0,10,50},
{50,50,50,50,50,1,1,1,10,50}, };

//�յ�Ϊ0 ��Ϊ5 ����Ϊ4 Ŀ�ĵ�Ϊ3  ���ƶ�ǽΪ15��16
//��ɫǽ20����ɫǽ21��ǳ��ǽ22����ɫǽ23 �հ�ǽ50
int map01[7][7] =
{ {50,50,40,50,50,50,50},
{40,40,40,40,40,40,40},
{21,20,15,23,20,16,21},
{20,3,0,5,4,0,23},
{23,3,0,0,4,0,20},
{22,21,23,22,21,0,22},
{50,50,50,50,20,23,20}, };

//ǽΪ1 �յ�Ϊ0 ��Ϊ5 ����Ϊ4 Ŀ�ĵ�Ϊ3  
//��ɫǽ20����ɫǽ21��ǳ��ǽ22����ɫǽ23����ɫ24���հ�ǽ50
int map02[9][8] =
{ {20,24,23,20,22,24,20,21},
{22,0,0,0,0,0,0,23},
{24,0,0,20,0,4,0,22},
{20,0,21,23,0,0,0,20},
{23,0,0,20,5,0,0,23},
{24,0,3,22,21,0,0,21},
{20,0,0,0,0,0,4,20},
{22,20,23,21,20,22,3,22},
{50,50,50,50,50,23,20,21}, };

//������
int main()
{
    char k;//���ڽ������˵��¼�������
    int a1, a2, a3;//����playgame����ֵ
    char choose1, choose2;//���ڴ洢ѡ���Ƿ�ֱ��������һ��
    int flag = 0;
    int map1[7][10];
    int map2[7][7];
    int map3[9][8];

    InitGame();//λ��initgame.h

	//��ʼ������
    HWND txz = initgraph(560, 600);
    SetWindowTextA(txz, "������");
    setbkcolor(RGB(245,245,245));
    cleardevice();

    mciSendString("open sf.mp3 alias BGM", 0, 0, 0);//��������
    mciSendString("play BGM repeat", 0, 0, 0);//ѭ������

    do {
        k = menu();//λ��initgame.h
        switch (k)
        {     
        gate1:
        case '1':
            Create1(map1);//λ��game1.h
            while (1)
            {
                cleardevice();
                DrawMap1(map1);//λ��game1.h
                a1 = PlayGame1(map1);//λ��game1.h
                if (a1 == 1)
                    break;
                else if (a1 == 2)
                {
                    settextstyle(25, 0, "����");
                    outtextxy(30, 440, "�Ƿ�Ҫ����ڶ���?");
                    settextstyle(25, 0, "����");
                    outtextxy(30, 475, "��ѡ��:(y/n)");
                    choose1=_getch();
                    if (choose1 == 'y')
                        goto gate2;
                    else
                        break;
                }
                else if (a1 == 3)
                {
                    goto gate1;
                }
            }
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "����");
            outtextxy(30, 520, "�����������...");
            system("pause");
            cleardevice();
            break;
        gate2:
        case '2':
            Create2(map2);//λ��game2.h
            while (1)
            {
                cleardevice();
                DrawMap2(map2);//λ��game2.h
                a2 = PlayGame2(map2);//λ��game2.h
                if (a2 == 1)
                    break;
                else if (a2 == 2)
                {
                    settextstyle(25, 0, "����");
                    outtextxy(30, 490, "�Ƿ�Ҫ���������?");
                    settextstyle(25, 0, "����");
                    outtextxy(30, 520, "��ѡ��:(y/n)");
                    choose2=_getch();               
                    if (choose2 == 'y')
                        goto gate3;
                    else
                        break;
                }
                else if (a2 == 3)
                {
                    goto gate2;
                }
            }
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "����");
            outtextxy(30, 520, "�����������...");
            system("pause");
            cleardevice();
            break;
        gate3:
        case '3':
            Create3(map3);//λ��game3.h
            while (1)
            {
                cleardevice();
                DrawMap3(map3);//λ��game3.h
                a3 = PlayGame3(map3);//λ��game3.h
                if (a3 == 1)
                    break;
                else if (a3 == 3)
                {
                    goto gate3;
                }
            }
            settextcolor(RGB(0, 0, 0));
            settextstyle(25, 0, "����");
            outtextxy(30, 520, "�����������...");
            system("pause");
            cleardevice();
            break;
        case '4':
            system("cls");
            ShowMessage1();
            break;
        case '5':
            system("cls");
            ShowMessage2();
            break;      
        }
    } while (k);
    return 0;
}
