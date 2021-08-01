#pragma once

extern IMAGE imgbk, img01, img02, img03, img04, img05, img06;
extern IMAGE img0, img1, img2, img3, img4, img5;
extern IMAGE img15, img16, img40, img50;
extern IMAGE img20, img21, img22, img23, img24;
extern IMAGE imgmes1,imgmes2;

extern int map01[7][7];

//���������Ա㴫ֵ
void Create2(int map2[7][7])
{
    int i, j;
    for (i = 0;i < 7;i++)
    {
        for (j = 0;j < 7;j++)
        {
            map2[i][j] = map01[i][j];
        }
    }
}

//���Ƶڶ��ؽ��漰��ͼ
void DrawMap2(int map2[7][7])
{
    //��forѭ����������
    BeginBatchDraw();
    putimage(0, 0, &img02);
    
    for (int i = 0;i < 7;i++)
    {
        for (int j = 0;j < 7;j++)
        {
            switch (map2[i][j])
            {
            case 0:
                putimage((j + 3) * 40, (i + 2) * 40, &img0);
                break;
            case 40:
                putimage((j + 3) * 40, (i + 2) * 40, &img40);
                break;
            case 50:
				//�հ�ǽ50
                putimage((j + 3) * 40, (i + 2) * 40, &img50);
                break;
            case 20:
				//��ɫǽ20
                putimage((j + 3) * 40, (i + 2) * 40, &img20);
                break;
            case 21:
				//��ɫǽ21
                putimage((j + 3) * 40, (i + 2) * 40, &img21);
                break;
            case 22:
				//ǳ��ǽ22
                putimage((j + 3) * 40, (i + 2) * 40, &img22);
                break;
            case 23:
				//��ɫǽ23
                putimage((j + 3) * 40, (i + 2) * 40, &img23);
                break;
            case 3:
                putimage((j + 3) * 40, (i + 2) * 40, &img4);
                break;
            case 4:
                putimage((j + 3) * 40, (i + 2) * 40, &img2);
                break;
            case 5:
                putimage((j + 3) * 40, (i + 2) * 40, &img3);
                break;
            case 7:
				//���ӵ���Ŀ�ĵ� 4+3=7
                putimage((j + 3) * 40, (i + 2) * 40, &img5);
                break;
            case 8:
				//�˵���Ŀ�ĵ� 5+3=8
                putimage((j + 3) * 40, (i + 2) * 40, &img3);
                break;
            case 15:
				//���ƶ�ǽ1
                putimage((j + 3) * 40, (i + 2) * 40, &img15);
                break;
            case 16:
				//���ƶ�ǽ2
                putimage((j + 3) * 40, (i + 2) * 40, &img16);
                break;
            }
        }
    }
    settextcolor(RGB(0, 0, 0));
    settextstyle(25, 0, "����");
    outtextxy(30, 380, "ǽ��ˢ��");
    settextcolor(RGB(255, 0, 0));
    outtextxy(130, 380, "��");
    settextcolor(RGB(0, 200, 255));
    outtextxy(155, 380, "ɫ");
    settextcolor(RGB(0, 0, 0));
    outtextxy(180, 380, "��");
    outtextxy(30, 415, "�ѵ�ֻ�Ǳ�ÿ���?");
    putimage(0, 545, &img05);
    EndBatchDraw();
}

//������Ϸ
int PlayGame2(int map2[7][7])
{
    //��ȡ����ǰ���˵��±�
    int row, col;//�˵� �� �� ��
    char x;//�˳�ʱy/n
    for (int i = 0;i < 7;i++)//���Ʊ��� 0-6
    {
        for (int j = 0;j < 7;j++)//���Ʊ���0-9
        {
            if (map2[i][j] == 5 || map2[i][j] == 8)
            {
                row = i;//i 0-6
                col = j;//j 0-9
            }
        }
    }

    //ʤ���ж�
    if (map2[3][1] == 7 && map2[4][1] == 7)
    {
        settextstyle(30, 0, "����");
        outtextxy(30, 450, "��ϲ��!�ɹ�ͨ���˵ڶ���!");
        return 2;
    }

    //����������ͼ������Ӧ������
    char input;//����һ���ַ�����
    input = _getch();//���ܼ�����������Ӧ��ֵ
    //getch() ����ʾ���ģ����¼������Ͻ���
    switch (input)
    {
        /************************************
        ����������Щ���
        1.�˵�ǰ���ǿյ�
        2.�˵�ǰ����Ŀ�ĵ�
        3.�˵�ǰ�������������ӵ�ǰ���ǿյ�
        4.�˵�ǰ�������������ӵ�ǰ����Ŀ�ĵ�
		5.�˵�ǰ������ɫǽ����ǽ���ƣ���ǽǰ���ǿյ�
        *************************************/
    case 'w'://��
        if (map2[row - 1][col] == 0 || map2[row - 1][col] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map2[row][col] -= 5;//�˵�ID 5/8
            map2[row - 1][col] += 5;
        }
        else if (map2[row - 1][col] == 4 || map2[row - 1][col] == 7)//�˵�ǰ��������
        {
            if (map2[row - 2][col] == 0 || map2[row - 2][col] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map2[row - 2][col] += 4;
                map2[row - 1][col] += 1;
                map2[row][col] -= 5;
            }

        }
        else if (map2[row - 1][col] == 15 && map2[row - 2][col] == 40)
        {
            map2[row][col] -= 5;
            map2[row - 1][col] = 5;
            map2[row - 2][col] = 15;
            if (map2[0][2] == 15)//�����µ�Χǽ
            {
                map2[0][0] = 20;
                map2[0][1] = 21;
                map2[0][3] = 23;
                map2[0][4] = 20;
                map2[0][5] = 22;
                map2[0][6] = 21;
                map2[1][0] = 23;
                map2[1][6] = 20;
                map2[1][1] = 0;
                map2[1][3] = 0;
                map2[1][4] = 0;
                map2[1][5] = 0;
            }
        }
        break;
    case 'a'://��
        if (map2[row][col - 1] == 0 || map2[row][col - 1] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map2[row][col] -= 5;//�˵�ID 5/8
            map2[row][col - 1] += 5;
        }
        else if (map2[row][col - 1] == 4 || map2[row][col - 1] == 7)//�˵�ǰ��������
        {
            if (map2[row][col - 2] == 0 || map2[row][col - 2] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map2[row][col - 2] += 4;
                map2[row][col - 1] += 1;
                map2[row][col] -= 5;
            }

        }
        break;
    case 's'://��
        if (map2[row + 1][col] == 0 || map2[row + 1][col] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map2[row][col] -= 5;//�˵�ID 5/8
            map2[row + 1][col] += 5;
        }
        else if (map2[row + 1][col] == 4 || map2[row + 1][col] == 7)//�˵�ǰ��������
        {
            if (map2[row + 2][col] == 0 || map2[row + 2][col] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map2[row + 2][col] += 4;
                map2[row + 1][col] += 1;
                map2[row][col] -= 5;
            }

        }
        else if (map2[row + 1][col] == 16 && map2[row + 2][col] == 0)
        {
            map2[row][col] -= 5;
            map2[row + 1][col] = 5;
            map2[row + 2][col] = 16;
        }
        break;
    case 'd'://��
        if (map2[row][col + 1] == 0 || map2[row][col + 1] == 3)//����˵�ǰ���ǿյ�/Ŀ�ĵ�
        {

            map2[row][col] -= 5;//�˵�ID 5/8
            map2[row][col + 1] += 5;
        }
        else if (map2[row][col + 1] == 4 || map2[row][col + 1] == 7)//�˵�ǰ��������
        {
            if (map2[row][col + 2] == 0 || map2[row][col + 2] == 3)//����ǰ���ǿյ�/Ŀ�ĵ�
            {
                map2[row][col + 2] += 4;
                map2[row][col + 1] += 1;
                map2[row][col] -= 5;
            }

        }
        break;
    case 'q'://�˳�
        settextstyle(25, 0, "����");
        outtextxy(30, 450, "������ȷ��Ҫ�˳��Ѷ�Ϊ�ǳ��򵥵ĵڶ�����?");
        settextstyle(25, 0, "����");
        outtextxy(30, 485, "��ѡ��:(y/n)");
        x=_getch();
        if (x == 'y')
            return 1;
        break;
    case 'r'://���¿�ʼ����
        return 3;
        break;
    }
    return 0;
}